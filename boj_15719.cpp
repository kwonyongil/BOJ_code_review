#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main(void){
    vector<int> result; // 몇번째 위치에서 찾았는지
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    
    
    vector<int> pi(1000001,0); // 0으로 초기화한 접두 접미사 일치 배열 정보,
    int j=0;
    for(int i=1; i<str2.size(); i++){  // 실패 함수 만드는 함수, 실패함수는 작은 문자열 기준!!!!!!!
        while(j > 0 && str2[i] != str2[j])  // j는 접두사
            j = pi[j-1];  // 맞았던 곳 까지 바로 가서 비교
        if(str2[i] == str2[j])  // i는 접미사
            pi[i] = ++j;
    }
    
    j=0;
    for(int i=0; i<str1.size(); i++){ // i가 긴 글
        // 현재 글자가 불일치하면 fail 값을 계속 따라감
        while(j > 0 && str1[i] != str2[j])
            j = pi[j-1]; //j 짧은글이 맞았던 곳 +1 까지 j를 이동후 비교 시작
        if(str1[i] == str2[j]){  // 현재 글자가 일치
            if(j == str2.size()-1){   // 맞은 j가 짧은글 마지막이면 다 찾음!
                result.push_back(i-j+1);
                j = pi[j]; // 찾지 못한 것처럼 j 짧은글이 맞았던 곳 +1까지 j를 이동시키면 됨
            }
            else
                j++; // 똑같은데 마지막꺼아니면 다음꺼 또 보면된다.
        }
    }
    
    cout << result.size() << "\n";
    for (auto i : result)
        cout << i << " ";
    
}
