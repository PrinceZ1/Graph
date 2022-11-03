/*Cho mê cung A có n hàng, n cột. Một con chuột xuất phát từ ô (s, t) và di chuyển tới ô (u, v). Nhiệm vụ của bạn là xác định số bước đi tối thiểu để con chuột con thể di chuyển từ ô (s, t) tới ô (u, v) hoặc xác định rằng không thể tìm được đường tới ô (u, v). Mê cung A chỉ bao gồm các số 1 hoặc 0. Trong đó 1 đại diện cho đường đi và 0 đại diện cho vật cản, con chuột chỉ có thể di chuyển từ ô hiện tại sang các ô chung đỉnh với nó và có đường đi.

Input Format

Dòng đầu tiên là số nguyên dương N. Dòng thứ 2 gồm 4 số nguyên s, t, u, v. Dữ liệu đảm bảo ô (s, t) có giá trị 1. N dòng tiếp theo, mỗi dòng gồm N số nguyên mô tả mê cung A.

Constraints

2<=n<=1000; 0<=A[i][j]<=1;

Output Format

In ra số bước đi tối tiểu của con chuột hoặc in ra -1 nếu con chuột không thể đi đến nơi.

Sample Input 0

10
9 6 9 3
1 1 0 1 1 1 1 0 0 1 
0 0 1 0 0 1 0 1 0 1 
1 1 1 1 0 0 0 1 1 0 
1 0 0 0 1 0 0 0 1 1 
1 0 1 0 0 1 0 1 1 0 
0 0 1 1 0 1 0 0 0 0 
1 1 0 1 0 1 1 0 0 0 
0 0 0 1 1 0 1 1 0 1 
1 0 1 0 0 1 0 0 1 1 
0 1 1 1 1 0 1 0 1 1 
Sample Output 0

3
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int arr[1001][1001];
struct Basic{
    int x , y , cnt;
};
bool check(int x , int y , int n)
{
    if(x <= n && y <= n && x >= 1 && y >= 1) return true;
    return false;
}
int BFS(int a , int b , int c , int d , int n)
{
    int dx[] = {1 , 1 , 1 , 0 , 0 , -1 , -1 , -1};
    int dy[] = {0 , 1 , -1 , 1 , -1 , 1 , 0 , -1};
    
    queue<Basic>q;
    q.push({a , b , 0});
    arr[a][b] = 0;
    Basic t;
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        
        if(t.x == c && t.y == d) return t.cnt;
        
        for(int i = 0 ; i < 8 ; i++)
        {
            int x = t.x + dx[i];
            int y = t.y + dy[i];
            
            if(check(x , y , n) && arr[x][y])
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
    int n , a , b , c ,d ; cin >> n >> a >> b >>c >> d;
    for(int i = 1 ; i <= n ;i++)
    {
        for(int j = 1 ; j <= n ;j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << BFS(a , b , c , d , n);
    return 0;
}