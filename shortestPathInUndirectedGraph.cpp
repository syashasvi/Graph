#include<bits/stdc++.h>
using namespace std;

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

        int src; cin>>src;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        queue<int>q;
        q.push(src);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto x:adj[curr]){
                if(dist[x] > dist[curr]+1){
                    dist[x] = dist[curr]+1;
                    q.push(x);
                }
            }
        }
        for(auto x:dist){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
