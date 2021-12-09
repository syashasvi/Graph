#include<bits/stdc++.h>
using namespace std;

bool dfs(int src,vector<int>adj[], vector<bool>&vis, vector<bool>&dfsvis){
    vis[src] = true;
    dfsvis[src] = true;

    for(auto x:adj[src]){
        if(!vis[x]){
            if(dfs(x,adj,vis,dfsvis)==true) return true;
        }else{
            if(dfsvis[x]==true) return true;
        }
    }

    dfsvis[src] = false;
    return false;
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int>adj[n+1];

        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
        }
        vector<bool>vis(n+1,false);
        vector<bool>dfsvis(n+1,false);

        bool flag=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,dfsvis)==true){
                    flag=1;
                    break;
                }
            }
        }

        if(flag==1) cout<<"Cycle\n";
        else cout<<"NoCycle\n";

    }
}
