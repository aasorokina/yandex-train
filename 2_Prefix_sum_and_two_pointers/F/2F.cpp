#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  unsigned long long int mod = 1000000007;
  std::vector<long long int> vec(n);
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i];
  }

  std::vector<unsigned long long int> prefix_sum(n + 1, 0);
  std::vector<unsigned long long int> suffix_sum(n + 1, 0);

  for (int i = 0; i < n; i++) {
    prefix_sum[i + 1] = (prefix_sum[i] + vec[i]) % mod;
  }

  for (int i = n - 1; i >= 0; i--) {
    suffix_sum[i] = (suffix_sum[i + 1] + vec[i]) % mod;
  }

  unsigned long long int answer = 0;
  for (int i = 1; i < n - 1; i++) {
    answer = (answer +
              ((vec[i] * ((prefix_sum[i] * suffix_sum[i + 1]) % mod)) % mod)) %
             mod;
  }

  std::cout << (answer % mod) << '\n';
  return 0;
}