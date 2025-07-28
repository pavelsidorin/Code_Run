#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;
  if (n < m) {
    int y = m + 14 - n;
    int x = (m + 6) % y + 1;
    std::cout << x;
  } else {
    std::cout << m + 7;
  }
}
