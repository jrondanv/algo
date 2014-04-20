n = 0

while True:
    try:
        number_of_inputs = int(raw_input())
    except:
        break
    
    current_sum = 0
    
    inputs = raw_input()
    inputs = inputs.split()
    inputs = inputs[:number_of_inputs]
    inputs = [int(x) for x in inputs]

    n += 1
    val = 'nao achei'

    for i in xrange(number_of_inputs):
        if inputs[i] == current_sum:
            val = inputs[i]
            break
        current_sum += inputs[i]

    print "Instancia %s" % n
    print val
    print