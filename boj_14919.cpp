#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000;
int M;
int range[MAX];
int result[MAX];
int main(void)
{
        cin >> M;
        //기준
        double criteria = (double)1 / M + 0.0000000001;
        //범위의 한계를 지정
        for (int i = 0; i < M; i++)
        {
                 range[i] = (i + 1) * criteria * 1000000;
                 //(i + 1) * 1,000,000을 M으로 나누었을 때 소수점이 무한대로 늘어날 경우 1을 더해준다
                 if (((i + 1) * 1000000) % M)
                         range[i]++;
        }
        double num;
        do
        {
                 cin >> num;
                 num += 0.0000000001;
                 num *= 1000000;
 
                 //범위를 찾는다
                 if (0 <= num && num < range[0])
                         result[0]++;
                 else
                 {
                         for (int i = 1; i < M; i++)
                                 if (range[i - 1] <= num && num < range[i])
                                 {
                                          result[i]++;
                                          break;
                                 }
                 }
        } while (getc(stdin) == ' ');
        for (int i = 0; i < M; i++)
                 cout << result[i] << " ";
        cout << "\n";
        return 0;
}