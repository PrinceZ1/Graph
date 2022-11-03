/*Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy xác định xem đồ thị có tồn tại chu trình hay không? Bài này các bạn cài đặt bằng 3 phương pháp : DFS, BFS và DSU.

Input Format

Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Constraints

1=<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra 1 nếu đồ thị tồn tại chu trình, ngược lại in ra 0.

Sample Input 0

10 13
6 5
6 3
6 1
6 2
9 5
3 9
9 7
3 7
3 2
6 7
6 9
3 5
6 8
Sample Output 0

0
Sample Input 1

10 16
9 10
6 4
6 1
6 3
9 2
3 9
9 4
3 8
3 5
6 7
6 10
9 6
6 8
3 7
6 5
9 7
Sample Output 1

1
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
vector<int>v[maxn];
bool ok[maxn];
int color[maxn];
bool DFS(int s)
{
    color[s] = 1;
    for(int x : v[s])
    {
        if(!color[x])
        {
            if(DFS(x)) return true;
        }
        else if(color[x] == 1) return true;
    }
    color[s] = 2;
    return false;
}

int main()
{
    int n , m ; cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1 ; i <= n ;i++)
    {
        if(color[i] == 0)
        {
            if(DFS(i))
            {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
}