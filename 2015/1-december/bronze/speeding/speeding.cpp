#include <bits/stdc++.h>
using namespace std;
ofstream fout ("speeding.out");
ifstream fin ("speeding.in");
int main() {
    int limit[101];
    int speed[101];
    int n,m;
    fin >> n>> m;
    int point = 0;
    int seg,lim;
    for(int i = 0; i < n; i++){
        fin >> seg >> lim;
        for(int th = 0; th < seg; th++){
            limit[point] = lim;
            point+=1;
        }
    }
    point = 0;
    for(int j = 0; j < m; j++){
        fin >> seg >> lim;
        for(int th = 0; th < seg; th++){
            speed[point] = lim;
            point+=1;
        }
    }
    int maxdiff = 0;
    for(int k = 0; k < 100; k++){
        maxdiff = max(maxdiff, speed[k]-limit[k]);
    }
    cout << maxdiff<<"\n";
    fout << maxdiff<<"\n";
    return 0;
}