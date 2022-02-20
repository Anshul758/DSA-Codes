#include<iostream>
#include <list>
#include <limits.h>
#include<bits/stdc++.h>

using namespace std;

// for directed graph

vector<int> adj[20009];

bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        vector<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;  
    return false;
}




int main()
{
    int n, m;
    cin>>n>>m;

    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    int x,y;
    for(int i=0; i<m; i++) {
    	cin>>x>>y;

    	adj[x].push_back(y);
    }

    bool check = false; 

    for(int i = 0; i < n; i++)
        if (isCyclicUtil(i, visited, recStack))
            check = true;

    if(check)
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
