#include <iostream>
#include <vector>
#include <set>
#include <string>

int main() {
  std::string s = "VEER";
  std::set<std::string> tree;
  std::queue<std::string> q;
  tree.insert(s);
  q.push(s);
  for (int i = 1; i <= 10; ++i) {
    std::queue<std::string> q_temp;
    while (!q.empty()) {
      std::string a = q.front();
      q.pop();
      for (int i = 0; i < a.size(); ++i) {
        if (i < a.size() - 1 && a[i] == 'E' && a[i + 1] == 'E') {
          std::string c = a.substr(0, i + 1) + 'T' + a.substr(i + 1);
          size_t b = tree.size();
          tree.insert(c);
          if (tree.size() > b) {
            q_temp.push(c);
          }
        }
        if (a[i] == 'V') {
          std::string c;
          if (i < a.size() - 1) {
            c = a.substr(0, i + 1) + 'E' + a.substr(i + 1);
          } else {
            c = a + 'E';
          }
          size_t b = tree.size();
          tree.insert(c);
          if (tree.size() > b) {
            q_temp.push(c);
          }
        }
        if (a[i] == 'R') {
          std::string c;
          c = a.substr(0, i) + 'E' + a.substr(i);
          size_t b = tree.size();
          tree.insert(c);
          if (tree.size() > b) {
            q_temp.push(c);
          }
        }
      }
    }
    q = q_temp;
  }
  int sum = 0;
  for (auto x : tree) {
    if (x.size() == 14) {
      ++sum;
    }
  }
  std::cout << sum;
}
