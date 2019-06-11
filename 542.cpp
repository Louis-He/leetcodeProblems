class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return matrix;
        }
        vector<vector<int> > finalRes(matrix.size(), vector<int>(matrix[0].size(), 10000));

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    finalRes[i][j] = 0;
                }
                if(i >= 1){
                    finalRes[i][j] = min(finalRes[i - 1][j] + 1, finalRes[i][j]);
                }
                if(j >= 1){
                    finalRes[i][j] = min(finalRes[i][j - 1] + 1, finalRes[i][j]);
                }
            }
        }

        for(int i = matrix.size() - 1; i >= 0; i--){
            for(int j = matrix[0].size() - 1; j >= 0; j--){
                if(matrix[i][j] == 0){
                    finalRes[i][j] = 0;
                }
                if(i <= int(matrix.size()) - 2){
                    finalRes[i][j] = min(finalRes[i + 1][j] + 1, finalRes[i][j]);
                }
                if(j <= int(matrix[0].size()) - 2){
                    finalRes[i][j] = min(finalRes[i][j + 1] + 1, finalRes[i][j]);
                }
            }
        }



        return finalRes;
    }
};

