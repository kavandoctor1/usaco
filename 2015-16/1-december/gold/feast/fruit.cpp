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

ofstream fout ("feast.out");
ifstream fin ("feast.in");

int main(){
    ll t,a,b; fin>>t>>a>>b;
    bool dp[t+1][2];
    memset(dp,false,sizeof(dp));
    dp[0][0] = true;
    dp[0][1] = true;
    For(t+1){
        if(dp[i][0]){
            if(i+a < t+1){
                dp[i+a][0] = true;
                ll x = (i+a)/2;
                ll in = trunc(x);
                dp[in][1] = true;
            }
            if(i+b < t+1){
                dp[i+b][0] = true;
                ll x = (i+b)/2;
                ll in = trunc(x);
                dp[in][1] = true;
            }
        }
    }
    For(t+1){
        if(dp[i][1]){
            if(i+a < t+1){
                dp[i+a][1] = true;
            }
            if(i+b < t+1){
                dp[i+b][1] = true;
            }
        }
    }
    ll maxm = 0;
    For(t+1){
        if(dp[i][0] || dp[i][1]){
            maxm = i;
        }
    }
    For(t+1){
        cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
    }
    fout<<maxm<<'\n';
}
