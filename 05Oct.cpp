class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int ans1 = INT_MIN;
        int ans2 = INT_MIN;
        int c1 = 0;
        int c2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            int val = nums[i];
            if(val==ans1)
            {
                c1++;
            }
            else if(val==ans2)
            {
                c2++;
            }
            else if(c1==0)
            {
                ans1 = val;
                c1++;
            }
            else if(c2==0)
            {
                ans2 = val;
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ans1 && ans1!=INT_MIN)
            {
                c1++;
            }
            if(nums[i]==ans2 && ans2!=INT_MIN && ans1!=ans2)
            {
                c2++;
            }
        }
        int n = nums.size();
        vector<int>v;
        if(c1>n/3)
        {
            v.push_back(ans1);
        }   
        if(c2>n/3)
        {
            v.push_back(ans2);
        }
        return v;
    }
};