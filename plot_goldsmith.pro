;figure 1
fname = "optically_thin.txt"
n = read_seven_arrays(fname,X,T50,T50bkg,T100,T100bkg,T250,T250bkg)

device,decompose=0
window,2,xsize=600,ysize=600
plot,[0],[0],xrange=[-2,2],yrange=[-0.5,2.],xstyle=1,ystyle=1
loadct,13,/silent
oplot,X,T50,color=110
oplot,X,T50bkg,color=110,linestyle=2
oplot,X,T100,color=80
oplot,X,T100bkg,color=80,linestyle=2
oplot,X,T250,color=255
oplot,X,T250bkg,color=255,linestyle=2
loadct,0,/silent

;figure 2
fname = "optically_thick.txt"
n_ot = read_four_arrays(fname,Xot,T50ot,T100ot,T250ot)

device,decompose=0
window,6,xsize=600,ysize=600
plot,[0],[0],xrange=[-2,2],yrange=[-1.0,2.6],xstyle=1,ystyle=1
loadct,13,/silent
oplot,Xot,T50ot,color=110
oplot,Xot,T100ot,color=80
oplot,Xot,T250ot,color=255
loadct,0,/silent


;figure 3
fname = "optically_thick_with_bkg.txt"
n_otb = read_four_arrays(fname,Xotb,T100_90b,T100_60b,T100_b)

device,decompose=0
window,10,xsize=600,ysize=600
plot,[0],[0],xrange=[-2,2],yrange=[-1.0,2.6],xstyle=1,ystyle=1
loadct,13,/silent
oplot,Xotb,T100_90b,color=110
oplot,Xotb,T100_60b,color=80
oplot,Xotb,T100_b,color=255
loadct,0,/silent

;figure 4
fname = "TA_vs_tau0.txt"
ntau0 = read_seven_arrays(fname,tau0,T100,T10,T1,T01,T001,T0001)
device,decompose=0
window,14,xsize=600,ysize=600
plot,[0],[0],xrange=[-2,3.5],yrange=[-2.0,2.0],xstyle=1,ystyle=1
oplot,tau0,T100
oplot,tau0,T10
oplot,tau0,T1
oplot,tau0,T01
oplot,tau0,T001
oplot,tau0,T0001


;figure 5
fname = "TA_vs_tau.txt"
ntau0 = read_twelve_arrays(fname,tau100,T100,tau10,T10,tau1,T1,tau01,T01,tau001,T001,tau0001,T0001)
device,decompose=0
window,18,xsize=600,ysize=600
plot,[0],[0],xrange=[-2,3.5],yrange=[-2.0,2.0],xstyle=1,ystyle=1
oplot,tau100,T100
oplot,tau10,T10
oplot,tau1,T1
oplot,tau01,T01
oplot,tau001,T001
oplot,tau0001,T0001

end