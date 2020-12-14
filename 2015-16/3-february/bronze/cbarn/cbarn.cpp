#include <bits/stdc++.h>
using namespace std;
ofstream fout ("cbarn.out");
ifstream fin ("cbarn.in");
#define For(x) for(int i = 0; i < x; i++)
#define Forv(vector) for(auto& i : vector)
int main(){
    int n;
    fin>>n;
    vector<int> barn;
    For(n){
        int temp;
        fin>>temp;
        barn.push_back(temp);
    }
    int minm = 1000000000;
    For(barn.size()){
        int count = 0;
        for(int j = 0; j < barn.size(); j++){
            int x = j-i;
            if(x<0){
                x+=n;
            }
            count += barn[j]*x;
        }
        minm = min(count,minm);
    }
    cout<<minm<<"\n";
    fout<<minm<<"\n";
}