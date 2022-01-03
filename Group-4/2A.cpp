#include <bits/stdc++.h>
using namespace std;

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
