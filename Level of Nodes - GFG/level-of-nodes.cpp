//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X) 
    {
        // code here
        queue<pair<int,int>> q;
        q.push({0,0});
        int vis[V]={0};
        vis[0]=1;
        while(!q.empty())
        {
            auto it=q.front();
            int node=it.first;
            int level=it.second;
            q.pop();
            if(node==X)
            {
                return level;
            }
            for(auto adjNode:adj[node])
            {
                if(!vis[adjNode])
                {
                    vis[adjNode]=1;
                    q.push({adjNode,level+1});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends