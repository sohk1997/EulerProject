#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll res = n;
        ll nn = n;
        for(int i = 2 ; i <= sqrt(nn) ; i++){
            if(n%i == 0){
                res = i;
                while(n%i == 0){
                    n /= i;
                }
            }
        }
        if(n > 1){
            res = n;
        }
        cout << res << endl;
    }
}

