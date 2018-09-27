#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int arr[MAX];

int find(int x){
    if(x == arr[x])
        return x;
    else{
        return arr[x]=find(arr[x]);
    }
}

void link(int x, int y){
    arr[find(x)] = find(y);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<MAX; i++)
        arr[i] = i;
    
    int N, M;
    cin >> N >> M;
    while(M--){
        int a;
        cin >> a;
        if(a==0){
            int x, y;
            cin >> x >> y;
            link(x,y);
        }
        else{
            int x, y;
            cin >> x >> y;
            if(find(x)==find(y))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
}
