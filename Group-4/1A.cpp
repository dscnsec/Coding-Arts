// Complexity Analysis
// Time Complexity: O(n + m)
// Sapce Complexity: O(n + m)

#include <bits/stdc++.h>
using namespace std;

void solve(int tc = 0) {
    // number of boxes in pile A
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x : a) {
			cin >> x;
		}

		// number of boxes in pile B
    int m;
    cin >> m;

    vector<int> b(m);
    for (int &x : b) cin >> x;

    // current idx of pile A
    int k = 0;

    // current idx of pile B
    int l = 0;

    // storing the ans
    int ans = 0;

    // finding median
    for (int i = 0; i < (m + n) / 2 + 1; i++) {
        if (k != m && l != n)
            ans = (a[k] > b[l] ? b[l++] : a[k++]);
        else if (k < n)
            ans = a[k++];
        else
            ans = b[l++];
    }

    // printing the answer
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    //cin >> tc;
    for (int t = 0; t < tc; t++)
        solve(t);
}
