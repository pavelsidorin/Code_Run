#include <iostream>
#include <vector>
#include <set>

struct DeadEnd {
  int number;
  int time;
  explicit DeadEnd(int number, int time) : number(number), time(time) {
  }
};

struct CompareDeadEnds {
  bool operator()(const DeadEnd& a, const DeadEnd& b) const {
    if (a.time == b.time) {
      return a.number < b.number;
    }
    return a.time < b.time;
  }
};

struct CompareNumbers {
  bool operator()(const DeadEnd& a, const DeadEnd& b) const {
    return a.number < b.number;
  }
};

int main() {
  std::set<DeadEnd, CompareDeadEnds> tree;
  std::set<DeadEnd, CompareNumbers> numbers;
  int k, n;
  std::vector<int> answer;
  std::cin >> k >> n;
  for (int i = 0; i < k; ++i) {
    tree.insert(DeadEnd(i + 1, 0));
  }
  bool b = false;
  for (int i = 0; i < n; ++i) {
    int begin_time, end_time;
    std::cin >> begin_time >> end_time;
    if (b) {
      continue;
    }
    while (!tree.empty() && tree.begin()->time < begin_time) {
      numbers.insert(*tree.begin());
      tree.erase(tree.begin());
    }
    if (numbers.empty()) {
      std::cout << 0 << " " << i + 1;
      b = true;
      continue;
    }
    DeadEnd updated_node(numbers.begin()->number, end_time);
    tree.insert(updated_node);
    answer.push_back(numbers.begin()->number);
    numbers.erase(numbers.begin());
  }
  if (!b) {
    for (const auto& x : answer) {
      std::cout << x << '\n';
    }
  }
}
