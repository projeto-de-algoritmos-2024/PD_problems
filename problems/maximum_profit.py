class Solution:

    def max(self, take, dontTake):
        return take if take >= dontTake else dontTake
    
    def compatible(self, jobs, i):
        for j in range(i-1, -1, -1):
            if jobs[j][1] <= jobs[i][0]:
                return j
        return -1
    
    def compatibles(self, jobs):
        p = []
        for i in range(len(jobs)):
            p.append(self.compatible(jobs, i))
        return p

    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])
        n = len(jobs)
        result = [0] * n
        p = self.compatibles(jobs)
        for i in range(n):
            include_profit = jobs[i][2]
            if p[i] != -1:
                include_profit += result[p[i]]
            result[i] = self.max(include_profit, result[i - 1] if i > 0 else 0)
        return result[-1]