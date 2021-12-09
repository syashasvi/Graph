#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int>adj[n+1];
        vector<int>indegree(n,0);

        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            indegree[y]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        //vector<int>topo;
        int count=0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;

            for(auto x:adj[curr]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }

        if(count!=n) cout<<"TRUE\n";
        else cout<<"FALSE\n";

    }
}
