class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // map<char,int> ransomNoteFrequency, magazineFrequency;
        int ransomNoteFrequency[26], magazineFrequency[26];
        
        for(auto c : ransomNote) 
            ransomNoteFrequency[c-'a']++;
        
        for(auto c : magazine) 
            magazineFrequency[c-'a']++;
        
        for(int i{}; i<26; i++) 
            if(magazineFrequency[i] < ransomNoteFrequency[i])
                return false;
        return true;
    }
};
