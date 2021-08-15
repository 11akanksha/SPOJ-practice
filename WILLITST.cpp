#include <iostream>
using namespace std;

int main()
{
    long long n;
    int t = 0;
    cin >> n;
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = 3 * n + 3;
        }
        t++;
        if (t > 47)
        {
            cout << "NIE" << endl;
            break;
        }
    }
    if (t <= 47)
    {
        cout << "TAK" << endl;
    }
    return 0;
}