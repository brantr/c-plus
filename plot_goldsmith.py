import matplotlib.pyplot as plt
import numpy as np
from array_io import *


#figure 1
fname = "optically_thin.txt"
X,T50,T50bkg,T100,T100bkg,T250,T250bkg = read_seven_arrays_nlines(fname)

fsize = 5.0

lg = 0.1
bg = 0.1
rg = 0.03
tg = 0.03
wx = 1.0 - lg - rg
wy = 1.0 - bg - tg

plt.figure(figsize=(fsize,fsize*wx/wy))
plt.xlim(-2,2)
plt.ylim(-0.5,2.)
plt.plot(X,T50,'-',color="green")
plt.plot(X,T50bkg,'-',linestyle="dashed",color="green")
plt.plot(X,T100,'-',color="blue")
plt.plot(X,T100bkg,'-',linestyle="dashed",color="blue")
plt.plot(X,T250,'-',color="red")
plt.plot(X,T250bkg,'-',linestyle="dashed",color="red")
plt.ylabel(r"$\log (T_{A} / \tau_0)$")
plt.xlabel(r"$\log (X = C_{ul}/A_{ul})$")

fplot = "goldsmith2012_figure1.png"
plt.savefig(fplot, bbox_inches="tight")



#figure 2
fname = "optically_thick.txt"
Xot,T50ot,T100ot,T250ot = read_four_arrays_nlines(fname)
plt.figure(figsize=(fsize,fsize*wx/wy))
plt.xlim(-2,2)
plt.ylim(-1.0,2.6)
plt.plot(Xot,T50ot,'-',color="green")
plt.plot(Xot,T100ot,'-',color="blue")
plt.plot(Xot,T250ot,'-',color="red")
plt.ylabel(r"$\log (T_{A} / \mathrm{K})$")
plt.xlabel(r"$\log (X = C_{ul}/\beta A_{ul})$")

fplot = "goldsmith2012_figure2.png"
plt.savefig(fplot, bbox_inches="tight")



#figure 3
fname = "optically_thick_with_bkg.txt"
Xotb,T100_90b,T100_60b,T100_b = read_four_arrays_nlines(fname)

plt.figure(figsize=(fsize,fsize*wx/wy))
plt.xlim(-2,2)
plt.ylim(-1.0,2.6)
plt.plot(Xotb,T100_90b,'-',color="green")
plt.plot(Xotb,T100_60b,'-',color="blue")
plt.plot(Xotb,T100_b,'-',color="red")
plt.ylabel(r"$\log (T_{A} / \mathrm{K})$")
plt.xlabel(r"$\log (X = C_{ul}/\beta A_{ul})$")

fplot = "goldsmith2012_figure3.png"
plt.savefig(fplot, bbox_inches="tight")


#figure 4
fname = "TA_vs_tau0.txt"
tau0,T100,T10,T1,T01,T001,T0001= read_seven_arrays_nlines(fname)

plt.figure(figsize=(fsize,fsize*wx/wy))
plt.xlim(-2,3.5)
plt.ylim(-2.0,2.0)
plt.plot(tau0,T100,'-')
plt.plot(tau0,T10,'-')
plt.plot(tau0,T1,'-')
plt.plot(tau0,T01,'-')
plt.plot(tau0,T001,'-')
plt.plot(tau0,T0001,'-')
plt.ylabel(r"$\log (\Delta T_{A} / \mathrm{K})$")
plt.xlabel(r"$\log (\tau_0)$")

fplot = "goldsmith2012_figure4.png"
plt.savefig(fplot, bbox_inches="tight")



#figure 5
fname = "TA_vs_tau.txt"
tau100,T100,tau10,T10,tau1,T1,tau01,T01,tau001,T001,tau0001,T0001 = read_twelve_arrays_nline(fname)
plt.figure(figsize=(fsize,fsize*wx/wy))
plt.xlim(-2,3.5)
plt.ylim(-2.0,2.0)
plt.plot(tau100,T100,'-')
plt.plot(tau10,T10,'-')
plt.plot(tau1,T1,'-')
plt.plot(tau01,T01,'-')
plt.plot(tau001,T001,'-')
plt.plot(tau0001,T0001,'-')
plt.ylabel(r"$\log (\Delta T_{A} / \mathrm{K})$")
plt.xlabel(r"$\log (\tau)$")

fplot = "goldsmith2012_figure5.png"
plt.savefig(fplot, bbox_inches="tight")


