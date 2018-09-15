#include <iostream>
#include <map>
#include <cctype>
#include <string>
using namespace std;
int N, M;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    map<int,string> map_1;
    map<string,int> map_2;
    for(int i=1; i<=N; i++){
        string str;
        cin >> str;
        map_1.insert(make_pair(i,str));
        map_2.insert(make_pair(str,i));
    }
    for(int i=0; i<M; i++){
        string str2;
        cin >> str2;
        int k;
        if(isdigit(str2[0])){   //isdigit은 char형만됨!
            k = stoi(str2);
            auto iter = map_1.find(k);
            cout << iter->second << '\n';
        }
        else{
            auto iter = map_2.find(str2);
            cout << iter->second << '\n';
        }
    }
}
