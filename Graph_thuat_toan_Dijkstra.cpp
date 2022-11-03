/*Cho đồ thị vô hướng có trọng số không âm G= (V, E) được biểu diễn dưới dạng danh sách cạnh trọng số. Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh s đến tất cả các đỉnh còn lại trên đồ thị. Dữ liệu đảm bảo có đường đi từ đỉnh s tới mọi đỉnh khác trên đồ thị.

Input Format

Dòng đầu tiên là n m và s tương ứng với số lượng đỉnh, cạnh và đỉnh bắt đầu. M dòng tiếp theo là các dòng mô tả cạnh của đồ thị.

Constraints

1<=n<=1000; 1<=m<=n*(n-1)/2; Trọng số các cạnh là số nguyên không âm không vượt quá 100;

Output Format

In ra đường đi ngắn nhất từ đỉnh u tới mọi đỉnh còn lại

Sample Input 0

10 44 5
7 5 60
9 8 31
9 1 83
4 3 25
6 2 1
4 1 52
6 3 76
7 6 95
9 7 84
8 2 91
10 7 8
6 4 32
10 2 76
3 1 62
10 6 88
8 3 12
5 3 15
5 4 40
9 2 20
3 2 5
5 1 36
9 4 98
8 6 65
8 5 95
10 3 55
9 6 95
10 1 5
4 2 70
7 1 80
10 4 35
7 2 99
10 9 24
6 5 94
2 1 77
8 1 12
8 4 76
9 3 27
5 2 5
9 5 12
10 5 1
8 7 59
6 1 1
10 8 92
7 3 54
Sample Output 0

6 5 10 35 0 6 9 18 12 1 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1001;
const int INF = 1e9 + 1;
vector<pair<ll,ll>>v[maxn];
ll d[maxn];

void dijkstra(int s , int n)
{
    for(int i = 1 ; i <= n ;i++)
    {
        d[i] = INF;
    }
    priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>>>Q;
    d[s] = 0;
    Q.push({0 , s});
    while(!Q.empty())
    {
        pair<ll,ll>top = Q.top(); 
        int w = top.first;
        int u = top.second;
        Q.pop();
        if(d[u] < w) continue;
        for(auto x : v[u])
        {
            ll z = x.first;
            ll y = x.second;
            if(d[z] > y + w)
            {
                d[z] = y + w;
                Q.push({d[z] , z});
            }
        }
    }
    for(int i = 1 ; i <= n ;i++) cout << d[i] << " ";
}

int main()
{
    int n , m , s ; cin >> n >> m >>s;
    for(int i = 1 ; i <= m ;i++)
    {
        int a , b , c ; cin >> a >> b >> c;
        v[a].push_back({b , c});
        v[b].push_back({a , c});
    }
    dijkstra(s , n);
}