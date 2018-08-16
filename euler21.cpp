#include <bits/stdc++.h>
#define MaxN int(1e5+10)
using namespace std;

int calcSumProperDivisor(int x)
{
    //1 is divisor of all number
    int sum = 1;

    for(int i = 2 ; i <= sqrt(x) ; i++)
    {
        if(x%i == 0)
        {
            sum += i;
            if(x/i != i){
                sum += x/i;
            }
        }
    }
    return sum;
}
int sumProperDivisor[MaxN];
int result[MaxN];

int main()
{
    for(int i = 2 ; i <= 1e5 ; i++)
    {
        sumProperDivisor[i] = calcSumProperDivisor(i);
    }

    for(int i = 2 ; i <= 1e5 ; i++)
    {
        result[i] = result[i-1];
        if(sumProperDivisor[i] <= 1e5 && sumProperDivisor[sumProperDivisor[i]] == i && sumProperDivisor[i] != i){
            result[i] += i;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << result[n] << endl;
    }
}
