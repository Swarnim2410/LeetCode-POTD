class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        stack<int>s;
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<maxi)
            {
                return true;
            }
            while(s.size() && s.top()<nums[i])
            {
                maxi = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};