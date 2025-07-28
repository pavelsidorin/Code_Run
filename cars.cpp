#include <iostream>
#include <vector>
#include <set>
#include <climits>

struct Car {
  int number;
  int p;
  explicit Car(int number, int p) : number(number), p(p) {
  }
};

struct CompareCarsOnTheGround {
  bool operator()(const Car& a, const Car& b) const {
    return a.p > b.p;
  }
};

struct CompareNextCars {
  bool operator()(const Car& a, const Car& b) const {
    if (a.number == b.number) {
      return a.p < b.p;
    }
    return a.number < b.number;
  }
};

int main() {
  size_t n, k, p;
  std::cin >> n >> k >> p;
  std::multiset<Car, CompareCarsOnTheGround> ground_heap;
  std::multiset<Car, CompareNextCars> next_heap;
  std::vector<int> cars(p);
  for (size_t i = 0; i < p; ++i) {
    std::cin >> cars[i];
    next_heap.insert(Car(cars[i], i));
  }
  size_t op = 0;
  size_t i = 0;
  while (ground_heap.size() < k && ground_heap.size() < p) {
    auto it = ground_heap.find(Car(cars[i], i));
    if (it == ground_heap.end()) {
      auto new_it = next_heap.find(Car(cars[i], i));
      ++new_it;
      if (new_it != next_heap.end() && new_it->number == cars[i]) {
        ground_heap.insert(*new_it);
      } else {
        ground_heap.insert(Car(cars[i], INT_MAX));
      }
      ++op;
    } else {
      ground_heap.erase(it);
      auto new_it = next_heap.find(Car(cars[i], i));
      ++new_it;
      if (new_it != next_heap.end() && new_it->number == cars[i]) {
        ground_heap.insert(*new_it);
      } else {
        ground_heap.insert(Car(cars[i], INT_MAX));
      }
    }
    ++i;
  }
  for (int j = i; j < p; ++j) {
    auto it = ground_heap.find(Car(cars[j], j));
    if (it == ground_heap.end()) {
      auto new_it = next_heap.find(Car(cars[j], j));
      ++new_it;
      if (ground_heap.size() == k) {
        ground_heap.erase(ground_heap.begin());
      }
      if (new_it != next_heap.end() && new_it->number == cars[j]) {
        ground_heap.insert(*new_it);
      } else {
        ground_heap.insert(Car(cars[j], INT_MAX));
      }
      ++op;
    } else {
      ground_heap.erase(it);
      auto new_it = next_heap.find(Car(cars[j], j));
      ++new_it;
      if (new_it != next_heap.end() && new_it->number == cars[j]) {
        ground_heap.insert(*new_it);
      } else {
        ground_heap.insert(Car(cars[j], INT_MAX));
      }
    }
  }
  std::cout << op;
}
