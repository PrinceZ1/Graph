/*Cho đồ thị có hướng G = được biểu diễn dưới dạng danh sách cạnh. Hãy chuyển đổi đồ thị dưới dạng danh sách cạnh này sang danh sách kề tương ứng.

Input Format

Dòng đầu tiên là 2 số n và m, tương ứng với số lượng đỉnh và cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. M dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Constraints

1<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra n dòng, trong đó dòng thứ i in ra danh sách kề của đỉnh i. Các đỉnh trong danh sách kề được liệt kê từ nhỏ tới lớn.

Sample Input 0

5 10
4 2
4 1
2 5
3 4
1 5
2 3
5 1
2 1
1 4
4 5
Sample Output 0

1 : 4 5 
2 : 1 3 5 
3 : 4 
4 : 1 2 5 
5 : 1 
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n , m ; cin >> n >> m;
    vector<int>v[n + 1];
    for(int i = 1 ; i <= m ;i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        sort(v[i].begin() , v[i].end());
        cout << i << " : " ;
        for(int x : v[i]) cout << x << " ";
        cout << endl;
    }
}