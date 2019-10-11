#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Modulos python
import numpy as np
import scipy.interpolate
import matplotlib as mpl
import matplotlib.pyplot as plt

#le os dados e armazena em 2 vetores: x, y.
x, y = np.loadtxt('dados01.dat', unpack=True)

#plotando graficos
plt.plot(x, y, linestyle='-' , color='k', label= r'$\omega = 10 rad/s $')

#colocando legenda
plt.legend(loc='best')

#colocando nomes
plt.title('Trajetoria de Bobi')
plt.xlabel('X')
plt.ylabel('Y')
plt.show()