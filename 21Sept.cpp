class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();  
        int total_elements = n1 + n2;
        //I always want to perform binary search on shorter array..
        //I will always perform on nums1 and so if second array size is
        //larger, swap the two arrays..
        if(n1 > n2)
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        //I require leftreq elements on left side..
        int leftreq = (n1 + n2 + 1)/2;
        int start = 0;
        int end = n1;
        while(start<=end)
        {
            //mid1 elements on left and mid2 elements on right...
            int mid1 = start + (end-start)/2;
            int mid2 = leftreq - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            //check validity for all 4 pointers...
            if(mid1 < n1)
            {
                r1 = nums1[mid1];
            }
            if(mid2 < n2)
            {
                r2 = nums2[mid2];
            }
            if(mid1 - 1 >= 0)
            {
                l1 = nums1[mid1-1];
            }
            if(mid2 - 1 >= 0)
            {
                l2 = nums2[mid2 - 1];
            }
            //if our sequence is valid..
            if(l1 <= r2 && l2 <= r1)
            {
                //if total number of elements are odd, return max of both lefts..
                if(total_elements % 2)
                {
                    return max(l1,l2);
                }
                //else return max of lefts + min of rights divided by 2..
                else
                {
                    return ((double)(max(l1,l2) + min(r1,r2))) / 2.0;   
                }
            }
            //derived by dry run..
            else if(l1 > r2)
            {
                end = mid1 - 1;
            }
            else
            {
                start = mid1 + 1;
            }
        }
        return 0;
    }
};