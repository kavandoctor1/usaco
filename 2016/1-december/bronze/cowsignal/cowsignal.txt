#include <bits/stdc++.h>
using namespace std;
ofstream fout ("cowsignal.out");
ifstream fin ("cowsignal.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int l = 0; l < x; l++)
#define For4(x) for(int q = 0; q < x; q++)
#define Forv(vector) for(auto& i : vector)
int main(){
    int m,n,k;
    fin>>m>>n>>k;
    For(m){
        string str;
        fin>>str;
        For4(k){
            For2(n){
                For3(k){
                    fout<<str[j];
                }
            }
            fout<<"\n";
        }
    }
}