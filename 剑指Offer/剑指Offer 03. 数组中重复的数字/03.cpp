class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int,int> out;
        for(int i = 0; i < nums.size();i++)
        {
            if(out.count(nums[i]) == 0) // 判断map中是否存在该元素
            {
                out[nums[i]] = 1;
            }
            else    // 说明数组之前有该元素，此时的元素是第二个
            {
                return nums[i];
            }
        }
        return 0;
    }
};