class Solution:
    """
    @param ransomNote: a string
    @param magazine: a string
    @return: whether the ransom note can be constructed from the magazines
    """

    def canConstruct(self, ransomNote, magazine):
        # Write your code here
        letters = [chr(x) for x in range(97, 123)]
        for i in letters:
            if ransomNote.count(i) > magazine.count(i):
                return False
        return True
