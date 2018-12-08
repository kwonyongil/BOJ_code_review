#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp [1001][1001];
string str1, str2;
int main(void){
    cin >> str1 >> str2;
    for(int i=0; i<=str1.size(); i++){
        dp[i][0] = i;
    }
    for(int j=0; j<=str2.size(); j++){
        dp[0][j] = j;
    }
    for(int i=1; i<= str1.size(); i++){
        for(int j=1; j<= str2.size(); j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]+1));
            }
        }
    }
    cout << dp[str1.size()][str2.size()];  
}