class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;
    int n = text.size();
    string currentWord = "";
    for (int i = 0; i <= n; i++) {
        if (i < n && text[i] != ' ') currentWord += text[i];
        else {
            if (!currentWord.empty()) {
                bool canType = true;
                for (int j = 0; j < (int)currentWord.size(); j++) {
                    for (int k = 0; k < (int)brokenLetters.size(); k++) {
                        if (currentWord[j] == brokenLetters[k]) {
                            canType = false;
                            break;
                        }
                    }
                    if (!canType) break;
                }
                if (canType) count++;
                currentWord.clear();  
            }
        }
    }
    return count;
    }
};