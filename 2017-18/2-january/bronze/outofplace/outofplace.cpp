#include <bits/stdc++.h>
using namespace std;
ofstream fout ("outofplace.out");
ifstream fin ("outofplace.in");
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) for(auto& abcd : vector){cout<<abcd.first<<" "<<abcd.second<<"\n";}

int main(){
    int n;
    fin>>n;
    int arr[n];
    For(n){
        int temp;
        fin>>temp;
        arr[i]=temp;
    }
    int count = 0;
    int i, j; 
    for (i = 0; i < n-1; i++){       
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1]){
               swap(arr[j], arr[j+1]);
               count++;
           }
       }
    }
    fout<<count<<"\n";
}