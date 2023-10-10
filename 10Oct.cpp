class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int x=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                nums[x]=nums[i];
                x++;
            }
        }
        nums[x]=nums[n-1];
        x++;
        int a = x;
        int i=0;
        int j=0;
        int left = n - a;
        int mini = n;
        while(i<a)
        {
            int curr = nums[i];
            int range = nums[i] + n - 1;
            while(j<a && nums[j]<=range)
            {
                j++;
            }
            mini = min(mini,n-j+i);
            i++;
        }
        return mini;
    }
};