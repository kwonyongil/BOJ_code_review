#include <iostream>
#include <vector>
using namespace std;
pair<char, char> tree[27];
void preorder(int x){
    char c = x + 'A'
    cout << c;
    if(tree[x].first!='.')
        preorder(tree[x].first-'A');
    if(tree[x].second!='.')
        preorder(tree[x].second-'A');
}
void midorder(int x){
    char c = x + 'A'

    if(tree[x].first!='.')
        midorder(tree[x].first-'A');
    cout << c;
    
    if(tree[x].second!='.')
        midorder(tree[x].second-'A');
}

void postorder(int x){
    char c = x + 'A'

    if(tree[x].first!='.')
        postorder(tree[x].first-'A');
    if(tree[x].second!='.')
        postorder(tree[x].second-'A');
    cout << c;
}

int main(void){
    int N;
    cin >> N;
    for(int i=0; i<26; i++){
        tree.first = '.';
        tree.second = '.';
    }
    while(N--){
        char a, b, c;
        cin >> a >> b >> c;
        int k = a - 'A'; 
        tree[k].first = b;
        tree[k].second = c;
    }
    
    preorder(0);
    cout << '\n';
    midorder(0);
    cout << '\n';    
    postorder(0);
    
}
