class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        double differenceX = points[1][0] - points[0][0];
        double differenceY = points[1][1] - points[0][1];
        
        if(differenceX != 0){
            double diffXtime = (points[2][0] - points[0][0]) / differenceX;
            double Yguess = points[0][1] + diffXtime * differenceY;
            if(Yguess == points[2][1]){
                return false;
            }else{
                return true;
            }
        }else{
            if(differenceY == 0){
                return false;
            }
            // x coords are all the same
            if(points[2][0] == points[0][0]){
                return false;
            }else{
                return true;
            }
        }
    }
};
