#Bessie, Elsie, Daisy, Gertie, Annabelle, Maggie, and Henrietta
cows = ["Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"]
fin = open("notlast.in", "r");
fout = open("notlast.out", "w")
ls = [[0,s] for s in cows]
n = int(fin.readline().strip())
for _ in range(n):
    x = fin.readline().strip().split()
    s = x[0]
    t = int(x[1])
    if s == cows[0]:
        ls[0][0] += t
    elif s == cows[1]:
        ls[1][0]+=t
    elif s == cows[2]:
        ls[2][0]+=t
    elif s == "Gertie":
        ls[3][0]+=t
    elif s == "Annabelle":
        ls[4][0]+=t
    elif s == "Maggie":
        ls[5][0]+=t
    elif s == "Henrietta":
        ls[6][0]+=t
ls.sort()
minm = ls[0][0]
while len(ls) > 0 and ls[0][0] == minm:
    ls.pop(0)
if len(ls) > 1 and ls[0][0] == ls[1][0]:
    fout.write("Tie\n")
elif len(ls) == 0:
    fout.write("Tie\n")
else:
    fout.write(ls[0][1]+"\n")
fout.close()