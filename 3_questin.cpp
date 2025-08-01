#include <algorithm>
#include <numeric>
#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  int x = a * d + c * b;
  int y = b * d;
  int del = std::gcd(x, y);
  x /= del;
  y /= del;
  std::cout << x << " " << y;
}
