from math import cos, pi, fabs


class PGaussSolver ():
    def __init__(self, pf, a, b, n):
        self.__pf = pf
        self.__ma = a
        self.__mb = b
        self.__mn = n
        self.result = 0


    def legendre(self, n, x):
        if (n == 0):
            return 1
        elif (n == 1):
            return x;
        else:
            return ((2*n - 1)/n) * x * self.legendre(n-1, x) - ((n-1)/n)*self.legendre(n-2, x)


    def dlegendre(self, n, x):
        res = (n/(x*x - 1)) * ((x* self.legendre(n, x)) - self.legendre(n-1, x))
        return res


    def legendreZeroes(self, n, i):
        xnew1 = 0
        xold1 = cos(pi*(i - 1/4) / (n + 1/2))
        error = 1
        iter = 1

        while (error > 1e-3):
            if (iter != 1):
                xold1 = xnew1

            xnew1 = xold1 - self.legendre(n, xold1) / self.dlegendre(n, xold1)
            iter += 1
            error = fabs(xold1 - xnew1)

        return xnew1


    def weight(self, n, x):
        res = 2 / ((1- x**2) * self.dlegendre(n, x)**2)
        return res


    def exec(self):
        integral = 0

        for i in range(1, self.__mn + 1):
            integral += self.__pf(self.legendreZeroes(self.__mn, i)) * self.weight(self.__mn, self.legendreZeroes(self.__mn, i))
            # integral += self.__pf(self.__mn)

        self.result = ((self.__mb - self.__ma) / 2) * integral


    def getResult(self):
        return self.result
        