#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

struct Event {
  size_t time;
  size_t coord;
};

class Rectangle {
 public:
  size_t n;
  std::stack<Event> events;
  std::vector<size_t> rectangle;

  explicit Rectangle(size_t n) : n(n) {
    rectangle.resize(n);
    for (size_t i = 0; i < n; ++i) {
      std::cin >> rectangle[i];
    }
  }

  size_t MaxArea() {

    size_t max_area = 0;
    for (size_t time = 0; time < n; ++time) {
      while (!events.empty() && events.top().coord >= rectangle[time]) {
        auto prev = std::move(events.top());
        events.pop();
        if (!events.empty()) {
          max_area = std::max((time - events.top().time - 1) * prev.coord, max_area);
        } else {
          max_area = std::max((time) * prev.coord, max_area);
        }
      }
      events.emplace(time, rectangle[time]);
    }
    while (!events.empty()) {
      auto prev = std::move(events.top());
      events.pop();
      if (!events.empty()) {
        max_area = std::max((n - events.top().time - 1) * prev.coord, max_area);
      } else {
        max_area = std::max((n) * prev.coord, max_area);
      }
    }
    return max_area;
  }
};

int main() {
  size_t n;
  std::cin >> n;
  Rectangle rectangle(n);
  std::cout << rectangle.MaxArea();
}
