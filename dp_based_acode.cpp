#include <iostream>
#include <string.h>
#define ll long long
using namespace std;
ll dp[5005];
ll count_codes(string &s, int i)
{

    int l = s.length();
    if (i == l)
    {
        return 1;
    }

    if (s[i] == '0')
        return 0;

    if (dp[i] != -1)
        return dp[i];

    ll ans = count_codes(s, i + 1);
    if (i + 1 < l)
    {
        int c = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (c > 9 && c <= 26)
        {
            ans += count_codes(s, i + 2);
        }
    }

    dp[i] = ans;

    return ans;
}

int main()
{
    string n;
    cin >> n;
    while (n[0] != '0')
    {
        memset(dp, -1, sizeof(dp));
        cout << count_codes(n, 0) << endl;
        cin >> n;
    }
    return 0;
}
//Also refer: https://discuss.codechef.com/t/doubt-in-spoj-acode/92688/8