#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string source;
  std::string sink;
  std::cin >> source >> sink;
  std::vector<std::vector<int>> dp(source.length() + 1, std::vector<int>(sink.length() + 1, 0));
  for (int i = 0; i < n; ++i) {
    ++dp[i][0]; ++dp[0][i];
  }
  for (size_t i = 1; i < source.length() + 1; ++i) {
    for (size_t j = 1; j < sink.length() + 1; ++j) {
      if (source[i - 1] == sink[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = std::min({dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
      }
    }
  }
  std::cout << dp[source.length()][sink.length()];
}
