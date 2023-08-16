class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        list<int>l;
        int i=0;
        int j=0;
        int n = nums.size();
        vector<int>v;
        while(j<n)
        {
            if(l.size()==0)
            {
                l.push_back(nums[j]);
            }
            else
            {
                while(l.size() && l.back()<nums[j])
                {
                    l.pop_back();
                }
                l.push_back(nums[j]);
            }
            if(j-i+1<k)
            {
                j++;
            }
            else
            {
                v.push_back(l.front());
                if(nums[i]==l.front())
                {
                    l.pop_front();
                }
                i++;
                j++;
               
            }
        }
        return v;
        
    }
};