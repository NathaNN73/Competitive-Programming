#include <bits/stdc++.h>

#define MAXN 200005
#define INF 1e17
#define int long long

using namespace std;

vector<vector<pair<int,int>>> adj;
int dist[MAXN];
int parent[MAXN];

int n;

void BellmanFord(int u){
    for(int i = 0; i < n; i++)dist[i] = INF;
    dist[u] = 0;

    for(int time = 0; time < n-1; ++time){
        for(int u = 0; u < n; ++u){
            for(auto [v,w] : adj[u]){
                if(dist[v] < INF && dist[u] + w  < dist[v]){
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
    }
}



