#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

int main() {
  using ll = long long;
  std::string s;
  std::cin >> s;
  ll sum_c = 0;
  for (const auto& x : s) {
    if (x == 'c') ++sum_c;
  }
  ll sum_a = 0;
  ll sum = 0;
  for (const auto& x : s) {
    if (x == 'b') {
      sum += sum_a * sum_c;
    }
    if (x == 'a') ++sum_a;
    if (x == 'c') --sum_c;
  }
  std::cout << sum;
}
