#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class list{
    public :
        int a, b;
        long long int cost;
    
    bool operator()(list a, list b){
        return a.cost < b.cost;
    }
};

vector <list> edge;
vector <int> par;
int find(int x){
    return (par[x]==x) ? x : par[x] = find(par[x]);
}

void uni(int a, int b){
    par[find(a)] = find(b);
}

int main(void){
    int N;
    cin >> N;
    par.resize(N+1);
    for(int i = 0; i< N+1; i++){
        par[i] = i;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            long long int x;
            cin >> x;
            if(i<j){
                list l;
                l.a = i;
                l.b = j;
                l.cost = x;
                edge.push_back(l);
            }
        }
    }
    sort(edge.begin(), edge.end(), list());
    long long int sum = 0;
    for(int i=0; i<edge.size(); i++){
        if(find(edge[i].a)!=find(edge[i].b)){
            uni(edge[i].a, edge[i].b);
            sum += edge[i].cost;
        }
    }
    cout << sum;
    
}
