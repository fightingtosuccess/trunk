import numpy

def matrix_factorization(R, P, Q, K, steps=5000, alpha=0.0002, beta=0.02):
    Q = Q.T
    for step in xrange(steps):
        for i in xrange(len(R)):
            for j in xrange(len(R[i])):
                if R[i][j] > 0:
                    eij = R[i][j] - numpy.dot(P[i,:],Q[:,j])
                    for k in xrange(K):
                        P[i][k] = P[i][k] + alpha * (2 * eij * Q[k][j] - beta * P[i][k])
                        Q[k][j] = Q[k][j] + alpha * (2 * eij * P[i][k] - beta * Q[k][j])
        eR = numpy.dot(P,Q)
        e = 0
        for i in xrange(len(R)):
            for j in xrange(len(R[i])):
              e = e + pow(R[i][j] - numpy.dot(P[i,:],Q[:,j]), 2)
              for k in xrange(K):
              e = e + (beta/2) * ( pow(P[i][k],2) + pow(Q[k][j],2) )
        if e < 0.001:
            break
    return P, Q.T

if __name__ == "__main__":
    R = [
         [5,0,0,0,0,-5,0,0,5,3,0,1,5],
         [0,0,0,3,0,0,0,0,3,0,0,0,4],
         [0,0,1,0,2,-5,4,0,0,-2,-2,0,-2],
         [0,4,4,3,0,0,-2,0,-5,0,0,3,0],
         [0,5,-5,0,-5,0,4,3,0,0,4,0,0],
         [0,0,4,0,0,3,0,0,4,0,0,0,0],
         [0,-2,0,0,0,5,0,0,0,4,0,4,-2],
         [0,-2,0,0,0,5,0,5,0,4,0,0,-2],
        ]

    R = numpy.array(R)

    N = len(R)
    M = len(R[0])
    K = 5

    P = numpy.random.rand(N,K)
    Q = numpy.random.rand(M,K)

    nP, nQ = matrix_factorization(R, P, Q, K)
    print(nP)
    print(nQ)
    nR = numpy.dot(nP,nQ.T)
    print(nR)
