class Solution {
public:
        // General Idea:
    // - Brute force checking will time out, we need efficent way to look up words
    // - Create an vector that stores indices for each character a-z in S
    // - Then for each word, do a binary search for next index for current character in word 
    //   that is greater than the index we last found for the alst character
    // - If it doesn't exist, word doesn't exist, otherwise continue to search for word
    
	int numMatchingSubseq (string S, vector<string>& words) {
		vector<vector<int>> alpha (26);
		for (int i = 0; i < S.size (); ++i) alpha[S[i] - 'a'].push_back (i);
		int res = 0;

		for (const auto& word : words) {
			int x = -1;
			bool found = true;

			for (char c : word) {
				auto it = upper_bound (alpha[c - 'a'].begin (), alpha[c - 'a'].end (), x);
				if (it == alpha[c - 'a'].end ()) found = false;
				else x = *it;
			}

			if (found) res++;
		}

		return res;
	}
};

// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         vector<vector<int>> waiting(26);
//         int ans = 0;
        
//         for(int i=0; i<words.size(); i++) {
//             string str = words[i];
//             int pos = str[0] - 'a';
//             waiting[pos].push_back(i);
//         }
        
//         for(char c : s) {
            
//             int idx = c - 'a';
//             auto curWaiting = waiting[idx];
//             waiting[idx].clear();
            
//             for(int i : curWaiting) {
//                 string str = words[i];
//                 str.erase(str.begin());
//                 words[i] = str;
//                 if(str.empty()) ans++;
//                 else {
//                     waiting[str[0] - 'a'].push_back(i);
//                 }
//             }
//         }
        
//         return ans;
//     }
// };