N = int(raw_input())

for i in xrange(N):
    P = int(raw_input())
    data = [len(raw_input().split()) for x in xrange(P)]
    m = min(data)

    print " ".join(str(i+1) for i,e in enumerate(data) if e==m)
    if (i != N-1): raw_input()