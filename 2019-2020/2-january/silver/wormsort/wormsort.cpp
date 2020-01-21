#include <bits/stdc++.h> 
using namespace std; 
#define For(x) for(int i = 0; i < x; i++)
#define show(vector) for(auto& abcd : vector){cout<<abcd<<"\n";}

ofstream fout ("wormsort.out");
ifstream fin ("wormsort.in");
// Creating shortcut for an integer pair 
typedef  pair<int, int> iPair; 
  
// Structure to represent a graph 
struct Graph 
{ 
    int V, E; 
    vector< pair<int, iPair> > edges; 
    bool *nobodyCares;
    // Constructor 
    Graph(int V, int E, bool F[]) 
    { 
        this->V = V; 
        this->E = E; 
        nobodyCares = F;
    } 
  
    // Utility function to add an edge 
    void addEdge(int u, int v, int w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 
  
    // Function to find MST using Kruskal's 
    // MST algorithm 
    int kruskalMST(); 
}; 
  
// To represent Disjoint Sets 
struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 
  
    // Constructor. 
    DisjointSets(int n) 
    { 
        // Allocate memory 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
  
        // Initially, all vertices are in 
        // different sets and have rank 0. 
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
  
            //every element is parent of itself 
            parent[i] = i; 
        } 
    } 
  
    // Find the parent of a node 'u' 
    // Path Compression 
    int find(int u) 
    { 
        /* Make the parent of the nodes in the path 
           from u--> parent[u] point to parent[u] */
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    // Union by rank 
    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
  
        /* Make tree with smaller height 
           a subtree of the other tree  */
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else // If rnk[x] <= rnk[y] 
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 
  
 /* Functions returns weight of the MST*/ 
  
int Graph::kruskalMST() 
{ 
    int mst_wt = INT_MAX; // Initialize result 
  
    // Sort edges in increasing order on basis of cost 
    sort(edges.begin(), edges.end()); 
    reverse(edges.begin(),edges.end());
    // Create disjoint sets 
    DisjointSets ds(V); 
    // Iterate through all sorted edges 
    vector< pair<int, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
        int u = it->second.first; 
        int v = it->second.second; 
        if(nobodyCares[u] && nobodyCares[v]){
            continue;
            //cout<<"YAY";
        }
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
  
        // Check if the selected edge is creating 
        // a cycle or not (Cycle is created if u 
        // and v belong to same set) 
        if (set_u != set_v) 
        { 
            // Current edge will be in the MST 
            // so print it 
            cout << u << " - " << v << endl; 
  
            // Update MST weight 
            mst_wt = min(it->first,mst_wt);
            // Merge two sets 
            ds.merge(set_u, set_v); 
        } 
    } 
  
    return mst_wt; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int no_vertices, m;
	fin>>no_vertices>>m;

    bool inPlace[no_vertices+1];
    memset(inPlace, false, sizeof(inPlace));
	vector<int> order;
	bool worm = true;
	For(no_vertices){
	    int x;
	    fin>>x;
	    order.push_back(x);
	    if(i+1 == x){
	        inPlace[i+1] = true;
	    }
	    else{
	        worm = false;
	    }
	}
	Graph g(no_vertices, m, inPlace);
	
	For(m){
	    int a,b,w;
	    fin>>a>>b>>w;
        g.addEdge(a,b,w);

	}
    int ans = g.kruskalMST(); 
    if(!worm){
        fout<<ans<<"\n";
    }
    else{
        fout<<"-1\n";
    }
    /*
    int V = 9, E = 14; 
    Graph g(V, E); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    cout << "Edges of MST are \n"; 
    
  
    cout << "\nWeight of MST is " << mst_wt; 
  
    return 0; 
    */
} 