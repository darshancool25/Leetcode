# https://leetcode.com/problems/goat-latin/

class Solution:
    def toGoatLatin(self, S: str) -> str:
        my_list  = S.split()
        vowels = ['a','A','e','E','i','I','o','O','u','U'];
        for i in range(len(my_list)):
            if my_list[i][0] in vowels:
                my_list[i] += "ma"
            else:
                my_list[i] = my_list[i][1:] + my_list[i][0] + "ma"
            my_list[i] += "a"*(i+1)
        return " ".join(my_list)
