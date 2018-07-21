def busca_binaria(lista,num):
    """
    Retorna a posição n da lista tal que o valor em n seja <=num
    e n+1 seja >num.

    :param lista: lista ordenada de numeros.
    :param num: numero que se quer procurar dentro da lista.
    """

    tam_lista=len(lista)
    posicao=int(tam_lista/2)
    fator_mudanca=posicao
    if(lista[0]>=num):
        return 0
    elif(lista[-1]<=num):
        return len(lista)-1
    else:
        while(True):
            posicao_esq=lista[posicao]
            posicao_dir=lista[posicao+1]
            fator_mudanca=int(fator_mudanca / 2)
            if(posicao_esq<=num and posicao_dir>=num):
                return posicao
            elif(lista[posicao]>num):
                posicao=posicao-fator_mudanca
            else:
                posicao=posicao+fator_mudanca

            if(fator_mudanca==0):
                fator_mudanca=2


def crivo_aristoteles(num_max):
    """
    Retorna uma lista dos primos de 1 a num_max.

    :param num_max:
    :return: list
    """

    array_primos=[cont+1 for cont in range(num_max)]

    for cont in range(1,int(pow(num_max,0.5))):
        num=array_primos[cont]
        if(num!=-1):
            for cont_2 in range(num,int(num_max/num)+1):
                array_primos[cont_2*num-1]=-1

    return [num for num in array_primos if(num!=-1)]

def hiperprimos(num):
    """
    retorna a quantidade de hiperprimos que são
    menores que num.

    :param num:
    :return:
    """

    quant_hiperprimos=0
    lista_num=crivo_aristotenes(num)

    for primo in lista_num:
        result=busca_binaria(lista_num,int(pow(num,(1/primo))))
        if(result==0):
            break
        else:
            quant_hiperprimos=quant_hiperprimos+result

    return quant_hiperprimos


while True:
  try:
    num=int(input())
    print(hiperprimos(num))
  except EOFError:
    break





