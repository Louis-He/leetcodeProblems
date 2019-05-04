class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        
        for(int i = left; i <= right; i++){
            bool flag = true;
            int num = i;
            while(num > 0){
                int digit = num % 10;
                if(digit == 0 || i % digit != 0){
                    flag = false;
                    break;
                }
                num /= 10;
            }
            
            if(flag){
                res.push_back(i);
            }
        }
        return res;
    }
};
