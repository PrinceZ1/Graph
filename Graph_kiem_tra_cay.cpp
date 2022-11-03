/*Một đồ thị N đỉnh là một cây, nếu như nó có đúng N-1 cạnh và giữa 2 đỉnh bất kì, chỉ tồn tại duy nhất 1 đường đi giữa chúng. Cho một đồ thị vô hướng N đỉnh và M cạnh, hãy kiểm tra đồ thị đã cho có phải là một cây hay không?

Input Format

Dòng đầu tiên là số n, m tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Constraints

1<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra 1 nếu đồ thị đã cho là cây, ngược lại in ra 0.

Sample Input 0

6 5
4 3
2 1
6 5
5 4
3 2
Sample Output 0

1
Sample Input 1

6 4
6 3
3 2
4 2
6 4
Sample Output 1

0
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
bool DFS2(int u , int par)
{
    check[u] = 1;
    for(int x : v[u])
    {
        if(!check[x])
        {
            if(DFS2(x , u)) return true;
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
    int ans = 0;
    for(int i = 1 ; i <= n ;i++)
    {
        if(!check[i])
        {
            ++ans;
            DFS(i);
        }
    }
    if(ans == 1)
    {
        memset(check , 0 , sizeof(check));
        if(!DFS2(1 , 0)) cout << 1;
        else cout << 0;
    }
    else cout << 0;
}