# https://leetcode.com/problems/partition-labels/

'''
Quick Explanation -
Greedily choose smallest partition for the first letter,i.e l=0
for all elements in that partition, if someones last index, i.e mydict[S[i]]
is greater than r, update r
After each iteration : l = r+1
'''
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        l,r,mydict,ans = 0,0,{},[]
        for i in range(len(S)):
            mydict[S[i]] = i
        while(l<len(S)):
            i,r = l,mydict[S[l]]
            while(i<r):
                if(mydict[S[i]]>r):
                    r = mydict[S[i]]
                i += 1
            ans.append(r-l+1)
            l = r+1
        return ans
