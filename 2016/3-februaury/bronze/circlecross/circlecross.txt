#include <bits/stdc++.h>
using namespace std;
ofstream fout ("circlecross.out");
ifstream fin ("circlecross.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)

int findnum(string s, char c){
    int count = 0;
    For(s.size()){
        if (s[i] ==c) count++;
    }
    return count;
}
int main(){
    string circle;
    fin >> circle;
    vector<char> found;
    int cross = 0;
    For(51){
        char search = circle[i];
        if(find(found.begin(),found.end(),search) == found.end()){
            string middle;
            int current = i+1;
            while(circle[current] != search){
                middle += circle[current];
                current++;
            }
            For(middle.size()){
                if(findnum(middle,middle[i]) == 1){
                    cross++;
                }
            }
            found.push_back(search);
        }
    }
    fout<<cross/2<<"\n";
}