#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N, M;
vector<vector<int>> v;
vector<pair<int,int>> h;
vector<pair<int,int>> c;

int dp[14];
int main(void){
    cin >> N >> M;
    v.resize(N,vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int a;
            cin >> a;
            v[i][j] = a;
            if(a==1){
                h.push_back(make_pair(i,j));
            }
            else if(a==2){
                c.push_back(make_pair(i,j));
            }
        }
    }
    sort(c.begin(),c.end());
    fill(dp, dp+M, 1);
    int sum = 9999999;
    do{
        int cnt = 0;
        for(int i=0; i<h.size(); i++){
            int cur = 999999;
            for(int j=0; j<c.size(); j++){
                if(dp[j]==0)
                    continue;
                int x = abs(c[j].first-h[i].first);
                int y = abs(c[j].second-h[i].second);
                cur = min(cur,x+y);
            }
            cnt += cur;
        }
        sum = min(sum,cnt);
    }while(prev_permutation(dp,dp+c.size()));

    cout << sum;
}
