#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
bool flag;
vector<vector<int>> v;
vector<vector<int>> map;
int sum = 0;

void game(int k, int cnt){

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            map[i][j]=0;
    if(k==0){
        for(int j= N-1; j>=0; j--){
            for(int i=0; i<N; i++){
                if(v[i][j]!=0){
                    for(int t=j+1; t<N; t++){
                        if(v[i][t]==v[i][j]&&map[i][t]==0){ //숫자가 같고 합쳐진거아니면
                            v[i][j] = 0;
                            v[i][t] += v[i][t];
                            map[i][t] = 1;
                            flag = true;
                            break;
                        }
                        else if(v[i][t]==0)
                            continue;
                        else{    // 이미 합쳐진거거나 같은 숫자 아니면
                            int temp = v[i][j];
                            v[i][j] = 0;
                            v[i][t-1] = temp;
                            flag = true;
                            break;
                        }
                    }
                    if(flag!=true){
                        int temp = v[i][j];
                        v[i][j] = 0;
                        v[i][N-1] = temp;
                    }
                    flag = false;
                }
            }
        }
    }
    else if(k==1){
        for(int i=N-1; i>=0; i--){
            for(int j=0; j<N; j++){
                if(v[i][j]!=0){
                    for(int t=i+1; t<N; t++){
                        if(v[t][j]==v[i][j]&&map[t][j]==0){ //숫자가 같고 합쳐진거아니면
                            v[i][j] = 0;
                            v[t][j] += v[t][j];
                            map[t][j] = 1;
                            flag = true;
                            break;
                        }
                        else if(v[t][j]==0)
                            continue;
                        else{    // 이미 합쳐진거거나 같은 숫자 아니면
                            int temp = v[i][j];
                            v[i][j] = 0;
                            v[t-1][j] = temp;
                            flag = true;
                            break;
                        }
                    }
                    if(flag!=true){
                        int temp = v[i][j];
                        v[i][j] = 0;
                        v[N-1][j] = temp;
                    }
                    flag = false;
                }
            }
        }
    }
    else if(k==2){
        for(int j=0; j<N; j++){
            for(int i=0; i<N; i++){
                if(v[i][j]!=0){
                    for(int t=j-1; t>=0; t--){
                        if(v[i][t]==v[i][j]&&map[i][t]==0){ //숫자가 같고 합쳐진거아니면
                            v[i][j] = 0;
                            v[i][t] += v[i][t];
                            map[i][t] = 1;
                            flag = true;
                            break;
                        }
                        else if(v[i][t]==0)
                            continue;
                        else{    // 이미 합쳐진거거나 같은 숫자 아니면
                            int temp = v[i][j];
                            v[i][j] = 0;
                            v[i][t+1] = temp;
                            flag = true;
                            break;
                        }
                    }
                    if(flag!=true){
                        int temp = v[i][j];
                        v[i][j] = 0;
                        v[i][0] = temp;
                    }
                    flag = false;
                }
            }
        }
    }
    else{
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(v[i][j]!=0){
                    for(int t=i-1; t>=0; t--){
                        if(v[t][j]==v[i][j]&&map[t][j]==0){ //숫자가 같고 합쳐진거아니면
                            v[i][j] = 0;
                            v[t][j] += v[t][j];
                            map[t][j] = 1;
                            flag = true;
                            break;
                        }
                        else if(v[t][j]==0)
                            continue;
                        else{    // 이미 합쳐진거거나 같은 숫자 아니면
                            int temp = v[i][j];
                            v[i][j] = 0;
                            v[t+1][j] = temp;
                            flag = true;
                            break;
                        }
                    }
                    if(flag!=true){
                        int temp = v[i][j];
                        v[i][j] = 0;
                        v[0][j] = temp;
                    }
                    flag = false;
                }
            }
        }
    }
    if(cnt==5){
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                sum = max(sum,v[i][j]);
        return;
    }
    vector<vector<int>> temp = v;
    v = temp;
    game(0,cnt+1);
    v = temp;
    game(1,cnt+1);
    v = temp;
    game(2,cnt+1);
    v = temp;
    game(3,cnt+1);
}
int main(void){
    
    cin >> N;
    map.resize(N,vector<int>(N));
    v.resize(N,vector<int>(N));

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            int a;
            cin >> a;
            v[i][j] = a;
        }
    
    vector<vector<int>> temp = v;
    v = temp;
    game(0,1);
    v = temp;
    game(1,1);
    v = temp;
    game(2,1);
    v = temp;
    game(3,1);
    
    cout << sum;
}
