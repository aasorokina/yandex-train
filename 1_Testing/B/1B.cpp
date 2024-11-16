#include <iostream>

int main() {
  unsigned long long int a, b, c, d, m, n = 0;
  std::cin >> a >> b >> c >> d;

  unsigned long long int red_shirts = a + 1;
  unsigned long long int blue_shirts = b + 1;
  unsigned long long int red_socks = c + 1;
  unsigned long long int blue_socks = d + 1;
  unsigned long long int both_shirts = std::max(a, b) + 1;
  unsigned long long int both_socks = std::max(c, d) + 1;

  if (a == 0) {
    m = 1;
    n = red_socks;
  } else if (b == 0) {
    m = 1;
    n = blue_socks;
  } else if (c == 0) {
    m = red_shirts;
    n = 1;
  } else if (d == 0) {
    m = blue_shirts;
    n = 1;
  } else if ((red_shirts + red_socks) < (blue_shirts + blue_socks) &&
             (red_shirts + red_socks < both_shirts + 1) &&
             (red_shirts + red_socks < both_socks + 1)) {
    m = red_shirts;
    n = red_socks;
  } else if ((red_shirts + red_socks) > (blue_shirts + blue_socks) &&
             (blue_shirts + blue_socks < both_shirts + 1) &&
             (blue_shirts + blue_socks < both_socks + 1)) {
    m = blue_shirts;
    n = blue_socks;
  } else {
    if ((red_shirts == both_shirts || blue_shirts == both_shirts) && (both_shirts + 1 <= both_socks + 1)) {
      m = both_shirts;
      n = 1;
    }
    else if((red_socks == both_socks || blue_socks == both_socks) && (both_shirts + 1 > both_socks + 1)){
      m = 1;
      n = both_socks;
    }
  }
  std::cout << m << " " << n << "\n";
  return 0;
}