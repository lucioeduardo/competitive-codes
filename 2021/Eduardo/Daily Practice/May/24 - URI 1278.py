f = False

while True:
  try:
      n = int(input())

      if(n == 0):
        break

      if(f):
        print()
      f=True

      lines = []
      length=0

      for i in range(n):
        s = input()
        s = " ".join(s.split())
        lines.append(s)
        length = max(length, len(s))
      
      for s in lines:
        print(s.rjust(length))
  except EOFError:
      break