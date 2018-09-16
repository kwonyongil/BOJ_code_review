#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;
vector<long> k;
int main(void){
    int a;
    cin >> a;
    while(a--){
        long b;
        cin >> b;
        k.push_back(b);
    }
    long answer = 99999999;
    
    long o = 0;
    for(int i=0; i<k.size()-1;i++){
        long y = k[i];
        
        auto q = lower_bound(k.begin()+i+1, k.end(), -y); // 0을 만들어주는 -k[i]를 찾고 없을 시 가까운값 구함
        if(q-k.begin()>=k.size())
                o = y+k[q-k.begin()-1];
        else if(k[q-k.begin()-1]!=y){
            if(abs(y+k[q-k.begin()])==min(abs(y+k[q-k.begin()]),abs(y+k[q-k.begin()-1]))){
                o = y+k[q-k.begin()];
            }
            else{
                o = y+k[q-k.begin()-1];
            }
        }
        else{
            o = y+k[q-k.begin()];
        }
        if(abs(answer)==min(abs(answer), abs(o))){
            answer = answer;
        }
        else{
            answer = o;
        }
        
    }
    cout << answer;
}