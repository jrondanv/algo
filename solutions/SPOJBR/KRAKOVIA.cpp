teste = 1
while True:
    n, f = map(int, raw_input().split())

    if not n: break

    c = 0
    for i in xrange(n):
        c += int(raw_input())

    print "Bill #%s costs %s: each friend should pay %s" % (teste, c, c/f)
    print
    teste += 1



