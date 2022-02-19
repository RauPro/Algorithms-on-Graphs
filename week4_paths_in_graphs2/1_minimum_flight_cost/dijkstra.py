# Uses python3

import sys
from heapq import heappush, heappop

INF = float('inf')
if __name__ == '__main__':

    V, E = map(int, input().split(" "))
    AL = [[] for u in range(V)]
    for _ in range(E):
        u, v, w = map(int, input().split(" "))
        AL[u-1].append((v-1, w))

    dist = [INF for u in range(V)]
    s, t = map(int, input().split(" "))
    s = s-1
    t = t-1

    dist[s] = 0
    pq = []
    heappush(pq, (0, s))

    while len(pq) > 0:
        d, u = heappop(pq)
        if d > dist[u]:
            continue
        for v, w in AL[u]:
            if dist[u] + w >= dist[v]:
                continue
            dist[v] = dist[u] + w
            heappush(pq, (dist[v], v))

    print( -1 if dist[t] == INF else dist[t])
