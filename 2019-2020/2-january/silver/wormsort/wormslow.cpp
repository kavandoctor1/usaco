#include <bits/stdc++.h> 
using namespace std; 
#define For(x) for(int i = 0; i < x; i++)
#define For2(x) for(int j = 0; j < x; j++)
#define For3(x) for(int k = 0; k < x; k++)
#define Forv(vector) for(auto& i : vector)
#define Forv2(vector) for(auto& j : vector)
#define show(vector) for(auto& abcd : vector){cout<<abcd<<"\n";}
ofstream fout ("wormsort.out");
ifstream fin ("wormsort.in");


int widest_path_problem(vector<vector<pair<int, int> > >& Graph, 
						int src, int target) 
{ 
	vector<int> widest(Graph.size(), INT_MIN); 

	vector<int> parent(Graph.size(), 0); 

	priority_queue<pair<int, int>, vector<pair<int, int> >, 
				greater<pair<int, int> > > 
		container; 

	container.push(make_pair(0, src)); 

	widest[src] = INT_MAX; 

	while (container.empty() == false) { 
		pair<int, int> temp = container.top(); 

		int current_src = temp.second; 

		container.pop(); 

		for (auto vertex : Graph[current_src]) { 
			int distance = max(widest[vertex.second], 
							min(widest[current_src], vertex.first)); 

			if (distance > widest[vertex.second]) { 

				widest[vertex.second] = distance; 
				parent[vertex.second] = current_src; 
				container.push(make_pair(distance, vertex.second)); 
			} 
		} 
	} 


	return widest[target]; 
} 

// Driver code 
int main() 
{ 

	// Graph representation 
	vector<vector<pair<int, int> > > graph; 
	int no_vertices, m;
	fin>>no_vertices>>m;
	graph.assign(no_vertices +1, vector<pair<int, int> >()); 

	vector<int> order;
	For(no_vertices){
	    int x;
	    fin>>x;
	    order.push_back(x);
	}
	For(m){
	    int a,b,w;
	    fin>>a>>b>>w;
        graph[a].push_back(make_pair(w,b));
        graph[b].push_back(make_pair(w,a));

	}
	bool worm = false;
	int ans = INT_MAX;
    For(no_vertices){
        if(i+1 != order[i]){
            ans = min(widest_path_problem(graph,i+1, order[i]), ans);
            worm=true;
        }
    }
    if(worm){
        fout<<ans<<"\n";
    }
    else{
        fout<<"-1\n";
    }
    

	return 0; 
} 
