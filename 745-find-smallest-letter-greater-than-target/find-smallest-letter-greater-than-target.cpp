class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int beg=0;
        int end=letters.size()-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
           
            if(letters[mid]<=target) beg=mid+1;
            else end=mid-1;
        }
        return letters[beg%letters.size()];
    }
};