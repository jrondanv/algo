import heapq, operator

n, t = map(int, raw_input().split())

alunos = []

for aluno in xrange(n):
    nome, hab = raw_input().split()
    heapq.heappush(alunos, (-int(hab), nome))

times = [[] for i in xrange(t)]

for i in xrange(n):
    times[i%t].append(heapq.heappop(alunos))

for time in xrange(t):
    print "Time", time+1
    print "\n".join(aluno[1] for aluno in sorted(times[time], key=operator.itemgetter(1)))
    print