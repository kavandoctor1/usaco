#include <bits/stdc++.h>
using namespace std;
ofstream fout ("angry.out");
ifstream fin ("angry.in");

int countleft(vector<int> bales, int i, int range){
    if(i==0){
        return 1;
    }
    if(bales[i] -range >bales[i-1]){
        return 1;
    }
    return 1+countleft(bales,i-1,range+1);
    
}
int countright(vector<int> bales, int i, int range){
    //cout<<bales[i]<<" ";
    if(i==bales.size()-1){
        return 1;
    }
    if(bales[i] + range < bales[i+1]){
        return 1;
    }
    
    return 1+countright(bales,i+1,range+1);
    
}
int main() {
    int n;
    fin>>n;
    vector<int> haybales;
    int temp;
    for(int i = 0; i < n; i++){
        fin >> temp;
        haybales.push_back(temp);
    }
    sort(haybales.begin(),haybales.end());
    int maxm = 0;
    for(int i = 1; i < haybales.size(); i++){
        cout<<haybales[i]<<" "<<countleft(haybales, i, 1)+countright(haybales, i, 1)-1<<"\n\n";
        maxm = max(maxm,countleft(haybales, i, 1)+ countright(haybales, i, 1)-1);
    }
    //cout<<maxm<<"\n";
    fout<<maxm<<"\n";
}