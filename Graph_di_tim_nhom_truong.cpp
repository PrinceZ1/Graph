/*Trong một lớp học luôn tồn tại những nhóm học sinh, các học sinh trong nhóm này sẽ thân thiết với nhau hơn. Giả sử trong 1 nhóm, nếu bạn a chơi thân vs bạn b và bạn b chơi thân với bạn c, thì bạn a và bạn c sẽ chơi thân với nhau. Hiện nay Tèo là lớp trưởng lớp 10A1, vì không thích việc chia bè kéo cánh trong lớp nên Tèo quyết định tìm các bạn nhóm trưởng của các nhóm để bàn việc hợp nhất các nhóm. Tèo biết rằng trong các nhóm nhỏ, nhóm trưởng là người có nhiều quan hệ thân thiết với các thành viên khác trong nhóm nhất và là người có số thứ tự nhỏ nhất. Nếu một bạn nào đó không chơi với ai cả thì bạn đó là nhóm trưởng của chính mình. Bạn hãy giúp tèo in ra thứ tự của các trưởng nhóm theo thứ tự từ nhỏ đến lớn nhé.

Input Format

Dòng đầu tiên là n và m, tương ứng với số lượng sinh viên trong lớp và số lượng tình bạn giữa các bạn trong lớp. Các sinh viên được đánh số từ 1 tới n. M dòng tiếp theo mỗi dòng gồm 2 số a, b thể hiện tình bạn thân thiết giữa bạn a và bạn b, a và b khác nhau.

Constraints

1<=n<=1000; 1<=m<=n*(n-1)/2; 1<=a,b<=n;

Output Format

In ra thứ tự của các trưởng nhóm theo thứ tự từ nhỏ đến lớn nhé.

Sample Input 0

10 6
4 3
4 1
8 5
8 6
4 2
8 2
Sample Output 0

4 7 9 10 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

vector<ll>v[1001];
ll check[1001];
vector<ll>arr;
void DFS(ll u)
{
    check[u] = 1;
    arr.push_back(u);
    for(ll x : v[u])
    {
        if(!check[x])
        {
            DFS(x);
        }
    }
}

int main()
{
    ll n , m ; cin >> n >> m;
    while(m--)
    {
        ll a , b ; cin >> a >> b;
        v[a].push_back(b) ; v[b].push_back(a);
    }
    vector<ll>dem;
    for(ll i = 1 ; i <= n ;i++)
    {
        if(!check[i])
        {
            DFS(i);
            ll Max = -9 , vt = i;
            for(auto x : arr)
            {
                ll n = v[x].size();
                if(n > Max)
                {
                    Max = n;
                    vt = x;
                }
                else if(n == Max)
                {
                    if(vt > x) vt = x;
                }
            }
            dem.push_back(vt);
            arr.clear();
        }
    }
    sort(dem.begin() , dem.end());
    for(auto x : dem) cout << x << " ";
    return 0;
}