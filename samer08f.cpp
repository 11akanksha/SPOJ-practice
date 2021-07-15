#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        int res = n * (n + 1) * (2 * n + 1) / 6;
        cout << res << endl;
        cin >> n;
    }
    return 0;
}