//Merge sort
#include <iostream>
using namespace std;

void merge(int *a, int s, int e, int mid)
{
    int i = 0, j = 0, k = s;
    int l1 = mid - s + 1, l2 = e - mid;
    int a1[l1], a2[l2];

    for (int p = 0; p < l1; p++)
    {
        a1[p] = a[s + p];
    }
    for (int p = 0; p < l2; p++)
    {
        a2[p] = a[mid + 1 + p];
    }
    while (i < l1 && j < l2)
    {
        if (a1[i] <= a2[j])
        {
            a[k++] = a1[i++];
        }
        else if (a2[j] < a1[i])
        {
            a[k++] = a2[j++];
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

void merge_sort(int *a, int s, int e)
{
    if (e > s)
    {
        int mid = (s + e) / 2;
        merge_sort(a, s, mid);
        merge_sort(a, mid + 1, e);
        merge(a, s, e, mid);
    }
}

int main()
{
    int a[] = {4, 5, 2, 9, 10, 20, 18};
    int l = sizeof(a) / sizeof(a[0]);
    cout << "Given Array:\n";
    for (int i = 0; i < l; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    merge_sort(a, 0, l - 1);
    cout << "Sorted Array:\n";
    for (int i = 0; i < l; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
