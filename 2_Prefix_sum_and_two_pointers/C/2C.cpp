#include <iostream>
#include <vector>

int main() {
  int n, r;
  std::cin >> n >> r;
  std::vector<long long int> vec(n);
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i];
  }
  int left = 0, right = 1;
  long long int count = 0;
  long long int sum = 0;
  while (right != n) {
    sum = vec[right] - vec[left];
    if (sum > r) {
      count += (n-right);
      left++;
      right--;
    }
    right++;
  }
  std::cout << count << "\n";
  return 0;
}