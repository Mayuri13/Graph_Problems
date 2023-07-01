//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet
{
    vector<int> size, parent;
    //declaring the constructor
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    //Utimate parent finding function
    int findUPar(int node){
        if(node==parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    //union by size function
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //Kruskal's algo
         // 5, 1, 2
        // 5, 2, 1
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        sort(edges.begin(),edges.end());
        int mst = 0;
        DisjointSet ds(V);
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first, v = it.second.second;
            if(ds.findUPar(u)!=ds.findUPar(v)){
                mst+=wt;
                ds.unionBySize(u,v);
            }
        }
        return mst;
        
        //Prim's algo
        
        // vector<int>vis(V,0);
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // pq.push({0,0});
        // int sum=0;
        // //{weight,node}
        // while(!pq.empty()){
        //     int node = pq.top().second;
        //     int wt = pq.top().first;
        //     pq.pop();
        //     if(vis[node]==1) continue;
        //     vis[node] = 1;
        //     sum+=wt;
        //     for(auto it:adj[node]){
        //         if(!vis[it[0]])
        //             pq.push({it[1],it[0]});
        //     }
        // }
        // return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends