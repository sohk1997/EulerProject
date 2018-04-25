#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool palindrome(int x){
    int xx = x;
    int rex = 0;
    while(xx > 0){
        rex = (rex*10) + xx%10;
        xx /= 10;
    }
    return rex == x;
}

int findMax(vector<int> arr, int l, int r, int val){
    int res = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] < val){
            res = arr[mid];
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return res;
}

vector<int> palin;

int main(){
    for(int i = 100 ; i < 1000 ; i++){
        for(int j = i ; j < 1000 ; j++){
            if(palindrome(i*j) && i*j > 100000){
                palin.push_back(i*j);
            }
        }
    }
    sort(palin.begin(),palin.end());
    int length = palin.size();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << findMax(palin,0,length-1,n) << endl;
    }
}

