class Solution {
public:
    // T: O(nlogn)
    int candy_sort(vector<int>& ratings) {
        vector<int> candies(ratings.size(),1);
        vector<pair<int,int>> temp;
        for(int i=0;i<ratings.size();i++)
            temp.push_back({ratings[i],i});
        sort(temp.begin(),temp.end());
        for(auto e:temp){
            int i=e.second;
            if(i>0 && ratings[i]>ratings[i-1]) candies[i]=max(candies[i],1+candies[i-1]);
            if(i<ratings.size()-1 && ratings[i]>ratings[i+1]) candies[i]=max(candies[i],1+candies[i+1]);
        }
        int sum=0;
        for(int candy:candies) sum+=candy;
        return sum;
    }
    
    // T: O(n)
    int candy(vector<int>& ratings) {
        vector<int> left(ratings.size(),1), right(ratings.size(),1);
        for(int i=1;i<ratings.size();i++)
            if(ratings[i]>ratings[i-1]) left[i]=left[i-1]+1;
        for(int i=ratings.size()-2;i>=0;i--)
            if(ratings[i]>ratings[i+1]) right[i]=right[i+1]+1;
        int sum=0;
        for(int i=0;i<ratings.size();i++){
            sum+=max(left[i],right[i]);
        }
        return sum;
    }
};