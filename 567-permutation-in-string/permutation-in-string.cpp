class Solution {
public:

    bool isFreqSame(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length())
            return false;

        int freq[26] = {0};

        // Store frequency of s1
        for(int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windowSize = s1.length();

        for(int i = 0; i <= s2.length() - windowSize; i++) {
            
            int windowFreq[26] = {0};

            for(int j = 0; j < windowSize; j++) {
                windowFreq[s2[i + j] - 'a']++;
            }

            if(isFreqSame(freq, windowFreq)) {
                return true;
            }
        }

        return false;
    }
};
