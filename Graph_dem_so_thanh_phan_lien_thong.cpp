/*Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy đếm số thành phần liên thông của đồ thị.

Input Format

Dòng đầu tiên là 2 số n và m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Constraints

1<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra số thành phần liên thông của đồ thị

Sample Input 0

5 4
4 1
2 1
3 2
4 3
Sample Output 0

2
Sample Input 1

5 2
4 1
2 1
Sample Output 1

3
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
vector<int>v[maxn];
bool ok[maxn];

void BFS(int s)
{
    queue<int>Q;
    Q.push(s);
    ok[s] = true;
    while(!Q.empty())
    {
        int top = Q.front(); Q.pop();
        for(int x : v[top])
        {
            if(!ok[x])
            {
                Q.push(x);
                ok[x] = true;
            }
        }
    }
}
int main()
{
    int n , m ; cin >> n >> m ;
    for(int i = 1 ; i <= m ; i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ;i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(!ok[i])
        {
            ++ans;
            BFS(i);
        }
    }
    cout << ans;
}