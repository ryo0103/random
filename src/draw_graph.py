import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sys

conf_name = sys.argv[1]
results = []
with open("output/"+conf_name+"/output.txt", "r") as f:
    line = f.readline()
    results = [float(result) for result in line.strip().split(",")]
plt.hist(results, bins=30, edgecolor="black", alpha=0.7)
plt.grid(True)
plt.savefig("output/"+conf_name+"/output.png")