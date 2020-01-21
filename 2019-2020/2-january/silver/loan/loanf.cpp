#include <bits/stdc++.h>
using namespace std;
ofstream fout ("loan.out");
ifstream fin ("loan.in");

int main(){
    long long N,K,M;
    fin>>N>>K>>M;
    long long left = 1;
    long long right = K;
    while(right-left>0){
        long long x= ceil((left+right)/2.0);
        long long k = ceil(1.0* log(1.0*M*x/N) / log(1.0*(x-1)/x));
        long long cur = pow(x-1,k)*ceil(1.0*N/pow(x,k));
        if(cur - M*(K-k) <= 0){
            left = x;
        }
        else{
            right = x-1;
        }
    }
    fout<<left<<"\n";
}