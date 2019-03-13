import sys
import numpy as np
import time

n = int(sys.argv[1])

start = time.time()
A = np.random.uniform(0,1,n*n).reshape((n,n))
B = np.random.uniform(0,1,n*n).reshape((n,n))
C = np.zeros((n,n))
stop = time.time()
print("time: ", stop-start)

start = time.time()
C = A @ B
stop = time.time()
print("time: ", stop-start)

#print(A)
#print(B)
#print(C)
