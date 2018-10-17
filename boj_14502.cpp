#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M;
vector<vector<int>> v;
vector<vector<bool>> visited;


int g_x[4] = {1, 0, -1, 0};
int g_y[4] = {0, 1, 0, -1};

int sum = 0;

int main(void){
    cin >> N >> M;
    v.resize(N,vector<int>(M));
    visited.resize(N, vector<bool>(M));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int a;
            cin >> a;
            v[i][j] = a;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            vector<vector<int>> temp = v;
            if(v[i][j]==0){
                v[i][j] = 1;
                for(int a=i; a<N; a++){
                    int b=0;
                    if(a==i)
                        b=j;
                    for(; b<M; b++){
                        vector<vector<int>> temp2 = v;
                        if(v[a][b]==0){
                            v[a][b] = 1;
                            for(int c=a; c<N; c++){
                                int d=0;
                                if(c==a)
                                    d=b;
                                for(; d<M; d++){
                                    vector<vector<int>> temp3 = v;
                                    if(v[c][d]==0){
                                        v[c][d] = 1;
                                        queue<pair<int,int>> q;
                                        for(int x=0; x<N; x++){
                                            for(int y=0; y<M; y++){
                                                if(v[x][y]==2){
                                                    visited[x][y] = true;
                                                    q.push(make_pair(x,y));
                                                    while(!q.empty()){
                                                        pair<int,int> s = q.front();
                                                        q.pop();
                                                        for(int u=0; u<4; u++){
                                                            if(s.first+g_x[u] >=0 && s.first+g_x[u] < N && s.second+g_y[u] >=0 && s.second+g_y[u] < M){
                                                                if(v[s.first+g_x[u]][s.second+g_y[u]]==0 && visited[s.first+g_x[u]][s.second+g_y[u]]==false){
                                                                    v[s.first+g_x[u]][s.second+g_y[u]] = 2;
                                                                    visited[s.first+g_x[u]][s.second+g_y[u]]=true;
                                                                    q.push(make_pair(s.first+g_x[u],s.second+g_y[u]));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        int cur = 0;
                                        for(int x=0; x<N; x++){
                                            for(int y=0; y<M; y++){
                                                if(v[x][y]==0)
                                                    cur += 1;
                                            }
                                        }
                                        sum = max(cur,sum);
                                    }
                                    v = temp3;
                                    for(int x=0; x<N; x++){
                                        for(int y=0; y<M; y++){
                                            visited[x][y] = false;
                                        }
                                    }
                                }
                            }
                        }
                        v = temp2;
                    }
                }
            }
            v = temp;
        }
    }
    cout << sum;
}
