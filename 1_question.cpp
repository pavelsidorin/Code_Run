#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  for (const auto& x : s) {
    if ((x - '0') % 2 != 0) {
      std::cout << 0;
      return 0;
    }
  }
  std::cout << 1;
}
