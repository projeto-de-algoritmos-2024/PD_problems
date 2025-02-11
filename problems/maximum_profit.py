import bisect
from typing import List

class Solution:
    
    def compatible(self, jobs, i, end_times):
        j = bisect.bisect_right(end_times, jobs[i][0]) - 1
        return j

    def compatibles(self, jobs):
        end_times = [job[1] for job in jobs]
        return [self.compatible(jobs, i, end_times) for i in range(len(jobs))]

    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])
        n = len(jobs)
        result = [0] * n
        p = self.compatibles(jobs)
        
        for i in range(n):
            include_profit = jobs[i][2]
            if p[i] != -1:
                include_profit += result[p[i]]
            
            result[i] = max(include_profit, result[i - 1] if i > 0 else 0)
        
        return result[-1]
