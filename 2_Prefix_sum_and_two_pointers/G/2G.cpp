#include <algorithm>
#include <iostream>
#include <vector>

using ull = unsigned long long int;

int main() {
  ull n, c;
  std::cin >> n >> c;
  std::string s;
  std::cin >> s;
  std::vector<int> prefix_a(n + 1, 0);
  std::vector<int> prefix_b(n + 1, 0);

  for (int i = 0; i < n; i++) {
    prefix_a[i + 1] = prefix_a[i] + ((s[i] == 'a') ? 1 : 0);
    prefix_b[i + 1] = prefix_b[i] + ((s[i] == 'b') ? 1 : 0);
  }

  ull left = 0;
  ull right = 1;
  ull max_len = 0;
  ull len = 0;
  ull diff = 0;

  if (n <= 2) {
    if (c > 0) {
      max_len = s.length();
    } else if (c == 0) {
      max_len = 1;
    }
    right = n;
  }

  while (right != n) {
    if (s[right] == 'b') {
      diff += (prefix_a[right] - prefix_a[left]);
    }

    if (diff > c) {
      if (s[left] == 'a') {
        diff -= (prefix_b[right + 1] - prefix_b[left]);
      }
      left++;
    } else {
      len = right - left + 1;
      if (len > max_len) max_len = len;
    }
    right++;
  }
  std::cout << max_len << '\n';
  return 0;
}