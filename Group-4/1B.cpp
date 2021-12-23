#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long int
#define endl "\n"

void solve(int tc = 0) {
	// number of users
	int m, n;
	cin >> n >> m;

	// mapping the username to a particular index
	unordered_map<string, int> mp;

	// taking followers of each users
	vector<string> data[n];
	int k = 0;
	while (m--)
	{
		string s, t;
		cin >> s >> t;

		if (!mp[s]) mp[s] = k++;
		if (!mp[t]) mp[t] = k++;
		data[mp[t]].push_back(s);
	}

	// printing the followers of given user

	string s;
	while (cin >> s)
	{
		cout << data[mp[s]].size() << endl;
		for (string& dt : data[mp[s]])
			cout << dt << " ";
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