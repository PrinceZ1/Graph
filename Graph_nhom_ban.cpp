/*Trong một lớp học luôn tồn tại những nhóm học sinh, các học sinh trong nhóm này sẽ thân thiết với nhau hơn. Giả sử trong 1 nhóm, nếu bạn a chơi thân vs bạn b và bạn b chơi thân với bạn c, thì bạn a và bạn c sẽ chơi thân với nhau. Hiện nay Tèo là lớp trưởng lớp 10A1, vì không thích việc chia bè kéo cánh trong lớp nên Tèo quyết định tìm ra nhóm có số bạn chơi thân với nhau nhất trong nhóm để đưa các thành viên của các nhóm khác vào trong nhóm có số lượng thành viên cao nhất này. Bạn hãy giúp Tèo tìm ra số lượng thành viên lớn nhất của 1 nhóm chơi thân bất kỳ trong lớp nhé !

Input Format

Dòng đầu tiên là n và m, tương ứng với số lượng sinh viên trong lớp và số lượng tình bạn giữa các bạn trong lớp. Các sinh viên được đánh số từ 1 tới n. M dòng tiếp theo mỗi dòng gồm 2 số a, b thể hiện tình bạn thân thiết giữa bạn a và bạn b, a và b khác nhau.

Constraints

1<=n<=1000; 1<=m<=n*(n-1)/2; 1<=a,b<=n;

Output Format

In ra nhóm có số lượng bạn lớn nhất

Sample Input 0

10 6
8 2
4 1
8 6
8 7
8 1
8 5
Sample Output 0

7
*/

#include <bits/stdc++.h>
using namespace std;
vector<int>v[10001];
int check[10001];
int ans = 0;
void DFS(int u)
{
    check[u] = 1;
    ++ans;
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
    for(int i = 0 ; i < m ; i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int res = 0;
    for(int i = 1 ; i <= n ;i++)
    {
        if(!check[i])
        {
            ans = 0;
            DFS(i);
            res = max(res , ans);
        }
    }
    cout << res;
}