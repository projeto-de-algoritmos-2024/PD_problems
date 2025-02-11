class Solution:
    def max(self, take, dontTake):
        if take >= dontTake:
            return take
        else:
            return dontTake
    def compatible(self, jobs, i):
        for j in range(i-1, -1, -1):
            if jobs[j][1] <= jobs[i][0]:
                return j

    def compatibles(self, jobs):
        p = []
        for i in range(len(jobs) - 1, -1, -1):
            p.append(self.compatible(jobs, i))
        return list(reversed(p))


    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])
        result = [-1 for job in jobs]
        result[0] = 0
        p = self.compatibles(jobs)
        for i in range(1, len(jobs)):
            result[i] = self.max(jobs[i][2] + result[p[i]],  result[i-1])
        return result[-1]