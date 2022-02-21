# Uses python3
import sys
import math


class UnionFind:  # OOP style
    def __init__(self, N):
        self.p = [i for i in range(N)]
        self.rank = [0 for i in range(N)]
        self.setSize = [1 for i in range(N)]
        self.numSets = N

    def findSet(self, i):
        if (self.p[i] == i):
            return i
        else:
            self.p[i] = self.findSet(self.p[i])
            return self.p[i]

    def isSameSet(self, i, j):
        return self.findSet(i) == self.findSet(j)

    def unionSet(self, i, j):
        if (not self.isSameSet(i, j)):
            self.numSets -= 1
            x = self.findSet(i)
            y = self.findSet(j)
        # rank is used to keep the tree short
        if (self.rank[x] > self.rank[y]):
            self.p[y] = x
            self.setSize[x] += self.setSize[y]
        else:
            self.p[x] = y
            self.setSize[y] += self.setSize[x]
            if (self.rank[x] == self.rank[y]):
                self.rank[y] += 1

    def numDisjointSets(self):
        return self.numSets

    def sizeOfSet(self, i):
        return self.setSize[self.findSet(i)]


def distance(x, y, x2, y2):
    return math.sqrt(math.pow((x - x2), 2) + math.pow((y - y2), 2))


if __name__ == '__main__':
    n = int(input())
    nodes = [[] for u in range(2)]
    for i in range(n):
        x, y = map(int, input().split(" "))
        nodes[0].append((x, y))
        nodes[1].append(i)

    EL = [];
    for p in range(len(nodes[0])):
        for d in range(p + 1, len(nodes[0])):
            EL.append((distance(*nodes[0][p], *nodes[0][d]), nodes[1][p], nodes[1][d]))

    EL.sort()
    mst_cost = 0
    num_taken = 0
    UF = UnionFind(n + 1)
    for i in range(len(EL)):
        if num_taken == n - 1:
            break
        w, u, v = EL[i]
        if not UF.isSameSet(u, v):
            num_taken += 1
            mst_cost += w
            UF.unionSet(u, v)
    print("{:.9f}".format(mst_cost))
