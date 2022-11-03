/*Ở 28techland có n thành phố và m đường giữa chúng. Mục tiêu là xây dựng những con đường mới để có một tuyến đường giữa hai thành phố bất kỳ. Nhiệm vụ của bạn là tìm ra số lượng đường tối thiểu cần thiết, đồng thời xác định những con đường nào nên được xây dựng.

Input Format

Dòng đầu tiên có hai số nguyên n và m: số thành phố và đường. Các thành phố được đánh số từ 1 tới n. Sau đó, có m dòng mô tả các con đường. Mỗi dòng có hai số nguyên a và b: có một con đường giữa các thành phố đó, các con đường này là đường 2 chiều. Một con đường luôn nối hai thành phố khác nhau và có nhiều nhất một con đường giữa hai thành phố bất kỳ.

Constraints

1<=n<=1000; 0<=m<=n*(n-1)/2; 1<=a,b<=n;

Output Format

Dòng đầu tiên in ra K là số con đường cần xây dựng. K dòng tiếp theo in ra các con đường được xây dựng, do có nhiều cách xây dựng đường nên bạn sẽ lựa chọn ra các con đường có thứ tự từ điển nhỏ nhất để xây dựng nhưng với một điều kiện đó là, mỗi thành phố được lựa chọn là điểm xuất phát của con đường không quá 1 lần.

Sample Input 0

6 3
4 3
4 1
4 2
Sample Output 0

2
1 5
5 6
Explanation 0

Có thể có nhiều cách xây dựng đường đi ví dụ : xây dựng đường đi giữa thành phố 2 và 5, 1 và 6 sẽ kết nối mọi thành phố. Tuy nhiên do yêu cầu của đầu bài, bạn sẽ phải xây dựng 2 con đường là 1->5, 5->6. Không thể xây dựng 1->5, 1->6 vì như vậy thành phố 1 sẽ 2 lần là điểm khởi đầu của con đường.
*/

#include <bits/stdc++.h>
using namespace std;
vector<int>v[10001];
int check[10001];

void DFS(int u)
{
    check[u] = 1;
    for(int x : v[u])
    {
        if(!check[x])
        {
            DFS(x);
        }
    }
}

int main()
{
    int n , m ; cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int>res;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!check[i])
        {
            res.push_back(i);
            DFS(i);
        }
    }
    cout << res.size() - 1<< endl;
    for(int i = 0 ; i < res.size() - 1 ; i++)
    {
        cout << res[i] << " " << res[i + 1] << endl;
    }
}