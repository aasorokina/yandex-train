#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<long long int> vec(n);
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i];
  }
  std::sort(vec.begin(), vec.end());
  int left = 0, right = 1;
  long long int count = 1;
  long long int sum = 0;
  while (right != n) {
    sum = vec[right] - vec[left];
    if (sum > k) {
      left++;
      right++;
    } else {
      right++;
      count++;
    }
  }
  std::cout << count << "\n";
  return 0;
}