#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> add(vector<ll> &a, vector<ll> &b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<ll> ans;
    ll len = min(a.size(), b.size());
    ll carry = 0;

    for (ll i = 0; i < len; i++)
    {
        ll val = a[i] + b[i] + carry;
        carry = val / 10;
        ans.push_back(val % 10);
    }

    if (a.size() > len)
    {
        for (ll i = len; i < a.size(); i++)
        {
            ll val = a[i] + carry;
            carry = val / 10;
            ans.push_back(val % 10);
        }
    }

    if (b.size() > len)
    {
        for (ll i = len; i < b.size(); i++)
        {
            ll val = b[i] + carry;
            carry = val / 10;
            ans.push_back(val % 10);
        }
    }

    while (carry > 0)
    {
        ans.push_back(carry % 10);
        carry = carry / 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

vector<ll> sub(vector<ll> x, vector<ll> y)
{
    reverse(y.begin(), y.end());

    vector<ll> ans;
    ll len = y.size();
    for (ll i = 0; i < len; i++)
    {
        if (x[i] < y[i])
        {
            x[i + 1]--;
            ans.push_back(10 + x[i] - y[i]);
        }
        else
        {
            ans.push_back(x[i] - y[i]);
        }
    }

    if (x.size() > len)
    {
        for (ll i = len; i < x.size(); i++)
        {
            if (x[i] < 0)
            {
                x[i + 1]--;
                ans.push_back(10 + x[i]);
            }
            else
            {
                ans.push_back(x[i]);
            }
        }
    }
    reverse(ans.begin(), ans.end());

    //To remove the leading zeroes:
    vector<ll> arr;
    ll i = 0;
    while (ans[i] == 0)
        i++;
    for (; i < ans.size(); i++)
    {
        arr.push_back(ans[i]);
    }
    return arr;
}

vector<ll> div_by_2(vector<ll> &sum)
{
    vector<ll> ans;
    int val = 0;
    for (ll i = 0; i < sum.size(); i++)
    {
        if (val != 0)
        {
            val = val * 10 + sum[i];
            ans.push_back(val / 2);
            val = val % 2;
        }
        else
        {
            if (sum[i] < 2)
            {
                val += sum[i];
                ans.push_back(0);
            }
            else
            {
                val = sum[i] % 2;
                ans.push_back(sum[i] / 2);
            }
        }
    }
    //removing the leading zeroes:
    vector<ll> arr;
    ll i = 0;
    while (ans[i] == 0)
    {
        i++;
    }
    while (i < ans.size())
    {
        arr.push_back(ans[i]);
        i++;
    }
    return arr;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        string k, n;
        cin >> k >> n;
        vector<ll> digk;
        vector<ll> dign;

        for (ll i = 0; i < k.length(); i++)
        {
            digk.push_back(k[i] - '0');
        }
        for (ll i = 0; i < n.length(); i++)
        {
            dign.push_back(n[i] - '0');
        }
        vector<ll> sum = add(digk, dign);
        vector<ll> div = div_by_2(sum);

        for (ll i = 0; i < div.size(); i++)
        {
            cout << div[i];
        }
        cout << endl;
        vector<ll> diff = sub(digk, div);
        for (ll i = 0; i < diff.size(); i++)
        {
            cout << diff[i];
        }
        cout << endl;
    }
    return 0;
}

//We'll be using the logic:
//x+y=n(the total apples they have) and y=x+k
//we are given the values of n and k in the ques and we need to find x & y
//Hence we'll add the following 2 equations:
//x+y=n and y-x=k.which'll give: x+y+y-x=n+k => 2y=n+k => y=(n+k)/2
//and then x=n-y.
//For any doubts,refer: https://www.youtube.com/watch?v=ZdXD0Xzluzw