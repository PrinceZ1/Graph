/*Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy đếm số lượng đỉnh trụ của đồ thị.

Input Format

Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Constraints

1=<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra số lượng đỉnh trụ của đồ thị

Sample Input 0

10 6
5 4
5 2
10 2
10 7
5 3
10 1
Sample Output 0

3
Explanation 0

3 đỉnh trụ của đồ thị là : 2, 5, 10
*/

#include <bits/stdc++.h>
using namespace std;

vector<int>v[1001];
int check[10001];

void DFS(int u)
{
    check[u] = 1;
    for(int x : v[u])
    {
        if(!check[x])
        {
            DFS(x);
        }
    }
}
int main()
{
    int n , m ; cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!check[i])
        {
            ++ans;
            DFS(i);
        }
    }
    int res = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        memset(check , 0 , sizeof(check));
        check[i] = 1; // loai bo dinh i;
        int dem = 0;
        for(int j = 1 ; j <= n ; j++)
        {
            if(!check[j])
            {
                ++dem;
                DFS(j);
            }
        }
        if(dem > ans) ++res;
    }
    cout << res;
}