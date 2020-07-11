#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;

		vector<vector<int>> dp(prices.size(), { 0,0,0 });

		dp[0][0] = 0;
		dp[0][1] = -prices[0];
		dp[0][2] = 0;

		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2]);
			dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
			dp[i][2] = dp[i - 1][1] + prices[i];
		}

		return std::max(dp[prices.size() - 1][0], dp[prices.size() - 1][2]);

	}
};
int main() {

	vector<int> a{ 1,2,3 };

	Solution s;

	std::cout << s.maxProfit(a) << std::endl;;
}
