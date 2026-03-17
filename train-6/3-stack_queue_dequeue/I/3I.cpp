#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using ull = unsigned long long int;
using ll = long long int;

void can_go(std::vector<std::deque<std::pair<int, int>>> &rovers,
            std::deque<std::pair<int, int>> &queue, int const &time,
            int const &a, int const &b, std::vector<int> &answer);

int main() {
  int n, a, b;
  std::cin >> n >> a >> b;
  std::vector<int> answer(n, 0);
  std::vector<std::deque<std::pair<int, int>>> rovers;
  std::deque<std::pair<int, int>> first;
  std::deque<std::pair<int, int>> second;
  std::deque<std::pair<int, int>> third;
  std::deque<std::pair<int, int>> fourth;

  int d, t;
  for (int i = 0; i < n; i++) {
    std::cin >> d >> t;
    if (d == 1)
      first.push_back({i + 1, t});
    else if (d == 2)
      second.push_back({i + 1, t});
    else if (d == 3)
      third.push_back({i + 1, t});
    else if (d == 4)
      fourth.push_back({i + 1, t});
  }
  std::sort(first.begin(), first.end(),
            [](const auto &a, const auto &b) { return a.second < b.second; });
  std::sort(second.begin(), second.end(),
            [](const auto &a, const auto &b) { return a.second < b.second; });
  std::sort(third.begin(), third.end(),
            [](const auto &a, const auto &b) { return a.second < b.second; });
  std::sort(fourth.begin(), fourth.end(),
            [](const auto &a, const auto &b) { return a.second < b.second; });

  rovers.push_back(first);
  rovers.push_back(second);
  rovers.push_back(third);
  rovers.push_back(fourth);

  for (int i = 1; i <= 1000; i++) {
    can_go(rovers, rovers[0], i, a - 1, b - 1, answer);
  }

  for (int i : answer) {
    std::cout << i << '\n';
  }
  return 0;
}

void can_go(std::vector<std::deque<std::pair<int, int>>> &rovers,
            std::deque<std::pair<int, int>> &queue, int const &time,
            int const &a, int const &b, std::vector<int> &answer) {
  bool main_straight = (abs(a - b) == 2) ? true : false;
  bool passed = false;

  if (main_straight) {
    if (!rovers[a].empty() && time >= rovers[a].front().second) {
      answer[rovers[a].front().first - 1] = time;
      rovers[a].pop_front();
      passed = true;
    }
    if (!rovers[b].empty() && time >= rovers[b].front().second) {
      answer[rovers[b].front().first - 1] = time;
      rovers[b].pop_front();
      passed = true;
    }
    if (!passed) {
      int c = (a == 3) ? 0 : (a + 1);
      int d = (b == 3) ? 0 : (b + 1);
      if (!rovers[c].empty() && time >= rovers[c].front().second) {
        answer[rovers[c].front().first - 1] = time;
        rovers[c].pop_front();
        bool passed = true;
      }
      if (!rovers[d].empty() && time >= rovers[d].front().second) {
        answer[rovers[d].front().first - 1] = time;
        rovers[d].pop_front();
        bool passed = true;
      }
    }
  } else {
    for (int i = 0; i < 4 && passed == false; i++) {
      if (!rovers[i].empty() && time >= rovers[i].front().second) {
        int right = (i == 0) ? 3 : (i - 1);
        int left = (i == 3) ? 0 : (i + 1);
        if ((i == a && right == b) || (i == b && right == a)) {
          if (rovers[right].empty() || time < rovers[right].front().second) {
            answer[rovers[i].front().first - 1] = time;
            rovers[i].pop_front();
            passed = true;
          }
        } else if ((i == a || i == b) && right != a && right != b) {
          answer[rovers[i].front().first - 1] = time;
          rovers[i].pop_front();
          passed = true;
        } else if ((i != a && i != b) &&
                   (rovers[a].empty() || time < rovers[a].front().second) &&
                   (rovers[b].empty() || time < rovers[b].front().second)) {
          if (rovers[right].empty() || time < rovers[right].front().second) {
            answer[rovers[i].front().first - 1] = time;
            rovers[i].pop_front();
            passed = true;
          }
        }
      }
    }
  }
}