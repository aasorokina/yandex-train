#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  int m, n;
  std::cin >> n >> m;
  std::unordered_map<int, int> heights;
  std::vector<std::pair<int, std::pair<int, int>>> events;

  int l, r, x;
  for (int i = 0; i < n; i++) {
    std::cin >> l >> r >> x;
    events.push_back({l, {r, x}});
  }

  std::vector<int> areas(m);
  for (int i = 0; i < m; i++) {
    std::cin >> areas[i];
  }

  for (auto&& ev : events) {
    int l = ev.first;
    int r = ev.second.first;
    int x = ev.second.second;

    for (int j = 0, size = areas.size(); j < size; j++) {
      int num = areas[j];
      if (num >= l && num <= r) {
        heights[num] += x * (((num - l) % 2 == 0)? 1 : -1);
      }
    }
  }

  for (int n : areas) {
    std::cout << heights[n] << '\n';
  }

  return 0;
}
