#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
vector<vector<int>> v; //인접리스트
int arr[1001]; // B구역애들이 현재 연결되어있는 A노드 번호를 저장
bool visited[1001];//방문했는지 알려주는 배열(매칭시도마다 초기화)
bool dfs(int x){
    for(int i=0;i<v[x].size();i++){
        if(visited[v[x][i]]==false){ //방문안한것중
            visited[v[x][i]]=true; // 방문한것
            
            if(arr[v[x][i]]==-1 || dfs(arr[v[x][i]])){
                arr[v[x][i]] = x;  // -1이어도 그 값 넣고 dfs로 탐색중에도 그 값 넣음
                return true;
            }
        }
    }
    return false;
}

int main(void){
    int cnt=0; //최대매칭수
    int A, B;
    fill(arr,arr+1001,-1);
    cin >> A >> B;
    v.resize(A+1);

    for(int i=1;i<=A;i++){
        int k;
        cin >> k;
        for(int j=0; j<k; j++){
            int t;
            cin >> t;
            v[i].push_back(t);
        }
    }
        
    for(int i=1; i<v.size(); i++){
        if(dfs(i))
            cnt++;
        memset(visited,false,sizeof(visited)); //방문정보는 초기화
    }
    cout << cnt;
}
