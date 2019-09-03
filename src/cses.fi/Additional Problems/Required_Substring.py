# https://cses.fi/problemset/task/1112

def factorial(n):
	
	if n<=1:
		return 1
	res = 1
	for i in range(1,n+1):
		res = (res * i)
	
	return res


n = int(input())
s = input()

MOD = 1000000007

print(factorial(n-len(s)+1)*(26**(n-len(s)))%MOD);
