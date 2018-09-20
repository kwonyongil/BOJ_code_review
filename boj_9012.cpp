#include <iostream>
#include <vector>

using namespace std;
int T;
int main(void){
    cin >> T;
    
    while(T--){
        bool flag = true;
        string str;
        cin >> str;
        vector<char> v;
        for(int i=0; i< str.size(); i++ ){
            if(str[i]=='(')
                v.push_back('(');
            else{
                if(v.size()==0){
                    flag = false;
                    break;
                }
                else{
                    v.pop_back();
                }
            }
        }
        (v.size() == 0 && flag == true) ? cout << "YES" << '\n' : cout << "NO" << '\n';
    }
}