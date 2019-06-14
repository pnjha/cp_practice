#https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

s1 = input()
s2 = input()

s1 = s1 + s1

if s2 in s1:
	print("Yes")
else:
	print("No")

