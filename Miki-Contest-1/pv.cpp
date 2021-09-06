#include <bits/stdc++.h>

using namespace std;

const int M = 105, N = 105;
const int dR[] = {1,-1,0,0}, dC[] = {0,0,-1,1};

int grid[M][N], m, n, ans[M];
bool vis[M][N] = {false};

bool valid(int row, int col) {
	if (row < 0 || row >= m || col < 0 || col >= n || vis[row][col] || grid[row][col] == 0) return false;
	return true;
}

int bfs(int scrR, int scrC) {
	int ans = 1;
	queue<pair<int, int>> q;
	q.push({scrR,scrC});
	vis[scrR][scrC] = true;
	while (!q.empty()) {
		int row = q.front().first, col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) 
			if (valid(row+dR[i],col+dC[i])) {
				ans++; vis[row+dR[i]][col+dC[i]]=true; q.push({row+dR[i],col+dC[i]});
			}
	}
	return ans;
}

signed main() {
	int idx = 0;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1 && vis[i][j] == false) {
				ans[idx++] = bfs(i,j);
			}
			else vis[i][j] = true;
		}
	sort(ans,ans+idx);
	for (int i = 0; i < idx; i++) cout << ans[i] << endl;
	return 0;
}