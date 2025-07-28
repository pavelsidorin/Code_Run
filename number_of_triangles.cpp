#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  int on_level = 1;
  int k = 1;
  for (int i = 2; i < n + 1; ++i) {
    on_level += 2;
    k += on_level;
    dp[i] = dp[i - 1] + ((i + 1) * i) / 2 + i - 1 + ((i % 2 == 0) ? dp[i / 2] - 1 : 0);
  }

}
