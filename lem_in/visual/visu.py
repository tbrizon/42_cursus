# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    visu.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 14:10:24 by tbrizon           #+#    #+#              #
#    Updated: 2019/10/25 14:10:25 by tbrizon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import argparse
import matplotlib.pyplot as plt
import numpy as np
import networkx as nx
import os
from pprint import pprint
from matplotlib.animation import FuncAnimation
from reader import parse
from fourmisses import Ant
from matplotlib.offsetbox import TextArea, DrawingArea, OffsetImage, AnnotationBbox
from matplotlib._png import read_png
import matplotlib.image as mpimg

# Colors
bg_color = '#000000'
edge_color = '#A9A9A9'
text_color = '#d4d1de'
default_node_color = '#540606'
ant_colors = ['#08d141', '#bd21bf', '#ff6f00', '#66B615']

# Node size
node_size = 1000

def highlight_node(node, highlight_color):
    node.set_color(highlight_color)
    node.set_edgecolor(edge_color)

def make_ants(pos, speed_rate, data):
    list_ants = []
    for ant_num in range(1, int(data['ants']) + 1):
        ant = Ant(ant_num)
        ant.set_path(data)
        ant.set_location(pos, data)
        ant.set_trip(pos, speed_rate, data)
        ant.color = ant_colors[ant_num % 4]
        list_ants.append(ant)
    
    return (list_ants)

def draw_ant(position, color, ant_img, args): 

    i = 5
    ax = fig.add_subplot(111)
    ant_img = read_png('./images/Fourmisse.png')
    imagebox = OffsetImage(ant_img, zoom=.03)

    if args.images == True and i == 5:
        xy = [position[0], position[1]]
        ab = AnnotationBbox(imagebox, xy,
            xycoords='data',
            boxcoords="offset points")                                  
        ax.add_artist(ab)
    else:
        ant = plt.plot([position[0]], [position[1]], color=color, marker='.', markersize=40.0)
        return (ant)
    

def draw_node(node_name, node_color, node_size, edge_color):
    node_list = []
    node_list.append(node_name)
    node = nx.draw_networkx_nodes(
        G,
        pos,
        nodelist=node_list,
        node_color=node_color,
        node_size=node_size)
    node.set_edgecolor(edge_color)
    return (node)


def draw_nodes(data, node_color, node_size, edge_color):
    nodes = {}
    for name in data['nodes']:
        if name == data['start'] or name == data['end']:
            node = draw_node(name, node_color, node_size * 7, edge_color)
        else:
            node = draw_node(name, node_color, node_size, edge_color)
        nodes[name] = node
    return (nodes)


def re_init(num, G, pos, speed_rate, data, ants, args, ant_img):

    fig.clear()
    node_size = 800

    if args.images == True:
        background = plt.imread('./images/Background.png')
        plt.imshow(background, zorder=0, extent=[-1.1, 0, 0, 1.10])
        plt.imshow(background, zorder=0, extent=[0, 1.10, 0, 1.10])
        plt.imshow(background, zorder=0, extent=[-1.1, 0, -1.10, 0])
        plt.imshow(background, zorder=0, extent=[0, 1.10, -1.10, 0])

    # nodes and tunnels
    tunnels = nx.draw_networkx_edges(G, pos, edge_color=edge_color, style = 'dotted',width=2.0)
    nodes = draw_nodes(data, default_node_color,
                       node_size, edge_color)
    # draw the ants
    for ant in ants:
        if num < len(ant.trip):
            draw_ant(ant.trip[num], ant.color, ant_img, args)
    room_names = nx.draw_networkx_labels(G,
                                         pos,
                                         font_size=10,
                                         labels=dict([(data['start'],
                                                       'START'),
                                                      (data['end'],
                                                       'END')]),
                                         font_color=text_color)
    fig.set_facecolor(bg_color)
    plt.axis('off')


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("map", help="Path to map file", type=str)
    parser.add_argument("-s", "--solution",
                        help="File path to solution", type=str)
    parser.add_argument("--images", help="Background activation = 1, ant activation = 2 both = 3", action="store_true")
    args = parser.parse_args()
    if not os.path.exists(args.map):
        raise IOError("Map file not found")

    if args.solution and not os.path.exists(args.solution):
        raise IOError("Solution file not found")
    data = parse(args.map, args.solution)
    # Graph
    G = nx.Graph()
    G.add_edges_from(data['tunnels'])
    # Fruchterman-Reingold force-directed algorithm's to set rooms.
    pos = nx.spring_layout(G)
    # Ants speed
    speed_rate = 7
    # create an array of * on the ants object
    ants = make_ants(pos, speed_rate, data)
    # size of the graph
    fig = plt.figure(figsize = (15, 10))
    ant_img = read_png('./images/Fourmisse.png')
    ani = FuncAnimation(
    fig,
    re_init,
    frames=data['num_turns'] * 
    speed_rate,
    fargs=(
        G,
        pos,
        speed_rate,
        data,
        ants,
        args,
        ant_img),
    interval=30,
    repeat=True)
    plt.show()   
