class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int x = abs(nums[i]) - 1;
            if(nums[x]<0)
            {
                return abs(nums[i]);
            }
            nums[x]*=-1;
        }  
        return 0;    
    }
};