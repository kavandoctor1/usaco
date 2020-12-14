#include <bits/stdc++.h>
using namespace std;
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) Forv(vector){Forv2(i){cout<<j<<" ";}cout<<"\n";}

ofstream fout ("cowtip.out");
ifstream fin ("cowtip.in");
vector<vector<int > > grid;

void toggle(int a, int b){
    For(a+1){
        For2(b+1){
            if(grid[i][j]==0){
                grid[i][j] = 1;
            }
            else{
                grid[i][j] = 0;
            }
        }
    }
}

int main(){
    int n;
    fin>>n;
    
    For(n){
        vector<int> temp;
        For2(n){
            char c;
            fin>>c;
            temp.push_back((int) c-48);
        }
        grid.push_back(temp);
    }
    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j>=0;j--){
            if (grid[i][j] == 1){
                toggle(i,j);
                ans++;
            }
        }
    }
    fout<<ans<<"\n";
}