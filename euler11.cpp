#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int a[50][50];

int calcVer(int ver,int hor){
    if(ver - 3 < 0){
        return 0;
    }
    return a[ver][hor] * a[ver-1][hor] * a[ver-2][hor] * a[ver-3][hor];
}

int calcHor(int ver, int hor){
    if(hor - 3 < 0){
        return 0;
    }
    return a[ver][hor] * a[ver][hor-1] * a[ver][hor-2] * a[ver][hor-3];
}

int calcDiaL(int ver, int hor){
    if(ver - 3 < 0 || hor - 3 < 0){
        return 0;
    }
    return a[ver][hor] * a[ver-1][hor-1] * a[ver-2][hor-2] * a[ver-3][hor-3];
}

int calcDiaR(int ver,int hor){
    if(ver - 3 < 0){
        return 0;
    }
    return a[ver][hor] * a[ver-1][hor+1] * a[ver-2][hor+2] * a[ver-3][hor+3];
}

int main(){
    for(int i = 0 ; i < 20 ; i++){
        for(int j = 0 ; j < 20 ; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 0 ; i < 20 ; i++){
        for(int j = 0 ; j < 20 ; j++){
            ans = max(ans,calcVer(i,j));
            ans = max(ans,calcHor(i,j));
            ans = max(ans,calcDiaL(i,j));
            ans = max(ans,calcDiaR(i,j));
        }
    }
    cout << ans;
}

