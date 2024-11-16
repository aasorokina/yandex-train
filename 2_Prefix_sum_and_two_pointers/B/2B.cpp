#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> vec(n);
  std::vector<long long int> prefix(n + 1);
  prefix[0] = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i];
    prefix[i + 1] = prefix[i] + vec[i];
  }

  int left = 0, right = 1; 
  int count = 0;
  long long int sum = 0;
  while (right != n+1) {
    sum = prefix[right] - prefix[left];
    if (sum > k) {
      left++;
      right--;
    } else if (sum == k) {
      count++;
      left++;
    }
    right++;
  }
  std::cout << count << "\n";
  return 0;
}