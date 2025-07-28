#include <iostream>
#include <vector>
#include <climits>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> dp(n + 1, INT_MAX);
  std::vector<int> a;
  for (int i = 0; i * i * i < n + 1; ++i) {
    dp[i * i * i] = 1;
    if (i != 0) {
      a.push_back(i * i * i);
    }
  }
  for (int i = 1; i < n + 1; ++i) {
    for (const auto& x : a) {
      if (i + x < n + 1) {
        dp[i + x] = std::min(dp[i] + 1, dp[i + x]);
      } else {
        break;
      }
    }
  }
  std::cout << dp[n];
}
