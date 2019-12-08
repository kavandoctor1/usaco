#include <bits/stdc++.h>
using namespace std;
ofstream fout ("paintbarn.out");
ifstream fin ("paintbarn.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
int main(){
    int grid[1001][1001];
    For(1001){
        For2(1001){
            grid[i][j] = 0;
        }
    }
    int n,k;
    fin>>n>>k;
    For(n){
        int a,b,c,d;
        fin>>a>>b>>c>>d;
        for(int x = a; x < c; x++){
            grid[x][b]++;
            grid[x][d]--;
        }
    }
    int ans  =0;
    For(1001){
        For2(1001){
            if(grid[i][j] ==k)ans++;
            grid[i][j+1]+=grid[i][j];
        }
    }
    fout<<ans<<"\n";
    
}