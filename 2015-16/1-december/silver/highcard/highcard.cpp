#include <bits/stdc++.h>
using namespace std;
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) for(auto& abcd : vector){cout<<abcd<<"\n";}
using ll = long long;
ofstream fout ("highcard.out");
ifstream fin ("highcard.in");

int main(){
    int n;
    fin>>n;
    vector<int> b;
    vector<int> e;
    bool elsie[2*n+1];
    For(2*n+1){
        elsie[i]=false;
    }
    For(n){
        int temp;
        fin>>temp;
        elsie[temp-1] = true;
    }
    For(2*n){
        if(elsie[i]){
            e.push_back(i);
        }
        else{
            b.push_back(i);
        }
    }
    int i = 0;
    while (i < b.size()){
        while(e[i]>b[i]){
            b.erase(b.begin()+i);
        }
        i++;
    }
    show(e);
    show(b);
    fout<<b.size()<<"\n";
}