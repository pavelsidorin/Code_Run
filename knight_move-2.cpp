#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

int n, m;
std::unordered_map<int64_t, __int128_t> cache;

__int128_t F(int x, int y) {
    if (x == n - 1 && y == m - 1) return 1;
    if (x > n - 1 || x < 0 || y < 0 || y > m - 1) return 0;
    int64_t key = x * 51 + y;
    if (cache.count(key)) return cache[key];
    return cache[key] = F(x + 1, y + 2) + F(x + 2, y + 1) + F(x + 2, y - 1) + F(x - 1, y + 2);
}

void print_int128(__int128_t num) {
    if (num == 0) {
        std::cout << "0";
        return;
    }
    bool is_negative = (num < 0);
    if (is_negative) num = -num;

    std::string result;
    while (num > 0) {
        int digit = num % 10;
        result.push_back('0' + digit);
        num /= 10;
    }
    if (is_negative) result.push_back('-');
    std::reverse(result.begin(), result.end());
    std::cout << result;
}

int main() {
    std::cin >> n >> m;
    print_int128(F(0, 0));
    return 0;
}
