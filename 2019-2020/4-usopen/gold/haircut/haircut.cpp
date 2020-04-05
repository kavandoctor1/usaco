#include <bits/stdc++.h>
using namespace std;
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) for(auto& abcd : vector){cout<<abcd<<"\n";}
#define ll long long
ofstream fout ("haircut.out");
ifstream fin ("haircut.in"); 
  
// Returns sum of arr[0..index]. This function assumes 
// that the array is preprocessed and partial sums of 
// array elements are stored in BITree[]. 
int getSum(int BITree[], int index) 
{ 
    int sum = 0; // Initialize result 
  
    // Traverse ancestors of BITree[index] 
    while (index > 0) 
    { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree.  The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    // Traverse all ancestors and add 'val'
    while (index <= n) 
    { 
       // Add 'val' to current node of BI Tree 
       BITree[index] += val; 
  
       // Update index to that of parent in update View 
       index += index & (-index); 
       
    } 
} 
  
// Returns inversion count arr[0..n-1] 
void getInvCount(int arr[], int n) 
{ 
    
    ll invcount = 0; // Initialize result 
  
    // Find maximum element in arr[] 
    int maxElement = n;
  
    // Create a BIT with size equal to maxElement+1 (Extra 
    // one is used so that elements can be directly be 
    // used as index) 
    int BIT[maxElement+1]; 
    for (int i=0; i<=maxElement; i++) 
        BIT[i] = 0; 
    
    ll yay[n+1];
    For(n+1){
        yay[i]=0;
    }
    
    // Traverse all elements from right. 
    for (int i=0; i< n; i++) 
    { 
        // Get count of elements smaller than arr[i] 
        int x = (i - getSum(BIT, arr[i]));
        cout<<i<<" "<<x<<"\n";
        invcount += x; 
        yay[arr[i]-1] += x;
        // Add current element to BIT 
        updateBIT(BIT, maxElement, arr[i], 1); 
    } 
    for(ll i = n-1; i >= 0; i--){
        yay[i]+= yay[i+1];
    }
    For(n){
        fout<<invcount-yay[i]<<"\n";
    }
  
} 
  
// Driver program 
int main() 
{ 
    int n;
    fin>>n;
    int arr[n];
    For(n){
        int x;
        fin>>x;
        arr[i]=x+1;
    }
    getInvCount(arr,n); 
    return 0; 
} 