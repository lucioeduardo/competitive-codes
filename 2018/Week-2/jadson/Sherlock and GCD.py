def mdc(a,b):
	"""
	calcula o maximo divisor comum dos numeros a e b.

	"""
	if(b>a):
		return mdc(b,a)

	if(a%b==0):
		return b

	return mdc(b,a%b)

def subset_exist(array):

	for cont in range(0,len(array)):
		for cont2 in range(cont,len(array)):
			if(mdc(array[cont],array[cont2])==1):
				return True

	return False


test_cases=int(input())
for cont in range(0,test_cases):
	size_array=int(input())
	array=[int(value) for value in input().split(" ")]
	if(subset_exist(array)):
		print("YES")
	else:
		print("NO")
