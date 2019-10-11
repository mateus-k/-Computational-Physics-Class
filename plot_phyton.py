#!/usr/bin/env python
# -*- coding: utf-8 -*-
 
#Modulos python
import numpy as np
import scipy.interpolate
import matplotlib as mpl
import matplotlib.pyplot as plt
 
#*******************************************
 
#le os dados e armazena em 2 vetores: x, y.
x, y = np.loadtxt('trajetoria.dat', unpack=True)
 
coef = np.polyfit(x , y, 2)
print coef

pol = np.poly1d(coef)
print pol

xnovo = np.linspace(0.0, 200.0 , 200)
ynovo = pol(xnovo)
  
#plotando os dados
plt.plot(x, y, marker=',', markersize=5, linestyle= ' ')
plt.plot(xnovo, ynovo, linestyle= '-', label='ajuste')

plt.legend(loc='best')

plt.ylabel(r'$y = y0 + v_{y0} t + \frac{1}{2}gt^2$')
plt.xlabel(u'posição X em metros')
plt.show()


