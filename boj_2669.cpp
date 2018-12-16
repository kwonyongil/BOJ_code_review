#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class rect{
    public :
        int x1, y1, x2, y2; // 왼쪽아래 x,y 오른쪽 위 x,y
}; //width와 height를 넣어도 되지만 이게더 편하다.

vector<rect> rects; // 사각형들 벡터
vector<int> X, Y; // x좌표 리스트, y좌표 리스트
int main(void){
    
    rects.resize(4);
    for(int i=0; i<4; i++){
        cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2; // rects벡터 완성
        X.push_back(rects[i].x1); // X벡터, Y벡터 완성
        X.push_back(rects[i].x2);
        Y.push_back(rects[i].y1);
        Y.push_back(rects[i].y2);
    }
    sort(X.begin(),X.end()); // X,Y를 정렬해야 차근차근 직사각형들을 계산해 나갈 수 있다.
    sort(Y.begin(),Y.end());
    int sum = 0;
    for(int i=0; i<X.size()-1; i++){
        for(int j=0; j<Y.size()-1; j++){
            for(int k=0; k<4; k++){
                if(X[i] >= rects[k].x1 && X[i+1] <= rects[k].x2 && Y[j] >= rects[k].y1 && Y[j+1] <= rects[k].y2){
                    //*정렬된 x,y좌표에서 i번째 i+1번째, j번째 j+1의 x,y가 모두 현재 있는 사각형안에 포함되어야 존재하는 면적이므로 이를 검사한 후 포함되면 넓이를 구한다!
                    sum += (X[i+1]-X[i])*(Y[j+1]-Y[j]);
                    break;
                }
            }
        }
    }
    cout << sum;
}