class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int count = 1;
        int index = 1;
        int previous = nums[0];
        while(index < nums.size()){
            if(nums[index] != previous){
                nums[count] = nums[index];
                count++;
            }
            previous = nums[index];
            index++;
        }
        
        return count;
    }
};
