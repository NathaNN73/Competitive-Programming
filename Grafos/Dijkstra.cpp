#include <bits/stdc++.h>

#define MAXN 100005
#define INF 1e17
#define int long long

using namespace std;

vector<vector<pair<int,int>>> adj;
int dist[MAXN];
int parent[MAXN];
bool vis[MAXN];

int n;

void dijkstra(int s){
    memset(vis, false, sizeof vis);

    priority_queue<pair<int,int>> pq;
    
    for(int i = 0; i < n; ++i){
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[s] = 0;
    vis[s] = true;
    
    pq.push({0, s});
    while(!pq.empty()){
        auto [u,distance] = pq.top();
        vis[u] = true;
        pq.pop();
        for(auto [v, w] : adj[u]){
            if(!vis[v]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({-dist[v], v});
                }
            }
        }
    }

}
