class Solution {
public:
    // O(logm + logn), m & n are size of arrays
    int find_old(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2, int r2, int cnt) {
        if(l1>r1) return nums2[l2+cnt-1];
        else if(l2>r2) return nums1[l1+cnt-1];
        int mid1=(l1+r1)/2,mid2=(l2+r2)/2;
        int cmid1 = mid1-l1+1,cmid2=mid2-l2+1;
        if(cmid1+cmid2<=cnt){
            if(nums1[mid1]<nums2[mid2]) return find(nums1,mid1+1,r1,nums2,l2,r2,cnt-cmid1);
            else return find(nums1,l1,r1,nums2,mid2+1,r2,cnt-cmid2);
        } else{
             if(nums1[mid1]<nums2[mid2]) return find(nums1,l1,r1,nums2,l2,mid2-1,cnt);
            else return find(nums1,l1,mid1-1,nums2,l2,r2,cnt);
        }
    }
    
    // O(logk or log(m+n)), k is the kth position code is looking for
    int find(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2, int r2, int cnt) {
        if(l1>r1) return nums2[l2+cnt-1];
        else if(l2>r2) return nums1[l1+cnt-1];
        int mid1=min(l1+cnt/2,r1),mid2=min(l2+cnt/2,r2);
        int cmid1 = mid1-l1+1,cmid2=mid2-l2+1;
        if(cmid1+cmid2<=cnt){
            if(nums1[mid1]<nums2[mid2]) return find(nums1,mid1+1,r1,nums2,l2,r2,cnt-cmid1);
            else return find(nums1,l1,r1,nums2,mid2+1,r2,cnt-cmid2);
        } else{
             if(nums1[mid1]<nums2[mid2]) return find(nums1,l1,r1,nums2,l2,mid2-1,cnt);
            else return find(nums1,l1,mid1-1,nums2,l2,r2,cnt);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size()+nums2.size();
        if(len%2==1){
            return find(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,len/2+1);
        } else{
            int med1=find(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,len/2);
            int med2=find(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,len/2+1);
            return (med1+med2)/2.0;
        }
    }
};