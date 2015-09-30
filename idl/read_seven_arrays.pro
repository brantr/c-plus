function read_seven_arrays,fdata,x,y,z,u,t,v,p

	openr,1,fdata
	n = 0L
	readf,1,n
	x = dblarr(n)
	y = dblarr(n)
	z = dblarr(n)
	u = dblarr(n)
	t = dblarr(n)
	v = dblarr(n)
	p = dblarr(n)
	for i=0L,n-1 do begin
		readf,1,xb,yb,zb,ub,tb,vb,pb
		x(i) = double(xb)
		y(i) = double(yb)
		z(i) = double(zb)
		u(i) = double(ub)
		t(i) = double(tb)
		v(i) = double(vb)
		p(i) = double(pb)
	endfor
	close,1
	return,n


end
