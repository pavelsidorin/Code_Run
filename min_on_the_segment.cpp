#include <iostream>
#include <queue>
#include <deque>

class MinQue {
  std::queue<int> q_;
  std::deque<int> min_;
 public:

  void Push(int& x) {
    q_.push(x);
    while (!min_.empty() && min_.back() > x) {
      min_.pop_back();
    }
    min_.push_back(x);
  }

  void Pop() {
    if (q_.empty()) {
      return;
    }
    if (!min_.empty() && q_.front() == min_.front()) {
      min_.pop_front();
    }
    q_.pop();
  }

  int ExtractMin() {
    return min_.front();
  }

  explicit MinQue(int k) {
    for (int i = 0; i < k; ++i) {
      int x;
      std::cin >> x;
      Push(x);
    }
    std::cout << ExtractMin() << '\n';
  }

};

int main() {
  int n, k;
  std::cin >> n >> k;
  MinQue q(k);
  for (int i = 0; i < n - k; ++i) {
    int x;
    std::cin >> x;
    q.Push(x);
    q.Pop();
    std::cout << q.ExtractMin() << '\n';
  }
}
