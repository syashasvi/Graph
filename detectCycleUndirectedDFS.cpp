#include<bits/stdc++.h>
using namespace std;

bool IsCycle(int src, vector<int>adj[], vector<bool>&vis, int parent){
    vis[src] = true;

    for(auto x:adj[src]){
        if(!vis[x] ){
            if(IsCycle(x,adj,vis,src)) {
                return true;
            }
        }
        else{
            if(x!=parent) return true;
        }
    }

    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int>adj[n+1];

        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<bool>vis(n+1,false);
        bool flag=0;

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(IsCycle(i,adj,vis,-1)==true){
                    flag=1;
                    break;
                }
            }
        }

        if(flag==1) cout<<"CYCLE\n";
        else cout<<"NO CYCLE\n";
    }
}
