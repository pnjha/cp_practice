import re
import math

def get_tasks(arr,time):
	sum = 0
	for item in arr:
		sum += math.floor(time/item)
	return math.floor(sum)


def main():
	line1 = input()
	n,t = re.split(" ",line1)
	n = int(n)
	t = int(t)

	line2 = input()
	arr = re.split(" ",line2)
	arr = list(map(int, arr))

	max_ele = -1

	if n == 1:
		print(t * arr[0])
		return 0

	for i in arr:
		if i > max_ele:
			max_ele = i

	max_time = max_ele * t

	left = 1
	right = max_time
	mid = -1
	tasks = 0

	while left<right:

		mid = math.floor((left + right)/2)

		tasks = get_tasks(arr,mid)

		if tasks < t:
			left = mid+1
		else:
			right = mid

	
	print(right)

	return 0

if __name__ == '__main__':

	main()