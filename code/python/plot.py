import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("dati-bethe2.txt", delimiter=' ', usecols=[0,1,2])
x, E, stop = data[:,0], data[:,1], data[:,2]

fig, ax1 = plt.subplots(figsize=(5,5))

# Primo asse y
ax1.scatter(x, E, s = 1, c = "black", marker = '*', label = "E")
ax1.set_ylabel("E", color = "black")
ax1.tick_params(axis = 'y', labelcolor = "black")

# Secondo asse y
ax2 = ax1.twinx()
ax2.scatter(x, stop, s=1, c="red", marker='*', label="stop")
ax2.set_ylabel("stop", color="red")
ax2.tick_params(axis='y', labelcolor="red")

plt.xlabel("Profondità")
plt.show()



# fig = plt.figure(figsize = (5,5))
# ax = fig.add_subplot(111)
# 
# ax.scatter(x, E, s =2, c = "black", marker = '*')
# ax.scatter(x, stop, s =2, c = "red", marker = '*')
# plt.show()