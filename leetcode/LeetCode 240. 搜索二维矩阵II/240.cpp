class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;

        const int rows = matrix.size();
        const int cols = matrix[0].size();

        for(int i = 0; i< rows;i++)
        {
            if(matrix[i][0] <= target && matrix[i][cols-1] >= target)
            {
                if(fun(target,matrix[i]))
                    return true;
            }
        }
        return false;
    }

    // 二分法
    bool fun(int target,vector<int> vec)
    {
        int l = 0;
        int r = vec.size()-1;

        while(l <= r)
        {
            int middle = l + (r-l)/2;

            if(target > vec[middle])
            {
                l = middle+1;
            }
            else if(target < vec[middle])
            {
                r = middle -1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};