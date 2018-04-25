#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool notPrime[1000001];
ll ans[1000001];
int main(){
    notPrime[1] = true;
    for(int i = 2 ; i <= 1000000 ; i++){
        ans[i] = ans[i-1];
        if(!notPrime[i]){
            ans[i] += i;
        }
        if(!notPrime[i] && i < 1000){
            for(int j = i ; j <= 1000000/i ; j++){
                notPrime[j*i] = true;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
}

