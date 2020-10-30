class Solution {
public:
   int findNumberOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector <int> len_seq(n, 1), qtd(n, 1);
      int lis = 1;
       
      for(int i = 1; i < n; i++){
         for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
               if(len_seq[j] + 1 > len_seq[i]){
                  len_seq[i] = len_seq[j] + 1;
                  qtd[i] = qtd[j];
               }
               else if(len_seq[j] + 1 == len_seq[i]){
                  qtd[i] += qtd[j];
               }
            }
            lis = max(lis, len_seq[i]);
         }
      }
      int res = 0;
      for(int i = 0; i < n; i++){
         if(len_seq[i] == lis)res += qtd[i];
      }
      return res;
   }
};