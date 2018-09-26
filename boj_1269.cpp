#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
vector<int> A;
vector<int> B;
vector<int> result_inter;
vector<int> result_union;
int main(void){
    int a, b;
    cin >> a >> b;
    while(a--){
        int x;
        cin >> x;
        A.push_back(x);
    }
    while(b--){
        int y;
        cin >> y;
        B.push_back(y);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector<int>::iterator iter; // 안쓰임
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(result_inter,result_inter.begin()));
    
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(result_union,result_union.begin()));
    
    cout << result_union.size() - result_inter.size();
}
