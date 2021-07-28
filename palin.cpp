#include <iostream>
#include <string>
#define ll long long
using namespace std;

bool all9s(string &a)
{
    for (ll i = 0; i < a.size(); i++)
    {
        if (a[i] != '9')
        {
            return false;
        }
    }
    return true;
}

bool all0s(string &a)
{
    for (ll i = 0; i < a.size(); i++)
    {
        if (a[i] != '0')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (all9s(s))
        {
            cout << 1;
            for (ll i = 0; i < s.length() - 1; i++)
            {
                cout << 0;
            }
            cout << 1 << endl;
            continue;
        }

        if (all0s(s))
        {
            cout << 1;
            for (ll i = 0; i < s.length() - 2; i++)
            {
                cout << 0;
            }
            cout << 1 << endl;
            continue;
        }

        ll len = s.length();
        ll l, r; //left and right pointers
        l = r = len / 2;

        if (len % 2 == 0)
        {
            l--;
        }

        while (l >= 0 && s[l] == s[r])
        {
            l--;
            r++;
        }

        if (l < 0 || s[l] < s[r])
        {
            l = r = len / 2;
            if (len % 2 == 0)
            {
                l--;
            }

            ll carry = 1; //as we need to add 1
            while (l >= 0)
            {
                ll num = (s[l] - '0') + carry;
                carry = num / 10;
                s[l] = (num % 10) + '0';
                s[r] = s[l];
                l--;
                r++;
            }
        }
        else
        {
            while (l >= 0)
            {
                s[r] = s[l];
                l--;
                r++;
            }
        }
        //diplay the result:
        cout << s << endl;
    }
    return 0;
}
//For doubts,refer: https://www.youtube.com/watch?v=aza7mCUM8io