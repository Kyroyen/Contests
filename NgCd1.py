
from heapq import heappop, heappush
# import random
# from functools import cache
from typing import List
from collections import Counter, deque, defaultdict
from heapq import heapify

def solvution(g:dict, costs:dict):
    pass
    # Shuru
    cityind = {i:ind for ind,i in enumerate(g.keys())}
    indtocity = list(g.keys())
    # print(indtocity)
    print(cityind)
    n = len(cityind)
    
    graph = [[] for i in range(n)]
    for i,j in g.items():
        graph[cityind[i]].extend(map(lambda x: cityind[x], j))
    
    def getOffCntsMon(cityind:int, month:int):
        # print(month)
        return costs[indtocity[cityind]][month]
    
    # print(graph)
    hep = [(-getOffCntsMon(i,0),  i, [i], 0, 0) for i in range(n)]
    heapify(hep)
    # print(hep)
    
    dp = [[0 for _ in range(12)] for i in range(n)]
    
    for i in range(n):
        dp[i][0] = getOffCntsMon(i,0)
        
    # print(dp)
    
    def getQuarterChanges(lenPath, chngs):
        if lenPath%3==0:
            return 0
        return chngs
    
    res = None
    ans = -1
    
    while hep:
        currholi, city, path, chngs, totchngs = heappop(hep)
        # print(currholi, city, path, chngs)
        staySameHolidays = -(currholi-getOffCntsMon(city, len(path)))
        if staySameHolidays>dp[city][len(path)]:
            dp[city][len(path)] = staySameHolidays
            if len(path)+1<12:
                heappush(hep, (-staySameHolidays, city, path+[city], getQuarterChanges(len(path), chngs), totchngs))
            elif ans<=staySameHolidays:
                ans = staySameHolidays
                res = path+[city]
        
        if getQuarterChanges(len(path), chngs)<2 and totchngs<8:
            for nxt in graph[city]:
                chngtonxtHolidays = -(currholi-getOffCntsMon(nxt, len(path)))
                if chngtonxtHolidays>dp[nxt][len(path)]:
                    dp[nxt][len(path)] = chngtonxtHolidays
                    if len(path)+1<12:
                        heappush(hep, (-chngtonxtHolidays, nxt, path+[nxt], getQuarterChanges(len(path), chngs)+1, totchngs+1))
                    elif ans<=chngtonxtHolidays:
                        ans = chngtonxtHolidays
                        res = path+[nxt]
    # print(dp)
    print("Cities by month: ",[indtocity[i] for i in res])
    print("Total Holidays:",ans+1)
    print("Holidays by month:", [getOffCntsMon(i,ind) for ind,i in enumerate(res)])
    for i in range(n):
        print(i, costs[indtocity[i]])
    
    # Khatam


# # Check+Debug
# solvution()

# # FORCES--CHEF
# for _ in range(in1()):
#     solvution(
#         in1(), lster()
#     )

# CSES-ATCODER
if __name__=="__main__":
    print(solvution(
        {
            "Noida": ["Delhi", "Gurugram","Faridabad"],
            "Delhi": ["Noida", "Gurugram", "Sonipat","Faridabad"],
            "Sonipat": ["Delhi", "Panipat", "Gurugram"],
            "Gurugram": ["Noida", "Delhi", "Sonipat","Panipat","Faridabad"],
            "Panipat": ["Sonipat", "Gurugram"],
            "Faridabad": ["Delhi","Noida","Gurugram"]
        },
        {
            "Noida": [1, 3, 4, 2, 1, 5, 6, 5, 1, 7, 2, 1],
            "Delhi": [5, 1, 8, 2, 1, 7, 2, 6, 2, 8, 2, 6],
            "Sonipat": [2, 5, 8, 2, 1, 6, 9, 3, 2, 1, 5, 7],
            "Gurugram": [6, 4, 1, 6, 3, 4, 7, 3, 2, 5, 7, 8],
            "Panipat": [2, 4, 3, 1, 7, 2, 6, 8, 2, 1, 4, 6],
            "Faridabad": [2, 4, 6, 7, 2, 1, 3, 6, 3, 1, 6, 8]
        }
    ))
