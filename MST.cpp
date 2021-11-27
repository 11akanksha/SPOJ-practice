#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adjacencyList[n + 1];
    bool visited[n + 1] = {};
    //Hence initially all values in the visited array are 0 (false)
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        adjacencyList[x].push_back(make_pair(y, wt));
        adjacencyList[y].push_back({x, wt});
    }
    //This will help us to select a minimum wt edge and the vertex connected to it
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    //Enter a node to start with
    cout << "Which node to start with?" << endl;
    int st;
    cin >> st;
    Q.push({0, st});
    //{Weight,Node}

    long long int mst = 0;
    while (!Q.empty())
    {
        pair<int, int> best = Q.top();
        Q.pop();
        int selectedWt = best.first;
        int pointingTo = best.second;
        //Not an active edge:
        if (visited[pointingTo])
            continue;
        //An active edge:
        mst += selectedWt;
        visited[pointingTo] = true;
        //pointingTo is visited now
        for (auto x : adjacencyList[pointingTo])
        {
            //if its neighbour is not visited:
            if (!visited[x.first])
            {
                Q.push({x.second, x.first});
            }
        }
    }
    cout << mst << endl;
    return 0;
}
