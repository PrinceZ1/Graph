/*Cho đồ thị vô hướng G = được biểu diễn dưới dạng danh sách kề. Hãy chuyển đổi đồ thị dưới dạng danh sách kề này sang danh sách cạnh tương ứng.

Input Format

Dòng đầu tiên là số nguyên dương n, tương ứng với số đỉnh của đồ thị. N dòng tiếp theo mỗi dòng chứa nhiều số nguyên, dòng thứ i tương ứng với các đỉnh trong danh sách kề của đỉnh i.

Constraints

1<=n<=1000;

Output Format

In ra các cạnh trong đồ thị trên từng dòng, các cạnh được liệt kê tăng dần. Chú ý mỗi cạnh chỉ liệt kê một lần.

Sample Input 0

5
4 
3 4 5 
2 5 
1 2 
2 3 
Sample Output 0

1 4
2 3
2 4
2 5
3 5
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n ; cin >> n; cin.ignore();
    vector<pair<int,int>>v;
    for(int i = 1 ; i <= n ;i++)
    {
        string s; getline(cin , s);
        stringstream ss(s);
        string io;
        while(ss >> io)
        {
            if(stoi(io) > i) v.push_back({i , stoi(io)});
        }
    }
    for(pair<int,int> x : v) cout << x.first << " " << x.second << endl;
}