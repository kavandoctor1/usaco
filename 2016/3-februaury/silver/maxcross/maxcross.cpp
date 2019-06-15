#include <bits/stdc++.h>
using namespace std;
ofstream fout ("maxcross.out");
ifstream fin ("maxcross.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
int main(){
    int n,b,k;
    fin>>n>>k>>b;
    vector<int> walks;
    For(n+1){
        walks.push_back(0);
    }
    For(b){
        int temp;
        fin>>temp;
        walks[temp]=1;
    }
    for(int x = 1; x < n+1; x++){
        walks[x] = walks[x]+walks[x-1];
    }
    int minm = 1000000;
    Forv(walks){
        cout<<i<<"\n";
    }
    For(n-k+1){
        minm = min(minm,walks[i+k]-walks[i]);
    }
    fout<<minm<<"\n";
}