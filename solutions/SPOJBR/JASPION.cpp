N = int(raw_input())

for i in xrange(N):
    P, T = map(int,raw_input().split())
    d= dict((raw_input(), raw_input()) for x in range(P))
    
    for j in xrange(T):
        l = raw_input().split()
        print " ".join(d.get(w,w) for w in l)
    print 