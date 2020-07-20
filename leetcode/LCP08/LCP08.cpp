#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
	vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
		vector<int> out(requirements.size(), -1);
		int prop_count = increase[0].size();

		// 计算当天的属性值
		for (int i = 1; i < increase.size(); i++) {
			for (int j = 0; j < prop_count; j++) {
				increase[i][j] += increase[i - 1][j];
			}
		}

		// 构建属性列
		vector<vector<int>> prop(prop_count, vector<int>(increase.size() + 1, 0));
		for (int i = 0; i < increase.size(); i++) {
			for (int j = 0; j < prop_count; j++) {
				prop[j][i + 1] = increase[i][j];
			}
		}


		// i 为requirements的每一行索引
		for (int i = 0; i < requirements.size(); i++) {
			for (int j = 0; j < prop_count; j++)   // j为列，含义为：属性值
			{
				int this_day = find(requirements[i][j], prop[j]);   // 满足该属性的最小天数
				if (this_day == -1)  // 该属性无法满足触发条件
				{
					out[i] = -1;
					break;  // 退出循环，开始检测下一个剧情
				}
				if (this_day > out[i])  // 如果该天数大于之前的属性最大值（隐含了该属性可以满足触发条件）
				{
					out[i] = this_day; // 进行更新
				}
			}
		}

		return out;
	}

	int find(const int value, const vector<int>& vec) const {
		int l = 0;
		int r = vec.size() - 1;
		int middle = l + (r - l) / 2;

		while (l <= r) {
			middle = l + (r - l) / 2;

			if (vec[middle] >= value) {
				r = middle - 1;
			}
			else {
				l = middle + 1;
			}
		}
		if (r + 1 > vec.size() - 1)	return -1;

		return (vec[r + 1] >= value ? r + 1 : -1);
	}

};

int main() {
	vector<vector<int>> increase{ {2,8,4} ,{2,5,0},{10,9,8} };
	vector<vector<int>> r{ {2,11,3} ,{15,10,7},{9,17,12},{8,1,14} };
	Solution solution;
	vector<int> o = solution.getTriggerTime(increase, r);

	for (auto i : o)
		cout << i << endl;
}