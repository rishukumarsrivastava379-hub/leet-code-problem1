class Solution {
public:
    int maxArea(vector<int>& height) {
        int MaxWater =0;//ans
        int lp=0,rp=height.size()-1;
        while(lp<rp){
            int w=rp-lp;
            int ht=min(height[lp],height[rp]);
            int currWater=w*ht;
            MaxWater=max(MaxWater,currWater);
            height[lp]<height[rp]?lp++:rp--;
        }

        return MaxWater;
        
    }
};