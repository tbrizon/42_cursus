# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    fourmisses.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 12:11:30 by tbrizon           #+#    #+#              #
#    Updated: 2019/10/25 14:10:28 by tbrizon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import matplotlib as plt
import matplotlib.image as mpimg
from matplotlib.offsetbox import TextArea, DrawingArea, OffsetImage, AnnotationBbox

class Ant:


    def __init__(self, number, node_path=None, trip=None, color='g.'):
        self.number = number
        self.node_path = node_path
        self.trip = trip
        self.color = color
    
    def set_path(self, data):
        self.node_path = []
        started = False
        self.node_path.append(data['start'])
        for turn in data['turns']:
            for move in turn:
                if move[0] == str(self.number):
                    self.node_path.append(move[1])
                    started = True
            if not started:
                self.node_path.append(data['start'])
    def set_location(self, pos, data):
        self.current_location = pos[data['start']]

    def set_trip(self, pos, speed_rate, data):
        trip = []
 
        for cmpt in range(len(self.node_path)):
            if cmpt != 0:
                start = pos[self.node_path[cmpt-1]]
                end = pos[self.node_path[cmpt]]
                x = np.linspace(start[0], end[0], num=speed_rate)
                y = np.linspace(start[1], end[1], num=speed_rate)
                
                trip.extend(list(zip(x,y)))
            cmpt += 1
        self.trip = trip