class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int nTask[26], last[26];
        
        
        for(int i=0; i<26; i++){
            nTask[i]=0;
            last[i]=-999999;

        }
        
        
        for(char c: tasks){
            nTask[c-'A']++;
        }
        
        int qtd=0;
        int time=0;
        
        while(qtd < tasks.size()){
            int choice = -1;
            
            for(int i=0; i<26; i++){
                if(time - last[i] > n && nTask[i] > 0){
                    if(choice == -1 || nTask[i] > nTask[choice])
                        choice = i;
                }
            }
            
            if(choice != -1){
                cout << time << " " << choice << " " << last[choice] << endl;
                qtd++;
                nTask[choice]--;
                last[choice]=time;
            }
            
            time++;
        }
        
        return time;
    }
};