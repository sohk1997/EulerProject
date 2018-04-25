#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull fibo[100];
int main(){
    int cnt = 1;
    ull maxval = 1e16;
    fibo[0] = 1;
    fibo[1] = 2;
    while(fibo[cnt] < 4*maxval){
        cnt++;
        fibo[cnt] = fibo[cnt-1] + fibo[cnt-2];
    }
    cnt++;
    int t;
    cin >> t;
    for(int i = 0 ; i < t ;i++){
        ull n ;
        cin >> n;
        ull sum = 0;
        for(int j = 1 ; fibo[j] <= n && j < cnt ; j += 3){
            sum += fibo[j];
        }
        cout << sum << endl;
    }
}

