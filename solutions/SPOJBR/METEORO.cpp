teste = 0

while True:
    teste += 1

    fazenda = [int(x) for x in raw_input().split()]
    if fazenda == [0, 0, 0, 0]: break

    n = int(raw_input())
    meteoritos = [[int(x) for x in raw_input().split()] for i in xrange(n)]

    count = 0
    for meteorito in meteoritos:
        if fazenda[0] <= meteorito[0] <= fazenda[2] and fazenda[3] <= meteorito[1] <= fazenda[1]:
            count += 1

    print "Teste", teste
    print count
    print
