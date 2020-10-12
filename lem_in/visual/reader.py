# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    reader.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 14:10:13 by tbrizon           #+#    #+#              #
#    Updated: 2019/10/25 14:10:15 by tbrizon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import argparse
import os
import re
import sys

from pprint import pprint


def parse_map(data, map_path):
    patterns = {
        'tunnels': re.compile(r'^([\d\w]+)-([\d\w]+)\n$'),
        'nodes': re.compile(r'^([\d\w]+) \d+ \d+\n$'),
        'start': re.compile(r'^##start\n$'),
        'end': re.compile(r'^##end\n$'),
        'ants': re.compile(r'^(\d+)\n$')
    }

    with open(map_path, 'r') as f:
        for line in f:
            for key, value in patterns.items():
                for match in value.findall(line):
                    if key in ['start', 'end']:
                        node = next(f)
                        while node.startswith("#"):
                            node = next(f)
                        match = patterns['nodes'].search(node)
                        data[key] = match.groups(1)[0]
                        data['nodes'].append(match.groups()[0]) 
                    elif key is 'ants':
                        data[key] = match
                    else:
                        data[key].append(match)
    return data


def parse_sol(data, sol_path):
    re_turns = re.compile(r'L([\d\w]+)-([\d\w]+)')

    if not sol_path:
        out_solution = sys.stdin.read().splitlines()
    else:
        with open(sol_path, 'r') as f:
            out_solution = f.readlines()
    for line in out_solution:
        visual_solution = re_turns.findall(line)
        if visual_solution:
            data['num_turns'] += 1
            data['turns'].append(visual_solution)
    
    return data


def parse(map_path, sol_path=None):
    data = {
        'tunnels': [],
        'nodes': [],
        'turns': [],
        'start': None,
        'end': None,
        'ants': None,
        'num_turns': 0,
    }
    return parse_sol(parse_map(data, map_path), sol_path)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("map", help="Path to map file", type=str)
    parser.add_argument("-s", "--solution",
                        help="File path to solution", type=str)
    args = parser.parse_args()
    if not os.path.exists(args.map):
        raise IOError("Map file not found")
    if args.solution and not os.path.exists(args.solution):
        raise IOError("Solution file not found")
    parse(args.map, args.solution)
    pprint(parse(args.map, args.solution))