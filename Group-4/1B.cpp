// Complexity Analysis
// Time Complexity: O(n) in worst case
// Sapce Complexity: O(n^2) in worst case

#include <bits/stdc++.h>
using namespace std;

void solve(int tc = 0) {
	// number of users
	int m, n;
	cin >> n >> m;

	// map the username to a particular index
	unordered_map<string, int> mp;

	// taking followers of each users
	vector<vector<string>> data(n + 1);
	int k = 1;
	while(m--) {
		string s, t;
		cin >> s >> t;

		// mapping the username to an index if the name isn't mapped
		if(!mp[s]) {
			mp[s] = k++;
		}
		
		if(!mp[t]) {
			mp[t] = k++;
		}

		// pushing the username according to mapped index
		data[mp[t]].emplace_back(s);
	}

	// printing the followers of given user
	string s;
	while (cin >> s) {
		cout << data[mp[s]].size() << '\n';
		
		for (string& dt : data[mp[s]]) {
			cout << dt << " ";
		}
		
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc = 1;
	//cin >> tc;
	for (int t = 0; t < tc; t++)
		solve(t);
}
