#Problem Name : 226A - Flying Saucer Segments
#Execution Time : 62 ms
#Memory : 0 KB
n, m = map(int, raw_input().split())

print ((pow(3, n, m) - 1) + m ) % m