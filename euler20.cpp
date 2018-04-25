#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string product(string a, int x){
    int mem = 0;
    string ans = "";
    for(int i = a.length()-1 ; i >= 0 ; i--){
        int aa = a[i] - '0';
        int calc = aa*x + mem;
        mem = calc/10;
        char x = calc%10 + '0';
        ans = x + ans;
    }
    while(mem > 0){
        char x = mem%10 + '0';
        ans = x + ans;
        mem /= 10;
    }
    while(ans[ans.length()-1] == '0'){
        ans.erase(ans.length()-1,1);
    }
    return ans;
}

int calcSum(string s){
    int ans = 0;
    for(int i = 0 ; i < s.length() ; i++){
        int xx = s[i] - '0';
        ans += xx;
    }
    return ans;
}

int ans[1001];

void init(){
    string calc = "1";
    ans[0] = 1;
    for(int i = 1 ; i <= 1000 ; i++){
        calc = product(calc,i);
        ans[i] = calcSum(calc);
    }
}

int main()
{
    init();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
}

