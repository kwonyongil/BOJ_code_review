#include <iostream>
#include <stack>
using namespace std;
int main(void){
    string A, B, str;
    cin >> A >> B;
    int i=A.size()-1;
    int j=B.size()-1;
    int c = 0;
    while(0 <= i || 0 <=j){
        int t;
        if(0 <= i && 0 <=j){
            t = A[i]-'0'+B[j]-'0'+c;
        }
        else if(0 > i || 0 <=j){
            t = B[j]-'0'+c;
        }
        else{
            t = A[i]-'0'+c;
        }

        if(t>= 10){
            str.push_back(t-10+'0');
            c=1;
        }
        else{
            str.push_back(t+'0');
            c=0;
        }
        if(A.size()!=i){
            i--;
        }
        if(B.size()!=j){
            j--;
        }
    }
    if(c==1)
        str.push_back('1');
    
    for(int i=str.size()-1; i>=0; i--){
        cout << str[i];
    }
}
