#include <bits/stdc++.h>
using namespace std;
ofstream fout ("buckets.out");
ifstream fin ("buckets.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
int main(){
    int b1,b2,l1,l2,r1,r2;
    For(10){
        For2(10){
            char c;
            fin>>c;
            if(c == 'B'){
                b1 = i;
                b2 = j;
            }
            else if(c == 'L'){
                l1 = i;
                l2 = j;
            }
            else if(c == 'R'){
                r1 = i;
                r2 = j;
            }
        }
    }
    //cout<<b.first<<" "<<b.second<<' '<<l.first<<" "<<l.second;
    if(b1==l1&&l1==r1&&((b2<r2&&r2<l2)||(l2<r2&&r2<b2))){
        fout<<abs(b2-l2)+abs(b1-l1)+1<<"\n";
    }
    else if(b2==l2&&l2==r2&&((b1<r1&&r1<l1)||(l1<r1&&r1<b1))){
        fout<<abs(b2-l2)+abs(b1-l1)+1<<"\n";
    }
    else{ 
        fout<<abs(b2-l2)+abs(b1-l1)-1<<"\n";
    }

}