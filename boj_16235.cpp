#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;
int r[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int l[8] = {0, -1, -1, -1, 0, 1, 1, 1};
vector<vector<int>> v;
vector<vector<int>> d;
class tree{
    public :
        int age;
        int x, y;
        int die;
        bool operator()(tree a, tree b){
            return a.age < b.age;
        }
};
vector<tree> t;

int main(void){
    cin >> N >> M >> K;
    v.resize(N,vector<int>(N));
    d.resize(N,vector<int>(N));
    
    for(int i=0; i<N; i++)
        for(int j = 0; j<N; j++){
            d[i][j] = 5; //양분초기화
        }
    
    for(int i=0; i<N; i++)
        for(int j = 0; j<N; j++){
            int a;
            cin >> a;
            v[i][j] = a; // 추가되는 양분
        }
    
    for(int i=0; i<M; i++){
        int x, y, z;
        cin >> x >> y >> z;
         // 심어진 나무
        tree tr;
        tr.age = z;
        tr.x = x-1;
        tr.y = y-1;
        tr.die = 1;
        t.push_back(tr);
    }
    
    while(K--){
        sort(t.begin(),t.end(),tree());

        for(int k=0; k<t.size(); k++){
            if(t[k].die==1){
                if(t[k].age <= d[t[k].x][t[k].y]){
                    d[t[k].x][t[k].y] -= t[k].age;
                    t[k].age++;
                }
                else{
                    t[k].die = 2;
                }
            }
        }

        for(int k=0; k<t.size(); k++){
            if(t[k].die==2){
                d[t[k].x][t[k].y] += t[k].age/2;
                t[k].die = 0;
            }
        }

        for(int k=0; k<t.size(); k++){
            if(t[k].age%5==0 && t[k].die==1){
                for(int n=0; n<8; n++){
                    if(t[k].x+r[n] >= 0 && t[k].x+r[n] < N && t[k].y+l[n] >= 0 && t[k].y+l[n] < N){
                        tree tr;
                        tr.age = 1;
                        tr.x = t[k].x+r[n];
                        tr.y = t[k].y+l[n];
                        tr.die = 1;
                        t.push_back(tr);
                    }
                }
            }
        }
        
        vector<tree> temp;
        for(int k=0; k<t.size(); k++){
            if(t[k].die==1){
                temp.push_back(t[k]);
                
            }
        }
        t.clear();
        t = temp;
        sort(t.begin(),t.end(),tree());
        
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                d[i][j] += v[i][j];
        
    }
    int answer = 0;
    for(int k=0; k<t.size(); k++){
        if(t[k].die ==1)
            answer++;
    }

    cout << answer;
    
}