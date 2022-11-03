/*Cho đồ thị vô hướng G =(V, E) liên thông. Hãy in ra các cạnh của cây khung này theo thuật toán DFS bắt đầu từ đỉnh s. Thứ tự mở rộng cây khung của thuật toán DFS luôn mở rộng đỉnh có thứ tự nhỏ hơn trước.

Input Format

Dòng đầu tiên là n, m, và s tương ứng với số đỉnh, số cạnh và đỉnh gốc của cây khung. M dòng tiếp theo mỗi dòng là một cạnh của cây, dữ liệu đảm bảo cạnh chỉ nối giữa 2 đỉnh khác nhau.

Constraints

1<=s<=n<=1000; 1<=m<=n*(n - 1)/2;

Output Format

In ra các cạnh của cây khung theo thứ tự duyệt bằng thuật toán DFS theo từng dòng.

Sample Input 0

7 12 3
6 3
6 2
5 3
5 4
7 3
5 2
7 1
4 3
2 1
6 4
7 2
3 2
Sample Output 0

3->2
2->1
1->7
2->5
5->4
4->6
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

vector<int>v[100001];
int check[100001];
vector<string>duongdi;
void DFS(int s)
{
    check[s] = 1;
    for(int x : v[s])
    {
        if(!check[x])
        {
            string res = "";
            res += to_string(s) + "->" + to_string(x);
            duongdi.push_back(res);
            DFS(x);
        }
    }
}
int main()
{
    int n , m , s ; cin >> n >> m >> s;
    for(int i = 1 ; i <= m;i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);v[b].push_back(a);
    }
    for(int i = 1 ; i <= n ;i++)
    {
        sort(v[i].begin() , v[i].end());
    }
    DFS(s);
    for(auto x : duongdi)
    {
        cout << x << endl;
    }
    return 0;
}