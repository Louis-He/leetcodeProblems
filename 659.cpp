class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size() < 3){
            return false;
        }

        vector<int> numNum = vector<int>(nums[nums.size() - 1] - nums[0] + 2, 0);
        int minimum = nums[0];

        for(int i = 0; i < nums.size(); i++){
            numNum[nums[i] - minimum]++;
        }

        /* DEBUG START */
//        for(int i = 0; i < numNum.size(); i++){
//            cout << numNum[i] << ", ";
//        }
        /* DEBUG END */

        queue<int> possibleBegins = queue<int>();
        int previous = 0;
        for(int i = 0; i < numNum.size(); i++){
            int current = numNum[i];
            if(current - previous > 0){
                while(current - previous > 0){
                    possibleBegins.push(i);
                    current--;
                }
            }else if(current - previous < 0){
                while(current - previous < 0){
                    int leastBegin = possibleBegins.front();
                    if(i - 1 - leastBegin < 2){
                        // a chain with less than 3 consecutive nums must exist
                        return false;
                    }else{
                        possibleBegins.pop();
                        current++;
                    }
                }
            }

            previous = numNum[i];
        }

        return true;
    }
};