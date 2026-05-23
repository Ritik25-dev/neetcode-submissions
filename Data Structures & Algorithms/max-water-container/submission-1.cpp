class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int st =0, end=height.size()-1;
        while(st<end){
            int width = end-st;
            int s =min(height[st],height[end]);
            int temp = s * width;
            ans = max(ans,temp);
            if(height[st]>height[end]){
                end--;
            }
            else{
                st++;
            }
        }
        return ans;
    }
};
