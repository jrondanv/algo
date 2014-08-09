T = int(raw_input())

for t in xrange(1,T+1):
	print "Case #%d:" % t,

	N = int(raw_input())
	L = map(int, raw_input().split())

	inv = {}
	ind = {}
	for index, x in enumerate(L):
		ind[x] = index

	L2 = list(sorted(L, reverse=True))

	tot = 0
	for x in xrange(N):
		for y in xrange(x+1, N):
			if L[x] > L[y]:
				tot += 1

	best = tot
	for x in xrange(N, -1, -1):
		for y in xrange(N):
			if y < ind[x] and L[y] > L[ind[x]]:
				tot -= 1
			if y > ind[x] and L[y] > L[ind[x]]:
				tot += 1

		print x, tot

		best = min(best, tot)

	print best

