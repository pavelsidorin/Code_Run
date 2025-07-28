#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::vector<int> left(n + 1, -1);
  std::vector<int> right(n + 1, -1);
  int head = 0;
  int tail = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == 'R') {
      right[i] = i;
      std::swap(right[i - 1], right[i]);
      left[i] = i - 1;
      if (right[i] != -1) {
        left[right[i]] = i;
      } else { tail = i; }
    }
    if (s[i - 1] == 'L') {
      left[i] = i;
      std::swap(left[i - 1], left[i]);
      right[i] = i - 1;
      if (left[i] != -1) {
        right[left[i]] = i;
      } else { head = i; }
    }
  }
  std::vector<int> result;
  int current = head;
  while (current != -1) {
    result.push_back(current);
    current = right[current];
  }
  for (const auto& x : result) {
    std::cout << x << " ";
  }
}
