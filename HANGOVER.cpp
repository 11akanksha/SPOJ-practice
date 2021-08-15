#include <iostream>
using namespace std;

int main()
{
    float c;
    cin >> c;
    while (c != 0.00)
    {
        float p = 0.00, n = 0;
        while (p <= c)
        {
            n++;
            p += (float)1 / (n + 1);
        }
        cout << n << " card(s)" << endl;
        cin >> c;
    }
    return 0;
}