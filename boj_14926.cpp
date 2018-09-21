#include <iostream>
#include <vector>

using namespace std;
vector<int> degree;
vector<vector<int>> Edge;
vector<vector<bool>> visited;
void dfs(int a){
    for(int i=0; i<Edge[a].size(); i++){
        if(degree[Edge[a][i]]>1 && visited[a][Edge[a][i]]!=true){
            degree[a]--;
            degree[Edge[a][i]]--;
            visited[Edge[a][i]][a]=true;
            visited[a][Edge[a][i]]=true;
            cout << 'a' << Edge[a][i]+1 << " ";
            dfs(Edge[a][i]);
            return;
        }
    }
    for(int i=0; i<Edge[a].size(); i++){
        if(degree[Edge[a][i]]==1 && visited[a][Edge[a][i]]!=true){
            cout << 'a' << Edge[a][i]+1 << " ";
            return;
        }
    }
}

int main(void){
    int n;
    cin >> n;
    degree.resize(n,n-1);
    visited.resize(n,vector<bool>(n));
    Edge.resize(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j)
                Edge[i].push_back(j);
        }
    }
    cout << 'a' << 1 << " ";
    dfs(0);
}