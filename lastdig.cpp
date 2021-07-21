#include <iostream>
#define ll long long
using namespace std;

ll last_dig(int a, int b, int p)
{
    ll r = 1; //the result
    if (a % p == 0)
    {
        return 0;
    }
    while (b > 0)
    {
        //if b is odd:
        if (b & 1)
        {
            r = (r * a) % p;
        }
        //divide b by 2:
        b = b >> 1;
        a = (a * a) % p;
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
        cout << last_dig(a, b, 10) << endl;
    }
    return 0;
}

//to check if a no is odd: no & 1
//to devide a no by 2: no = no >> 1

//we'll use the concept of modular exponentiation here
//wherein we'll use the fact that for a^b,
//when b is even ,last digit will be same as a*a
//ex) 4^2=16,last dig=6; 4^16=(4^2)^8=16^8=(16*16)^4=36^4
//=(36*36)^2 and last dig of 36*36=6*6=6 and squaring it:6
//which is same as 4^2's last digit
//for an odd b, only the left out odd will create a change in
//the last digit of the a^b.