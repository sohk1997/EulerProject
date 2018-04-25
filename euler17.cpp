#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string mapping[100];
string first3[3] = {"","Thousand","Million"};
string second3[2] = {"","Billion"};

void init(){
    mapping[0] = "";
    mapping[1] = "One";
    mapping[2] = "Two";
    mapping[3] = "Three";
    mapping[4] = "Four";
    mapping[5] = "Five";
    mapping[6] = "Six";
    mapping[7] = "Seven";
    mapping[8] = "Eight";
    mapping[9] = "Nine";
    mapping[10] = "Ten";
    mapping[11] = "Eleven";
    mapping[12] = "Twelve";
    mapping[13] = "Thirteen";
    mapping[14] = "Fourteen";
    mapping[15] = "Fifteen";
    mapping[16] = "Sixteen";
    mapping[17] = "Seventeen";
    mapping[18] = "Eighteen";
    mapping[19] = "Nineteen";
    mapping[20] = "Twenty";
    mapping[30] = "Thirty";
    mapping[40] = "Forty";
    mapping[50] = "Fifty";
    mapping[60] = "Sixty";
    mapping[70] = "Seventy";
    mapping[80] = "Eighty";
    mapping[90] = "Ninety";
}

string getFirst3(ll x,int cnt){
    string ans = "";
    ll xx = x%100;
    ll yy = x/100;
    if(xx < 20){
        ans = ans + mapping[xx];
    }else{
        ans = ans + mapping[xx%10];
        ans = mapping[xx/10 * 10] + " " + ans;
    }if(yy > 0){
        ans = mapping[yy] + " Hundred " + ans;
    }
    return ans + " " + first3[cnt];
}

string getBi(ll x,int cnt)
{
    string ans = "";
    int countt = 0;
    while(x > 0){
        ans = getFirst3(x%1000,countt) + " " + ans;
        countt++;
        x /= 1000;
    }
    return ans + " " +second3[cnt];
}

string clean(string a){
    string ans = "";
    ans += a[0];
    for(int i = 1 ; i < a.length() ; i++){
        if(a[i-1] != ' ' || a[i] != ' '){
            ans = ans + a[i];
        }
    }
    return ans;
}

string get(ll x){
    string ans = "";
    int cnt = 0;
    while(x > 0){
        ans = getBi(x%1000000000,cnt) + " " + ans;
        x /= 1000000000;
        cnt++;
    }
    return clean(ans);
}


int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << get(n) << endl;
    }
}

