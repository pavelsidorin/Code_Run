#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

int main() {
  std::unordered_map<char, std::string> rules;
  for (char c : {'N', 'S', 'W', 'E', 'U', 'D'}) {
    std::getline(std::cin, rules[c]);
  }
  char source;
  int source_number;
  std::cin >> source >> source_number;
  std::unordered_map<char, std::vector<int>> dp;
  for (char c : {'N', 'S', 'W', 'E', 'U', 'D'}) {
    dp[c].resize(source_number + 1, 1);
  }
  for (int i = 2; i <= source_number; ++i) {
    for (const char& c : {'N', 'S', 'W', 'E', 'U', 'D'}) {
      for (const char& x : rules[c]) {
        dp[c][i] += dp[x][i - 1];
      }
    }
  }
  std::cout << dp[source][source_number];
}
