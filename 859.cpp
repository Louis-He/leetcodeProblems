class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()){
            return false;
        }
        
        if(A == B){
            vector<int> stat = vector<int>(26, 0);
        
            for(int i = 0; i < A.size(); i++){
                stat[A[i] - 97]++;
            }

            for(int i = 0; i < stat.size(); i++){
                if(stat[i] >= 2){
                    return true;
                }
            }
            return false;
        }else{
            int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
            for(int i = 0; i < A.size(); i++){
                if(A[i] != B[i]){
                    if(a1 == 0){
                        a1 = A[i];
                        b1 = B[i];
                    }else if(a2 == 0){
                        a2 = A[i];
                        b2 = B[i];
                    }else{
                        return false;
                    }
                }
            }
            if(a1 == b2 && a2 == b1){
                return true;
            }else{
                return false;
            }
        }
    }
};
