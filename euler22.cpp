#include <bits/stdc++.h>
#define MaxN int(6e3+10)
using namespace std;

string name[MaxN];
int score[MaxN];

int calcScore(string s)
{
    int sum = 0;
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] > 'a')
        {
            sum += s[i] - 'a' + 1;
        }
        else
        {
            sum += s[i] - 'A' + 1;
        }
    }
    return sum;
}

int indexOf(int n,string value)
{
    int l = 0;
    int r = n-1;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(name[m] == value)
        {
            return m;
        }
        if(name[m] < value)
        {
            l = m+1;
        }
        else
        {
            r = m-1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> name[i];
    }
    sort(name,name+n);
    for(int i = 0 ; i < n ; i++)
    {
        score[i] = calcScore(name[i]);
    }

    int q;
    cin >> q;
    while(q--)
    {
        string s;
        cin >> s;
        int index = indexOf(n,s);
        cout << (index+1) * score[index] << endl;
    }

}
