#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void clean(string &a, string &b){
    while(a.length() < b.length()){
        a = "0" + a;
    }
    while(b.length() < a.length()){
        b = "0" + b;
    }
}

string sum(string a, string b){
    int mem = 0;
    string ans = "";
    for(int i = a.length()-1 ; i >= 0 ; i--){
        int aa = a[i] - '0';
        int bb = b[i] - '0';
        int calc = aa + bb + mem;
        mem = calc/10;
        ans = char(calc%10 + '0') + ans;
    }
    if(mem > 0){
        ans = "1" + ans;
    }
    return ans;
}

int main(){
    string ans = "";
    int n;
    cin >> n;
    while(n--){
        string a;
        cin >> a;
        clean(ans,a);
        ans = sum(ans,a);
    }
    for(int i = 0 ; i < 10 ; i++)   {
        cout << ans[i];
    }
}

