#include <bits/stdc++.h>
using namespace std;
ofstream fout ("pails.out");
ifstream fin ("pails.in");
#define For(x) for(int i = 0; i < x; i++)
int main(){
    int maxm = 0;
    int x, y, m;
    fin>>x>>y>>m;
    int mx = m/x;
    For(mx+1){
        int n = x*i;
        int b = (m-n)/y;
        b*=y;
        maxm = max(maxm,b+n);
    }
    cout<<maxm<<"\n";
    fout<<maxm<<"\n";
}