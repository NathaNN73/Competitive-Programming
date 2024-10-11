#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

vector<vector<int>> adj;
bool vis[MAXN];

int n;

vector<int> topsort;

void dfs(int u){
    vis[u] = true;
    for(auto v : adj[u]){
        if(!vis[v])
            dfs(v);
    }
    topsort.push_back(u);
}

int main(){
    int n; cin >> n;
    adj.resize(n);

    for(int i = 0; i < n; i++){
        int u, v; cin >> u >> v;
        //u--; v--;
        adj[u].push_back(v);
    }

    //TOPSORT
    for(int i = 0; i < n; i++){
        if(!vis[i])
            dfs(i);
    }

    reverse(topsort.begin(), topsort.end());

    cout << "Topsort: ";
    for(auto node : topsort)
        cout << node << " "; 
}

