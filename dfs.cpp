#include<bits/stdc++.h>

using namespace std;

void dfs(int src, vector<int>adj[], vector<bool>&vis, vector<int>&dfsTraveral){
    vis[src]=true;
    dfsTraveral.push_back(src);
    for(auto x:adj[src]){
        if(!vis[x]){
            dfs(x,adj,vis,dfsTraveral);
        }
    }
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        vector<int>adj[n+1];

        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<bool>vis(n+1,false);
        vector<int>dfsTraveral;

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,dfsTraveral);
            }
        }

        for(int i=0;i<dfsTraveral.size();i++){
            cout<<dfsTraveral[i]<<" ";
        }
        cout<<endl;
    }
}
