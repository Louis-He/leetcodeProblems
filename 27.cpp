class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }
        
        int current = 0;
        int endList = nums.size() - 1;
        
        while(current <= endList){
            if(nums[current] == val){
                nums[current] = nums[endList];
                endList--;
            }else{
                current++;
            }
        }
        
        return endList + 1;
    }
};
