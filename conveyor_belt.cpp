#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>

bool Check(int x) {
  std::stack<double> stack;
  std::vector<double> conv(x);
  std::vector<double> conv_sorted(x);
  for (int i = 0; i < x; ++i) {
    std::cin >> conv[i];
    conv_sorted[i] = conv[i];
  }
  std::sort(conv_sorted.begin(), conv_sorted.end());
  int k = 0;
  for (int i = 0; i < x; ++i) {
    while (!stack.empty() && stack.top() == conv_sorted[k]) {
      ++k;
      stack.pop();
    }
    if (conv[i] == conv_sorted[k]) {
      ++k;
    } else {
      stack.push(conv[i]);
    }
  }
  while (!stack.empty() && stack.top() == conv_sorted[k]) {
    ++k;
    stack.pop();
  }
  return stack.empty();
}

int main() {
  int n;
  std::cin >> n;
  for (int k = 0; k < n; ++k) {
    int x;
    std::cin >> x;
    std::cout << Check(x) << '\n';
  }
}
