/*Cho bàn cờ A cỡ nxn, một con mã ở ô (s, t) muốn di chuyển sang ô (u, v). Hãy tìm số bước tối thiểu để con mã có thể đến ô (u, v) hoặc xác định rằng con mã không thể đi tới nơi. Bàn cờ A được mô tả bằng các giá trị 0, 1, trong đó ô có giá trị 1 thì con mã có thể tự do di chuyển đến ô này, ngược lại nếu giá trị tại một ô của bàn cơ là 0 thì con mã không thể di chuyển đến ô này.

Input Format

Dòng đầu tiên là số nguyên dương N. Dòng thứ 2 gồm 4 số nguyên s, t, u, v. Dữ liệu đảm bảo ô (s, t) có giá trị 1. N dòng tiếp theo, mỗi dòng gồm N số nguyên mô tả bàn cờ.

Constraints

2<=n<=1000; 0<=A[i][j]<=1;

Output Format

In ra số bước đi tối tiểu của con mã hoặc in ra -1 nếu con mã không thể đi đến nơi.

Sample Input 0

10
6 7 8 9
0 1 1 0 1 0 1 0 1 0 
1 1 0 0 1 1 0 0 1 0 
1 1 0 1 1 0 0 1 0 0 
0 1 1 1 1 1 1 1 1 0 
0 0 1 0 0 1 1 1 1 1 
1 1 0 1 1 0 1 0 0 0 
1 0 0 0 0 1 1 0 1 1 
1 1 1 1 1 1 1 0 1 1 
1 0 0 1 1 1 0 1 1 1 
1 0 0 1 1 0 0 1 0 1 
Sample Output 0

4
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int arr[1001][1001];
struct Basic{
    int x ,y, cnt;
};
bool check(int x , int y , int n)
{
    if(x <= n && x >= 1 && y >= 1 && y <= n) return true;
    return false;
}
int BFS(int a ,int b , int c , int d ,int n)
{
    int dx[] = {1 , 1 , 2 , 2 , -1 , -1 , -2 , -2};
    int dy[] = {2 , -2 , 1 , -1 , 2 , -2 , 1 , -1};
    queue<Basic>q;
    q.push({a , b , 0});
    Basic t;
    int x , y;
    arr[a][b] = 0;
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        if(t.x == c && t.y == d)
        {
            return t.cnt;
        }
        for(int i = 0 ; i < 8 ; i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];
            if(check(x , y , n) && arr[x][y] == 1)
            {
                arr[x][y] = 0;
                 q.push({x , y , t.cnt + 1});
            }
        }
    }
    return -1;
}
int main()
{
    int n , a , b , c , d; cin >> n >> a >> b >> c >> d;
    for(int i = 1 ; i <= n ;i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << BFS(a , b , c , d , n);
    return 0;
}