#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long int;

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<ll> vec(n);
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i];
  }

  std::sort(vec.begin(), vec.end());
  
  int left = 0, right = 1;
  ll count = 1;
  ll sum = 0;

  while (right != n) {
    sum = vec[right] - vec[left];
    if (sum > k) left++;
    else count++;
    right++;
  }
  std::cout << count << "\n";
  return 0;
}