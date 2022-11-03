/*Cho đồ thị vô hướng G =(V, E) liên thông. Hãy in ra các cạnh của cây khung này theo thuật toán BFS bắt đầu từ đỉnh s. Thứ tự mở rộng cây khung của thuật toán BFS luôn mở rộng đỉnh có thứ tự nhỏ hơn trước.

Input Format

Dòng đầu tiên là n, m, và s tương ứng với số đỉnh, số cạnh và đỉnh gốc của cây khung. M dòng tiếp theo mỗi dòng là một cạnh của cây, dữ liệu đảm bảo cạnh chỉ nối giữa 2 đỉnh khác nhau.

Constraints

1<=s<=n<=1000; 1<=m<=n*(n - 1)/2;

Output Format

In ra các cạnh của cây khung theo thứ tự duyệt bằng thuật toán BFS theo từng dòng.

Sample Input 0

9 18 4
9 3
5 4
5 1
5 2
7 5
4 3
8 5
4 2
2 1
9 4
7 2
8 6
9 7
4 1
6 1
9 1
6 3
7 1
Sample Output 0

4->1
4->2
4->3
4->5
4->9
1->6
1->7
5->8
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

vector<int>v[100001];
int check[100001];
vector<string>duongdi;
void BFS(int s)
{
    queue<int>q;
    q.push(s) ; check[s] = 1;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int x : v[u])
        {
            if(!check[x])
            {
                string res = "";
                res += to_string(u) + "->" + to_string(x);
                duongdi.push_back(res);
                q.push(x);
                check[x] = 1;
            }
        }
    }
}
int main()
{
    int n , m , s ; cin >> n >> m >> s;
    for(int i = 1 ; i <= m;i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);v[b].push_back(a);
    }
    for(int i = 1 ; i <= n ;i++)
    {
        sort(v[i].begin() , v[i].end());
    }
    BFS(s);
    for(auto x : duongdi)
    {
        cout << x << endl;
    }
    return 0;
}