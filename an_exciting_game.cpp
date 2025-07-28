#include <iostream>
#include <vector>
#include <climits>

int main() {
  int n, a, b;
  std::cin >> n >> a >> b;
  std::vector<int> dp(std::max(n + 1, 2), 0);
  dp[0] = 0;
  dp[1] = 0;
  for (int i = 2; i <= n; ++i) {
    int sum = INT_MAX;
    for (int j = 1; j < i; ++j) {
      sum = std::min(std::max(dp[j] + a, dp[i - j] + b), sum);
    }
    dp[i] = sum;
  }
  std::cout << dp[n];
}
