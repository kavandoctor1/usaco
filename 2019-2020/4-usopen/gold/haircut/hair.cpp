#include <bits/stdc++.h>
using namespace std;
#define For(x) for(ll i = 0; i < x; i++)
#define For2(x) for(ll j = 0; j < x; j++)
#define For3(x) for(ll k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) for(auto& abcd : vector){cout<<abcd<<"\n";}
#define ll long long
ofstream fout ("haircut.out");
ifstream fin ("haircut.in"); 
int main() 
{ 
    ll n;
    fin>>n;
    ll arr[n];
    For(n){
        ll x;
        fin>>x;
        arr[i]=x;
    }
    ll yay[n+1];
    For(n+1){
        yay[i]=0;
    }
    ll tot = 0;
    For(n){
        for(ll j = i+1; j < n; j++){
            if(arr[j]<arr[i]){
                yay[arr[j]]++;
                tot++;
            }
        }
    } 
    for(ll i = n-1; i >= 0; i--){
        yay[i]+= yay[i+1];
    }
    For(n){
        fout<<tot-yay[i]<<"\n";
    }
    return 0; 
} 