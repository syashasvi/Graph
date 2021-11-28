#include<bits/stdc++.h>

using namespace std;

void bfs(int src,vector<int>adj[],vector<bool>&vis,vector<int>&bfsTraversal){
  queue<int>q;
  q.push(src);
  vis[src] = true;

  while(!q.empty()){
    int curr = q.front();
    q.pop();
    bfsTraversal.push_back(curr);

    for(auto x : adj[curr]){
      if(!vis[x]){
        q.push(x);
        vis[x]=true;
      }
    }
  }
}

int main(){
  int t; cin>>t;
  while(t--){
    int V,E; cin>>V>>E;
    vector<int>adj[V];
    vector<bool>vis(V+1,false);

    for(int i=0;i<E;i++){
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    vector<int>bfsTraversal;

    for(int i=0;i<V;i++){
      if(vis[i]==false){
        bfs(i,adj,vis,bfsTraversal);
      }
    }

    for(int i=0;i<bfsTraversal.size();i++){
      cout<<bfsTraversal[i]<<" ";
    }
    cout<<endl;

  }
}
