fin = open("breedflip.in",'r')
fout = open("breedflip.out", 'w')
n = int(fin.readline().strip())
a = fin.readline().strip()
b = fin.readline().strip()
s = ""
for i in range(n):
    if(a[i]!=b[i]):
        s+="1"
    else:
        s+="0"
s = list(s)
i = 0
while i < len(s) - 1:
    if(s[i] == s[i+1]):
        s.pop(i)
    else:
        i+=1
fout.write(str(s.count('1')) + "\n")