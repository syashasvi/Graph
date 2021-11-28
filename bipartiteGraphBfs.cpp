#include<bits/stdc++.h>
using namespace std;

bool bfsCheck(int src, vector<int>adj[],vector<int>&color){
    queue<int>q;
    q.push(src);
    color[src] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        int tempclr = color[curr];
        for(auto x:adj[curr]){
            if(tempclr != -1){
                int revcolr = 0;
                if(tempclr==0){
                    revcolr = 1;
                }
                if(color[x] == -1){
                    color[x] = revcolr;
                    q.push(x);
                }else{
                    if(color[x]==revcolr) continue;
                    else return false;
                }
            }
        }
    }

    return true;
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

        //vector<bool>vis(n+1,false);
        vector<int>color(n+1,-1);

        bool flag=0;

        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(bfsCheck(i,adj,color)==true){
                    flag=1;
                    break;
                }
            }
        }

        if(flag==1) cout<<"BIPATITE\n";
        else cout<<"NOT BIPATITE\n";
    }
}
