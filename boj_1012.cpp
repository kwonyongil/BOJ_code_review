#include <iostream>
#include <vector>
#include <cstring> //memset 사용(초기화)

using namespace std;

vector<vector<int>> graph; //그래프
vector<vector<bool>> visited; //dfs므로 방문확인
int x[4] = {1,0,-1,0}; //동서남북 x좌표
int y[4] = {0,-1,0,1}; //동서남북 y좌표
int M, N, K;
int cnt = 0; //지렁이 수

void DFS(int j, int i){
    visited[i][j] = true;   //방문했음
    
    for(int k=0; k<4; k++){ //동서남북으로체크
         if(j+x[k]>=0&&j+x[k]<M&&i+y[k]>=0&&i+y[k]<N) //x좌표 y좌표가 0<=x< M사이여야함 y도마찬가지
            if(visited[i+y[k]][j+x[k]]!=true&&graph[i+y[k]][j+x[k]]!=0) //방문안하고 0 아닌 애들
                DFS(j+x[k],i+y[k]);
    }
    return;
}

int main(void){
    int T;
    cin >> T;
    while(T—){
        cnt = 0;
        
        cin >> M >> N >> K;
        graph.resize(N,vector<int>(M));  //초기화
        visited.resize(N,vector<bool>(M)); //초기화
        while(K—){
            int a, b;
            cin >> a >> b;
            graph[b][a] = 1;
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(visited[i][j]!=true&&graph[i][j]!=0){
                    visited[i][j] = true;
                    DFS(j,i);
                    cnt++;
                }
            }
        }
        memset(&graph,0,sizeof(graph));  //전역으로쓴애들은 0으로 다시 초기화
        memset(&visited,0,sizeof(visited)); //전역으로쓴애들은 0==flase로 다시 초기화
        cout << cnt << endl;
    }    
}
