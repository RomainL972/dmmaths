from tkinter import *
import argparse
import os
import time

parser = argparse.ArgumentParser(description='Affiche le résultat du programme DM')
parser.add_argument('--disques', '-d', type=int,choices=range(1, 12),default=10,
                    help='le nombre de disques')
parser.add_argument('--dm-path', '-p',default='build/src/DM',
                    help='le chemin d\'accès du programme DM')
parser.add_argument('--interactive', '-i',action='store_true',
                    help='le programme devrait-il rester ouvert à la fin')

args = parser.parse_args()

tk = Tk()
c = Canvas(tk, width=1000, height=500)
c.pack()

colors = ['blue', 'red', 'orange', 'black', 'magenta', 'cyan', 'green', 'gray', 'brown', 'yellow', 'purple'];
disques = args.disques
text = ["A", "B", "C"]

x = 1000
y = 500

pile = {"x": x/3, "y": y}
offset = {"x": pile["x"] * 10 / 100, "y": pile["y"] * 10 / 100}
available = {"x": pile["x"] - offset["x"], "y": pile["y"] - offset["y"]}

def rel_line(x, y, relX, relY):
    c.create_line(x, y, x+relX, y+relY)

def rel_rect(x, y, relX, relY, color="black"):
    return c.create_rectangle(x, y, x+relX, y+relY, fill=color)

piles = [[], [], []]

# Draw lines
for i in range(3):
    rel_line(pile["x"] * i + offset["x"]/2, pile["y"] - offset["y"]/2, available["x"], 0)

diff = {"x": available["x"]/(disques+1), "y": available["y"]/disques}
size = {"y": diff["y"]}

# Draw disks
for i in range(disques):
    size["x"] = available["x"] - diff["x"] * (i + 1)
    res = rel_rect(offset["x"]/2 + diff["x"]*(i+1)/2, pile["y"]-offset["y"]/2-diff["y"]*i, size["x"], -size["y"], colors[i])
    piles[0].append([i, res])

os.system(args.dm_path + " " + str(disques) + " 1")
movesFile = open("moves.txt", "r")

def moveDisque(fromP, to):
    global size, available, diff, pile
    disqueFrom = piles[fromP].pop()
    size["x"] = available["x"] - diff["x"] * (disqueFrom[0] + 1)
    c.delete(disqueFrom[1])
    disqueFrom = disqueFrom[0]
    # rel_rect(pile["x"] * fromP + offset["x"]/2 + diff["x"]*(disqueFrom+1)/2, pile["y"]-offset["y"]/2-diff["y"]*len(piles[fromP]), size["x"], -size["y"], "white")
    res = rel_rect(pile["x"] * to   + offset["x"]/2 + diff["x"]*(disqueFrom+1)/2, pile["y"]-offset["y"]/2-diff["y"]*len(piles[to  ]), size["x"], -size["y"], colors[disqueFrom])
    piles[to].append([disqueFrom, res])


lines = movesFile.readlines()
def main(lines, i):
    line = lines[i]
    moveDisque(int(line[0]), int(line[2]))
    if i+1 < len(lines):
        tk.after(10, lambda: main(lines, i+1))
main(lines, 0)

# movesFile = open("moves.txt", "r")
#
# for line in movesFile.readlines():
#     moveDisque(int(line[0]), int(line[2]))

tk.mainloop()
