#include <bits/stdc++.h>
using namespace std;
ofstream fout ("square.out");
ifstream fin ("square.in");
#define For(x) for(int i = 0; i < x; i++)
#define Forv(vector) for(auto& i : vector)
int main(){
    int x1,x2,x3,x4,y1,y2,y3,y4;
    fin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    int maxx=max({x1,x2,x3,x4});
    int minx=min({x1,x2,x3,x4});
    int maxy=max({y1,y2,y3,y4});
    int miny=min({y1,y2,y3,y4});
    int maxd = max(maxx-minx, maxy-miny);
    fout<<maxd*maxd<<"\n";
    cout<<maxd*maxd<<"\n";
}