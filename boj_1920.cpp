#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A, B;
vector<int> v;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> A;
    while(A--){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    cin >> B;
    while(B--){
        int b;
        cin >> b;
        if(binary_search(v.begin(),v.end(),b))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
        
    }
}