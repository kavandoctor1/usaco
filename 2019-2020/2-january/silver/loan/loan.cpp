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
        long long k = 0;
        long long cur = N;
        while(true){
            if(floor(cur/x) <= M){
                break;
            }
            k++;
            cur = ceil(1.0*cur*(x-1)/x);
        }
        if(cur - M*(K-k) <= 0){
            left = x;
        }
        else{
            right = x-1;
        }
    }
    fout<<left<<"\n";
}