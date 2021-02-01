min_cost = 1e100
best_solution = None
cache = {}

def dist(p1, p2):
    return ((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)**0.5

def find_best_config(coordinates):
    if len(coordinates) == 2:
        return dist(*coordinates), coordinates

    coordinate0 = coordinates.pop(0)
    best_score = 1e100
    best_config = None
    for i in range(len(coordinates)):
        copy = coordinates[:]
        coordinate1 = copy.pop(i)
        dist_c = dist(coordinate0, coordinate1)
        c = tuple([tuple(c) for c in copy])
        if c in cache:
            dist_t, config = cache[c]
        else:
            dist_t, config = find_best_config(copy)
            cache[c] = dist_t, config

        if dist_c + dist_t < best_score:
            best_score = dist_c + dist_t
            best_config = [coordinate0, coordinate1] +  config

    return best_score, best_config


n = int(input())
coordinates = []

for i in range(2*n):
    coordinates.append(list(map(int, input().split())))

print(round(find_best_config(coordinates)[0], 2))
