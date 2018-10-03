#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
int arr[312501];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    const unsigned int bi = 1;
    
    
    for(int i=0; i<T; i++){
        int a;
        cin >> a;
        
        if((arr[a/32]&(bi << (a-1)%32))){
            cout << a;
            return 0;
        }
        else{
            arr[a/32] |= (bi << (a-1)%32);
        }
    }
}
