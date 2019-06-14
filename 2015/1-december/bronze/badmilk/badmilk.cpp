#include <bits/stdc++.h>
using namespace std;
ofstream fout ("badmilk.out");
ifstream fin ("badmilk.in");
int main() {
    int N,M,D,S;
    fin >> N >> M >> D >> S;
    vector<vector<pair<int,int> > > drink;
    vector<vector<int> > dronk;
    for(auto i = 0; i < N; i++){
        vector<pair<int,int> > temp;
        drink.push_back(temp);
        vector<int> tem;
        dronk.push_back(tem);
        
    }
    int p,m,t;
    for(auto i = 0; i < D; i++){
        fin>>p>>m>>t;
        p=p-1;
        pair<int,int> pai(t,m);
        drink[p].push_back(pai);
        dronk[p].push_back(m);
    }
    for(auto i = 0; i < N; i++){
        sort(drink[i].begin(),drink[i].end());
    }
    vector<vector<int> >  sick;
    for(auto i = 0; i < N; i++){
        vector<int> temp;
        sick.push_back(temp);
    }
    int choose;
    for(auto i = 0; i < S; i++){
        fin>>p>>t;
        p = p-1;
        if(i == 0){
            choose = p;
        }
        for(auto j = 0; j<drink[p].size(); ++j){
            if(drink[p][j].first >= t){
                break;
            }
            sick[p].push_back(drink[p][j].second);
        }
    }
    cout<<"Sick\n";
    for(auto a = 0; a < sick.size(); a++){
        for(auto b = 0; b < sick[a].size(); b++){
            cout<<sick[a][b]<<" ";
        }
        cout<<"\n";
    }
    
    vector<int> possible;
    for(auto x = 0; x< sick[choose].size();x++){
        bool truth = true;
        for(auto vect = 0 ; vect < sick.size(); vect++){
            if(sick[vect].size() != 0){
                if(find(sick[vect].begin(), sick[vect].end(), sick[choose][x]) == sick[vect].end()){
                    truth = false;
                    break;
                }
            }
        }
        if(truth){
            possible.push_back(sick[choose][x]);
        }
    }
    cout<<"dronk\n";
    for(auto a = 0; a < dronk.size(); a++){
        for(auto b = 0; b < dronk[a].size(); b++){
            cout<<dronk[a][b]<<" ";
        }
        cout<<"\n";
    }
    
    auto count = 0;
    for(auto p = 0; p < possible.size();p++){
        cout<<possible[p]<<"\n";
        int tri = 0;
        for(auto a = 0; a <dronk.size(); a++){
            if (find(dronk[a].begin(), dronk[a].end(), possible[p]) != dronk[a].end()){
                tri+=1;
            }
        }
        count = max(tri,count);
    }
    fout<<count<<"\n";
    return 0;
}