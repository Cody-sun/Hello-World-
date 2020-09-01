#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int flag = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        flag++;
        for (int j = i + 1; j < nums.size(); j++)
            if (nums[i] != nums[j])
            {
                nums[flag] = nums[j];
                i = j - 1;
            }
    }
    cout << flag;
    return 0;
}
