class Solution:
    def intToRoman(self, num: int) -> str:
        roman_dict_10 = {
            1:'I', 10:'X', 100:'C', 1000:'M',
        }
        roman_dict_5 = {
            5:'V', 50:'L', 500:'D'
        }

        l = len(str(num))-1
        answer = ""
        for s in str(num):
            s = int(s)
            if s!=4 and s!=9:
                if s >= 5:
                    answer += roman_dict_5[5*(10**l)]
                    s -= 5
                answer += roman_dict_10[10**l] * s
            elif s == 4:
                answer += roman_dict_10[10**l]
                answer += roman_dict_5[5*(10**l)]
            elif s == 9:
                answer += roman_dict_10[10**l] + roman_dict_10[10**(l+1)]
            l-=1    
        return answer