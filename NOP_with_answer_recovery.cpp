#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::reverse;

struct Coord {
  int i;
  int j;
  explicit Coord(int i, int j) : i(i), j(j) {
  }
};

void PrintPath(const vector<vector<int>>& dp, int i, int j, vector<int>& source) {
  if (i == 0 || j == 0) {
    return;
  }
  if (dp[i][j] == dp[i - 1][j]) {
    PrintPath(dp, i - 1, j, source);
  } else if (dp[i][j] == dp[i][j - 1]) {
    PrintPath(dp, i, j - 1, source);
  } else {
    PrintPath(dp, i - 1, j - 1, source);
    cout << source[i] << " ";
  }
}

int main() {
  int n = 0;
  cin >> n;
  vector<int> source(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> source[i];
  }
  int m = 0;
  cin >> m;
  vector<int> sink(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> sink[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      if (source[i] == sink[j]) {
        dp[i][j] = std::max(dp[i - 1][j - 1] + 1, dp[i][j]);
      }
    }
  }
  PrintPath(dp, n, m, source);
}
