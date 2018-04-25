#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool isLeap(ll y)
{
    if(y%400 == 0)
    {
        return true;
    }
    if(y%100 == 0)
    {
        return false;
    }
    if(y%4 == 0)
    {
        return true;
    }
    return false;
}


int getNumberOfDay(ll y, int m)
{
    if(m == 2)
    {
        if(isLeap(y))
        {
            return 29;
        }
        return 28;
    }
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8
            || m == 10 || m == 12)
    {
        return 31;
    }
    return 30;
}

int getDay(ll y,int m,int d)
{
    int firstDay = 1;
    ll leap = (y - 1900 + 300 - 1)/400 - (y-1900 - 1)/100 + (y-1900 - 1)/4;
    ll day = (365%7 * ((y-1900)%7)) + leap%7;
    day = (day + firstDay)%7;
    for(int i = 1 ; i < m ; i++)
    {
        day = day + getNumberOfDay(y,i);
        day %= 7;
    }
    if(d != 1)
    {
        day = day + getNumberOfDay(y,m);
    }
    day %= 7;
    return day;
}
int main()
{
    int t;
    cin >> t;
    ll y1,m1,d1;
    ll y2,m2,d2;
    while(t--)
    {
        cin >> y1 >> m1 >> d1;
        cin >> y2 >> m2 >> d2;
        int day = getDay(y1,m1,d1);
        int ans = 0;
        if(d1 != 1)
        {
            m1++;
        }
        if(m1 > 12){
            m1 = 1;
            y1++;
        }
        while(y1 < y2 || (y1 == y2  && m1 <= m2))
        {
            if(day == 0)
            {
                ans++;
            }
            day = (day + getNumberOfDay(y1,m1))%7;
            m1++;
            if(m1 > 12)
            {
                m1 = 1;
                y1++;
            }
        }
        cout << ans << endl;
    }
}

