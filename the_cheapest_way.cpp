#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<std::vector<int> > dp(n + 1, std::vector<int>(m + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> dp[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j > 0) {
        dp[i + 1][j] += std::min(dp[i][j], dp[i + 1][j - 1]);
      } else {
        dp[i + 1][j] += dp[i][j];
      }
      if (i == 0) {
        dp[i][j + 1] += dp[i][j];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cout << dp[i][j] << " ";
    }
    std::cout << '\n';
  }
  std::cout << dp[n - 1][m - 1];
}
