#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int dp[1000001];

int main(void){
    
    int a;
    cin >> a;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    for(int i = 5; i<1000001; i++){
        int x=999999999; int y=999999999; int z=999999999;
        if(i%3==0)
            x= dp[i/3] +1;
        if(i%2==0)
            y = dp[i/2] +1;
        z = dp[i-1] +1;
        
        dp[i] = min(x,min(y,z));
    }
    cout << dp[a];
}
