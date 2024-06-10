import itertools

cities = {'A': (0, 0), 'B': (1, 5), 'C': (2, 3), 'D': (5, 2), 'E': (6, 6)}

def distance(city1, city2):
    x1, y1 = cities[city1]
    x2, y2 = cities[city2]
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

perms = itertools.permutations(cities.keys())

shortest_path = None
shortest_distance = float('inf')

for perm in perms:
    total_distance = 0
    for i in range(len(perm) - 1):
        total_distance += distance(perm[i], perm[i+1])
    total_distance += distance(perm[-1], perm[0])
    if total_distance < shortest_distance:
        shortest_path = perm
        shortest_distance = total_distance

print('Shortest path:', shortest_path)
print('Total distance:', shortest_distance)