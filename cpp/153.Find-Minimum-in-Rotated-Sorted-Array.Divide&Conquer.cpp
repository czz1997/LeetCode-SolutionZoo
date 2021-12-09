// 100% faster
// O(logn) O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(isSorted(nums, 0, nums.size() - 1))
            return nums[0];
        
        int i{}, j{(int)nums.size() - 1}, mid{};
        while(j - i > 1){
            mid = (i+j)/2;
            if(isSorted(nums, i, mid)){
                i = mid;
            }
            else
                j = mid;
        }
        return min(nums[i], nums[j]);
    }
    
    bool isSorted(vector<int>& nums, int i, int j){
        if(nums[i] < nums[j] || i == j)
            return true;
        else
            return false;
    }
};
