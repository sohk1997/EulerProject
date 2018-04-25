#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int calcSum(int n){
    return n*(n+1)/2;
}

int countDiv(int n){
    int nn = n;
    int ans = 1;
    int i = 2;
    while(i <= sqrt(nn)){
        int countt = 0;
        while(nn%i == 0){
            countt++;
            nn /= i;
        }
        ans *= (countt+1);
        i++;
    }
    if(nn > 1){
        ans *= 2;
    }
    return ans;
}

int ans[1001];
int main(){
    int maxU = 0;
    int cnt = 0;
    int check = 1;
    while(maxU <= 1000){
        int divisors = countDiv(calcSum(check));
        if(maxU < divisors){
            maxU = divisors;
            while(cnt < maxU){
                ans[cnt] = calcSum(check);
                cnt++;
            }
        }
        check++;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
}

