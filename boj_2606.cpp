#include <iostream>
#include <vector>
using namespace std;
int N, M;
int par[101];
int find(int x){
    return (x==par[x])? x : par[x] = find(par[x]);
}
void link(int a, int b){
    par[find(a)] = find(b);
}

int main(void){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        par[i] = i;
    }
    while(M--){
        int a, b;
        cin >> a >> b;
        if(find(a) != find(b)){
            link(a,b);
        }
    }
    int cnt = 0;
    for(int i=2; i<=101; i++){
        
        if(find(1) == find(i) && par[i]!=0){
            cnt++;
        }
    }
    cout << cnt;
}