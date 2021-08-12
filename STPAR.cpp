#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v(1000);
    int n;
    cin >> n;
    while (n != 0)
    {
        int max = 0;
        v.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] > max)
                max = v[i];
        }

        int lane[n], ans[n];
        int l = 1, a = 0;

        lane[0] = 1001;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1] && v[i] <= lane[l - 1])
            {
                lane[l] = v[i];
                l++;
            }
            else
            {
                if (v[i] > lane[l - 1])
                {
                    ans[a] = lane[l - 1];
                    l--;
                    a++;
                    i--;
                }
                else
                {
                    ans[a] = v[i];
                    a++;
                }
            }
        }

        for (int i = l - 1; i > 0; i--)
        {
            if (v[n - 1] > lane[l - 1])
            {
                ans[a] = lane[l - 1];
                lane[l] = v[n - 1];
                a++;
                l++;
            }
            else
            {
                ans[a] = lane[i];
                a++;
            }
        }

        bool res = is_sorted(ans, ans + a);
        if (res)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        cin >> n;
    }
    return 0;
}