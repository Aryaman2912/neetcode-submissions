class Solution:

    def encode(self, strs: List[str]) -> str:
        return "" if not len(strs) else "+".join([','.join([str(ord(c)) for c in string]) for string in strs]) + "+"

    def decode(self, s: str) -> List[str]:
        return [] if not len(s) else ['' if string.split(',') == [''] else ''.join([chr(int(x)) for x in string.split(',')]) for string in s[:-1].split('+')]
