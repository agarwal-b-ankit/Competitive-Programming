class Solution {
private:
    int count(int n){
        return (n*(n+1))/2;
    }
public:
    int candy(vector<int>& ratings) {
        int sum=0, slope=0, currSlope=0, up=0, down=0, curr;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]) curr=1;
            else if(ratings[i]<ratings[i-1]) curr=-1;
            else curr=0;
            
            if((slope>0 && curr==0) || (slope<0 && curr>=0)){
                sum+=count(up)+count(down)+max(up,down);
                up=0;
                down=0;
            }
            if(curr>0) up++;
            else if(curr<0) down++;
            else sum++;
            slope=curr;
        }
        sum+=count(up)+count(down)+1+max(up,down);
        return sum;
    }
};