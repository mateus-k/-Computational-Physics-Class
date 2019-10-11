#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Modulos python
import numpy as np
import scipy.interpolate
import matplotlib as mpl
import matplotlib.pyplot as plt

#le os dados e armazena em 2 vetores: x, y.
x, y = np.loadtxt('dados01.dat', unpack=True)

#fazendo ajuste
coef = np.polyfit(x , y, 2)
print coef

pol = np.poly1d(coef)
print pol

xnovo = np.linspace(-6.0, 10.0 , 30)
ynovo = pol(xnovo)

#plotando os dados e o ajuste
plt.plot(x, y, '.')
plt.plot(xnovo, ynovo, linestyle= '--', marker='^', color='g' )

#colocando legenda
plt.legend(['dados01.dat', r'$y = \alpha x^2+\beta x+\gamma $' ], loc=3)

#colocando nomes
plt.title('Exemplo 01')
plt.xlabel('X')
plt.ylabel('Y')
plt.show()


