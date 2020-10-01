# # fill in this function
# def fib():
#     a, b = 1, 1
#     while 1:
#         yield a, b
#         a, b = b, a + b

# # testing code
# import types
# if type(fib()) == types.GeneratorType:
#     print("Good, The fib function is a generator.")

# counter = 0
# for n, m in fib():
#     print(n,m)
#     counter += 1
#     if counter == 10:
#         break

def test_decorator(f):
	def wrapper(x):
		wrapper.calls += 1
		return f(x)
	wrapper.calls = 0
	return wrapper

@test_decorator
def succ(x):
	return x + 1

print(succ.calls)
for i in range(10):
    succ(i)
print(succ.calls)