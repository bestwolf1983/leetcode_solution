class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        l = []
        word_begin = None

        for i in range(len(s)):
            if word_begin == None and s[i] != ' ':
                word_begin = i

            #end of word
            if word_begin != None :
                if (i + 1 < len(s) and s[i + 1] == ' ') or i == len(s) - 1:
                    l.append(s[word_begin:i+1])
                    word_begin = None

        #reverse each word
        new_l = [word[::-1] for word in l]
        return ' '.join(new_l)[::-1]
