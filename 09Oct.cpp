class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int s=0;
        vector<int>v;
        int a = nums.size();
        int e=a-1;
        int ans1 =-1;
        int m = s+(e-s)/2;
        while(s<=e)
        {
             if(nums[m]==target)
             {
                 ans1 = m;
                 e = m-1;
             }
             else if(target>nums[m])
             {
                 s=m+1;
             }
             else if(target<nums[m])
             {
                 e=m-1;
             }
             m = s+(e-s)/2;
        }

        s=0;
        a = nums.size();
        e=a-1;
        int ans2 =-1;
        m = s+(e-s)/2;
        while(s<=e)
        {
             if(nums[m]==target)
             {
                 ans2 = m;
                 s = m+1;
             }
             else if(target>nums[m])
             {
                 s=m+1;
             }
             else if(target<nums[m])
             {
                 e=m-1;
             }
             m = s+(e-s)/2;
        }
        v.push_back(ans1);
        v.push_back(ans2);
        return v;

        
    }
};