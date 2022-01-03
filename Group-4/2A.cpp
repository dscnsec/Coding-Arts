// Complexity Analysis
// Time Complexity: O(n) in worst case
// Sapce Complexity: O(n^2) in worst case

#include <bits/stdc++.h>
using namespace std;
// for debugging the program
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif
struct Node {
	int key;
	Node* left;
	Node* right;
};
Node* newNode(int value) {
	Node* n = new Node;
	n->key = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}
Node* createTree(string& s) {
	if(s.size() == 0 || s[0] == 'N') {
		return NULL;
	}
	stringstream ss(s);
	vector<string> arr;
	string input;
	while(ss >> input) {
		arr.emplace_back(input);
	}
	Node* root = newNode(stoi(arr[0]));
	queue<Node*> q;
	q.push(root);
	for (int i = 1; i < (int) arr.size(); i++) {
		Node* curNode = q.front();
		if(arr[i] != "N") {
			curNode->left = newNode(stoi(arr[i]));
			q.push(curNode->left);
		}
		i++;
		if(i < (int) arr.size() && (arr[i] != "N")) {
			curNode->right = newNode(stoi(arr[i]));
			q.push(curNode->right);
		}
		q.pop();
	}
	return root;
}
Node* LCA(Node* root, int src, int dest) {
	if(root == NULL) {
			return root;
	}
	if(root->key == src || root->key == dest) {
			return root;
	}
	Node* left = LCA(root->left, src, dest);
	Node* right = LCA(root->right, src, dest);
	if(left != NULL && right != NULL) {
			return root;
	}
	if(left == NULL && right == NULL) {
			return NULL;
	}
	if(left != NULL) {
			return LCA(root->left, src, dest);
	}
	return LCA(root->right, src, dest);
}
int findLevel(Node* root, int k, int level) {
	if(root == NULL) {
		return -1;
	}
	if(root->key == k) {
			return level;
	}
	int left = findLevel(root->left, k, level + 1);
	if(left == -1) {
			return findLevel(root->right, k, level + 1);
	}
	return left;
}
int findDistance(Node* root, int src, int dest) {
	Node* lca = LCA(root, src, dest);
	int d1 = findLevel(lca, src, 0);
	int d2 = findLevel(lca, dest, 0);
	return d1 + d2 - 1;
}

void solve() {	
	string s, t = "";
	getline(cin,s);
	while(s.size() == 0) {
		getline(cin,s);
	}
	int src, dest;
	cin >> src >> dest;
	Node* root = createTree(s);
	cout << findDistance(root, src, dest) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  //cin >> tc;
  for(int t = 0; t < tc; t++)
    solve();
}
