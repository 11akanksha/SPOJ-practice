//GAVE TLE:
// #include <iostream>
// #include <vector>
// using namespace std;

// void dfs(int j, vector<vector<int>> &adj, vector<bool> &vis, int dis, vector<int> &distance)
// {
//     if (vis[j])
//         return;
//     vis[j] = true;
//     for (auto ch : adj[j])
//     {
//         dfs(ch, adj, vis, dis + 1, distance);
//     }
//     distance[j] = dis;
// }

// int main()
// {
//     int n, u, v;
//     cin >> n;

//     vector<vector<int>> adj(n + 1);

//     for (int i = 1; i < n; i++)
//     {
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int> maxDistByNode(n + 1);
//     for (int i = 1; i <= n; i++)
//     {
//         vector<bool> vis(n + 1);
//         vector<int> dis(n + 1);
//         dfs(i, adj, vis, 0, dis);
//         int max = 0;
//         for (int j = 1; j <= n; j++)
//         {
//             if (dis[j] > max)
//             {
//                 max = dis[j];
//             }
//         }

//         maxDistByNode[i] = max;
//     }
//     int max = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (maxDistByNode[i] > max)
//         {
//             max = maxDistByNode[i];
//         }
//     }
//     cout << max << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[10001];
bool vis[10001];

int maxD, farthest_node;
void dfs(int node, int d)
{
    vis[node] = true;
    if (d > maxD)
    {
        maxD = d;
        farthest_node = node;
    }
    for (auto ch : adj[node])
    {
        if (vis[ch] == false) //if the child is not visited
        {
            dfs(ch, d + 1);
        }
    }
}

int main()
{
    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    maxD = -1;
    dfs(1, 0);

    memset(vis, false, n + 1);
    maxD = -1;
    dfs(farthest_node, 0);

    cout << maxD;
    return 0;
}