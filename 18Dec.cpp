class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            if (a >= max1)
            {
                max2 = max1;
                max1 = a;
            }
            else if (a >= max2)
            {
                max2 = a;
            }
            if (a <= min1)
            {
                min2 = min1;
                min1 = a;
            }
            else if (a <= min2)
            {
                min2 = a;
            }
        }
        return max1 * max2 - min1 * min2;
    }
};