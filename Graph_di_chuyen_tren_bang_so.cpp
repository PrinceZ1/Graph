/*Cho một bảng số kích thước N x M. Chi phí khi đi qua ô (i,j) bằng A[i][j]. Nhiệm vụ của bạn là hãy tìm một đường đi từ ô (1, 1) tới ô (N, M) sao cho chi phí là nhỏ nhất. Tại mỗi ô, bạn được phép đi sang trái, sang phải, đi lên trên và xuống dưới.

Input Format

Dòng 1 bắt đầu bởi hai số nguyên N và M.
N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j]
Constraints

1 ≤ N, M ≤ 500.
(0 ≤ A[i][j] ≤ 9).
Output Format

In ra một số nguyên là chi phí nhỏ nhất cho đường đi tìm được.

Sample Input 0

6 7
0 3 6 0 5 9 1 
6 5 4 4 0 7 6 
4 0 2 1 5 6 1 
2 7 7 3 3 1 6 
4 4 9 6 9 7 2 
3 6 4 4 1 9 2 
Sample Output 0

28
Sample Input 1

4 5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
Sample Output 1

24
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[501][501];
void dijkstra(int n , int m)
{
    vector<vector<ll>>d(n + 1, vector<ll>(m + 1, 1e9 + 7));
    int dx[] = {1 , -1 , 0 , 0};
    int dy[] = {0 , 0 , -1 , 1};
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>Q;
    Q.push({a[1][1] , make_pair(1 , 1)});
    d[1][1] = a[1][1];
    while(!Q.empty())
    {
        pair<ll,pair<ll,ll>> top = Q.top(); Q.pop();
        if(d[top.second.first][top.second.second] < top.first) continue;
        for(int i = 0 ; i < 4 ; i++)
        {
            int i1 = dx[i] + top.second.first;
            int j1 = dy[i] + top.second.second;
            if(i1 < 1 || j1 < 1 || i1 > n || j1 > m) continue;
            if(d[i1][j1] > top.first + a[i1][j1])
            {
                d[i1][j1] = top.first + a[i1][j1];
                Q.push({d[i1][j1] ,make_pair(i1 , j1)});
            }
        }
    }
    cout << d[n][m];
}
int main()
{
    int n , m ; cin >> n >> m;
    for(int i = 1 ;i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
        }
    }
    dijkstra(n ,m);
}