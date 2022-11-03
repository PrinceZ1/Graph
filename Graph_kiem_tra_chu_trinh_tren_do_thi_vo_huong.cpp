/*Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy xác định xem đồ thị có tồn tại chu trình hay không? Bài này các bạn cài đặt bằng 3 phương pháp : DFS, BFS và DSU.

Input Format

Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Constraints

1<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra 1 nếu đồ thị tồn tại chu trình, ngược lại in ra 0.

Sample Input 0

10 11
10 5
10 4
10 1
10 3
5 2
5 4
10 8
5 3
5 1
10 6
10 9
Sample Output 0

1
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
vector<int>v[maxn];
bool ok[maxn];

bool DFS(int s , int par)
{
    ok[s] = true;
    for(int x : v[s])
    {
        if(!ok[x])
        {
            if(DFS(x , s)) return true;
        }
        else if(x != par) return true;
    }
    return false;
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
    for(int i = 1 ; i <= n ;i++)
    {
        if(!ok[i])
        {
            if(DFS(i , 0))
            {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
}