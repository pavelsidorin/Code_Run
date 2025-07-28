#include <iostream>
#include <vector>

int Move(int n, int m) {
  if (n < 2 && m < 2) {
    return 1;
  }
  if (n == 0 || m == 0) {
    return 1;
  }
  std::vector<std::vector<int> > dp(n, std::vector<int>(m, 0));
  dp[0][0] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (j > 1) {
        dp[i][j] += dp[i - 1][j - 2];
      }
      if (i > 1) {
        dp[i][j] += dp[i - 2][j - 1];
      }
    }
  }
  return dp[n - 1][m - 1];
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::cout << Move(n, m);
}
