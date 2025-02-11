# 1235. Maximum Profit in Job Scheduling
# Url: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
# Difficulty: Hard
# Description:
	# We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i]. 
  # You're given the startTime, endTime and profit arrays, return the maximum profit you can take 
  # such that there are no two jobs in the subset with overlapping time range.
  # If you choose a job that ends at time X you will be able to start another job that starts at time X.

# Example:
	# Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
	# Output: 120
  # Explanation: The subset chosen is the first and fourth job.

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
