#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        if (n <= 0)
            return 0;

        int f[n + 1]{0};
        f[0] = 1;

        for (int index = 1; index <= n; index++) // index:1->n
        {
            for (int i = 1; i <= index; i++) // i:1->index
            {
                f[index] = f[index] + f[i - 1] * f[index - i];
            }
        }

        return f[n];
    }
};

int main()
{
    Solution s;

    cout << s.numTrees(4) << endl;
}