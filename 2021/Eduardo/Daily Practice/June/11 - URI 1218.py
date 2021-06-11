c=1
first = True

while True:
  try:
    n = int(input())
    inp = input().split()

    f=0
    m=0

    for i in range(0, len(inp), 2):
      if(int(inp[i]) == n):
        if(inp[i+1] == 'F'):
          f+=1
        else:
          m+=1
    

    if(not first):
      print()
    first=False

    print(f'Caso %d:'%c)
    c+=1

    print(f'Pares Iguais: %d'%(f+m))
    print(f'F: %d'%(f))
    print(f'M: %d'%(m))

  except EOFError:
    break