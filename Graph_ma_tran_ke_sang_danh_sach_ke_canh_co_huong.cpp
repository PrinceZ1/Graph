/*Cho ma trận kề A[][] của đồ thị có hướng G = (V, E) chỉ bao gồm các số 0 hoặc 1. Hãy chuyển đổi đồ thị này thành danh sách cạnh và danh sách kề tương ứng.

Input Format

Dòng đầu tiên là n tương ứng với số lượng đỉnh của đồ thị. n dòng tiếp theo mỗi dòng gồm n số mô tả ma trận A

Constraints

1<=n<=1000

Output Format

Những dòng đầu tiên liệt kê danh sách cạnh theo thứ tự từ điển tăng dần. Sau đó cách ra 1 dòng và liệt kê danh sách kề, trong đó các đỉnh trong danh sách kề được in ra theo thứ tự tăng dần. Xem output mẫu để rõ hơn.

Sample Input 0

5
0 0 0 1 0 
1 0 1 1 1 
1 0 0 1 1 
1 0 0 0 0 
0 1 0 1 0 
Sample Output 0

1 4
2 1
2 3
2 4
2 5
3 1
3 4
3 5
4 1
5 2
5 4

1 : 4 
2 : 1 3 4 5 
3 : 1 4 5 
4 : 1 
5 : 2 4 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);cout.tie(NULL);cin.tie(NULL);
    int n ; cin >> n;
    vector<pair<int,int>>canh;
    vector<int>ke[n + 1];
    for(int i = 1 ; i <= n ;i++)
    {
        for(int j = 1 ; j <= n ;j++)
        {
            int x ; cin >> x;
            if(x)
            {
                canh.push_back({i , j});
                ke[i].push_back(j);
            }
        }
    }
    for(auto x : canh) cout << x.first << " " << x.second << endl;
    cout << endl;
    for(int i = 1 ; i <= n ;i++)
    {
        cout << i << " : " ;
        for(int x : ke[i]) cout << x << " ";
        cout << endl;
    }
}