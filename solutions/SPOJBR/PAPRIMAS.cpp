import string
table = dict(zip(string.ascii_lowercase + string.ascii_uppercase, range(1, 53)))

def is_prime(n):
    sqrt_n = int(n**0.5)
    for x in primes:
        if x > sqrt_n: break
        elif not n % x: return False
    return True


primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]

while True:
    try:
        inp = raw_input()
    except EOFError:
        break
    
    print ["It is not a prime word.", "It is a prime word."][is_prime(sum(table[x] for x in inp))]