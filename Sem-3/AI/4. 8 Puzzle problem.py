from heapq import heappush, heappop

n = 3

row = [1, 0, -1, 0]
col = [0, -1, 0, 1]

class PriorityQueue:
    def __init__(self):
        self.heap = []

    def push(self, item):
        heappush(self.heap, item)

    def pop(self):
        return heappop(self.heap)

    def empty(self):
        return not self.heap

class Node:
    def __init__(self, parent, matrix, empty_tile_pos, cost, level):
        self.parent, self.matrix, self.empty_tile_pos, self.cost, self.level = parent, matrix, empty_tile_pos, cost, level

    def __lt__(self, nxt):
        return self.cost < nxt.cost

def calculate_cost(matrix, final) -> int:
    return sum([matrix[i][j] != final[i][j] for i in range(n) for j in range(n)])

def new_node(matrix, empty_tile_pos, new_empty_tile_pos, level, parent, final) -> Node:
    new_matrix = [row[:] for row in matrix]
    x1, y1 = empty_tile_pos
    x2, y2 = new_empty_tile_pos
    new_matrix[x1][y1], new_matrix[x2][y2] = new_matrix[x2][y2], new_matrix[x1][y1]
    cost = calculate_cost(new_matrix, final)
    return Node(parent, new_matrix, new_empty_tile_pos, cost, level)

def print_matrix(matrix):
    for i in range(n):
        print(*matrix[i])

def print_path(root):
    if root is None:
        return
    print_path(root.parent)
    print_matrix(root.matrix)
    print()

def solve(initial, empty_tile_pos, final):
    pq = PriorityQueue()
    cost = calculate_cost(initial, final)
    root = Node(None, initial, empty_tile_pos, cost, 0)
    pq.push(root)
    visited = set()
    while not pq.empty():
        minimum = pq.pop()
        if minimum.cost == 0:
            print_path(minimum)
            return
        visited.add(tuple(map(tuple, minimum.matrix)))
        for i in range(4):
            new_empty_tile_pos = (minimum.empty_tile_pos[0] + row[i], minimum.empty_tile_pos[1] + col[i])
            if 0 <= new_empty_tile_pos[0] < n and 0 <= new_empty_tile_pos[1] < n:
                child = new_node(minimum.matrix, minimum.empty_tile_pos, new_empty_tile_pos, minimum.level + 1, minimum, final)
                if tuple(map(tuple, child.matrix)) not in visited:
                    pq.push(child)

initial = [[1, 2, 3], [5, 6, 0], [7, 8, 4]]
final = [[1, 2, 3], [5, 8, 6], [0, 7, 4]]
empty_tile_pos = [1, 2]
solve(initial, empty_tile_pos, final)