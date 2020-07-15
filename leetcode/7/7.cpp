#include <iostream>
#include <cmath>
using namespace std;

int reverse(int x) {

	int out = 0;

	while (x != 0) {
		int t = x % 10;
		x = x / 10;

		if (out > (INT_MAX / 10) || (out == (INT_MAX / 10) && t > (INT_MAX % 10))) { out = 0; break; }
		if (out < (INT_MIN / 10) || (out == (INT_MIN / 10) && t < (INT_MIN % 10))) { out = 0; break; }

		out = out * 10 + t;
	}

	return out;
}

int main() {
	int x = pow(2, 31) - 1;

	cout << reverse(-1463847412) << endl;
}