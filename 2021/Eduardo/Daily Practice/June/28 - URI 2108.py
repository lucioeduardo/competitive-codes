biggest = ""

while True:
  line = input()

  if(line == "0"):
    break

  words = line.split()

  for i in range(len(words)):
    if(i != 0):
      print("-",end='')
    print(f'%d'%len(words[i]), end='')
    if(len(words[i]) >= len(biggest)):
      biggest = words[i]
  
  print()

print(f'\nThe biggest word: %s'%biggest)