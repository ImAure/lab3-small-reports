import numpy as np

data = np.loadtxt("temp_avg.txt", delimiter=',', usecols=[0, 1])
#t, temp = (data[:, 0] - 21000) / 60000, data[:, 1]

np.savetxt("temp_avg.dat", np.column_stack((data[:, 0], data[:, 1])))

#import numpy                as np
#import matplotlib.pyplot    as plt
#
#plt.rcParams.update({
#    "pgf.texsystem": "pdflatex",
#    "text.usetex": True,
#    "font.family": "serif",
#    "pgf.rcfonts": False,  # Non ereditare font da matplotlib
#})
#
#fig = plt.figure(figsize=(1, 1))  # usa una figura piccola, scalabile dopo
#ax = fig.add_subplot(111)
#
#data = np.loadtxt("dati.txt", delimiter = ',', usecols = [0, 1])
#t, temp = (data[:,0] - 21000) / 60000, data[:,1]
#ax.scatter(t, temp, s = 2, c = "black", marker = '.')
#
#ax.set_xlim(0, 330)
#ax.set_ylim(16, 28)
#ax.set_xticks([0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330])
#ax.set_yticks([16, 18, 20, 22, 24, 26, 28])
#ax.set_xlabel("Time (minutes)")
#ax.set_ylabel("Temperature (°C)")
#
#fig.savefig("grafico.pgf")
#print("fatto!")

#########################

#import numpy as np
#import matplotlib.pyplot as plt
#
#plt.rcParams.update({
#    "pgf.texsystem": "pdflatex",
#    "text.usetex": True,
#    "font.family": "serif",
#    "pgf.rcfonts": False,
#})
#
#fig = plt.figure(figsize=(4, 3))  # Dimensione arbitraria, verrà gestita da LaTeX
#ax = fig.add_subplot(111)
#
#data = np.loadtxt("dati.txt", delimiter=',', usecols=[0, 1])
#t, temp = (data[:, 0] - 21000) / 60000, data[:, 1]
#ax.scatter(t, temp, s=2, c="black", marker='.')
#
#ax.set_xlim(0, 330)
#ax.set_ylim(16, 28)
#ax.set_xticks(np.arange(0, 331, 30))
#ax.set_yticks([16, 18, 20, 22, 24, 26, 28])
#ax.set_xlabel("Time (minutes)")
#ax.set_ylabel("Temperature (°C)")
#
#plt.savefig("plotcontent.pgf")
