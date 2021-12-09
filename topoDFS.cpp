#include<bits/stdc++.h>
using namespace std;

void dfs(int src,vector<int>adj[], vector<bool>&vis, stack<int>&recStack){
    vis[src] = true;
    for(auto x:adj[src]){
        if(!vis[x]){
            dfs(x,adj,vis,recStack);
        }
    }
    recStack.push(src);
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
            //adj[y].push_back(x);
        }

        vector<bool>vis(n+1,false);
        stack<int>recStack;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,recStack);
            }
        }

        while(!recStack.empty()){
            cout<<recStack.top()<<" ";
            recStack.pop();
        }
        cout<<endl;
    }
}
