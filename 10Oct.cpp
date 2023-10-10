class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size();
        set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }    
        int x=0;
        for(auto it : s)
        {
            nums[x]=it;
            x++;
        }
        int a = s.size();
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