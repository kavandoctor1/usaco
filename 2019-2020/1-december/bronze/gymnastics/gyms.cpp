#include <bits/stdc++.h>
using namespace std;
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) for(auto& abcd : vector){cout<<abcd<<"\n";}
ofstream fout ("gymnastics.out");
ifstream fin ("gymnastics.in");

int main(){
    int K,N;
    fin>>K>>N;
    int rounds[K][N];
    For(K){
        For2(N){
            int g;
            fin>>g;
            rounds[i][j] = g;
        }
    }
    int ans = 0;
    For(N){
        For2(N){
            if(i!=j){
                bool works = true;
                For3(K){
                    int uno = distance(rounds[k], find(rounds[k], rounds[k] + N, i+1));
                    int dos = distance(rounds[k], find(rounds[k], rounds[k] + N, j+1));
                    if(uno < dos){
                        works = false;
                        break;
                    }
                }
                if(works){
                    ans++;
                }
            }
            
        }
    }
    fout<<ans<<"\n";
    
}