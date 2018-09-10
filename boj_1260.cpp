#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int>> edge;
vector<bool> visited;
vector<bool> visited2;

queue<int> q;

void dfs(int n){
    cout << n << " ";
    vector<int> vec;
    for(int i=0; i<edge[n].size(); i++){
        vec.push_back(edge[n][i]);
    }
    sort(vec.begin(),vec.end());
    for(int i=0; i<vec.size(); i++){
        if(visited[vec[i]]!=true){
            visited[vec[i]]=true;
            dfs(vec[i]);
        }
    }
}

int main(void){
    int n, e, start;
    cin >> n >> e >> start;
    edge.resize(n+1);
    visited.resize(n+1);
    visited2.resize(n+1);
    while(e--){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    visited[start] = true;
    dfs(start);
    cout << endl;
    
    visited2[start]=true;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        vector<int> vec2;
        for(int i=0;i<edge[cur].size();i++){
            vec2.push_back(edge[cur][i]);
        }
        sort(vec2.begin(),vec2.end());
        for(int i=0;i<vec2.size();i++){
            if(visited2[vec2[i]]!=true){
                visited2[vec2[i]]=true;
                q.push(vec2[i]);
            }
        }
    }   
}