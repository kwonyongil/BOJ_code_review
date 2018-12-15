#include <iostream>
#include <string>
using namespace std;

int main(void){
    string str1;
    string str2;
    cin >> str1 >> str2;
    string temp_1, temp_2;
    temp_1 = str1;
    temp_2 = str2;
    for(int i=0; i<temp_1.size(); i++){
        if(temp_1[i]=='6')
            temp_1[i] = '5';
    }
    for(int j=0; j<str2.size(); j++){
        if(temp_2[j]=='6')
            temp_2[j] = '5';
    }
    
    int a = stoi(temp_1);
    int b = stoi(temp_2);
    cout << a+b << " ";
    string temp1, temp2;
    temp1 = str1;
    temp2 = str2;
    for(int i=0; i<temp1.size(); i++){
        if(temp1[i]=='5')
            temp1[i] = '6';
    }
    for(int j=0; j<str2.size(); j++){
        if(temp2[j]=='5')
            temp2[j] = '6';
    }
    int c = stoi(temp1);
    int d = stoi(temp2);
    cout << c+d;
    
}