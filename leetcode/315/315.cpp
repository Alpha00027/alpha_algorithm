#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> count(nums.size(), 0);
		if (nums.size() <= 1) return count; // ==0; ==1,右侧没有比他小的元素

		vector<int> ordered;    // 用于排序的序列

		for (int i = nums.size() - 1; i >= 0; i--) {
			int index = insert(ordered, nums[i]);
			count[i] = index;
		}
		return count;
	}
	// 使用二分法来进行查找和插入
	int insert(vector<int>& a, int target) {
		int start = 0;
		int end = a.size() - 1;
		int mid = 0;

		// find
		while (start <= end) {  // 需要有=号（a.size()==1的情况下，start == end，而此时不能直接插入元素在start位置）
			mid = start + (end - start) / 2;

			if (target <= a[mid])   // 当等于的时候，修改end值，使得最后到达相同元素的最左侧
				end = mid - 1;
			else
				start = mid + 1;
		}
		// 将target插入到start位置去
		a.push_back(0); // 添加一个无用元素，主要是为了扩充vector。
		for (int i = a.size() - 2; i >= start; i--) {
			a[i + 1] = a[i];
		}
		a[start] = target;
		return start;
	}
};

int main() {

	vector<int> test{ 3,2,2,1,0 };
	Solution tmp;
	vector<int> result = tmp.countSmaller(test);
	for (auto i = result.begin(); i != result.end(); i++) {
		cout << *i << endl;
	}
}
