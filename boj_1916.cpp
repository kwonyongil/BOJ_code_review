#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int s, d;
priority_queue<pair<int,pair<int,int>>> pq;
vector<vector<pair<int,int>>> e;
int N, M;
int dist[1001];

int main(void){
    memset(dist, -1, sizeof(dist));
    cin >> N >> M;
    e.resize(N+1);
    for(int i = 0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back(make_pair(b,c));
        
    }
    
    cin >> s >> d;
    
    dist[s] = 0;
    
    priority_queue<pair<int,int>> pq;
    
    pq.push(make_pair(-dist[s], s));
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        for(int i=0; i<e[p.second].size(); i++){
            if(dist[e[p.second][i].first]==-1 || dist[e[p.second][i].first] > e[p.second][i].second-p.first){
                dist[e[p.second][i].first] = e[p.second][i].second-p.first;
                pq.push(make_pair(-dist[e[p.second][i].first], e[p.second][i].first));
            }
        }
    }
    cout << dist[d];
}
