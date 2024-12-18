class Solution:
    def stringHash(self, s: str, k: int) -> str:
        res = []
        n = len(s)
        for i in range(n//k):
            res.append(chr(sum((ord(s[i])-97) for i in range(i*k, (i+1)*k))%mod + 97))
        
        return "".join(res)

if __name__=="__main__":
	print(stringHash("abcd", 2)
