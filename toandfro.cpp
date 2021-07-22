#include <iostream>
#include <string.h>
using namespace std;

int main()
{
int n;
cin >> n;
while (n != 0)
{
    string s;
    cin >> s;
    char a[200][20];
    int cols = n, rows = s.length() / n, k = -1;
    for (int i = 0; i < rows; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < cols; j++)
            {
                k++;
                a[i][j] = s[k];
            }
        }
        else
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                k++;
                a[i][j] = s[k];
            }
        }
    }
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            cout << a[i][j];
        }
    }
    cout << endl;
    cin >> n;
}
return 0;
}
