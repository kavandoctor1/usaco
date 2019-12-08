#include <bits/stdc++.h>
using namespace std;
ofstream fout ("planting.out");
ifstream fin ("planting.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
int main(){
    int n;
    fin>>n;
    int d[n+1];
    For(n+1){
        d[i]=0;
    }
    For(n-1){
        int a, b;
        fin>>a>>b;
        d[a]++;
        d[b]++;
    }
    int max = 0;
    For(n+1){
        if(d[i] > max) max = d[i];
    }
    fout<<max+1<<"\n";
}