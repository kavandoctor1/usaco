#include <bits/stdc++.h>
using namespace std;
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) for(auto& abcd : vector){cout<<abcd<<"\n";}
#define pb push_back
typedef long long ll;
typedef vector<int> vi; 
typedef pair<int, int> pi; 

ofstream fout ("circlecross.out");
ifstream fin ("circlecross.in");

int main(){
    int N; fin>>N;
    int circle[2*N];
    cout<<N;
    For(2*N){
        fin>>circle[i];
    }
    bool works[N+1][N+1];
    memset(works,false,sizeof(works));
    For(2*N){
        int x = circle[i];
        bool part[N+1];
        memset(part,false,sizeof(part));
        int j = i+1;
        while(circle[j]!=x){
            part[circle[j]] ^= true;
        }
        For2(N+1){
            works[x][j] = part[j];
        }
    }
    int ans = 0;
    For(N+1){
        For2(N+1){
            if(works[i][j]){ ans ++;}
        }
    }
    cout<<ans<<'\n';
    fout<<ans<<'\n';
}
