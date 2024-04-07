#include <bits/stdc++.h>
using namespace std;

int n; // 노드의 개수

struct node
{
	char left;
	char right;
};

node tree[26];

void preorder(char root)	// 전위순회
{
	// 루트 노드 탐색 후 자식 노드(왼->오) 탐색
	if (root != '.')
	{
		cout << root;
		preorder(tree[root - 'A'].left);
		preorder(tree[root - 'A'].right);
	}
}

void inorder(char root)		// 중위순회
{
	// 왼쪽 자식 노드 탐색 후 루트 노드 탐색 후 오른쪽 자식 노드 탐색(대칭)
	if (root != '.')
	{
		inorder(tree[root - 'A'].left);
		cout << root;
		inorder(tree[root - 'A'].right);
	}
}

void postorder(char root)	// 후위순회
{
	// 자식 노드(왼->오) 탐색 후 루트 노드 탐색
	if (root != '.')
	{
		postorder(tree[root - 'A'].left);
		postorder(tree[root - 'A'].right);
		cout << root;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;

		tree[root - 'A'].left = left;
		tree[root - 'A'].right = right;
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');

	return 0;
}
