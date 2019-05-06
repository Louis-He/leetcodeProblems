class Solution {
public:
    int maxArea(vector<int>& height) {
        int min; int max;
        int volumn = -1;
        
        for(int i = 0; i < height.size() - 1; i++){
            for(int j = i + 1; j < height.size(); j++){
                int tmpVolumn = int(fmin(height[i], height[j]) * (j - i));
                if (tmpVolumn > volumn){
                    volumn = tmpVolumn;
                    min = i;
                    max = j;
                }
            }
        }
        
        return volumn;
    }
};
