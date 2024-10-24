#include <bits/stdc++.h> 

#define MAXN 200005

using namespace std;

class DSU {
    public:
    int N;
    int parent[MAXN];
    int sz[MAXN];

    DSU (int n){
	this->N = n;
	init();
    }
    
    void init(){
	//makeset
	for(int i = 0; i <= N; i++){
	    parent[i] = i;
	    sz[i] = 1;
	}
    }

    int find_set(int v){
	if(parent[v] == v)return v;
	return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b){
	int u = find_set(a);
	int v = find_set(b);
	if(u != v){
	    if(sz[u] < sz[v])
		swap(u,v);
	    parent[v] = u;
	    sz[u] += sz[v];
	}
    }

};






