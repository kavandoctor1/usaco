fin = open("haybales.in", "r")
fout = open("haybales.out", "w")
N,Q = map(int, fin.readline().strip().split())
bales = list(map(int, fin.readline().strip().split()))
l = len(bales)
bales.sort()
for _ in range(Q):
    a, b = map(int, fin.readline().strip().split())
    left = 0
    right = len(bales)
