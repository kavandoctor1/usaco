#include <bits/stdc++.h>
using namespace std;
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) Forv(vector){Forv2(i){cout<<j<<" ";}cout<<"\n";}

ofstream fout ("div7.out");
ifstream fin ("div7.in");

int main(){
    int n;
    fin >> n;
    int first[7];
    int last[7];
    For(7){
        first[i] = n+1;
        last[i] = 0;
    }
    int curr = 0;
    For(n){
        int x;
        fin>>x;
        curr += x;
        curr%=7;
        first[curr] = min(i,first[curr]);
        last[curr] = i;
    }
    int maxm = 0;
    For(7){
        if(first[i] < n)
            maxm = max(maxm, last[i]-first[i]);
    }
    fout<<maxm<<"\n";
}