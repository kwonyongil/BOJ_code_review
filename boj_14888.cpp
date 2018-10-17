#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num;
vector<int> icon;
int y=1;
long long int min_sum = 9999999999;
long long int max_sum = -9999999999;

int main(void){
    int a;
    cin >> a;
    while(a--){
        int b;
        cin >> b;
        num.push_back(b);
    }
    int p, s, m, d;
    cin >> p >> s >> m >> d;
    for(int i=0; i<p; i++)
        icon.push_back(0);
    for(int i=0; i<s; i++)
        icon.push_back(1);
    for(int i=0; i<m; i++)
        icon.push_back(2);
    for(int i=0; i<d; i++)
        icon.push_back(3);
    
    sort(icon.begin(),icon.end());

    long long int sum = num[0];
    
    for(int i=0; i<icon.size(); i++){
        if(icon[i]==0){
            sum += num[y];
            y++;
        }
        else if(icon[i]==1){
            sum -= num[y];
            y++;
        }
        else if(icon[i]==2){
            sum *= num[y];
            y++;
        }
        else{
            sum /= num[y];
            y++;
        }
    }
    min_sum = min(sum,min_sum);
    max_sum = max(sum,max_sum);
    
    while(next_permutation(icon.begin(),icon.end())){
        long long int sum = num[0];
        y = 1;
        for(int i=0; i<icon.size(); i++){
            if(icon[i]==0){
                sum += num[y];
                y++;
            }
            else if(icon[i]==1){
                sum -= num[y];
                y++;
            }
            else if(icon[i]==2){
                sum *= num[y];
                y++;
            }
            else{
                sum /= num[y];
                y++;
            }
        }
        min_sum = min(sum,min_sum);
        max_sum = max(sum,max_sum);
    }
    cout << max_sum << '\n';
    cout << min_sum;
}
