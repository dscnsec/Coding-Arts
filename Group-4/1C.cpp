#include <bits/stdc++.h>
using namespace std;
#define int long long
int v;
void addedge(int &x, int &y, int &w, vector<vector<int>> &m)
{
	m[x][y] = m[y][x] = w;
}
void fwarshall(vector<vector<int>> &m)
{
	int i, j, k;
	for (k = 0; k <= v; k++)
	{
		for (i = 0; i <= v; i++)
		{
			for (j = 0; j <= v; j++)
			{
				m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
			}
		}
	}
}
pair<int, int> ans(int &prev, vector<vector<int>> &m, vector<bool> &visited)
{
	int min = INT_MAX;
	pair<int, int> p;
	for (int i = 0; i <= v; i++)
	{
		if (m[prev][i] < min && !visited[i])
		{
			min = m[prev][i];
			p.first = i;
			p.second = m[prev][i];
		}
	}
	visited[p.first] = true;
	return p;
}
void solve()
{
	int x, y, w, i;
	vector<vector<int>> m(v + 1, vector<int>(v + 1, INT_MAX));
	vector<bool> visited(v + 1, false);
	visited[0] = true;
	for (i = 0; i <= v; i++)
	{
		m[i][i] = 0;
	}
	int z = v * (v + 1) / 2;
	for (i = 0; i < z; i++)
	{
		cin >> x >> y >> w;
		addedge(x, y, w, m);
	}
	fwarshall(m);
	cout << "0 0\n";
	int prev = 0;
	for (i = 1; i <= v; i++)
	{
		pair<int, int> p = ans(prev, m, visited);
		cout << p.first << " " << p.second << endl;
		prev = p.first;
	}

}
int32_t main()
{
	cin >> v;
	solve();
}
