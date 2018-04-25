#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string ans[10001];

string product(string a,int x){
    int mem = 0;
    string ans = "";
    for(int i = a.length()-1 ; i >= 0 ; i--){
        int aa = a[i] - '0';
        int tmp = aa * x + mem;
        mem = tmp / 10;
        char x = tmp%10 + '0';
        ans = x + ans;
    }
    while(mem > 0){
        char x = mem%10 + '0';
        mem /= 10;
        ans = x + ans;
    }
    return ans;
}



void multi2(int x){
    ans[0] = "1";
    for(int i = 1 ; i <= x ; i++){
        ans[i] = product(ans[i-1],2);
    }
}

int calcSum(string x){
    int ans = 0;
    for(int i = 0 ; i < x.length() ; i++){
        int xx = x[i] - '0';
        ans += xx;
    }
    return ans;
}
int main(){
    multi2(10000);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << calcSum(ans[n]) << endl;
    }
}

