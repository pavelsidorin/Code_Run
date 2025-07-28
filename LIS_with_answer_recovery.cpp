#include <iostream>
#include <vector>
#include <climits>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> answer;
  std::vector<int> dp(n + 2, INT_MAX);
  answer.push_back(std::vector<int>());
  answer[0].push_back(a[0]);
  dp[0] = INT_MIN;
  dp[1] = a[0];
  int k = 1;
  for (int i = 1; i < n; ++i) {
    auto it = lower_bound(dp.begin(), dp.end(), a[i]);
    if (*it == INT_MAX) {
      answer.push_back(std::vector<int>());
      answer[k].push_back(a[i]);
      ++k;
    } else {
      answer[std::distance(dp.begin(), it) - 1].push_back(a[i]);
    }
    *it = a[i];
  }
  std::vector<int> total(k);
  --k;
  total[k] = answer[k][0];
  while (k > 0) {
    --k;
    for (size_t i = 0; i < answer[k].size(); ++i) {
      if (answer[k][i] < total[k + 1]) {
        total[k] = answer[k][i];
        break;
      }
    }
  }
  for (const auto& x : total) {
    std::cout << x << " ";
  }
}
