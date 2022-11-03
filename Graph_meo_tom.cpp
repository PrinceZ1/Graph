/*Chú mèo Tom đang ở gốc 1 cây với nhiều lá và cành. Cái cây này có rất nhiều lá và các đỉnh trung gian. Ở các nốt lá có treo các con cá và mèo Tom mong muốn ăn được nhiều cá nhất có thể vì thế nó dự định sẽ trèo từ gốc cây tương ứng với đỉnh 1 và đi lần lượt tới các nốt lá để ăn cá, nhưng trên đường đi từ nốt gốc lên nốt lá, mèo Tom phải đi qua các nốt trung gian. Các nốt trung gian này sẽ có những con gián và mèo Tom chỉ có thể đi đến các nốt lá để ăn cá nếu trên đường đi từ nốt gốc tới nốt lá có không quá m con gián liên tiếp. Bạn hãy giúp Tom đếm số cá tối đa mà nó có thể ăn được nhé.

Input Format

Dòng đầu tiên là n và m, tương ứng với số lượng nốt của cây và số con gián liên tiếp. Dòng thứ 2 gồm n số có giá trị 1 hoặc 0, tương ứng với vị trí ở nốt thứ i có hoặc không có con gián. N - 1 dòng tiếp theo mỗi dòng là mô tả 1 cạnh của cây.

Constraints

2<=n<=1000; 1<=m<=n;

Output Format

In ra số con cá tối đa mèo Tom có thể ăn

Sample Input 0

7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7
Sample Output 0

2
*/

#include <bits/stdc++.h>
using namespace std;
vector<int>v[1001];
int cat[1001];
int cnt = 0;
void DFS(int s , int par , int dem , int m)
{
    if(dem > m) return;
    if(v[s].size() == 1 && s != 1)
    {
        ++cnt;
    }
    for(int x : v[s])
    {
        if(x != par)
        {
            if(cat[x])
            {
                DFS(x , s , dem + 1 , m);
            }
            else DFS(x , s , 0 , m);
        }
    }

}
int main()
{
    int n , m ; cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> cat[i];
    }
    for(int i = 1 ; i < n ;i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(1 , 1 , cat[1] , m);
    cout << cnt;
}