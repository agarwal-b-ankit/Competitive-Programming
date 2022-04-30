class Solution {
public:    
    int trap(vector<int>& height) {
        vector<int> left(height.size());
        for(int i=0;i<height.size();i++){
            if(i==0) left[i]=height[i];
            else left[i]=max(left[i-1],height[i]);
        }
        vector<int> right(height.size());
        for(int i=height.size()-1;i>=0;i--){
            if(i==height.size()-1) right[i]=height[i];
            else right[i]=max(right[i+1],height[i]);
        }
        int water=0;
        for(int i=1;i<height.size()-1;i++){
            water+=min(left[i],right[i])-height[i];
        }
        return water;
    }
};