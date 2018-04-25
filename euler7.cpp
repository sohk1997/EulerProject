#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


int res[10001];
int check[104730];
int main(){
    int cnt = 0;
    int val = 1;
    while(cnt < 1e4){
        val++;
        if(check[val] == 0){
            res[cnt] = val;
            cnt++;
            for(int i = val ; i <= 104729/val ; i++){
                check[i*val] = 1;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n--;
        cout << res[n] << endl;
    }
}

