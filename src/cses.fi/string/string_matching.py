import regex as re

def main():

	s = input()
	p = input()

	matches = re.findall(p, s, overlapped=True)

	print(len(matches))

	# print(s.count(p))

	# print(s)
	# print(p)

	# s = re.sub(p," ",s);

	# l = re.split(" ",s)

	# print(len(l)-1)

if __name__ == '__main__':
	main()