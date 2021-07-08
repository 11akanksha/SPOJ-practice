#include <iostream>
#define ll long long
using namespace std;

ll l = 10000;
// not prime is 0 and prime is 1
void prime_sieve(ll *a)
{
    //1st mark all odd nos as prime
    for (ll i = 3; i < l; i += 2)
    {
        a[i] = 1;
    }
    //Sieve
    //now to move only to odd numbers:
    for (ll i = 3; i <= l; i += 2)
    {
        //if the current number is prime(true)
        if (a[i])
        {
            //mark all the multples of i as not prime(false)
            for (ll j = i * i; j <= l; j += i)
            {
                a[j] = 0;
            }
        }
    }
    //That's it..the array now has only prime numbers!!
    //special cases:
    //1 and 0 are not primes and 2 is a prime
    a[2] = 1;
    a[1] = a[0] = 0;

    // only to debug:
    // for (ll i = 0; i < l; i++)
    // {
    //     if (a[i] == 1)
    //     {
    //         cout << i << " ";
    //     }
    // }
}

int main()
{
    ll a[l] = {0}; //all are not primes
    prime_sieve(a);
    short t;
    cin >> t;
    while (t--)
    {
        ll m, n;
        cin >> m >> n;
        for (ll i = m; i <= n; i++)
        {
            //if a[i] is prime(true)
            if (a[i])
            {
                cout << i << endl;
            }
        }
        cout << endl;
    }
    return 0;
}