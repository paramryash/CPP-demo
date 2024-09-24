
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <climits>
#include <cstring>
using namespace std;
bool isSafe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> &m)
{

    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
    {
        return true;
    }
    return false;
}
void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> &visited, string path)
{
    
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    
    visited[x][y] = 1;

    
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();  
    }

    
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }


    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    
    visited[x][y] = 0;
}
vector<string> find_path(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    if (m[0][0] == 0)
    {
        return ans;
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    solve(m, n, ans, 0, 0, visited, path);

    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    int n = m.size();

    vector<string> result = find_path(m, n);
int count=1;
    if (result.size() == 0)
    {
        cout << "No path found" << endl;
    }
    else
    {
        cout << "Paths are: " << endl;
        
        for (int i = 0; i < result.size(); i++)
        {
            cout<<count++ <<". "<< result[i] << endl;
    
        }
    }

    return 0;
}
