#include <iostream>
#include <string.h>
using namespace std;

void iterative(string s)
{
    int *a = new int[s.length()];
    a[0] = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i - 1] == '0' && s[i] == '0')
        {
            a[i] = 0;
        }
        else if (s[i - 1] == '0' && s[i] != '0')
        {
            a[i] = a[i - 1];
        }
        else if (s[i - 1] != '0' && s[i] == '0')
        {
            if (s[i - 1] == '1' || s[i - 1] == '2')
            {
                a[i] = ((i >= 2) ? a[i - 2] : 1);
            }
            else
            {
                a[i] = 0;
            }
        }
        else
        {

            if ((s[i - 1] - '0') * 10 + (s[i] - '0') <= 26)
            {
                a[i] = a[i - 1] + ((i >= 2) ? a[i - 2] : 1);
            }
            else
            {
                a[i] = a[i - 1];
            }
        }
    }
    cout << a[s.length() - 1] << endl;
    delete[] a;
}

int main()
{
    string n;
    cin >> n;
    while (n != "0")
    {
        iterative(n);
        cin >> n;
    }
    return 0;
}
//Iterative : understood from https://www.youtube.com/watch?v=jFZmBQ569So