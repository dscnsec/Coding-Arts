#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	int n;
	cin >> n;

	int arr[n + 1][n+1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == j) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = INT_MAX;
			}
		}
	}


	for (int i = 0; i < n * (n + 1) / 2; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		arr[a][b] = c;
		arr[b][a] = c;
	}

	for (int k = 0; k <= n; k++)
	{

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}

	}
	
	int array[n + 1] = {0};
	int ans = 0, i = 0;
	cout << 0 << " " << 0 << "\n";
	array[0] = 1;
	while (ans < n)
	{
		int Min = INT_MAX, minIndex = 0;
		for (int j = 0; j <= n; j++)
		{
			if (i != j && Min > arr[i][j] && array[j] == 0)
			{
				Min = arr[i][j];
				minIndex = j;
			}
		}
		array[minIndex] = 1;
		cout << minIndex << " " << arr[i][minIndex] << "\n";
		i = minIndex;
		ans++;
	}




	return 0;
}
