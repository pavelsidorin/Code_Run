#include <iostream>
#include <vector>
#include <algorithm>

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
        dp[i + 1][j] += std::max(dp[i][j], dp[i + 1][j - 1]);
      } else {
        dp[i + 1][j] += dp[i][j];
      }
      if (i == 0) {
        dp[i][j + 1] += dp[i][j];
      }
    }
  }
  std::cout << dp[n - 1][m - 1];
  std::cout << '\n';
  std::vector<std::string> answer;
  int i = n - 1;
  int j = m - 1;
  while (i > 0 || j > 0) {
    if (i == 0) {
      --j;
      answer.push_back("R");
    } else if (j == 0) {
      --i;
      answer.push_back("D");
    } else {
      if (dp[i - 1][j] > dp[i][j - 1]) {
        --i;
        answer.push_back("D");
      } else {
        --j;
        answer.push_back("R");
      }
    }
  }
  std::reverse(answer.begin(), answer.end());
  for (const std::string& x : answer) {
    std::cout << x << " ";
  }
}
