#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int res;
    double n;
    cin >> n;
    //no of rectangle(excluding squares)
    for (int i = 1; i < sqrt(n); i++)
    {
        for (int j = i + 1; i * j <= n; j++)
        {
            res++;
        }
    }
    //no of squares:
    res += sqrt(n);
    cout << res;
    return 0;
}