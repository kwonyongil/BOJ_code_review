#include <vector>
#include <algorithm>
#include <iostream>
#define NMAX 40001
using namespace std;
vector<vector<pair<int,int>>> v;
int ac[NMAX][20];
int depth[NMAX];
bool visited[NMAX];
int dist[NMAX];
void getNode(int i){
    for(int j=0; j<v[i].size(); j++){
        if(visited[v[i][j].first]==false){
            depth[v[i][j].first] = depth[i]+1;
            dist[v[i][j].first] = v[i][j].second + dist[i];
            ac[v[i][j].first][0] = i;
            visited[v[i][j].first]=true;
            getNode(v[i][j].first);
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    v.resize(N+1);
    for(int i=0; i<N-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    depth[1] = 1;
    visited[1] = true;
    getNode(1);
    for(int j=0; j<19; j++) //for문 순서 주의!!
        for(int i=1; i<=N; i++){
            ac[i][j+1] = ac[ac[i][j]][j];
        }
    int M;
    cin >> M;
    while(M--){
        int a, b;
        int bottom, top;
        int par;
        cin >> a >> b;
        if(depth[a]>depth[b]){
            bottom = a;
            top = b;
        }
        else{
            bottom = b;
            top = a;
        }
        int diff;
        diff = depth[bottom] - depth[top];
        for(int i=0; diff; i++){
            if(diff%2==1){
                bottom = ac[bottom][i];
            }
            diff /= 2;
        }
        if(bottom==top){
            // 같은경우
            par = bottom;
            cout << dist[a]+dist[b]-(2*dist[par]) << '\n';
        }
        else{
            for(int i=19; i>=0; i--){
                if(ac[bottom][i]!=0 && ac[bottom][i]!=ac[top][i]){
                    bottom = ac[bottom][i];
                    top = ac[top][i]; //break을 쓰면 안되는이유는 최소 공통 조상이어야하므로! 더내려가야함
                }
            }
            par = ac[top][0];
            cout << dist[a]+dist[b]-(2*dist[par]) << '\n';
        }
    }
}
