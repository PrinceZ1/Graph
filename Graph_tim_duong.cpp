/*Cho một bảng S[][] kích thước N x M, bao gồm các ô trống, các vật cản. Ban đầu bạn ở vị trí S. Nhiệm vụ của bạn là hãy di chuyển tới vị trí T, sao cho số lần đổi hướng không quá hai lần. Các bạn có thể di chuyển từ 1 ô sang 4 ô chung cạnh với ô hiện tại và không có vật cản.

Input Format

Dòng 1 bắt đầu bởi hai số nguyên N và M. N dòng tiếp theo, mỗi dòng gồm M kí tự mô tả bảng S. Trong đó: ‘.’ là một ô trống, ‘*’ là vật cản, ‘S’ là vị trí xuất phát và ‘T’ là vị trí đích. (Chỉ có một vị trí S và T duy nhất).

Constraints

(1 ≤ N, M ≤ 500);

Output Format

In ra “YES” nếu tìm được đường đi, ra in “NO” trong trường hợp ngược lại.

Sample Input 0

9 6
**.*..
.**..T
.*..*.
.....*
...***
...*S.
*.....
****..
.....*
Sample Output 0

NO
Sample Input 1

6 10
S...*...**
...*.*....
......*.T.
.........*
...*.***..
....*.*...
Sample Output 1

YES
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 1;
int n , m , x , y;
char a[501][501];
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
bool DFS(int i , int j , int par , int dem)
{
    if(dem > 2) return false;
    for(int k = 0 ; k < 4 ; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 < 1 || j1 < 1 || i1 > n || j1 > m) continue;
        int tmp = dem;
        if(a[i1][j1] == '.')
        {
            a[i1][j1] = '*';
            int tmp = dem;
            if(k != par && a[i][j] != 'S') tmp += 1;
            if(DFS(i1 , j1 , k , tmp)) return true;
            a[i1][j1] = '.';
        }
        else if(a[i1][j1] == 'T')
        {
            if(k != par && a[i][j] != 'S') ++dem;
            if(dem <= 2) return true;
        }

    }
    return false;

}
int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ;j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'S')
            {
                x = i ; y = j;
            }
        }
    }  
    if(DFS(x , y , 1 , 0)) cout << "YES";
    else cout << "NO";
}