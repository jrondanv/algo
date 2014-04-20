import string
table = dict(zip(string.ascii_uppercase + "10-", '2223334445556667777888999910-'))

while True:
    try:
        inp = raw_input()
    except EOFError:
        break
    
    print "".join(table[x] for x in inp)