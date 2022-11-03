/*Tý đang xây dựng một mạng xã hội và mời các bạn của mình dùng thử. Bạn của bạn cũng là bạn. Vì vậy, Tý muốn mạng xã hội của mình là hoàn hảo, tức với mọi bộ ba X, Y, Z, nếu X kết bạn với Y, Y kết bạn với Z thì X và Z cũng phải là bạn bè của nhau trên mạng xã hội. Các bạn hãy xác định xem mạng xã hội hiện tại của Tý có là hoàn hảo hay không? Nếu có hãy in ra “YES”, “NO” trong trường hợp ngược lại.

Input Format

Mỗi test bắt đầu bởi 2 số nguyên N và M. M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v (u #v) cho biết u và v là kết bạn với nhau trên mạng xã hội của Tý.

Constraints

1<= N, M ≤ 100 000)

Output Format

In ra kết quả của bài toán

Sample Input 0

4 3
1 3
3 4
1 4
Sample Output 0

YES
Sample Input 1

4 4
3 1
2 3
3 4
1 2
Sample Output 1

NO
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

vector<int>v[100001];
int visited[100001];
vector<int>arr;

void BFS(int s)
{
    queue<int>q;
    q.push(s); visited[s] = 1;
    arr.push_back(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int x : v[u])
        {
            if(!visited[x])
            {
                q.push(x);
                arr.push_back(x);
                visited[x] = 1;
            }
        }
    }
}

int main()
{
    int n , m ; cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        int a , b ; cin >>a >> b;
        v[a].push_back(b) ; v[b].push_back(a);
    }
    for(int i = 1 ; i <= n ;i++)
    {
        if(!visited[i])
        {
            BFS(i);
            for(int k = 0 ; k < arr.size() - 1 ; k++)
            {
                if(v[arr[k]].size() != v[arr[k + 1]].size())
                {
                    cout << "NO"; return 0;
                }
            }
            arr.clear();
        }
    }
    cout << "YES";
    return 0;
}