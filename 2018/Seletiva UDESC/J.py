n = int(input())

def leftZero(expr):
	op = '+-*='

	size = len(expr)-1
	i = 1

	while i < size:
		
		if expr[i + 1] in op:
			i += 1
			continue
		if expr[i] == '0' and expr[i-1] in op:
			expr = expr[:i] + expr[i+1:]
			size = size-1
			continue
		i += 1
	return expr

for i in range(n):
	expr = '0+' + input()

	expr = expr.replace('--', '+')
	expr = expr.replace('+-', '-')
	expr = expr.replace('-+', '-')
	expr = expr.replace('++', '+')

	for i in range(10):
		current = expr.replace('?', str(i))
		current = leftZero(current)
		x, y = current.split('=')

		if(eval(x) == eval(y)):
			print(i)
			break
	else:
		print(-1)