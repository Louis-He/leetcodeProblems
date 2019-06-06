class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        if(A.size() == 0){ 
            return 0;
        }
        vector<int> reminderNum = vector<int>(K, 0);
        reminderNum[0] = 1;
        
        int sum = 0;
        int count = 0;
        for(int i = 0; i < A.size(); i++){
            sum += A[i];
            sum = sum % K;
            while(sum < 0){
                sum += K;
            }
            count += reminderNum[sum];
            reminderNum[sum] ++;
        }
        return count;
    }
};
