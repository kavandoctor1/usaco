#include <bits/stdc++.h>
using namespace std;
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) for(auto& abcd : vector){cout<<abcd<<"\n";}
ofstream fout ("sort.out");
ifstream fin ("sort.in");


int main(){
    int n;
    fin>>n;
    vector<int> nums;
    For(n){
        int x;
        fin>>x;
        nums.push_back(x);
    }
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    int maxm = 0;
    int i = 0;
    Forv2(nums){
        int index = lower_bound(sorted.begin(), sorted.end(), j)- sorted.begin();
        maxm = max(abs(i-index),maxm);
        i++;
    }
    fout<<maxm+1<<"\n";
}