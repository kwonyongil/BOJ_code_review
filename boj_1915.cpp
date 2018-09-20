#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> dp;
int main(void){
    int a, b;
    int answer = 0;
    cin >> a >> b;
    
    dp.resize(a,vector<int>(b));
    for(int i=0; i<dp.size(); i++){
        string str;
        cin >> str;
        for(int j= 0; j< dp[i].size(); j++){
            dp[i][j] = str[j]-'0';
            answer = max(answer,dp[i][j]);
        }
    }
    for(int i=1; i<dp.size(); i++)
        for(int j=1; j<dp[i].size(); j++){
            if(dp[i][j]!=0)
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                answer = max(answer,dp[i][j]);
        }
    
    cout << answer*answer;
}