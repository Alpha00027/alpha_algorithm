#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<string> out_;
	void gen(string s, int l, int r, const int n) {

		if (l < r) return;

		if (l < n) {
			gen(s + "[", l + 1, r, n);
		}
		if (r < n) {
			gen(s + "]", l, r + 1, n);
		}
		if (l == n && r == n) {
			out_.push_back(s);
			return;
		}
	}

public:
	vector<string> generateParenthesis(int n) {
		gen("", 0, 0, n);
		return out_;
	}
};

int main() {
	int n = 4;
	Solution solution;
	vector<string> o = solution.generateParenthesis(n);

	for (auto i : o) {
		cout << i << endl;
	}
}