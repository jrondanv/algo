teste = 0

while True:
    teste += 1

    n = int(raw_input())
    if n == 0: break
    
    jogadores = [raw_input(), raw_input()]

    jogos = [[int(x) for x in raw_input().split()] for i in xrange(n)]

    print "Teste", teste

    for x in jogos:
        print jogadores[sum(x) & 1]

    print