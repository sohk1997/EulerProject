#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0;
        int cnt0 = 0;
        int product = 1;
        for(int i = 0 ; i < s.length() ; i++){
            if(i > k-1){
                int num = s[i-k] - '0';
                if(num == 0){
                    cnt0--;
                }else{
                    product /= num;
                }
            }
            int num = s[i] - '0';
            if(num == 0){
                cnt0++;
            }
            else{
                product = product*num;
            }
            if(i >= k-1){
                if(cnt0 == 0 && product > ans){
                    ans = product;
                }
            }
        }
        cout << ans << endl;
    }
}

