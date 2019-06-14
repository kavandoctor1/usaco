#include <bits/stdc++.h>
using namespace std;
ofstream fout ("crossroad.out");
ifstream fin ("crossroad.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
int main(){
    int n;
    fin>>n;
    vector<vector<int> > cross;
    For(10){
        vector<int> c;
        cross.push_back(c);
    }
    For(n){
        int cow, side;
        fin>>cow>>side;
        cross[cow-1].push_back(side);
    }
    int crosses = 0;
    Forv(cross){
        if(i.size() > 1){
            auto current = i[0];
            Forv2(i){
                if(j != current){
                    crosses+=1;
                    current = j;
                }
            }
        }
        
    }
    fout<<crosses<<"\n";
}