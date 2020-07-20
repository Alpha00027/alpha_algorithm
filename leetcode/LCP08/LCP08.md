# LeetCode LCP 08. 剧情触发时间

## 题目

在战略游戏中，玩家往往需要发展自己的势力来触发各种新的剧情。一个势力的主要属性有三种，分别是文明等级（C），资源储备（R）以及人口数量（H）。在游戏开始时（第 0 天），三种属性的值均为 0。

随着游戏进程的进行，每一天玩家的三种属性都会对应增加，我们用一个二维数组 increase 来表示每天的增加情况。这个二维数组的每个元素是一个长度为 3 的一维数组，例如 [[1,2,1],[3,4,2]] 表示第一天三种属性分别增加 1,2,1 而第二天分别增加 3,4,2。

所有剧情的触发条件也用一个二维数组 requirements 表示。这个二维数组的每个元素是一个长度为 3 的一维数组，对于某个剧情的触发条件 c[i], r[i], h[i]，如果当前 C >= c[i] 且 R >= r[i] 且 H >= h[i] ，则剧情会被触发。

根据所给信息，请计算每个剧情的触发时间，并以一个数组返回。如果某个剧情不会被触发，则该剧情对应的触发时间为 -1 。

示例 1：

    输入： increase = [[2,8,4],[2,5,0],[10,9,8]] requirements = [[2,11,3],[15,10,7],[9,17,12],[8,1,14]]

    输出: [2,-1,3,-1]

    解释：

    初始时，C = 0，R = 0，H = 0

    第 1 天，C = 2，R = 8，H = 4

    第 2 天，C = 4，R = 13，H = 4，此时触发剧情 0

    第 3 天，C = 14，R = 22，H = 12，此时触发剧情 2

    剧情 1 和 3 无法触发。

示例 2：

    输入： increase = [[0,4,5],[4,8,8],[8,6,1],[10,10,0]] requirements = [[12,11,16],[20,2,6],[9,2,6],[10,18,3],[8,14,9]]

    输出: [-1,4,3,3,3]

    示例 3：

    输入： increase = [[1,1,1]] requirements = [[0,0,0]]

    输出: [0]

限制：

    1 <= increase.length <= 10000
    1 <= requirements.length <= 100000
    0 <= increase[i] <= 10
    0 <= requirements[i] <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ju-qing-hong-fa-shi-jian
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## 题解

首先考虑题目输入，`increase`为每日的属性递增值，而我们比较的是每日的属性值，所以我们需要构建数组来保存每日的属性值。
```C++
// 计算当天的属性值
for (int i = 1; i < increase.size(); i++) {
    for (int j = 0; j < prop_count; j++) {  // 属性值数量
        increase[i][j] += increase[i - 1][j];
    }
}
```

观察得知，属性值数组为递增数组，而触发条件数组不一定是递增数组。为了保证时间最短，我们通过遍历触发条件数组，然后在每层循环中访问属性值数组（由于属性值数组递增，查找具体元素可以节省时间）。

此时有一点需要注意，我们直接访问所有的列时，由于属性数据形式为`{[a,b,c]...[a,b,c]}`，我们无法直接取出所有的a属性，所以我们需要单独构建一个数组，来存储单个属性，最后构成：`{[a,a...a],[b,b...b],[c,c...c]}`形式。

同时，初始属性值为0，题目中数组的索引为0时代表第一天。为方便计算，我们手动添加0作为属性第0天的值，此时索引为1代表第一天。
```C++
// 构建属性列
vector<vector<int>> prop(prop_count, vector<int>(increase.size() + 1, 0));
for (int i = 0; i < increase.size(); i++) {
    for (int j = 0; j < prop_count; j++) {
        prop[j][i + 1] = increase[i][j];
    }
}
```

在构建完成属性列后，我们就可以开始进行寻找某个属性值在属性数组中第一个大于等于该属性的元素索引。我们使用二分法来进行查找：
```C++
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
```

此时，整个程序基本可以呈现：
```C++
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
```