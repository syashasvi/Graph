#include<bits/stdc++.h>
#define pii pair<int,int>
#define ss second
#define ff first
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pii>adj[n+1];

        for(int i=0;i<m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            adj[x].push_back({y,w});
            adj[y].push_back({x,w});
        }

        int src ; cin>>src;
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        priority_queue<pii,vector<pii>,greater<pii>>q;

        q.push({0,src});
        while(!q.empty()){
            auto top = q.top();
            q.pop();

            if(top.ss != INT_MAX){
                for(auto x:adj[top.ss]){
                    if(dist[top.ss]+x.ss < dist[x.ff]){
                        dist[x.ff] = dist[top.ss]+x.ss;
                        q.push({dist[x.ff],x.ff});
                    }
                }
            }
        }

        for(auto x:dist){
            cout<<x<<" ";
        }cout<<endl;
    }
}
