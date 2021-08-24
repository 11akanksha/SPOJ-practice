//NOTE: I got TLE here.I may add an optimized code when I learn some more!
//But the code gives correct o/p and just needs optimization.
#include <iostream>
#define ll long long
using namespace std;

ll a[200009];
ll c;
void merge(ll s, ll e, ll mid)
{
    ll i = 0, j = 0, k = s;
    ll l1 = mid - s + 1, l2 = e - mid;
    ll a1[l1], a2[l2];

    for (ll p = 0; p < l1; p++)
    {
        a1[p] = a[s + p];
    }
    for (ll p = 0; p < l2; p++)
    {
        a2[p] = a[mid + 1 + p];
    }
    while (i < l1 && j < l2)
    {
        if (a1[i] < a2[j])
        {
            a[k++] = a1[i++];
        }
        else if (a2[j] < a1[i])
        {
            a[k++] = a2[j++];
            c = c + l2;
        }
    }
    while (j < l2)
    {
        a[k++] = a2[j++];
    }
    while (i < l1)
    {
        a[k++] = a1[i++];
    }
}

void merge_sort(ll s, ll e)
{
    if (e > s)
    {
        int mid = (s + e) >> 1;
        merge_sort(s, mid);
        merge_sort(mid + 1, e);
        merge(s, e, mid);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll l;
        scanf("%lld", &l);
        for (ll i = 0; i < l; i++)
        {
            scanf("%lld", &a[i]);
        }
        c = 0;
        merge_sort(0, l - 1);
        printf("%lld\n", c);
    }
    return 0;
}