#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> v;
int dp[1001];
int main(void){
    cin >> N;
    while(N--){
        int a;
        cin >> a;
        v.push_back(a);
    }
    dp[0] = 1;
    int a_max = 1;
    for(int i=1; i<v.size(); i++){
        int answer = 0;
        for(int j=i-1; j>=0; j--){
            if(v[i]>v[j]){
                answer = max(answer,dp[j]);
            }
        }
        dp[i] = answer +1;
        a_max = max(a_max,dp[i]);
    }
    cout << a_max;
}
