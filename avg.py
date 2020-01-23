res = list()
with open("tester_res.txt") as f:
	for line in f:
		res.append(int(line))

print(sum(res)/len(res))
print(max(res))
c = 0
c2 = 0
for n in res:
	if n > 5499:
		c2 += 1
	elif n > 699:
		c += 1
print(f"Above bench (700): {c} | (5500): {c2}")