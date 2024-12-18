from functools import reduce
from collections import defaultdict
class mt:
    def __init__(self):
        T = lambda : defaultdict(T)
        self.triy = T()

    def add(self, word, ind):
        curr = self.triy
        for i in word:
            curr = curr[i]
            if "#" in curr:
                if curr["#"]!=ind:
                    curr["#"] = -1
            else:
                curr["#"] = ind
            

