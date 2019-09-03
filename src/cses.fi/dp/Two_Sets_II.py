# https://cses.fi/problemset/task/1093
MOD = 1000000007

n = int(input())

if (n*(n+1))%4 != 0:

	print("0")

else:

	size = int((n*(n+1))/4)+1

	dp = [0]*size
	dp[0] = 1

	for i in range(1,n+1):

		# print("i: ",i)

		for j in range(size-1,i-1,-1):

			# print("j: ",j)

			dp[j] = dp[j] + dp[j-i]


	print(dp)

	print((dp[-1]/2)%MOD)

