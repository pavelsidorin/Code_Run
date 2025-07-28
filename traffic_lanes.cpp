#include <iostream>
#include <vector>
#include <cstddef>

int main() {
  using ll = long long;
  int m, n;
  std::cin >> m >> n;
  if (n > m) {
	std::cout << 0;
	return 0;
  }
  std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(m + 1, 0));
  for (int i = 1; i <= m; ++i) {
    dp[1][i] = 1;
  }
  dp[1][0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = i; j <= m; ++j) {
    if (dp[i][j] == 0) continue;
      dp[i + 1][j] += dp[i][j];
      if (j < m) {
        for (int k = j + 1; k <= m; ++k) {
          dp[i + 1][k] += 2 * dp[i][j];
        }
      }
    }
  }
  std::cout << dp[n][m];
}
