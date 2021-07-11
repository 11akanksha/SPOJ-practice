//Aim:no of zeroes at the end of a factorial
#include <iostream>
using namespace std;

int no_of_zeroes(int no)
{
    int c = 0;
    for (int i = 5; no / i >= 1; i *= 5)
    {
        c += no / i;
    }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << no_of_zeroes(n) << endl;
    }
    return 0;
}
