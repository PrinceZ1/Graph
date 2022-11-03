/*Cho cây với đỉnh gốc là đỉnh 1, các đỉnh của cây được đánh số từ 1 tới n. Độ cao của một nốt trong cây được tính bằng số cạnh trên đường đi ngắn nhất giữa nốt này tới đỉnh gốc. Như vậy, gốc của cây là đỉnh 1 sẽ có độ cao là 0. Nhiệm vụ của bạn là hãy xác định chiều cao của mọi nốt trong cây. Dưới đây là một ví dụ về cây.image

Input Format

Dòng đầu tiên là số n - số nốt của cây. N - 1 dòng tiếp theo mỗi dòng mô tả một cạnh của cây.

Constraints

1<=n<=1000;

Output Format

In ra độ cao của các nốt, từ nốt 1 tới nốt n.

Sample Input 0

7
1 2
2 3
3 4
1 5
5 6
1 7
Sample Output 0

0 1 2 3 1 2 1
*/

#include <bits/stdc++.h>
using namespace std;
vector<int>v[1001];
bool ok[1001];
int dinh[1001];
void DFS(int s , int hight)
{
    ok[s] = true;
    dinh[s] = hight;
    for(int x : v[s])
    {
        if(ok[x] == 0)
        {
            DFS(x , hight + 1);
        }
    }
}
int main()
{
    int n ; cin >> n;
    for(int i = 1 ; i < n ;i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(1 , 0);
    for(int i = 1 ; i <= n ; i++)
    {
        cout << dinh[i] << " ";
    }
}