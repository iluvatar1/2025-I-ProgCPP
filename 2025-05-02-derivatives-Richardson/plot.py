import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# read data
x, h, fr, cr, fe, ce, rfe = np.loadtxt("derivatives.txt", unpack=True)

# plot 
fig, ax = plt.subplots()
ax.plot(h, fe, '-o', label='error forward')
ax.plot(h, ce, '-s', label='error central')
ax.plot(h, rfe, '-*', label='error richardson forward')
ax.set_xscale('log')
ax.set_yscale('log')
ax.set_xlabel('$h$')
ax.set_ylabel('error')
ax.legend()
fig.savefig('deriv.pdf')