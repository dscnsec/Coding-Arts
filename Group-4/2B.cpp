// Complexity Analysis
// Time Complexity: O(x * n) in worst case
// Sapce Complexity: O(n^2) in worst case

#include <bits/stdc++.h>
using namespace std;

void solve() {	
	// number of users
	int n;
	cin >> n;

	// number of connections
	int m;
	cin >> m;

	// storing the connection for all the users
	unordered_map<string, set<string>> mp;
	for(int i = 0; i < m; i++) {
		// follower's name
		string a;
		cin >> a;

		// followed name
		string b;
		cin >> b;	

		// inserting the follower
		mp[b].insert(a);
	}

	// number of new connections
	int x;
	cin >> x;

	for(int i = 0; i < x; i++) {
		// follower's name
		string c;
		cin >> c;

		// followed name
		string d;
		cin >> d;	

		vector<string> ans;
		for(auto& s: mp[d]) {
			if(!mp[s].count(c)) {
				ans.emplace_back(s);
			}
		}
		if(ans.size() == 0) {
			cout << "0\n";
		} else {
			for(auto& s: ans) {
				cout << s << " ";
			}
			cout << '\n';
		}
	}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
	
  int tc = 1;
  //cin >> tc;
  
  for(int t = 0; t < tc; t++)
    solve();
}
