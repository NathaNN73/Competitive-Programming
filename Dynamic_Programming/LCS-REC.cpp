#include <bits/stdc++.h>

#define MAXN 1005
using namespace std;

int dp[MAXN][MAXN];

int lcs(string a, string b){
    int n = a.size();
    int m = b.size();
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0)dp[i][j] = 0;
            else if(a[i-1] == b[j-1])dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

void rec(string a, string b, int i, int j){
    if(i == 0 || j == 0)return;
    if(a[i-1] == b[j-1]){
        rec(a, b, i-1, j-1);
        cout << a[i-1];
    }else if(dp[i-1][j] > dp[i][j-1]){
        rec(a, b, i-1, j);
    }else{
        rec(a, b, i, j-1);
    }
}

int main(){
    string a = "AGGTAB";
    string b = "GXTXAYB";
    cout << lcs(a, b) << endl;
    rec(a, b, a.size(), b.size());
    return 0;
}