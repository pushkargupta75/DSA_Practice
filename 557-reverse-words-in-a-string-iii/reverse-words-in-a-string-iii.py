class Solution(object):
    def reverseWords(self, s):
        a=s.split()
        for i in range(len(a)):
            a[i]=a[i][::-1]
        ans=" ".join(a)
        return ans
        