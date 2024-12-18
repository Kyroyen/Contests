from collections import defaultdict

class Sol:
    
    def __init__(self) -> None:
        self.di = defaultdict(list)
    
    def findanagrams(self, wrd:str):
        return self.di[self.getHash(wrd)]
    
    def getHash(self, wrd:str):
        x = "".join(sorted(wrd))
        return hash(x)
        
    def insert(self, wrd: str):
        ha = self.getHash(wrd)
        self.di[ha].append(wrd)


if __name__=="__main__":
    so = Sol()
    so.insert("abc")
    so.insert("bcd")
    so.insert("cde")
    so.insert("bca")
    
    print(so.findanagrams("cab"))
    
    
    