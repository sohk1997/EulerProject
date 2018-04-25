#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int getCheck(int x){
    for(int i = 2 ; i <= x ; i++){
        if(x%i == 0){
            int xx = x;
            while(xx%i == 0){
                xx /= i;
            }
            if(xx != 1){
                return 1;
            }else{
                return i;
            }
        }
    }
    return 1;
}

int res[41];

int main(){
    res[1] = 1;
    for(int i = 2 ; i <= 40 ; i++){
        res[i] = res[i-1] * getCheck(i);
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << res[n] << endl;
    }
}

