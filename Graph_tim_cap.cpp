/*Bạn được cung cấp một cây gốc với các nút và nút 1 là gốc. Có một đường đi duy nhất giữa hai nút bất kỳ. Ở đây, d(i, j) được định nghĩa là số cạnh trong một đường đi ngắn nhất giữa 2 nút i và j. Nhiệm vụ của bạn phải tìm số lượng cặp i, j sao cho d(i, j) = d(1, i) - d(1, j).

Input Format

Dòng đầu tiên là N là số lượng nút của cây. N - 1 dòng tiếp theo là các cạnh của cây.

Constraints

1<=N<=1000;

Output Format

In ra số lượng cặp (i, j) thỏa mãn yêu cầu của đầu bài.

Sample Input 0

10
9 10
5 9
7 4
4 5
2 3
6 7
7 8
3 6
1 2
Sample Output 0

51
Sample Input 1

4
1 2
2 3
3 4
Sample Output 1

10
Explanation 1

Các cặp thỏa mãn : (1, 1), (1, 2), (1, 3), (1, 4), (2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (4, 4).
*/

#include <bits/stdc++.h>
using namespace std;
vector<int>v[1001];
int ok[1001];
int DFS(int s , int par)
{
    int cnt = 1;
    for(int x : v[s])
    {
        if(x != par)
        {
            cnt += DFS(x , s);
        }
    }
    ok[s] = cnt;
    return cnt;
}
int main()
{
    int n ; cin >> n;
    for(int i = 1 ; i <= n - 1 ;i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(1 , -1);
    int res = 0;
    for(int i = 1 ; i <= n ;i++)
    {
        res += ok[i];
    }
    cout << res;
}