#include <bits/stdc++.h>
using namespace std;
ofstream fout ("cowqueue.out");
ifstream fin ("cowqueue.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
int main(){
    int n;
    fin>>n;
    vector<pair<int,int> > queue;
    For(n){
        int a,b;
        fin>>a>>b;
        pair<int,int> p(a,b);
        queue.push_back(p);
    }
    sort(queue.begin(),queue.end());
    int time = 0;
    Forv(queue){
        time = max(time, i.first);
        time+=i.second;
    }
    fout<<time<<"\n";
}