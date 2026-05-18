class Solution:

    def encode(self, strs: List[str]) -> str:
        if not len(strs):
            return str()
        res = ""
        for string in strs:
            temp = ""
            for c in string:
                temp += str(ord(c)) + ","
            temp = temp[:-1]
            res += temp + "+"
        return res

    def decode(self, s: str) -> List[str]:
        if not len(s):
            return []
        s = s[:-1]
        res = s.split('+')
        list_str = []
        for string in res:
            list_str.append('' if string.split(',') == [''] else ''.join([chr(int(x)) for x in string.split(',')]))
        return list_str
