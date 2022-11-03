/*Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra đồ thị có liên thông mạnh hay không? Bài này các bạn thử cài đặt bằng 3 cách là : brute force, thuật toán Tarjan, thuật toán Kosaraju.

Input Format

Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Constraints

1=<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra 1 nếu đồ thị liên thông mạnh, ngược lại in ra 0.

Sample Input 0

6 14
3 4
3 1
2 5
2 6
4 6
2 3
5 6
1 5
1 2
3 5
4 5
6 3
4 2
1 4
Sample Output 0

1
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
vector<int>v[maxn] , r[maxn];
bool ok[maxn];
stack<int>st;

void dfs1(int s)
{
    ok[s] = true;
    for(int x : v[s])
    {
        if(!ok[x])
        {
            dfs1(x);
        }
    }
    st.push(s);
}
void dfs2(int s)
{
    ok[s] = true;
    for(int x : r[s])
    {
        if(!ok[x])
        {
            dfs2(x);
        }
    }
}
void init()
{
    int n , m ; cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
        r[b].push_back(a);
    }
    for(int i = 1 ; i <= n ;i++)
    {
        if(!ok[i])
        {
            dfs1(i);
        }
    }
    memset(ok , false , sizeof(ok));
    int ans = 0;
    while(!st.empty())
    {
        int top = st.top(); st.pop();
        if(!ok[top])
        {
            dfs2(top);
            ++ans;
        }
    }
    if(ans == 1) cout << 1;
    else cout << 0;
}
int main()
{
    init();
}