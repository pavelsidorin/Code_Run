#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>

struct Node {
  int sum;
  double debt;
  explicit Node(int sum, double debt) : sum(sum), debt(debt) {
  }
};

struct CompareNodes {
  bool operator()(const Node& a, const Node& b) const {
    return a.sum < b.sum;
  }
};

int main() {
  int n;
  std::cin >> n;
  std::multiset<Node, CompareNodes> heap;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    heap.insert(Node(x, 0.0));
  }
  double total = 0.0;
  while (heap.size() > 1) {
    auto a = *heap.begin();
    heap.erase(heap.begin());
    auto b = *heap.begin();
    heap.erase(heap.begin());
	total += (a.sum + b.sum) * 0.05;
    heap.insert(Node(a.sum + b.sum, (a.sum + b.sum) * 0.05));
  }
  std::cout << std::fixed << std::setprecision(2) << total;
}
