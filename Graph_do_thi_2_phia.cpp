/*Trong Lý thuyết đồ thị, đồ thị hai phía là một đồ thị đặc biệt, trong đó tập các đỉnh có thể được chia thành hai tập không giao nhau thỏa mãn điều kiện không có cạnh nối hai đỉnh bất kỳ thuộc cùng một tập. Cho đồ thị vô hướng G = (V, E), hãy kiểm tra xem đồ thị đã cho có phải là đồ thị 2 phía hay không?image

Input Format

Dòng đầu tiên gồm 2 số n và m tương ứng với số đỉnh và số cạnh của đồ thị. M dòng tiếp theo là cạnh u-v, trong đó u khác v.

Constraints

1<=N<=1000; 1<=M<=N*(N-1)/2; 1<=u,v<=N;

Output Format

In ra YES nếu G là đồ thị 2 phía, ngược lại in NO

Sample Input 0

5 4
1 2
3 2
4 3
4 5
Sample Output 0

YES
Sample Input 1

6 5
2 1
2 3
3 4
5 4
1 6
Sample Output 1

YES
*/

#include <bits/stdc++.h>
using namespace std;
vector<int>v[10001];
int used[10001];
#define pb push_back
bool BFS(int s)
{
    queue<int>q;
    q.push(s); used[s] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop(); 
        for(int x : v[u])
        {
            if(!used[x])
            {
                used[x] = 3 - used[u];
                q.push(x); 
            }
            else if(used[x] == used[u]) return false;
        }
    }
    return true;
}
bool DFS(int s , int parent)
{
    used[s] = 1 - used[parent];
    for(int x : v[s])
    {
        if(used[x] == -1)
        {
            if(!DFS(x , s)) return false;
        }
        else if(used[x] == used[s]) return false;
    }
    return true;
}
int main()
{
    int n , m ; cin >> n >> m;
    for(int i = 1 ; i<= m ; i++)
    {
        int x , y ; cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    memset(used , -1 , sizeof(used));
    used[0] = 1;
    for(int i = 1 ;i  <= n ; i++)
    {
        if(used[i] == -1)
        {
            if(!DFS(i , 0))
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}