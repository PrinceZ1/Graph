/*Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường đi theo thuật toán BFS từ đỉnh s tới đỉnh t. Trong qúa trình mở rộng của thuật toán BFS, luôn ưu tiên mở rộng đỉnh có số thứ tự nhỏ hơn.

Input Format

Dòng đầu tiên là 4 số n, m, s, t, tương ứng với số lượng đỉnh, cạnh của đồ thị, đỉnh bắt đầu và đỉnh kết thúc. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Constraints

1<=s,t<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra đường đi từ s tới t nếu có đường đi, trường hợp không tồn tại đường đi thì in ra -1.

Sample Input 0

5 4 2 4
4 2
2 1
3 1
4 3
Sample Output 0

2 4 
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
vector<int>v[maxn];
bool ok[maxn];
int parent[maxn];
void BFS(int s)
{
    queue<int>Q;
    Q.push(s);
    ok[s] = true;
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        for(int x : v[u])
        {
            if(!ok[x])
            {
                parent[x] = u;
                Q.push(x);
                ok[x] = true;
            }
        }
    }
}
void path(int s , int t)
{
    BFS(s);
    if(!ok[t])
    {
        cout << -1;
        return;
    }
    vector<int>duong;
    while(s != t)
    {
        duong.push_back(t);
        t = parent[t];
    }
    duong.push_back(s);
    reverse(duong.begin(), duong.end());
    for(int x : duong) cout << x << " ";
}
int main()
{
    int n , m , s , t ; cin >> n >> m >> s >> t;
    for(int i = 1 ; i <= m ; i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1 ; i <= n ;i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    path(s , t);
}