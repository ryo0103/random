import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

results = []
with open("output/output.txt", "r") as f:
    line = f.readline()
    results = [float(result) for result in line.strip().split(",")]
plt.hist(results, bins=30, edgecolor="black", alpha=0.7)
plt.grid(True)
plt.savefig("output/output.png")