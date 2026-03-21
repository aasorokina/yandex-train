#include <algorithm>
#include <iostream>

using ull = unsigned long long;

int folds(ull a, ull b) {
  int res = 0;
  while (a > b) {
    b <<= 1;
    res++;
  }
  return res;
}

int main() {
  ull n, m, h, w, res = 0;
  std::cin >> n >> m >> h >> w;

  int cnt1 = folds(n, h) + folds(m, w); 
  int cnt2 = folds(n, w) + folds(m, h); 
  res = std::min(cnt1, cnt2);

  std::cout << res << '\n';
  return 0;
}
