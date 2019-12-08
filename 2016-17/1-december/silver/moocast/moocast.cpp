#include <bits/stdc++.h>
using namespace std;
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) for(auto& abcd : vector){cout<<abcd<<" ";}
ofstream fout ("moocast.out");
ifstream fin ("moocast.in");


int neighbours(int curr, bool visited[], vector<int> reach[]){
    if(visited[curr]){
        return 0;
    }
    visited[curr] = true;
    int ret = 1;
    For(reach[0].size()){
        if(reach[curr][i]) ret += neighbours(i, visited,reach);
    }
    return ret;
    
}
int main(){
    int n;
    fin>>n;
    // n = x;
    int cows[n][3];
    For(n){
        int a,b,c;
        fin>>a>>b>>c;
        cows[i][0] = a;
        cows[i][1] = b;
        cows[i][2] = c;
    }
    vector<int> reach[n];
    For(n){
        For2(n) reach[i].push_back(false);
    }
    For(n){
        For2(n){
            if((cows[j][0]-cows[i][0])*(cows[j][0]-cows[i][0])+(cows[j][1]-cows[i][1])*(cows[j][1]-cows[i][1]) <= cows[i][2]*cows[i][2]){
                reach[i][j] = true;
            }
        }
    }
    int maxm = 0;
    bool visited[n];
    For(n){
        For2(n) visited[j] = 0;
        maxm = max(maxm, neighbours(i,visited, reach));
    }
    fout<<maxm<<"\n";
}