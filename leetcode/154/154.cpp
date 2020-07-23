class Solution {
public:
    int minArray(vector<int>& numbers) {
        //if(numbers.size() == 0) return 0;
        if(numbers.size() == 1) return numbers[0];

        int tmp = numbers[numbers.size()-1];
        for(int i = numbers.size()-2;i>=0;i--)
        {
            if(numbers[i] <= tmp) tmp = numbers[i];
            else
                break;
        }
        return tmp;
    }
};