#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> out;
		if (nums1.size() == 0 || nums2.size() == 0) return out;

		// 排序
		std::sort(nums1.begin(), nums1.end());
		std::sort(nums2.begin(), nums2.end());

		auto p1 = nums1.begin();
		auto p2 = nums2.begin();

		while (p1 != nums1.end() && p2 != nums2.end()) {

			if (*p1 > * p2)
				p2++;
			else if (*p1 < *p2)
				p1++;
			else {
				out.push_back(*p1);
				p1++;
				p2++;
			}
		}
		return out;
	}

	vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
		vector<int> out;
		if (nums1.size() == 0 || nums2.size() == 0) return out;

		map<int, int> map1, map2;

		// 构建第一个哈希表
		for (int i = 0; i <= nums1.size() - 1; i++) {
			if (map1.find(nums1[i]) != map1.cend()) // 哈希表中有key
				map1[nums1[i]]++;
			else
				map1[nums1[i]] = 1; // 如果没有key，则构建一个
		}

		for (int i = 0; i <= nums2.size() - 1; i++) {
			if (map2.count(nums2[i]))
				map2[nums2[i]]++;
			else
				map2[nums2[i]] = 1;
		}

		// 比较两个哈希表
		for (auto it = map1.begin(); it != map1.end(); ++it) {
			if (map2.count(it->first))    // 查找map2中是否有相同的key
			{
				int min = 0;    // map1和map2中相同的key中更小的value
				if (it->second <= map2[it->first])
					min = it->second;
				else
					min = map2[it->first];

				// 将min个key放入输出
				for (int j = 0; j < min; j++) {
					out.push_back(it->first);
				}
			}
		}
		return out;
	}
};

int main() {

	vector<int> test1{ 3,3,2,1,5,7,2,3,3,3 };
	vector<int> test2{ 2,2,1,45,6,3,1,6,3,6,3,1,5,3 };
	Solution tmp;
	vector<int> result = tmp.intersect(test1, test2);
	for (auto i = result.begin(); i != result.end(); i++) {
		cout << *i << endl;
	}
	cout << endl;

	vector<int> result2 = tmp.intersect2(test1, test2);
	for (auto i = result2.begin(); i != result2.end(); i++) {
		cout << *i << endl;
	}
}