#!/usr/bin/env python
# -*- coding: utf-8 -*-
from turtle import *
import os
import sys
import argparse

parser = argparse.ArgumentParser(description='Affiche le résultat du programme DM')
parser.add_argument('--disques', '-d', type=int,choices=range(1, 12),default=5,
                    help='le nombre de disques')
parser.add_argument('--dm-path', '-p',default='build/DM',
                    help='le chemin d\'accès du programme DM')
parser.add_argument('--interactive', '-i',action='store_true',
                    help='le programme devrait-il rester ouvert à la fin')

args = parser.parse_args()

penup()
speed(0)
ht()

def drawRectangle(size, width):
    begin_fill()
    for side in range(4):
        if(side == 0 or side == 2):
            forward(size)
        else:
            forward(width)
        left(90)
    end_fill()

def moveDisque(disqueFrom, disqueTo):
    disqueSize = piles[disqueFrom].pop()
    xSize = xDefaultSize-xDefaultDifference*(disques-disqueSize);
    goto(xPiles[disqueFrom]-xSize/2,yPiles+yDefaultSize*(len(piles[disqueFrom])));
    color('white','white')
    drawRectangle(xSize, yDefaultSize)
    goto(xPiles[disqueTo]-xSize/2,yPiles+yDefaultSize*(len(piles[disqueTo])))
    color('white',colors[disqueSize])
    drawRectangle(xSize,yDefaultSize)
    piles[disqueTo].append(disqueSize)

colors = ['','blue', 'red', 'orange', 'black', 'magenta', 'cyan', 'green', 'gray', 'brown', 'yellow', 'purple'];
disques = args.disques
xDefaultSize = 250
yDefaultSize = 50
xDefaultDifference = 30
if(disques > 7):
    xDefaultDifference = 20
xPiles = [-300, 0, 300]
yPiles = -300
letters = ['A', 'B', 'C']

for number in range(3):
    goto(xPiles[number]-3,yPiles-20)
    write(letters[number])
    goto(xPiles[number]-135, yPiles)
    pendown()
    forward(xDefaultSize+20)
    penup()

piles = [[], [], []]

for number in range(disques,0,-1):
    seth(0)
    color('white', colors[number])
    xSize = xDefaultSize - xDefaultDifference * (disques-number)
    setx(xPiles[0]-xSize/2)
    sety(yPiles+yDefaultSize*(disques-number))
    drawRectangle(xSize, yDefaultSize)
    piles[0].append(number)

os.system(args.dm_path + " " + str(disques) + " 1")
movesFile = open("moves.txt", "r")

for line in movesFile.readlines():
    moveDisque(int(line[0]), int(line[2]))

if(args.interactive):
    exitonclick()
