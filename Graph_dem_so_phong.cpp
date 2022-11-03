/*Bạn được đưa cho một bản đồ của một tòa nhà và nhiệm vụ của bạn là đếm số lượng phòng của tòa nhà đó. Kích thước của bản đồ là n × m hình vuông và mỗi hình vuông là sàn hoặc tường. Bạn có thể đi bộ sang trái, phải, lên và xuống qua các ô sàn.

Input Format

Dòng nhập đầu tiên có hai số nguyên n và m: chiều cao và chiều rộng của bản đồ. Khi đó có n dòng gồm m ký tự mô tả bản đồ. Mỗi ký tự là một trong hai ký tự '.' hoặc '#' tương ứng với sàn nhà và tường.

Constraints

1≤n,m≤1000

Output Format

In ra số nguyên duy nhất là số phòng của tòa nhà

Sample Input 0

6 6
..###.
...#..
#..#..
.##.#.
######
.#.##.
Sample Output 0

7
Sample Input 1

6 6
####.#
.#..##
.#..##
####..
#...##
.##..#
Sample Output 1

6
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

char arr[1001][1001];
int dx[] = {1 , 0 , 0 , -1};
int dy[] = {0 , 1 , -1 , 0};
int n , m;
void DFS(int i , int j)
{
    for(int k = 0 ;k < 4 ; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        
        if(i1 >= 0 && j1 >= 0 && i1 <= n && j1 <= m && arr[i1][j1] == '.')
        {
            arr[i1][j1] = '#';
            DFS(i1,j1);
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
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n ;i++)
    {
        for(int j = 1 ; j <= m; j++)
        {
            if(arr[i][j] != '#')
            {
                arr[i][j] = '#';
                ++ans;
                DFS(i , j);
            }
        }
    }
    cout << ans;
    return 0;
}