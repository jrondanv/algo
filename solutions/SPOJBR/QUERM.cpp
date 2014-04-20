teste = 0

while True:
    teste += 1

    n = raw_input()
    if n == "0": break

    tickets = [int(x) for x in raw_input().split()]

    for index, x in enumerate(tickets):
        if x == index + 1:
            print "Teste", teste
            print x
            print
            break