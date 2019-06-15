#include <bits/stdc++.h>
using namespace std;
ofstream fout ("shuffle.out");
ifstream fin ("shuffle.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
int main(){
    int n;
    fin>>n;
    int shuffle[n];
    For(n){
        int temp;
        fin>>temp;
        shuffle[i] = temp;
    }
    int cows[n];
    For(n){
        int temp;
        fin>>temp;
        cows[i] = temp;
    }
    For(3){
        int ar[n];
        For2(n){
            ar[j] = cows[shuffle[j]-1];
        }
        For2(n){
            cows[j] = ar[j];
        }
    }
    For(n){
        fout<<cows[i]<<"\n";
    }
}