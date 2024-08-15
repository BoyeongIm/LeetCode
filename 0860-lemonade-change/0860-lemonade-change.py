class Solution(object):
    def lemonadeChange(self, bills):
        now = {5:0, 10:0, 20:0}
        for a in bills:
            if a==5:
                now[a]+=1
            elif a==10:
                if now[5]>0:
                    now[a]+=1
                    now[5]-=1
                else:
                    return False
            else:
                if now[5]>0 and now[10]>0:
                    now[a]+=1
                    now[5]-=1
                    now[10]-=1
                elif now[5]>=3:
                    now[a]+=1
                    now[5]-=3
                else:
                    return False
        
        return True
        