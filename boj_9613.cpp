#include <iostream>
#include <vector>

using namespace std;
int T;
int main(void){
    cin >> T;
    while(T--){
        int a;
        cin >> a;
        vector<int> v;
        for(int i=0; i<a; i++){
            int b;
            cin >> b;
            v.push_back(b);
        }
        long long int cnt = 0;
        for(int i=0; i<a-1; i++){
            for(int j=i+1; j<a; j++ ){
                int a = v[i];
                int b = v[j];
                int c;
                while(b){
                    c = a%b;
                    a = b;
                    b = c;
                }
                cnt += a;
            }
        }
        cout << cnt << '\n';
    }
}