#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long int
#define endl "\n"

void solve(int tc = 0) {
	// number of users
	int m, n;
	cin >> n >> m;

	// mapping the followers to the username
	unordered_map<string, unordered_map<string, int>> followers;
	while (m--)
	{
		string a, b;
		cin >> a >> b;
		followers[b][a] = 1;
	}
	int new_conn, noloop_flag = 0;
	cin >> new_conn;
	while (new_conn--)
	{
		noloop_flag = 0;
		string a, b;
		cin >> a >> b;
		for (auto &pair : followers[b])
		{
			//checking the followers
			if (followers[pair.first][a] == 0 && pair.first != a)
			{
				noloop_flag++;
				// printing the followers of given user excluding the other one's followers
				cout << pair.first << " ";
			}
		}
		if (!noloop_flag)
		{
			cout << 0;
		}
		cout << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc = 1;
	//cin >> tc;
	for (int t = 0; t < tc; t++)
		solve(t);
}
//time complexity=O(number of users * number of queries)
//space complexity=O((number of users+number of connections)*size of string)