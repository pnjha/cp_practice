s = input()

try:
	s = int(s)
	print("is integer")
except Exception as e:
	print("is not an integer")
