#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;

        int cost = prices[0];
        int profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (profit < prices[i] - cost)
                profit = prices[i] - cost;
            if (cost > prices[i])
                cost = prices[i];
        }
        return profit;
    }

    int maxProfit_1(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;

        vector<int> profit(prices.size(), 0);
        int cost = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            profit[i] = prices[i] - cost;
            if (cost > prices[i])
                cost = prices[i];
        }
        std::sort(profit.begin(), profit.end());

        return profit[prices.size() - 1];
    }
};

int main()
{
    Solution s;

    vector<int> prices{7, 6, 4};
    cout << s.maxProfit(prices) << endl;
    cout << s.maxProfit_1(prices) << endl;
}