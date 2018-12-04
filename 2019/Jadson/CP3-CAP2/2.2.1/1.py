lista = [3,1,2,3,4]
lista.sort()

for cont in range(len(lista) - 1):
	if lista[cont] == lista[cont+1]:
		print("Encontrou")
		break
else:
	print("Não encontrou")