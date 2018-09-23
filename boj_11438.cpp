#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
const int MAX = 100001;
using namespace std;
int N, M;

bool visited[MAX]; // 인접리스트에서 방문안한거
int depth[MAX]; // 깊이정보
int ac[MAX][20]; // 조상 정보
vector<vector<int>> v; //인접리스트!!

void getTree(int x){
    for(int i=0; i<v[x].size();i++){
        if(visited[v[x][i]]==false){
            depth[v[x][i]] = depth[x]+1;
            ac[v[x][i]][0] = x;
            visited[v[x][i]] = true;
            getTree(v[x][i]);
        }
    }
    
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int answer = 1;
    cin >> N;
    v.resize(N+1);
    depth[0] = -1;
    depth[1] = 1;
    N--;
    while(N--){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visited[1] = true;
    getTree(1);
    for(int i=0; i<20; i++)
        for(int j=1; j<MAX; j++){
            if(ac[j][i] != 0)
                ac[j][i+1] = ac[ac[j][i]][i];
        }
  
    cin >> M;
    while(M--){ // 쿼리문 받기 시작
        int u, v;
        cin >> u >> v;
        int down, up;
        if(depth[u] > depth[v]){ //깊이 더 낮은애 찾아줌
            down = u;
            up = v;
        }
        else{ //깊이 더 낮은애
            down = v;
            up = u;
        }
        int diff = depth[down] - depth[up]; 
        for(int i= 0; diff; i++){      // 깊이 같도록 만들어주는 반복문
            if(diff%2 == 1)     // 차이가 홀수면 교정해주기 위해
                down = ac[down][i];    // 이부분이 약간 이해안됨 외우자
            diff = diff/2;
        }
        if(down==up){
            answer = down;
            cout << answer << '\n';
        }
        else{
            for(int i=19; i>=0; i--){  //공통조상을찾기 전 2^k 조상으로 한번에 이동하기위해 뒤에서 부터 for문돔
                if(ac[down][i] != 0 && ac[down][i] != ac[up][i]){
                    down = ac[down][i];
                    up = ac[up][i];
                }
            }
            //down와 up은 공통조상 바로 아래 에서 멈추게 되므로 부모가 공통조상이된다.
            answer = ac[down][0];
            cout << answer << '\n';
        }
    }    
}
