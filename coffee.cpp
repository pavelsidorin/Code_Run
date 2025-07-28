#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::reverse;

struct Parent {
  int coupon_parent;
  bool coupon_used;
  explicit Parent(int c, bool used) : coupon_parent(c), coupon_used(used) {
  }
};

int main() {
  int n = 0;
  cin >> n;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1000000));
  vector<vector<Parent>> prev(n + 1, vector<Parent>(n + 1, Parent(0, false)));
  dp[0][0] = 0;
  vector<int> cost(n + 1);
  cost[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> cost[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int c = 0; c <= n; ++c) {
      if (dp[i - 1][c] == 1000000) {
        continue;
      }
      if (cost[i] > 100 && c < n && cost[i] + dp[i - 1][c] < dp[i][c + 1]) {
        dp[i][c + 1] = cost[i] + dp[i - 1][c];
        prev[i][c + 1] = Parent(c, false);
      } else if (cost[i] <= 100 && cost[i] + dp[i - 1][c] < dp[i][c]) {
        dp[i][c] = cost[i] + dp[i - 1][c];
        prev[i][c] = Parent(c, false);
      }
      if (c > 0 && dp[i - 1][c] < dp[i][c - 1]) {
        dp[i][c - 1] = dp[i - 1][c];
        prev[i][c - 1] = Parent(c, true);
      }
    }
  }
  int min_coupon = dp[n][0];
  int coupons = 0;
  for (int c = 1; c <= n; ++c) {
    if ((min_coupon > dp[n][c]) || (dp[n][c] == min_coupon && c > coupons)) {
      min_coupon = dp[n][c];
      coupons = c;
    }
  }
  int remain = coupons;
  vector<int> days;
  int day = n;
  while (day > 0) {
    int coupon_parent = prev[day][coupons].coupon_parent;
    bool coupon_used = prev[day][coupons].coupon_used;
    if (coupon_used) {
      days.push_back(day);
    }
    coupons = coupon_parent;
    --day;
  }
  reverse(days.begin(), days.end());
  cout << min_coupon << '\n' << remain << " " << days.size() << '\n';
  for (const int& x : days) {
    cout << x << '\n';
  }
}
