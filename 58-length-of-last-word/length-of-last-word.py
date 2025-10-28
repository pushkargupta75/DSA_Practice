class Solution(object):
    def lengthOfLastWord(self, s):
        t=s.split()
        return len(t[len(t)-1])
        