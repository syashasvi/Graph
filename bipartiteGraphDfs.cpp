#include<bits/stdc++.h>
using namespace std;

bool dfsCheck(int src,vector<int>adj[],vector<int>&color,int tempclr){
    color[src] = tempclr;
    int revcolr = 0;
    if(tempclr==0){
        revcolr=1;
    }
    for(auto x:adj[src]){
        if(color[x] == -1){
            if(dfsCheck(x,adj,color,revcolr)==true) continue;
            else return false;
        }else{
            if(color[x]==revcolr) continue;
            else return false;
        }
    }

    return true;
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

        vector<int>color(n+1,-1);
        bool flag=0;

        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(dfsCheck(i,adj,color,0)==true){
                    flag=1;
                    break;
                }
            }
        }

        if(flag==1) cout<<"BIPATITE\n";
        else cout<<"NOT BIPATITE\n";
    }
}
