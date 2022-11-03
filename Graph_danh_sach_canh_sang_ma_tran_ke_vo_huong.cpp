/*Cho đồ thị vô hướng G = được biểu diễn dưới dạng danh sách cạnh. Hãy chuyển đổi đồ thị dưới dạng danh sách cạnh này sang ma trận kề tương ứng.

Input Format

Dòng đầu tiên là 2 số n và m, tương ứng với số lượng đỉnh và cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v tương ứng với một cạnh của đồ thị.

Constraints

1<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra ma trận kề theo mẫu.

Sample Input 0

5 4
4 3
3 1
4 2
5 4
Sample Output 0

0 0 1 0 0 
0 0 0 1 0 
1 0 0 1 0 
0 1 1 0 1 
0 0 0 1 0 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , m ; cin >> n >> m;
    int arr[n + 1][n + 1];
    memset(arr , 0 , sizeof(arr));
    for(int i = 1 ; i <= m ; i++)
    {
        int a , b ; cin >> a >> b;
        arr[a][b] = 1; arr[b][a] = 1;
    }
    for(int i = 1 ; i <= n ;i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}