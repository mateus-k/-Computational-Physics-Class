#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Modulos python
import numpy as np
import scipy.interpolate
import matplotlib as mpl
import matplotlib.pyplot as plt

#le os dados e armazena em 2 vetores: x, y.
x1, y1 = np.loadtxt('onda01.dat', unpack=True)
x2, y2 = np.loadtxt('onda02.dat', unpack=True)
x, y = np.loadtxt('superposicao.dat', unpack=True)

#plotando graficos
plt.plot(x1, y1, linestyle='-' , color='b')
plt.plot(x2, y2, linestyle='-' , color='k')
plt.plot(x, y, linestyle='--' , color='r')

#colocando legenda
plt.legend(['onda01.dat', 'onda02.dat' , 'superposicao' ], loc='best')

#colocando nomes
plt.title('Principio de superposicao')
plt.xlabel('t')
plt.ylabel(r'$y = y_0i\mathrm{sin}(\omega_i t)$')
plt.show()
