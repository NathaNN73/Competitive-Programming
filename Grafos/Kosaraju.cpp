#include <bits/stdc++.h>
#define MAXN 200005

using namespace std;

vector<vector<int>> adj, inverted_adj;
vector<int> topsort, component;
bool vis[MAXN];

int n;

void dfs1(int u){
    vis[u] = true;
    for(auto v : adj[u])
        if(!vis[v])
            dfs1(1);

    topsort.push_back(u);
}

void dfs2(int u){ 
    vis[u] = true;
    component.push_back(u);
    for(auto v : inverted_adj[u])
        if(!vis[v])
            dfs2(v);
}

void invert_graph(){
    inverted_adj.resize(n);
    for(int u = 0; u < n; u++){
        for(auto v : adj[u])
            inverted_adj[v].push_back(u);
    }
}

vector<vector<int>> kosaraju(){
    vector<vector<int>> scc;
    memset(vis, false, sizeof vis);

    //FIRST DFS
    for(int i = 0; i < n; i++)
        if(!vis[i])dfs1(i);

    //TOPSORT and INVERTED GRAPH
    reverse(topsort.begin(), topsort.end());
    invert_graph();

    //SECOND DFS
    for(auto u : topsort)
        if(!vis[u]){
            component.clear();
            dfs2(u);
            scc.push_back(component);
        }

    return scc;
}


