#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> weights;
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
        visited.resize(V, false);
        weights.resize(V, 0);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void makeGraph(int E)
    {
        int u, v;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            addEdge(u, v);
        }
    }
    void debugGraph()
    {
#ifndef ONLINE_JUDGE
        for (int i = 0; i < V; i++)
        {
            cerr << i << " -> ";
            for (int j : adj[i])
            {
                cerr << j << " ";
            }
            cerr << endl;
        }
#endif
    }
    vector<int> calculateDistance(int vertex)
    {
        vector<int> distance(V, 0);
        queue<int> q;
        q.push(vertex);
        distance[vertex] = 0;
        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            for (auto child : adj[parent])
            {
                if (distance[child] != -1)
                {
                    distance[child] = distance[parent] + 1;
                    q.push(child);
                }
            }
        }
        return distance;
    }
    void dfs(int vertex)
    {
        visited[vertex] = true;
        for (auto child : adj[vertex])
        {
            if (!visited[child])
            {
                dfs(child);
            }
        }
    }
    void bfs(int vertex)
    {
        queue<int> q;
        q.push(vertex);
        visited[vertex] = true;
        while (!q.empty())
        {
            int p = q.front();
            q.pop();
            for (auto child : adj[p])
            {
                if (!visited[child])
                {
                    visited[child] = true;
                    q.push(child);
                }
            }
        }
    }
};
