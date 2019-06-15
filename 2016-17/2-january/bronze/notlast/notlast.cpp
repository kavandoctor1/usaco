#include <bits/stdc++.h>
using namespace std;
ofstream fout ("notlast.out");
ifstream fin ("notlast.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define Forv(vector) for(auto& i : vector)
int main(){
    int n;
    fin>>n;
    vector<string> cows= {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    vector<pair<int,string> > ls;
    Forv(cows){
        pair<int,string> p(0,i);
        ls.push_back(p);
    }
    For(n){
        string s;
        int t;
        fin >> s>>t;
        if (s == cows[0])
            ls[0].first += t;
        else if (s == cows[1])
            ls[1].first+=t;
        else if (s == cows[2])
            ls[2].first+=t;
        else if (s == "Gertie")
            ls[3].first+=t;
        else if (s == "Annabelle")
            ls[4].first+=t;
        else if (s == "Maggie")
            ls[5].first+=t;
        else
            ls[6].first+=t;
    }
    sort(ls.begin(),ls.end());
    int minm = ls[0].first;
    int index = 0;
    while(ls.size()>0 and ls[index].first == minm){
        ls.erase(ls.begin());
    }
    if(1<ls.size() and ls[index].first == ls[index+1].first){
        fout<<"Tie\n";
    }
    else if(ls.size()==0){
        fout<<"Tie\n";
    }
    else{
        fout<<ls[0].second<<"\n";
    }
    
    
}