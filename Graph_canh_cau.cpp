/*Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy đếm số lượng cạnh cầu của đồ thị.

Input Format

Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị. Giữa 2 đỉnh bất kỳ chỉ tồn tại nhiều nhất một cạnh nối.

Constraints

1<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra số lượng cạnh cầu của đồ thị

Sample Input 0

10 6
10 1
5 2
10 5
10 6
5 3
10 4
Sample Output 0

6
Sample Input 1

10 8
10 9
10 8
10 3
10 4
5 3
10 1
5 1
5 4
Sample Output 1

2
*/

#include <bits/stdc++.h>
using namespace std;
vector<int>v[1001];
int check[1001];
int n , m;
void reset()
{
    for(int i = 0 ; i <= 1001 ; i++)
    {
        v[i].clear();
    }
    memset(check , 0 , sizeof(check));
}
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
int TPLT()
{
    int res = 0;
    for(int i = 1 ; i <= n ;i++)
    {
        if(!check[i])
        {
            ++res;
            DFS(i);
        }
    }
    return res;
}
int cnt = 0;
void tinh(int canh , int res , vector<pair<int,int>>tmp)
{
    for(int i = 0 ;i < m ; i++)
    {
        if(i != canh)
        {
            v[tmp[i].first].push_back(tmp[i].second);
            v[tmp[i].second].push_back(tmp[i].first);
        }
    }
    int dem = TPLT();
    if(dem > res) ++cnt;
}
int main()
{
    cin >> n >> m;
    vector<pair<int,int>>tmp;
    for(int i= 1 ; i <= m ; i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        tmp.push_back({a , b});
    }
    int ans = TPLT();
    for(int i = 0 ;i < m ; i++)
    {
        reset();
        tinh(i , ans , tmp);
    }
    cout << cnt;
}