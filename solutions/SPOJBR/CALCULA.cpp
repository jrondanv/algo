teste = 0

while True:
    teste += 1

    n = int(raw_input())
    if n == 0: break

    expr = raw_input()

    print "Teste", teste
    print eval(expr)
    print