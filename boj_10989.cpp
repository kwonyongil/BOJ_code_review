#include <vector>
#include <iostream>
using namespace std;
int T;
vector<int> v(10001);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        int a;
        cin >> a;
        v[a]++;
    }
    for(int i=0; i<10001; i++){
        int k = v[i];
        while(k--){
            cout << i << '\n';
        }
    }
}
