#include<bits/stdc++.h>
using namespace std;

void dfs(int src, vector<pair<int,int>>adj[], vector<bool>&vis, stack<int>&recStack){
    vis[src]=true;
    for(auto x:adj[src]){
        if(!vis[x.first]){
            dfs(x.first,adj,vis,recStack);
        }
    }
    recStack.push(src);
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        vector<pair<int,int>>adj[n+1];
        vector<int>dist(n,INT_MAX);

        for(int i=0;i<m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            adj[x].push_back({y,w});
        }
        int src; cin>>src;
        dist[src] = 0;

        vector<bool>vis(n+1,false);
        stack<int>recStack;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,recStack);
            }
        }

        while(!recStack.empty()){
            int curr = recStack.top();
            recStack.pop();

            for(auto x:adj[curr]){
                if(dist[curr]+x.second < dist[x.first]){
                    dist[x.first] = dist[curr]+x.second;
                }
            }
        }

        for(auto x:dist){
            cout<<x<<" ";
        }cout<<endl;
    }
}
