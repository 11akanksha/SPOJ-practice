//compute factorials from 1 to 100
#include <iostream>
using namespace std;

//will not work for n>30
// long long fact(int n)
// {
//     long long a = 1;
//     for (int i = n; i > 1; i--)
//     {
//         a *= i;
//     }
//     return a;
// }

void multiply(int *a, int m, int &n)
{
    int carry = 0;
    for (int i = 0; i < n; i++)
    {
        int product = a[i] * m + carry;
        a[i] = product % 10;
        carry = product / 10;
    }

    while (carry)
    {
        a[n] = carry % 10;
        carry = carry / 10;
        n++;
    }
}

void big_fact(int no)
{
    int *a = new int[1000];
    for (int i = 0; i < 1000; i++)
    {
        a[i] = 0;
    }

    a[0] = 1;
    int n = 1; //n:no of digits in a

    for (int i = 2; i <= no; i++)
    {
        multiply(a, i, n);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << a[i];
    }
    cout << endl;
    delete[] a;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        big_fact(n);
    }
    return 0;
}