/*Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy thực hiện in ra danh sách các đỉnh được duyệt theo thuật toán BFS(s).

Input Format

Dòng đầu tiên là 2 số n và m và s, tương ứng với số lượng đỉnh, cạnh của đồ thị và đỉnh bắt đầu duyệt. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Constraints

1<=s<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra các đỉnh được duyệt theo thuật toán BFS(s). Chú ý trong quá trình mở rộng các đỉnh của thuật toán BFS luôn lựa chọn duyệt các đỉnh có thứ tự nhỏ hơn trước.

Sample Input 0

5 7 5
4 1
5 3
4 3
5 1
3 2
4 2
2 1
Sample Output 0

5 1 3 2 4 
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
        cout << top << " ";
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
    int n , m , s ; cin >> n >> m >> s;
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
    BFS(s);
}