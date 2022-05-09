#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 12 10:19:37 2022

@author: josephdeteix
"""

import numpy as np
import matplotlib.pyplot as plt

r = 0.059/2

def txt_en_numpy(name_file):
    File_data = np.loadtxt(name_file, dtype=float)
    return File_data

def deux_tablo_plot(name_file):
    data = txt_en_numpy(name_file)
    t_max = data.shape[0]
    temps = np.linspace(0,t_max,t_max)
    #plt.plot(temps,data,label = 'Forces', color = 'r')
    #plt.title('Force en fonction du temps')
    #plt.xlabel('Temps sans unité')
    #plt.ylabel('Masse en grammes')
    return temps,data

def donne_gamma(data):
    masse = data[-1]
    mmax = np.max(data)
    fmax = 9.81*(mmax - masse)*(10**(-3))
    gamma = fmax/(4*3.141592*r)
    return gamma

if __name__ == "__main__" :
    Gamma = np.zeros(4)
    for i in range(1,5):
    	temps, data = deux_tablo_plot('resultat_txt/eau_{}'.format(i))
    	#print(np.mean(data))
    	gamma = donne_gamma(data)
    	Gamma[i-1] = gamma
    #plt.legend()
    print(np.mean(Gamma), np.std(Gamma))
    
