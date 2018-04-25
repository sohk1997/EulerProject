#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int ans[5000001];
int ans2[5000001];

int calc(ll x){
    if(x <= 5 * 1e6){
        if(ans[x] != 0){
            return ans[x];
        }
    }
    if(x%2 == 0){
        ll tmp = calc(x/2);
        if(x <= 5 * 1e6){
            ans[x] = tmp+1;
        }
        return tmp+1;
    }
    ll tmp = calc((3*x+1)/2);
    if(x <= 5 * 1e6){
        ans[x] = tmp+2;
    }
    return tmp+2;
}

int main(){
    ans[1] = 1;
    for(int i = 2 ; i <= 5 * 1e6 ; i++){
        if(ans[i] == 0){
            calc(i);
        }
    }
    ans2[1] = 1;
    for(int i = 2 ; i <= 5 * 1e6 ; i++){
        ans2[i] = ans2[i-1];
        if(ans[ans2[i-1]] <= ans[i]){
            ans2[i] = i;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ans2[n] << endl;
    }
}

