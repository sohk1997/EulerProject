#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int ans[20][20];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int print = 0;
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= i ; j++){
                int x;
                cin >> x;
                ans[i][j] = max(ans[i-1][j],ans[i-1][j-1]) + x;
                print = max(print,ans[i][j]);
            }
        }
        cout << print << endl;
    }
}

