#include <bits/stdc++.h>
using namespace std;
ofstream fout ("berries.out");
ifstream fin ("berries.in");

int main(){
    int n,k;
    fin>>n>>k;
    vector<int> trs;
    int maxb = 0;
    for(int i = 0; i < n; i++){
        int temp;
        fin>>temp;
        trs.push_back(temp);
        maxb = max(maxb, temp);
    }
    
    int ans = 0;
    int i;
    for(i = maxb; i > 0; i--){
        vector<int> partition;
        int g = 0;
        for(auto& j : trs){
            g += j/i;
            partition.push_back(j%i);
        }
        sort(partition.begin(), partition.end(), greater <int>());
        int tans = 0;
        int tot = 0;
        if(g <= k/2){
            for(int l = k/2-g; l < min(k-g,(int)partition.size()); l++){
                tot += partition[l];

            }
            
            tans = tot;
        }
        else if(g <= k){
            for(int l = 0; l < min(k-g,(int)partition.size()); l++){
                tot += partition[l];
            }
            tans = tot + i*(g-k/2);
        }
        else{
            tans = i*(k/2);
        }
        ans = max(ans, tans);
    }
    fout<<ans<<"\n";
}