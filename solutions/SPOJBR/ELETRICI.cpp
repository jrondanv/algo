from datetime import date, timedelta

n = input()
while n:
    dc = 0
    ct = 0
    pdt = date(1000,1,1)
    pc = 0
    for x in xrange(n):
        d,m,y,c = map(int,raw_input().split())
        dt = date(y,m,d)

        if (dt == pdt + timedelta(days=1)):
            dc += 1
            ct += c - pc
        
        pdt, pc = dt, c
    print dc, ct
    n = input()