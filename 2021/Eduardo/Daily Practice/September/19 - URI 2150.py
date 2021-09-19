while True:
  try:
    v = input()
    s = input()

    res = 0

    for c in s:
      if c in v:
        res+=1
    
    print(res)


  except EOFError:
    break 