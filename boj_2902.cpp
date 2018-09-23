#include <cstring>
#include <iostream>
#include <string>
using namespace std;
    char a[1000];

int main(void){
    string str;
    cin >> str;

    char *token = strtok(&str[0],"-");
    while(token!=NULL){
        a[0] = *token;
        cout << a[0];
        token = strtok(NULL,"-");
    }
}