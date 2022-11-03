/*Thành phố Vice được xây dựng trên một nhóm các hòn đảo, với những cây cầu nối giữa chúng. Như bất kỳ ai ở Vice City đều biết, nỗi sợ hãi lớn nhất của các phó thành phố là một ngày nào đó các hòn đảo sẽ bị nhấn chìm. Vấn đề lớn của việc này là một khi các hòn đảo bị nhấn chìm, một số hòn đảo khác có thể bị ngắt kết nối. Bạn đã được thị trưởng thành phố Vice thuê để nói cho ông ta biết có bao nhiêu hòn đảo, khi bị nhấn chìm, sẽ ngắt kết nối các bộ phận của thành phố Vice. Bạn nên biết rằng ban đầu tất cả các hòn đảo của thành phố đều được kết nối với nhau.

Input Format

Dòng đầu tiên là N và M, tương ứng với số lượng đảo và cầu; M dòng tiếp theo của mỗi test case mô tả cầu nối giữa 2 hòn đảo u, v;

Constraints

1<=N<=1000; 1<=M<=N*(N-1)/2; 1<=u,v<=N;

Output Format

In ra số lượng hòn đảo khi bị ngập sẽ làm thành phố Vice bị ngắt kết nối.

Sample Input 0

6 8
1 3
6 1
6 3
4 1
6 4
5 2
3 2
3 5
Sample Output 0

1
*/

#include <bits/stdc++.h>
using namespace std;
vector<int>v[1001];
bool ok[1001];
void DFS(int s)
{
    ok[s] = true;
    for(int x : v[s])
    {
        if(!ok[x])
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
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!ok[i])
        {
            DFS(i);
            ++ans;
        }
    }
    int res = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        memset(ok , false , sizeof(ok));
        ok[i] = true; // loai bo dinh i
        int dem = 0;
        for(int j = 1 ; j <= n ;j++)
        {
            if(!ok[j])
            {
                DFS(j);
                ++dem;
            }
        }
        if(dem > ans) ++res;
    }
    cout << res;
}