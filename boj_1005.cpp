#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int answer = 0;

vector<int> arr;

int time_sum(int n,vector<int> build, vector<vector<int>> rule){
    int sum = 0;
    sum = build[n-1];
    int maxx = 0;
    for(int i=0; i<rule[n].size();i++){
        if(arr[rule[n][i]] == 999999)
            maxx = max(time_sum(rule[n][i],build,rule),maxx);
        else{
            maxx = max(arr[rule[n][i]],maxx);
        }
    }
    arr[n] = sum + maxx;
    return arr[n];
}

int main(void){
    
    auto T=0;
    cin >> T;
    while(T--){
        answer = 0;
        int n, r;
        cin >> n >> r;
        
        arr.resize(n+1);
        arr.assign(n+1,999999);
        vector<int> build;
        vector<vector<int>> rule;
        
        for(int i=0; i<n; i++){
            int t;
            cin >> t;
            build.push_back(t);
        rule.resize(n+1);
        for(int i=0; i<r; i++){
            int a, b;
            cin >> a >> b;
            rule[b].push_back(a);
        }
        int w;
        cin >> w;
        
        answer = time_sum(w,build,rule);
        cout << answer <<endl;
    }
}
