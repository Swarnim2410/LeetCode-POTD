class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        int n = nums.size();
        int f=0,g=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<=nums[i+1])
            {
                f++;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>=nums[i+1])
            {
                g++;
            }
        } 
        return (f==n-1 || g==n-1);
    }
};