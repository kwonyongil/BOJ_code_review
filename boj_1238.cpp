#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M, X;
vector<vector<pair<int,int>>> edge;
long long int dist[1001][1001];
int main(void){
    cin >> N >> M >> X;
    edge.resize(N+1);
    memset(dist, 9999999, sizeof(dist));
    while(M--){
        int a, b;
        long long int c;
        cin >> a >> b >> c;
        if(dist[a][b] > c)
            dist[a][b] = c;
    }
    
    for(int i=1;i<=N;i++)
        dist[i][i] = 0;
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(dist[i][k] > 999999 || dist[k][j] > 999999)
                    continue;
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    long long int answer = 0;
    for(int i=1; i<=N; i++){
        answer = max(answer, dist[i][X] + dist[X][i]);
    }
    cout << answer;
    
}