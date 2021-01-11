class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = 0, b=0;
        
        vector<int> copy = nums1;
        int it=0;
        
        while(a < m && b < n){
            if(copy[a] < nums2[b]){
                nums1[it++] = copy[a++];
            }else{
                nums1[it++] = nums2[b++];
            }
        }
        
        while(a < m)
            nums1[it++] = copy[a++];
        
        while(b < n)
            nums1[it++] = nums2[b++];
        
    }
};