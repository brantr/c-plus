function read_twelve_arrays,fdata,a,b,c,d,e,f,g,h,j,k,l,m

	openr,1,fdata
	n = 0L	
	readf,1,n

	a = fltarr(n)
	b = fltarr(n)
	c = fltarr(n)
	d = fltarr(n)
	e = fltarr(n)
	f = fltarr(n)
	g = fltarr(n)
	h = fltarr(n)
	j = fltarr(n)
	k = fltarr(n)
	l = fltarr(n)
	m = fltarr(n)
	for i=0L,n-1 do begin
		;printf,1,format='(12F0," ")',a(i),b(i),c(i),d(i),e(i),f(i),g(i),h(i),j(i),k(i),l(i),m(i)
		readf,1,ab,bb,cb,db,eb,fb,gb,hb,jb,kb,lb,mb
		a(i) = ab
		b(i) = bb
		c(i) = cb
		d(i) = db
		e(i) = eb
		f(i) = fb
		g(i) = gb
		h(i) = hb
		j(i) = jb
		k(i) = kb
		l(i) = lb
		m(i) = mb
	endfor
	close,1
	return,n


end
