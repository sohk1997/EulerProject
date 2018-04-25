#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i++){
        int n;
        cin >> n;
        ll n3 = n/3;
        ll n5 = n/5;
        ll n15 = n/15;
        if(n%3 == 0){
            n3--;
        }
        if(n%5 == 0){
            n5--;
        }
        if(n%15 == 0){
            n15--;
        }
        cout << ((n3*(n3+1))/2) * 3 + ((n5*(n5+1))/2) * 5  - ((n15*(n15+1))/2) * 15<< endl;
    }
}

