#include <bits/stdc++.h>

using ll = long long int;
#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
using namespace std;
// bool path(int v1, int v2, vector<vector<int>> &graph, int n, vector<int> &ans, bool checked[])
bool directLine(int v1, int v2, vector<vector<int>> &graph)
{
    fo(j, size(graph[v1]))
    {
        if (graph[v1][j] == v2 && graph[v1][j] != 0)
        {
            // cout<<"Hello";
            return true;
        }
    }
    return false;
}
bool path(int v1, int v2, vector<vector<int>> &graph, int n, vector<int> &ans, vector<bool> &checked, int m)
{
    checked[v1 - 1] = true;
    if (directLine(v1, v2, graph))
    {
        // cout<<v1<<" joined to "<<v2<<endl;
        return true;
    }
    else if (v1 == v2)
    {
        return false;
    }
    else
    {
        fo(i, n)
        {
            if (directLine(v1, i + 1, graph) && checked[i] == false)
            {
                // cout<<"checking "<<i+1<<" to "<<v2<<endl;
                if (path(i + 1, v2, graph, n, ans, checked, m))
                {
                    // cout<<"pushed"<<i+1;
                    ans.pb(i + 1);
                    return true;
                }
                else
                {
                    checked[i] = true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int testCases;
    cin >> testCases;
    fo(t, testCases)
    {
        int n, m;
        cin >> n >> m;
        // n = vertices, m = edges;
        vector<int> edge(n + 1, 0);
        vector<vector<int>> graph(n + 1);
        // vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
        int minWeight = INT_MAX;
        int v1, v2;
        int *R1 = new int[m];
        int *R2 = new int[m];
        int *W = new int[m];
        fo(i, m)
        {
            int r1, r2, w;
            cin >> r1 >> r2 >> w;
            edge[r1]++;
            edge[r2]++;
            graph[r1].pb(r2);
            graph[r2].pb(r1);
            R1[i] = r1;
            R2[i] = r2;
            W[i] = w;
        }
        fo(i,n+1){
            for (auto x:edge){
            cout<<x<<" ";
            }
            cout<<endl;
            if(edge[i]==1){
                int x = graph[i][0];
                edge[x]--;
                fo(j,size(graph[x])){
                    if(graph[x][j]==i){
                        graph[x].erase(graph[x].begin()+j);
                        break;
                    }
                }
                graph[i].clear();
                edge[i]--;
                i = 0;
            }
        }
        
        fo(i, m)
        {
            if (edge[R1[i]] >= 2 && edge[R2[i]] >= 2)
            {
                if (minWeight > W[i])
                {
                    minWeight = W[i];
                    v1 = R1[i];
                    v2 = R2[i];
                }
            }
        }
        delete[] R1;
        delete[] R2;
        delete[] W;
        // cout<<v1<<" "<<v2<<" "<<minWeight<<endl;
        vector<bool> checked(n, false);

        fo(i, n)
        {
            checked[i] = false;
        }
        fo(j, m)
        {
            if (graph[v1][j]== v2)
            {
                graph[v1].erase(graph[v1].begin() + j);
                break;
            }
        }
        fo(j, m)
        {
            if (graph[v2][j] == v1)
            {
                graph[v2].erase(graph[v2].begin()+j);
                break;
            }
        }
        vector<int> ans;
        ans.pb(v2);
        bool yes = path(v1, v2, graph, n, ans, checked, m);
        ans.pb(v1);
        cout << minWeight << " " << size(ans) << endl;
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}