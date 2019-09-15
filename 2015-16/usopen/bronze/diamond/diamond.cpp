#include <bits/stdc++.h>
using namespace std;
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) for(auto& abcd : vector){cout<<abcd<<"\n";}
using ll = long long;
ofstream fout ("diamond.out");
ifstream fin ("diamond.in");
int main(){
    int n,k;
    fin>>n>>k;
    vector<int> size;
    For(n){
        int temp;
        fin>>temp;
        size.push_back(temp);
    }
    sort(size.begin(), size.end());

    int sum[100010];
    For(100000){
        sum[i]=0;
    }
    Forv(size){
        sum[i]+=1;
    }
    For(10001){
        sum[i+1] = sum[i+1]+sum[i];
    }
    int maxm = 0;
    For(10000-k){
        
        maxm = max(maxm,sum[i+k+1]-sum[i]);
    }
    fout<<maxm<<"\n";
}