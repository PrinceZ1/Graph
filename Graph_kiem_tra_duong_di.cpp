/*Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh s và t có tồn tại đường đi tới nhau hay không ?

Input Format

Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị. Dòng tiếp theo là Q, Q dòng tiếp theo mỗi dòng chứa 2 đỉnh s, t cần truy vấn.

Constraints

1<=s,t<=n<=1000; 1<=m<=n*(n-1)/2; 1<=Q<=10000;

Output Format

Đối với mỗi truy vấn in ra 1 nếu có đường đi giữa s và t, ngược lại in ra -1.

Sample Input 0

5 3
5 4
4 1
4 3
3
4 5
4 2
3 4
Sample Output 0

1
-1
1
*/


#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
vector<int>v[maxn];
bool ok[maxn];
int parent[maxn] , size[maxn];
int find(int u)
{
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
bool Union(int a , int b)
{
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(size[a] < size[b]) swap(a , b);
    size[a] += b;
    parent[b] = a;
    return true;
}
int main()
{
    int n , m ; cin >> n >> m;
    for(int i = 1 ; i <= n ;i++) 
    {
        parent[i] = i;
        size[i] = 1;
    }
    for(int i = 1 ; i <= m ; i++)
    {
        int a , b ; cin >> a >> b;
        Union(a , b);
    }
    int q ; cin >>q;
    while(q--)
    {
        int a , b ; cin >> a >> b;
        if(parent[a] == parent[b])
        {
            cout << 1 << endl;
        }
        else cout << -1 << endl;
    }
}