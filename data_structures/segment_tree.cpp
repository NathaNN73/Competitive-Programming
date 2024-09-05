#include <bits/stdc++.h>

#define MAXN 200005
using namespace std;

class SegmentTree {
    public:

    int n;
    long long arr[MAXN];
   
    SegmentTree(int n){
        this->n = n;
    }

    void build(){
        for(int i = n-1; i >= 1; i--){
            arr[i] = arr[i<<1] + arr[i<<1|1];
        }
    }

    void update(int pos, int value){
        pos += n-1;
        arr[pos] = value;
        for(pos >>= 1; pos > 0; pos >>= 1){
            arr[pos] = arr[pos<<1] + arr[pos<<1|1];
        }
    }

    long long query(int l, int r){
        long long sum = 0;
        for(l += n-1, r += n-1; l <= r; l >>= 1, r >>= 1){
            if(l&1)sum += arr[l++];
            if(!(r&1))sum += arr[r--];
        }
        return sum;
    }

};
