#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int square(int i){
    return i*i;
}

int checkEquation(int x){
    if(x <= 0){
        return false;
    }
    int k = sqrt(x);
    return k*k == x;
}
int findRes(int sum,int product){
    int delta = square(sum) - 4*product;
    if(delta < 0 || !checkEquation(delta)){
        return -1;
    }
    int ans = sum + sqrt(delta);
    if(ans < -1 || ans%2 != 0){
        return -1;
    }
    return ans / 2;
}
int arr[3001];
int main(){
    for(int i = 1 ; i <= 3000 ; i++){
        arr[i] = -1;
        for(int j = 1 ; j < i ; j++){
            int squr = square(i-j) - square(j);
            if(squr > 0 && squr%2 == 0 && squr/2 < square(j)){
                int product = squr/2;
                int sum = i-j;
                int a = findRes(sum,product);
                if(!checkEquation(j*j - a*a)){
                    continue;
                }
                int calc = product * j;
                if(arr[i] < calc){
                    arr[i] = calc;
                }
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << arr[n] << endl;
    }
}

