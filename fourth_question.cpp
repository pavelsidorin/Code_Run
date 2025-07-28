#include <iostream>
#include <vector>
#include <climits>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> moods(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> moods[i];
  }
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, INT_MIN));
  std::vector<int> maxes(k + 1, INT_MIN);
  dp[0][0] = 0;
  maxes[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (i > 0 && dp[i - 1][j] != INT_MIN) {
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + moods[i - 1]);
      }
      if (i > 1 && dp[i - 2][j] != INT_MIN) {
        dp[i][j] = std::max(dp[i][j], dp[i - 2][j] + moods[i - 1]);
      }
      if (j > 0 && maxes[j - 1] != INT_MIN) {
        dp[i][j] = std::max(dp[i][j], maxes[j - 1] + moods[i - 1]);
      }
    }
    for (int j = 0; j <= k; j++) {
      if (dp[i][j] != INT_MIN) {
        maxes[j] = std::max(maxes[j], dp[i][j]);
      }
    }
  }
  int max = INT_MIN;
  for (int i = 0; i <= k; ++i) {
    max = std::max(dp[n][i], max);
  }
  std::cout << max;
}
