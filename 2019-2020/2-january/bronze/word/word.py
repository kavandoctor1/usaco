fin = open("word.in", 'r')
fout = open("word.out" , 'w')
N,K = map(int,fin.readline().strip().split())
words = fin.readline().strip().split()
words.reverse()
space = int(K)
w = words.pop()
fout.write(w)
space -= len(w)
while len(words) > 0:
    w = words.pop()
    if(len(w) <= space):
        fout.write(" " + w)
        space -= len(w)
    else:
        fout.write("\n" + w)
        space = K- len(w)
fout.write("\n")
    