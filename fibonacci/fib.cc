#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

int run_no_cache(int n) {
  if (n == 0)
    return 0;
  else if (n == 1 || n == 2)
    return 1;
  else
    return run_no_cache(n - 1) + run_no_cache(n - 2);
}

int run_with_cache(int n) {
  if (n == 0) return 0;
  if (n == 1 || n == 2) return 1;

  static vector<int> cache(n + 1, -1);

  if (cache[n] == -1)  // need calculate
    cache[n] = run_with_cache(n - 1) + run_with_cache(n - 2);
  return cache[n];
}

int main() {
  int count = 40;
  cout << run_no_cache(count) << endl;
  cout << run_with_cache(count) << endl;
  return 0;
}
