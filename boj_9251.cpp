#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;
int arr[MAX][MAX]; //dp
int main(void){
    string str1;
    string str2;
    cin >> str1 >> str2;
    for(int i=0; i<=str1.size(); i++)
        for(int j=0; j<=str2.size(); j++){
            if(i==0||j==0)
                arr[i][j] = 0;
            else if(str1[i-1]==str2[j-1])
                arr[i][j] = arr[i-1][j-1] + 1;
            else
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
        }
    cout << arr[str1.size()][str2.size()];
    
}
