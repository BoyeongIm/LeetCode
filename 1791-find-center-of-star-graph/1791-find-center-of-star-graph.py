class Solution(object):
    def findCenter(self, edges):
        # my solution
        count1 = 0
        count2 = 0
        while count1 < len(edges)-1 and count2 < len(edges)-1:
            for e in edges[1:]:
                if edges[0][0] in e:
                    count1 += 1
                if edges[0][1] in e:
                    count2 += 1
        if count1 == len(edges)-1:
            return edges[0][0]
        elif count2 == len(edges)-1:
            return edges[0][1]
            
        # another solution
        '''
        #어차피 *valid star graph* 이므로 처음 두 개의 list만 확인하면 됨.
        if edges[0][0]==edges[1][0] or edges[0][0]==edges[1][1]:
            return edges[0][0]
        else:
            return edges[0][1]
        '''
