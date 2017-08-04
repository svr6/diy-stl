import os,sys

def reverse(x):
    s = cmp(x, 0)
    print s
    r = int(`s*x`[::-1])
    print r
    return s*r * (r < 2**31)

if len(sys.argv) != 2:
    sys.exit(-1)

n = int(sys.argv[1])
r = reverse(n)
print 'result: ',r
