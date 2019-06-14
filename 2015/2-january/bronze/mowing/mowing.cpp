#include <bits/stdc++.h>
using namespace std;
ofstream fout ("mowing.out");
ifstream fin ("mowing.in");
#define For(x) for(int i = 0; i < x; i++)
int main(){
    int N;
    fin >> N;
    vector<pair<int,int> > visited;
    pair<int, int> current(0,0);
    visited.push_back(current);
    For(N){
        char direction;
        int steps;
        fin >> direction>>steps;
        if(direction == 'N'){
            For(steps){
                current.second += 1;
                visited.push_back(current);
            }
        }
        else if(direction == 'S'){
            For(steps){
                current.second -= 1;
                visited.push_back(current);
            }
        }
        else if(direction == 'W'){
            For(steps){
                current.first -= 1;
                visited.push_back(current);
            }
        }
        else if (direction == 'E'){
            For(steps){
                current.first += 1;
                visited.push_back(current);
            }
        }
        else{
            cout << "oh no\n";
        }
    }
    int minm = 10000;
    For(visited.size()){
        pair<int,int> p = visited[i];
        for(int j = i+1; j < visited.size(); j++){
            if(visited[j] == p){
                minm = min(minm,j-i);
                break;
            }
        }
    }
    if(minm == 10000){
        cout<<"-1\n";
        fout<<"-1\n";
    }
    else{
        cout<<minm<<"\n";
        fout<<minm<<"\n";
    }
}