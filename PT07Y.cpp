#include <iostream>
#include <vector>
using namespace std;

bool dfs(int curr, int par, vector<bool> &vis, vector<vector<int>> &adj)
{
    if (vis[curr])
    {
        return false;
    }
    vis[curr] = true;
    for (auto ch : adj[curr])
    {
        if (ch != par)
        {
            bool res = dfs(ch, curr, vis, adj);
            if (res == false)
            {
                return false;
            }
        }
    }
    return true;
}

bool isaTree(vector<vector<int>> &adj, int n)
{
    vector<bool> visited(n + 1);
    if (dfs(1, -1, visited, adj) == false)
    {
        return false;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (isaTree(adj, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}