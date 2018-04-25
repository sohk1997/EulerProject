#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int ans[1001][1001];
const int MOD = 1e9 + 7;

int main(){
    ans[0][0] = 1;
    for(int i = 1 ; i < 1001 ; i++){
        for(int j = 1 ; j <= i ; j++){
            ans[i][j] = (ans[i-1][j-1]+ans[i-1][j]) % MOD;
        }
        ans[i][0] = 1;
    }
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        cout << ans[a+b][a] << endl;
    }

}

