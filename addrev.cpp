#include <iostream>
using namespace std;

int rev(int n)
{
    int r = 0, d;
    while (n)
    {
        d = n % 10;
        n = n / 10;
        r = r * 10 + d;
    }
    return r;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        a = rev(a);
        b = rev(b);
        int c = a + b;
        c = rev(c);
        cout << c << endl;
    }
    return 0;
}