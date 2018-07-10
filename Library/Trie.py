class WordDictionary:
    data = [True] + [None for i in range(26)]

    def find(self, word, pos, node):
        while pos < len(word):
            if word[pos] == '.':
                for i in range(1, 27):
                    if node[i] and self.find(word, pos + 1, node[i]):
                        return True
                return False

            nxt = ord(word[pos]) - 96
            if not node[nxt]:
                return False
            node = node[nxt]
            pos += 1

        return node[0]

    """
    @param: word: Adds a word into the data structure.
    @return: nothing
    """

    def addWord(self, word):
        # write your code here
        p = self.data
        for i in word:
            nxt = ord(i) - 96
            if not p[nxt]:
                p[nxt] = [False] + [None for i in range(26)]
            p = p[nxt]
        p[0] = True

    """
    @param: word: A word could contain the dot character '.' to represent any one letter.
    @return: if the word is in the data structure.
    """

    def search(self, word):
        # write your code here
        return self.find(word, 0, self.data)

