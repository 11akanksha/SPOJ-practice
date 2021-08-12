#include <iostream>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        k = 192 + (k - 1) * 250;
        cout << k << endl;
    }
    return 0;
}