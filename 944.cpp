class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int rowSize = A.size();
        int colSize = A[0].size();
        
        int count = 0;
        for(int i = 0; i < colSize; i++){
            bool flag = true;
            for(int j = 0; j < rowSize - 1; j++){
                if(A[j][i] > A[j + 1][i]){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                count++;
            }
        }
        
        return count;
    }
};
