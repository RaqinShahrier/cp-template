#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5+7;

vector<int>g[N];
vector<bool>visited(N);
vector<vector<int>>connected_components;
vector<int>current_cc;


void dfs(int vertex){
    if(visited[vertex]){
        return;
    }
    visited[vertex] = true;
    current_cc.push_back(vertex);
    for(int child: g[vertex]){
        dfs(child);
    }
}



int32_t main(){
    int vertex_count = 7, edge_count = 5;
    vector<pair<int,int>>edges = {{1,7}, {2,5}, {2,1}, {3,7}, {4,6}};
    for(int i = 0; i<edge_count; i++){
        g[edges[i].first].push_back(edges[i].second);
        g[edges[i].second].push_back(edges[i].first);
    }
    for(int i = 1; i<=vertex_count; i++){
        if(visited[i]){
            continue;
        }
        dfs(i);
        connected_components.push_back(current_cc);
        current_cc.clear();
    }
    for(auto& component: connected_components){
        for(auto& vertex: component){
            cout<<vertex<<" ";
        }
        cout<<"\n";
    }
}

