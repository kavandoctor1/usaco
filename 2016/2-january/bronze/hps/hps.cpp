#include <bits/stdc++.h>
using namespace std;
ofstream fout ("hps.out");
ifstream fin ("hps.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define Forv(vector) for(auto& k : vector)
int main(){
    int n;
    fin >> n;
    vector<pair<int,int> > turns;
    For(n){
        int a,b;
        fin >> a >> b;
        if(a!=b){
            pair<int,int> p(a,b);
            turns.push_back(p);
        }
    }
    int poss[6][3] = {{1,2,3}, {1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
    int maxm = 0;
    For(6){
        auto current = poss[i];
        int win = 0;
        Forv(turns){
            if(current[k.first-1] == 1){
                if(current[k.second-1] == 2){
                    win+=1;
                }
            }
            else if(current[k.first-1] == 2){
                if(current[k.second-1] == 3){
                    win+=1;
                }
            }
            else{
                if(current[k.second-1] == 1){
                    win+=1;
                }
            }
        }
        maxm=max(win,maxm);
    }
    fout<<maxm<<"\n";
}