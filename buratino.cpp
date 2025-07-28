#include <iostream>
#include <vector>
#include <string>

int Time(std::string& s) {
  int hours = (s[0] - '0') * 10 + (s[1] - '0');
  int minuts = (s[3] - '0') * 10 + (s[4] - '0');
  int seconds = (s[6] - '0') * 10 + (s[7] - '0');
  return seconds + minuts * 60 + hours * 3600;
}

struct Event {
  int begin;
  int time;
  Event() : begin(0), time(0) {
  }
  explicit Event(int begin, int time) : begin(begin), time(time) {
  }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<Event> events(n);
  bool b = false;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    int begin = Time(s);
    int time;
    std::cin >> time;
    events[i] = Event(begin, time);
  }
  for (size_t i = 0; i < events.size() && !b; ++i) {
    if (events[i].begin >= 13 * 3600) {
      events.insert(events.begin() + i,  Event(13 * 3600, -1));
      b = true;
      int prev_time = 0;
      while (i < events.size() && events[i].begin < 14 * 3600) {
        prev_time = events[i].time;
        events[i].time = -1;
        ++i;
      }
      --i;
      events.insert(events.begin() + i + 1,  Event(14 * 3600, prev_time));
    }
  }
  events.emplace_back(18 * 3600, -1);
  int sum = 0;
  int total = 9 * 3600;
  size_t i = 1;
  while (i < events.size() && total < 18 * 3600) {
    if (events[i - 1].time == -1) {
      total = events[i].begin;
      ++i;
      continue;
    }
    int k = (events[i].begin - events[i - 1].begin) / events[i - 1].time;
    sum += k;
    total += k * events[i - 1].time;
    if (total < events[i].begin && total + events[i - 1].time < events[i].begin + events[i].time && (events[i].begin + events[i].time <= 13 * 3600 || (events[i].begin >= 14 * 3600 && events[i].begin + events[i].time <= 18 * 3600))) {
      sum += 1;
      total += events[i - 1].time;
      while (events[i].begin < total) {
        ++i;
      }
      --i;
      events[i].begin = total;
    } else if (total < events[i].begin) {
      total = events[i].begin;
    }
    ++i;
  }
  std::cout << sum;
}
