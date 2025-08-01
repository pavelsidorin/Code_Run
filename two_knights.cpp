#include <iostream>
#include <vector>
#include <climits>
#include <queue>

struct Coord {
  int x;
  int y;
  Coord(int x, int y) : x(x), y(y) {
  }
};

Coord Convert(const std::string& s) {
  return {(s[0] - '`') - 1, (s[1] - '0') - 1};
}

int BFS(const Coord& c1, const Coord& c2) {
  std::vector<std::vector<int>> dist(8, std::vector<int>(8, INT_MAX));
  dist[c1.x][c1.y] = 0;
  std::queue<Coord> q;
  q.push(c1);
  while (!q.empty()) {
    Coord from = q.front();
    q.pop();
    std::vector<Coord> d = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    for (const auto& [dx, dy] : d) {
      int x = from.x + dx;
      int y = from.y + dy;
      if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (dist[x][y] == INT_MAX) {
          dist[x][y] = dist[from.x][from.y] + 1;
          q.emplace(x, y);
        }
      }
    }
  }
  if ( dist[c2.x][c2.y]== INT_MAX || dist[c2.x][c2.y] % 2 != 0) {
    return -1;
  }
  return dist[c2.x][c2.y] / 2;
}

int main() {
  std::string s1;
  std::string s2;
  std::cin >> s1 >> s2;
  Coord c1 = Convert(s1);
  Coord c2 = Convert(s2);
  std::cout << BFS(c1, c2);
}
