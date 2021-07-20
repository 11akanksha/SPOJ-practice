#include <iostream>
// #include <algorithm>
#include <numeric>
using namespace std;

int TheCount(int a[], int n)
{
    int sum = 0;
    sum = accumulate(a, a + n, sum);
    int avg = sum / n;
    if (sum % n != 0)
    {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > avg)
        {
            count += (a[i] - avg);
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    while (n != (-1))
    {
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // sort(a, a + n); no need for this though :)
        cout << TheCount(a, n) << endl;
        cin >> n;
        delete[] a;
    }
    return 0;
}