class Solution {
public:
    
    map<string, string> db;
    
    string hash(){
        string res = "";
        
        for(int i=0; i<6; i++){
            int n = rand()%(36);
            
            if(n < 26)
                res += ('a'+n);
            else
                res += ('0'+(n-26));
        }
        
        return res;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string h = hash();
        
        while(db.count(h))
            h = hash();
        
        string shortUrl = "http://tinyurl.com/" + h;
        
        db[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return db[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));