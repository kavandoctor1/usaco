#include <bits/stdc++.h>
using namespace std;
ofstream fout ("blocks.out");
ifstream fin ("blocks.in");
#define For(x) for(int i = 0; i < x; i++)
#define Forv(vector) for(auto& j : vector)

int count(string s, char c) {
  int count = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == c) count++;

  return count;
}

int main(){
    int n;
    fin>>n;
    auto letters = "abcdefghijklmnopqrstuvwxyz";
    vector<pair<string,string> > blocks;
    For(n){
        string s,t;
        fin>>s>>t;
        pair<string,string> p(s,t);
        blocks.push_back(p);
    }
    For(26){
        int total = 0;
        Forv(blocks){
            total+=max(count(j.first,letters[i]),count(j.second,letters[i]));
        }
        fout<<total<<"\n";
    }
}