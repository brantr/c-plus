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


lg = 0.1
bg = 0.12
rg = 0.03
tg = 0.03

wx = 1.0 - lg - rg
wy = 1.0 - bg - tg

set_plot,'ps'
device,filename='TA_vs_tau0.eps',/encapsulated,/color,bits=8
device,xsize=5,ysize=5*wx/wy,/inches
bkg = fltarr(100,100)
tv,bkg,0,xsize=1,ysize=1,/normal
plot,[0],[0],xrange=[-2,3.5],yrange=[-2.0,2.0],xstyle=1,ystyle=1,xtitle='log!L10!N !Mt!L0!N',ytitle='log!L10!N !MD T!LA!N [K]',font=1,charsize=1.2,color=255,position=[lg,bg,lg+wx,bg+wy],/normal,/noerase,xthick=3,ythick=3

loadct,13,/silent

oplot,tau0,T100,color=255,thick=5
oplot,tau0,T10,color=225,thick=5
oplot,tau0,T1,color=210,thick=5
oplot,tau0,T01,color=140,thick=5
oplot,tau0,T001,color=80,thick=5
oplot,tau0,T0001,color=40,thick=5

loadct,0,/silent
device,/close
set_plot,'x'


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