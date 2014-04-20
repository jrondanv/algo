
inputs = raw_input()
inputs = inputs.split()
inputs = [float(x) for x in inputs]
A, G, RA, RG = inputs

if RA/A > RG/G:
    print 'A'
else:
    print 'G'