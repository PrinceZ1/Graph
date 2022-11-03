/*Cho đơn đồ thị vô hướng liên thông G = (V, E) gồm N đỉnh và M cạnh, các đỉnh được đánh số từ 1 tới N và các cạnh được đánh số từ 1 tới M. Có Q truy vấn, mỗi truy vấn yêu cầu bạn tìm đường đi ngắn nhất giữa đỉnh X tới Y.

Input Format

Dòng đầu tiên hai số nguyên N và M;
M dòng tiếp theo, mỗi dòng gồm 3 số nguyên u, v, c cho biết có cạnh nối giữa đỉnh u và v có độ dài bằng c.
Tiếp theo là số lượng truy vấn Q.
Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên X, Y.
Constraints

(1 ≤ N ≤ 100, 1 ≤ M ≤ N*(N-1)/2); (1 ≤ c ≤ 1000); Q (1 ≤ Q ≤ 100 000);

Output Format

Với mỗi truy vấn, in ra đáp án là độ dài đường đi ngắn nhất tìm được

Sample Input 0

5 6
1 2 6
1 3 7
2 4 8
3 4 9
3 5 1
4 5 2
3
1 5
2 5
4 3
Sample Output 0

8
10
3
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int OO = 1e9 + 7; 

vector<pair<int,int>>v[1001];
ll d[101][101];

void Dijkstra(int n , int m , int s)
{
    for(int i = 1 ; i <= n ; i++)
    {
        d[s][i] = OO;
    }
    d[s][s] = 0;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>q;
    q.push({0 , s});
    while(!q.empty())
    {
        int u = q.top().second;
        int du = q.top().first;
        q.pop();
        if(du != d[s][u]) continue;
        for(int i = 0 ; i < v[u].size() ; i++)
        {
            int a = v[u][i].second;
            int da = v[u][i].first;
            if(d[s][a] > da + du)
            {
                d[s][a] = da + du;
                q.push({d[s][a] , a});
            }
        }
    }
}

int main()
{
    int n , m , s ; cin >> n >> m ;
    for(int i = 1 ; i <= m ; i++) 
    {
        int x,y , z; cin >>x  >> y >> z;
        v[x].push_back({z , y});
        v[y].push_back({z , x});
    }
    for(int i = 1 ; i <= n ; i++)
    {
        Dijkstra(n , m , i);
    }
    int t; cin >> t;
    while(t--)
    {
        int a , b ; cin >> a >> b;
        cout << d[a][b] << endl;
    }
    return 0;
}