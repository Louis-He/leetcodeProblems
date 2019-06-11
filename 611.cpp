class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3){
            return 0;
        }

        sort(nums.begin(), nums.end());
        int numItem = nums.size();

        int res = 0;
        for(int i = numItem - 1; i >= 1; i--){
            int left = 0; int right = i - 1;
            int sum = 0;

            while(left < right){
                sum = nums[left] + nums[right];
                if(sum > nums[i]){
                    res += right - left;
                    right--;
                } else {
                    left++;
                }
            }
        }

        return res;
    }
};