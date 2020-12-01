t = int(input())

for i in range(t):
	v, e = map(int, raw_input().split())
	print(v - e - 2)