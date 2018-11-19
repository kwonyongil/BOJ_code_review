#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M;
vector<vector<pair<int,int>>> edge;
int dist[501];
int main(void){
    cin >> N >> M;
    edge.resize(N+1);
    memset(dist, 9999999, sizeof(dist));
    
    while(M--){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b,c));
    }
    bool flag;
    for(int i=0; i<N; i++){ // 한노드에서 다른 노드로 가는 최대 간선은 최대 N-1개이지만 N번 검사시에도 값이 바뀐다면 음의 사이클이 존재한다는 뜻
        flag = false; // 해당 라운드(i) 에 갱신됬는지 여부!
        dist[1] = 0;
        for(int j =1; j<= N; j++ ){  // 각 노드에 대해 검사
            for(int k=0; k<edge[j].size(); k++){
                int t = edge[j][k].first; // 목적지
                int cost = edge[j][k].second;
                if(dist[j] >= 9999999)
                    continue;
                if(dist[t] > cost+dist[j]){
                    dist[t] = cost+dist[j];
                    flag = true;
                }
            }
        }
    }
    if(flag==true){
        cout << -1;
    }
    else{
        for(int i=2; i<=N; i++){
            if(dist[i]>= 999999)
                cout << -1 <<'\n';
            else
                cout << dist[i] << '\n';
        }
    }
}
