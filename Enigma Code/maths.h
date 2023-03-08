int modulo(int a,int n){
	int r=0,q=0;
	q=a/n;
	r=a-(q*n);
	if(r<0){
		r+=n;
	}
	return r;
}

int mcd(int y,int x){
	int r=0;
	while(y!=0){
		r=x%y;                   					
		x=y;
		y=r;
	}
	return x;
}

int eucExt(int a,int b){    
    int r,r1=a,r2=b,s,s1=1,s2=0,t,t1=0,t2=1,q;
    while (r2>0) {
	   q=r1/r2;
	   r=r1-(q*r2);
	   r1=r2;r2=r;

	   s=s1-(q*s2);
	   s1=s2;s2=s;

	   t=t1-(q*t2);
	   t1=t2;t2=t;
    }
	return s1;
}
