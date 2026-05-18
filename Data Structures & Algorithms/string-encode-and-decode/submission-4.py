class Solution:

    def encode(self, strs: List[str]) -> str:
        if not len(strs):
            return str()
        return "+".join([','.join([str(ord(c)) for c in string]) for string in strs]) + "+"

    def decode(self, s: str) -> List[str]:
        if not len(s):
            return []
        return ['' if string.split(',') == [''] else ''.join([chr(int(x)) for x in string.split(',')]) for string in s[:-1].split('+')]
