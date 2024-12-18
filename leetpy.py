from io import TextIOWrapper
from typing import List, Set, Any, Optional, Generator, Tuple
# from functools import cache, lru_cache, reduce
from collections import defaultdict, Counter, deque
from math import inf, ceil, floor, comb, gcd, isinf, log, sqrt
from itertools import accumulate, chain, groupby, combinations
from functools import reduce, cache
from operator import mul
# from cachetools import cached
from bisect import bisect_right, bisect_left, insort
from heapq import heapify, heappop, heappush
import heapq
from sortedcontainers import SortedList
import sys


def lster(f: TextIOWrapper): return list(map(int, f.readline().split()))
def in1(f: TextIOWrapper): return int(f.readline())

# sys.setrecursionlimit(10)


class MagicTrie:

    def __init__(self, words=None) -> None:
        def T(): return defaultdict(T)
        self.trie = T()
        if not (words is None):
            for w in words:
                reduce(dict.__getitem__, w, self.trie)['#'] = True

    def add(self, word):
        reduce(dict.__getitem__, word, self.trie)['#'] = True

    def __contains__(self, word):
        x = self.trie
        for i in word:
            if i not in x:
                return False
            x = x[i]
        return "#" in x


class OverMagicTrie(MagicTrie):

    def go_over(self, word):
        x = self.trie
        for ind, i in enumerate(word):
            if i not in x:
                return word
            x = x[i]
            if ('#' in x):
                return word[:ind+1]
        return word
        
class Solution:
    def minValidStrings(self, words: List[str], target: str) -> int:
        trie = MagicTrie(words)
        print(trie.trie)
        n = len(target)
        
        dp = [inf]*(n+1)
        dp[n] = 0
        
        for i in range(n-1,-1,-1):
            ty = trie.trie
            print(target[i:])
            for j in range(i, n):
                if target[j] in ty:
                    print("+", target[j])
                    dp[i] = min(dp[j+1]+1, dp[i])
                    ty = ty[target[j]]
                else:
                    print("---", target[j])
                    break
            
        # print(dp)
        return -1 if isinf(dp[0]) else dp[0] 

                    
            
            
        
    def maxMoves(self, kx: int, ky: int, positions: List[List[int]]) -> int:
        npos = len(positions)
        
        dp = [[inf]*15 for _i in range(1<<npos)]
        mapper = {}
        for i in range(15):
            dp[0][i] = 0
        for i in range(npos):
            mapper[1<<i] = i+1
            dp[1<<i][i] = 0 
        
        for i in dp:
            print(*i)
        print(mapper)
        seen = set()
        
        dist = [[0]*16 for _ in range(16)]
        
        chng = ((-1,-2),(-2,-1),(-1,2),(-2,1),(1,2),(2,1),(1,-2),(2,-1))
        
        def dis(ind:int):
            temp = [[-1]*50 for _ in range(50)]
            a,b = positions[ind]
            temp[a][b] = 0
            
            que = deque([(a,b)])
            while que:
                for i in range(len(que)):
                    x,y = que.popleft()
                    for dx,dy in chng:
                        nx,ny = x+dx,y+dy
                        if 0<=nx<50 and 0<=ny<50 and temp[nx][ny]==-1:
                            temp[nx][ny] = temp[x][y] + 1
                            que.append((nx,ny))
            
            for i,(x,y) in enumerate(positions):
                dist[ind][i] = temp[x][y]

        for i in range(len(positions)):
            dis(i)
        
        for i in dist:
            print(i)

        # def getSetBits(x:int):
        #     cnt = 0
        #     while x:
        #         x = x&(x-1)
        #         cnt += 1
        #     return cnt
        
        # que = sorted((i for i in range( 1<<npos)), key= lambda x:(getSetBits(x), x))       
        
        # def getTransCost(aliceTurn:bool, src:int, dest:int):
        #     return 90
        
        # for i in que:
        #     x = i
        #     print(i)
        #     while x:
        #         t = (x&(x-1))^x
        #         ind = mapper[t]
        #         x = (x&(x-1))
        #         fndfor = (i^t)
        #         print(x,bin(t),ind,bin(fndfor))
        #         fndforx = fndfor
        #         val = inf
        #         turn = getSetBits(i)%2==1
        #         compfunc = min if turn else max
        #         while fndforx:
        #             fndforx = (fndforx&(fndforx-1))^fndfor
        #             transcost = getTransCost(turn, ind, mapper[fndforx]) + dp[fndfor][mapper[fndforx]]
        #             val = compfunc(val, transcost)
                
                    


if __name__ == '__main__':
    # print(Solution().catMouseGame([[6],[4],[9],[5],[1,5],[3,4,6],[0,5,10],[8,9,10],[7],[2,7],[6,7]]))
    # with open("./fileInput.txt", "r") as f:
    #     n = in1(f)
    #     arr = lster(f)
    
    print(Solution().minValidStrings(words = ["abcdef"], target = "xyz"))
    
    