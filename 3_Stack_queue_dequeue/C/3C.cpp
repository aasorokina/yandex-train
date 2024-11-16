#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

int main() {
  long long int n, k;
  std::cin >> n >> k;
  std::vector<long long int> numbers(n);
  std::vector<long long int> answer;
  std::deque<std::pair<long long int, long long int>> deq;

  for (int i = 0; i < n; i++) {
    std::cin >> numbers[i];
  }

  int left = 0;
  int right = 0;
  while (right < n) {
    if (!deq.empty() && numbers[right] < deq.back().first) {
      while (!deq.empty() && numbers[right] < deq.back().first) deq.pop_back();
    }
    deq.push_back({numbers[right], right});
    right++;
    if (right - left >= k) {
      if (left > deq.front().second) {
        deq.pop_front();
      }
      answer.push_back(deq.front().first);
      left++;
    }
  }

  for (int i = 0; i < answer.size(); i++) {
    std::cout << answer[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}