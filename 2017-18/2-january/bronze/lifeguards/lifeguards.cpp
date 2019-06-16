#include <bits/stdc++.h>
using namespace std;
ofstream fout ("lifeguards.out");
ifstream fin ("lifeguards.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) for(auto& abcd : vector){cout<<abcd.first<<" "<<abcd.second<<"\n";}
int main(){
    int n;
    fin >> n;
    vector<pair<int,int> > times;
    For(n){
        int s,t;
        fin>>s>>t;
        pair<int,int> p(s,t);
        times.push_back(p);
    }
    sort(times.begin(), times.end());
    int maxm = 0;
    For(n){
        vector<pair<int,int> > temp;
        temp = times;
        vector<pair<int,int> >::iterator it = temp.begin();
        For2(i){
            it++;
        }
        temp.erase(it);
        int count = 0;
        int a = 0;
        cout<<i<<"\n";
        while(a<temp.size()-1){
            if(temp[a].second >= temp[a+1].first){
                vector<pair<int,int> >::iterator it2 = temp.begin();
                For3(a){
                    it2++;
                }
                temp[a+1].first = temp[a].first;
                temp.erase(it2);
            }
            else{
                a+=1;
            }
        }
        Forv(temp){
            count+=i.second-i.first;
        }
        maxm = max(maxm,count);
    }
    fout<<maxm<<"\n";
}