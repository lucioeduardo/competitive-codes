out1 = open('out1.txt')
out2 = open('out2.txt')

out1 = out1.readlines()
out2 = out2.readlines()

if(out1 != out2):
	for i in xrange(len(out1)):
		if out1[i] != out2[i]:
			print('linha %d, saida esperada: %s\nsaida obtida: %s\n' %(i+1, out2[i], out1[i]))
else:
	print('accepted :)\ne ta ligeiro')