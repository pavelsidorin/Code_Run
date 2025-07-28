#include <iostream>
#include <queue>
#include <deque>

class MiddleQue {
  std::queue<int> q_begin_;
  std::deque<int> q_end_;
 public:

  void Push(int& x) {
    q_end_.push_back(x);
    if (q_end_.size() > q_begin_.size()) {
      q_begin_.push(q_end_.front());
      q_end_.pop_front();
    }
  }

  void PushMiddle(int x) {
    if (q_end_.size() < q_begin_.size()) {
      q_end_.push_front(x);
    } else {
      q_begin_.push(x);
    }
  }

  void Pop() {
    q_begin_.pop();
    if (q_begin_.size() < q_end_.size()) {
      q_begin_.push(q_end_.front());
      q_end_.pop_front();
    }
  }

  int ExtractNumber() {
    return q_begin_.front();
  }
};

int main() {
  int n;
  std::cin >> n;
  MiddleQue q;
  for (int i = 0; i < n; ++i) {
    char op = 0;
    std::cin >> op;
    if (op == '-') {
      std::cout << q.ExtractNumber() << '\n';
      q.Pop();
    }
    if (op == '+') {
      int x;
      std::cin >> x;
      q.Push(x);
    }
    if (op == '*') {
      int x;
      std::cin >> x;
      q.PushMiddle(x);
    }
  }
}
