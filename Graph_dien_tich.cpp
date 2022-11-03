/*Bạn được cung cấp một lưới 2D. Dấu '#' đại diện cho chướng ngại vật và dấu '.' đại diện cho không gian trống. Bạn cần tìm các khu vực của các thành phần bị ngắt kết nối. Các ô (i + 1, j), (i, j + 1), (i-1, j), (i, j-1) là các ô liền kề với ô (i, j).

Input Format

Dòng đầu tiên là n và m, tương ứng với số dòng và số cột của lưới 2D. N dòng tiếp theo, mỗi dòng là m kí tự '#'' hoặc '.'.

Constraints

1<=N,M<=1000;

Output Format

In ra diện tích các vùng không gian trống liền kề trên 1 dòng.

Sample Input 0

10 10
###.#.#..#
.######...
###..##.#.
.##...###.
##....#..#
.#..###...
..####.##.
...##.....
..#...####
.#..##.##.
Sample Output 0

1 1 8 1 11 1 17 9 1 1 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int n , m ,ans = 0;

char a[1001][1001];

int dx[] = {1 , 0 , 0 , -1};
int dy[] = {0 , 1 , -1 , 0};

void DFS(int i , int j)
{
    a[i][j] = '#';
    ++ans;
    for(int k = 0 ;k < 4 ; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        
        if(i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= m && a[i1][j1] == '.')
        {
            DFS(i1 , j1);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ;i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j  <= m ; j++)
        {
            if(a[i][j] == '.')
            {
                DFS(i , j);
                cout << ans << " ";
                ans = 0;
            }
        }
    }
    return 0;
}