#include <bits/stdc++.h>

#define MAXN 200005
using namespace std;

class FenwickTree {
    public:
    int n;
    long long arr[MAXN];
   
    FenwickTree(int n){
        this->n = n;
        build();
    }

    void build(){
        for(int i = 0; i <= n; i++)
            arr[i] = 0;
    }

    void update(int pos, int value){
        //int diff = value-arr[pos];
        while(pos <= n){
            arr[pos] += value;
            pos += (pos & -pos);
        }
    }

    long long query(int pos){
        long long sum = 0;
        while(pos > 0){
            sum += arr[pos];
            pos -= (pos & -pos);
        }
        return sum;
    }

};

