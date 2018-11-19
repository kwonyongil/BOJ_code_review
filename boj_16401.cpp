#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long int> v;
long long int low = 1;
long long int high = 0;
int main(void){
    int a, b;
    cin >> a >> b;
    for(int i = 0; i<b; i++){
        long long int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    high = v[v.size()-1];

    long long int answer = 0;

    long long int mid = (low+high)/2;

    while(low <= high){
        int j = 0;
        for(int i=0; i<v.size(); i++){
            j +=v[i]/mid;
        }
        if(j>=a){
            answer = max(answer,mid);
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        mid = (low+high)/2;
        
    }
        cout << answer;
}
