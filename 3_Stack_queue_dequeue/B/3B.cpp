#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> cities(n);
  std::vector<std::pair<int, int>> stack;
  std::vector<int> answer(n, 0);

  for (int i = 0; i < n; i++) {
    std::cin >> cities[i];
  }

  stack.push_back({cities[0], 0});
  for (int i = 1; i < n; i++) {
    if (cities[i] < stack.back().first) {
      int number = i;
      int cost = cities[i];
      while (!stack.empty() && stack.back().first > cost) {
        answer[stack.back().second] = number;
        stack.pop_back();
      }
    }
    stack.push_back({cities[i], i});
  }

  for (int i = 0; i < stack.size(); i++) {
    answer[stack[i].second] = -1;
  }

  for(int i = 0; i < answer.size(); i++ ){
    std::cout << answer[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}