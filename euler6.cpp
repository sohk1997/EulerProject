#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


ll res[10001];

int main(){
    res[1] = 0;
    ll sum = 1;
    for(int i = 2 ; i <= 10000 ; i++){
        res[i] = res[i-1] + 2*sum*i;
        sum += i;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << res[n] << endl;
    }
}

