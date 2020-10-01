s = input()
s = s.lower()

alphabets = "aeioubcdffghjklmnpqrstvwxyz"
flag = True

for alphabet in alphabets:
	if alphabet not in s:
		flag = False
		break

if flag == True:
	print("Panagram")
else:
	print("Not Panagram")