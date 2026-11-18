import numpy as np
import matplotlib.pyplot as plt
import glob

files = sorted(glob.glob("frame_*.dat"))

plt.figure(figsize=(6,6))

for f in files:

    data = np.loadtxt(f)

    x=data[:,0]
    y=data[:,1]

    plt.scatter(x,y,s=1)

    plt.xlim(0,100)
    plt.ylim(0,100)

    plt.title(f)
    plt.pause(0.05)
    plt.clf()

print("Visualization complete")
