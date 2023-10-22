#User function Template for python3
class Solution:
	def maxSumIS(self, Arr, n):
		dp = {}
		for i in range(n):
		    dp[i] = 0
		    
		dp[n-1] = Arr[n-1];
		
		i = n-1
		while i>=0:
		    sumi = Arr[i]
		    addi = 0
		    j=i+1
		    while j<n:
		        if Arr[j] > Arr[i]:
		            addi = max(addi,dp[j])
		        j = j+1
		    dp[i] = sumi+addi
		    i = i-1
		
		maxi = -1
		for i in dp.values():
		    maxi = max(maxi,i)
		    
		return maxi
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		Arr = [int(x) for x in input().split()]
		ob = Solution()
		ans = ob.maxSumIS(Arr,n)
		print(ans)

# } Driver Code Ends