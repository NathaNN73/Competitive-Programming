#include <bits/stdc++.h>

#define mod 1000000007
#define MAXN 1000005

using namespace std;


int factorial[MAXN];
int inv_factorial[MAXN];

int fast_pow(int a, int b){
    int res = 1;
    while(b){
        if(b&1)res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b /= 2;
    }
    return res;
}

void precompute(){
    factorial[0] = 1;
    for(int i = 1; i < MAXN; i++){
        factorial[i] = (1LL * factorial[i-1] * i) % mod;
    }
    inv_factorial[MAXN-1] = fast_pow(factorial[MAXN-1], mod-2);
    for(int i = MAXN-2; i >= 0; i--){
        inv_factorial[i] = (1LL * inv_factorial[i+1] * (i+1)) % mod;
    }
}

int binomial(int n, int k){
    if(k < 0 || k > n)return 0;
    return (1LL * factorial[n] * inv_factorial[k] % mod * inv_factorial[n-k]) % mod;
}

int main(){
    precompute();
    cout << binomial(5, 2) << endl;
    return 0;
}