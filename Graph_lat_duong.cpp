/*Ở 28techland có n thành phố và ban đầu không có đường giữa chúng. Tuy nhiên, mỗi ngày một con đường mới sẽ được xây dựng và sẽ có tổng cộng m con đường. Một cụm thành phố là một nhóm các thành phố trong đó có một tuyến đường giữa hai thành phố bất kỳ bằng cách sử dụng các con đường. Sau mỗi ngày, nhiệm vụ của bạn là tìm ra số lượng cụm thành phố và kích thước của cụm thành phố lớn nhất.

Input Format

Dòng đầu tiên có hai số nguyên n và m: số thành phố và đường. Các thành phố được đánh số 1,2,…, n. Sau đó, có m dòng mô tả các con đường mới. Mỗi dòng có hai số nguyên a và b: một con đường mới được xây dựng giữa các thành phố a và b. Bạn có thể cho rằng mọi con đường sẽ được xây dựng giữa hai thành phố khác nhau.

Constraints

1≤n≤10^5; 1≤m≤2⋅10^5; 1≤a,b≤n;

Output Format

In m dòng: thông tin cần thiết sau mỗi ngày.

Sample Input 0

5 3
1 2
1 3
4 5
Sample Output 0

4 2
3 3
2 3
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 1;
struct canh
{
    int x , y , w ;
};
vector<canh>v;
int res = 1;
int size[maxn] , parent[maxn];

int find(int u)
{
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
bool Union(int a , int b)
{
    a = find(a);
    b = find(b);
    if(a == b) return 0;
    if(size[a] < size[b]) swap(a , b);
    size[a] += size[b];
    parent[b] = a;
    res = max(res , size[a]);
    return 1;
}

int main()
{
    ios::sync_with_stdio(NULL);cout.tie(NULL);cin.tie(NULL);
    int n , m ; cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
    int ans = n;
    for(int i = 1 ; i <= m ;i++)
    {
        int a , b ; cin >> a >> b;
        ans -= Union(a , b);
        cout << ans << " " << res << endl;
    }
}