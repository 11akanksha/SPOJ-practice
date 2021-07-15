#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

string calc(string s)
{
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            ans += st.top();
            st.pop();
        }
        else if (s[i] == '(')
        {
            continue;
        }
        else
        {
            ans += s[i];
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << calc(s) << endl;
    }
    return 0;
}