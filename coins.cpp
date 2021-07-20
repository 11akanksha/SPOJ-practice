#include <iostream>
#include <map>
using namespace std;

map<long long, long long> m;

long long max_dollars(long long v)
{
    if (v < 12)
    {
        return v;
    }
    if (m.find(v) != m.end())
    {
        return m[v];
    }
    long long a = 0;
    a = max_dollars(v / 2) + max_dollars(v / 3) + max_dollars(v / 4);
    a = max(v, a);
    m[v] = a;
    return a;
}

int main()
{
    long long n;
    while (cin >> n)
    {
        cout << max_dollars(n) << endl;
        m.clear();
    }
    return 0;
}