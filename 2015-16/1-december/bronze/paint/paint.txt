#include <bits/stdc++.h>
using namespace std;
ofstream fout ("paint.out");
ifstream fin ("paint.in");
int main() {

    int a,b,c,d;
    fin >> a>>b>>c>>d;
    if (b < c || a > d){
        fout << (b+d-a-c)<<"\n";
    }
    else{
        fout << max(b,d) - min(a,c)<<"\n";
    }
    return 0;
}