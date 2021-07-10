//Ideally we cannot build a prime sieve of size of 10^8
//so we'll use segmented prime sieve here
//here we m and n can be 10^9
//n-m value given matters!!

//here,we'll first find out the primes from 0 to root n
//and store it in a vector(named primes).Then taking one prime
//,we'll mark its multiples as not prime in the array given by the question.

//to create the primes vector,we'll use prime seive over an array named p
//prime seive is the seive of erathosthenes
#include <iostream>
#include <vector>
using namespace std;

const int N = 100000;

vector<int> primes;
int p[N] = {0};

void seive()
{
    for (int i = 2; i <= N; i++)
    {
        if (p[i] == 0)
        { //prime
            primes.push_back(i);
            for (int j = i; j <= N; j += i)
            {
                p[j] = 1; //not prime
            }
        }
    }
}

int main()
{
    //for fast io as I was getting runtime error(SIGSEGV)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive(); //build it once for all the test cases
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        bool segment[n - m + 1]; //0 to n-m where 0->mth no and n-m->nth no
        //mark all numbers as prime initially
        for (int i = 0; i < n - m + 1; i++)
        {
            segment[i] = 0; //prime
        }
        //segment seive logic starts:
        //optimisation 1:when we mark the multiples of primes as not primes
        //we can find the first number closest to n by say,t=(m/p)*p
        //and then iterating from i=t with jumps of p
        //also,we'll only iterate for the primes between 0 to root n
        for (auto p : primes)
        {
            if (p * p > n)
            {
                break;
            }
            int t = (m / p) * p;

            //a corner case:
            //when primes and segment overlap
            //eg)if m=5 and n=100,hence primes if from 0 to root 100=10
            //so 5 and 7 are the common elements in both
            //for 5:t=(5/5)*5=5 which is all right
            //but for 7:t=(5/7)*7=0*7=0,so this will mark 0,7,14,28...
            //as not prime which is wrong.So in such cases we should set
            //t as 2*7=14

            if (p >= m and p <= n)
            {
                t = 2 * p;
            }

            for (int i = t; i <= n; i += p)
            {
                segment[i - m] = 1; //not prime
            }
        }
        //now loop over m to n and print the primes
        for (int i = m; i <= n; i++)
        {
            if (segment[i - m] == 0 and i != 1)
            {
                cout << i << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}

//while submitting select C++ 14 Clang on SPOJ else will give runtime error!