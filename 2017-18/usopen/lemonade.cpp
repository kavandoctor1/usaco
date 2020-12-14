#include <bits/stdc++.h>
using namespace std;
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) for(auto& abcd : vector){cout<<abcd<<"\n";}
ofstream fout ("lemonade.out");
ifstream fin ("lemonade.in");


int main(){
    int n;
    fin>>n;
    vector<int> nums;
    For(n){
        int x;
        fin>>x;
        nums.push_back(x);
    }
    sort(nums.rbegin(), nums.rend());
    auto x = 0;
    int cows =0;
    Forv(nums){
        if(i >= x){
            cows++;
        }
        x++;
    }
    fout<<cows<<"\n";
}