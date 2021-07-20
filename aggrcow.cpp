#include <iostream>
#include <algorithm>
using namespace std;

bool CanPlaceCows(int stalls[], int n, int c, int min_sep)
{
    //we'll place the 1st cow in the 1st stall
    int curr_cow = stalls[0];
    //we'll also maintain the count of the cows that have been placed:
    int count = 1;
    //then we'll see if the curr cow can be placed in the stalls
    //from (1 to n-1):
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - curr_cow >= min_sep)
        {
            //means,we can place the cow in this location
            curr_cow = stalls[i];
            count++;
            if (count == c)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);

        //now...the binary search(BS) algorithm

        //create a hypothetical search space:
        int s = 0;
        int e = a[n - 1] - a[0];

        //let's assume the max seperation is 0 as of now
        int ans = 0;
        //we're not applying BS on cows array given in ques
        //but on the search space we created
        while (s <= e)
        {
            int mid = (s + e) / 2;
            //now we'll check if we can place the cows at "mid" seperation
            bool CanBePlaced = CanPlaceCows(a, n, c, mid);
            //if the above is true: we'll check for higher values
            //if not:we'll check for lower values
            if (CanBePlaced)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        cout << ans << endl;
        delete[] a;
    }
    return 0;
}