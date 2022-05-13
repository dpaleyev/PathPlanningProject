import time

import pygame
from lxml import etree as et
import random

WIDTH = 900
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREY = (128, 128, 128)

WIN = pygame.display.set_mode((WIDTH, WIDTH))
pygame.display.set_caption("A* Path Finding Algorithm")


def data_parser(filename):
    tree = et.parse(filename)
    root = tree.getroot()
    paths = []
    hppath = root.find(".//hplevel")
    for agent in hppath.findall("agent"):
        path = []
        it = 0
        for section in agent.findall("section"):
            if it == 0:
                path.append((int(section.get("start.x")), int(section.get("start.y"))))
            path.append((int(section.get("finish.x")), int(section.get("finish.y"))))
            it += 1
        paths.append(path)

    grid = Grid(int(root.find(".//width").text), int(root.find(".//height").text), WIDTH)

    count_i = 0
    for row in root.find(".//grid"):
        count_j = 0
        for el in [int(i) for i in row.text.split()]:
            if el == 1:
                grid.grid[count_j][count_i].color = BLACK
            count_j += 1
        count_i += 1

    return paths, grid


class Cell:
    def __init__(self, row, col, width):
        self.row = row
        self.col = col
        self.x = row * width
        self.y = col * width
        self.color = WHITE
        self.isGoal = False
        self.goalColor = None
        self.width = width

    def draw(self, win):
        pygame.draw.rect(win, self.color, (self.x, self.y, self.width, self.width))
        if self.isGoal:
            pygame.draw.rect(win, self.goalColor, (self.x + 1, self.y + 1, self.width - 2, self.width - 2), 2)
        pygame.draw.rect(win, GREY, (self.x, self.y, self.width, self.width), 1)


class Grid:
    def __init__(self, row, col, width):
        self.grid = []
        self.rows = row
        self.columns = col
        self.gap = width // max(row, col)
        for i in range(row):
            self.grid.append([])
            for j in range(row):
                self.grid[i].append(Cell(i, j, self.gap))

    def update_grid(self, info, colors, prev):
        if len(prev) != 0:
            for cell in prev:
                self.grid[cell[0]][cell[1]].color = WHITE

        for i in range(len(info)):
            self.grid[info[i][0]][info[i][1]].color = colors[i]

    def set_goals(self, goals, colors):
        i = 0
        for goal in goals:
            cell = self.grid[goal[0]][goal[1]]
            cell.isGoal = True
            cell.goalColor = colors[i]
            i += 1

    def draw(self, win):
        win.fill(WHITE)

        for row in self.grid:
            for cell in row:
                cell.draw(win)

        pygame.display.update()


def main(win):
    filename = input()
    path, grid = data_parser(filename)
    agent_colors = [list(random.choices(range(256), k=3)) for _ in range(len(path))]
    goals = []
    for agent in path:
        goals.append(agent[-1])

    grid.set_goals(goals, agent_colors)

    run = True
    step = 0
    while run:
        prev = []
        new = []
        for agent in path:
            if len(agent) <= step:
                new.append(agent[-1])
            else:
                new.append(agent[step])
            if step != 0:
                if len(agent) <= step - 1:
                    prev.append(agent[-1])
                else:
                    prev.append(agent[step - 1])
        grid.update_grid(new, agent_colors, prev)
        grid.draw(win)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
                break

        step += 1
        time.sleep(1)
    pygame.quit()


main(WIN)