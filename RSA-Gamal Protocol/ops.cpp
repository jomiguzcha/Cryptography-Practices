#include "ops.h"

ZZ gcd(ZZ x, ZZ y){
    ZZ g(1);
    while(ZZ(x&1)==ZZ(0) && ZZ(y&1)==ZZ(0)){
        x>>=1;
        y>>=1;
        g<<=1;
    }
    while(x != ZZ(0)){
        while(ZZ(x&1)==ZZ(0)){
            x>>=1;
        }
        while(ZZ(y&1)==ZZ(0)){
            y>>=1;
        }
        ZZ t=ZZ(abs(x-y))<<1;
        if(x>=y){
            x=t;
        }
        else{
            y=t;
        }
    }
    return ZZ(g*y);
}
pair<ZZ,ZZ> gcdext(ZZ x, ZZ y){
    pair<ZZ,ZZ> auxiliar;
    ZZ g(1);
    while(ZZ(x&1)==ZZ(0) && ZZ(y&1)==ZZ(0)){
        x>>=1;
        y>>=1;
        g<<=1;
    }
    ZZ u(x);
    ZZ v(y);
    ZZ A(1);
    ZZ B(0);
    ZZ C(0);
    ZZ D(1);
    while(true){
        while(ZZ(u&1)==ZZ(0)){
            u>>=1;
            if(ZZ((A|B)&1)==ZZ(0)){
                A>>=1;
                B>>=1;
            }
            else{
                A=(A+y)>>1;
                B=(B-x)>>1;
            }
        }
        while(ZZ(v&1)==ZZ(0)){
            v>>=1;
            if(ZZ((C|D)&1)==ZZ(0)){
                C>>=1;
                D>>=1;
            }
            else{
                C=(C+y)>>1;
                D=(D-x)>>1;
            }
        }
        if (u>=v){
            u=u-v;
            A-=C;
            B-=D;
        }
        else{
            v=v-u;
            C-=A;
            D-=B;
        }
        if(u == ZZ(0)){
            ZZ a(C);
            ZZ b(D);
            auxiliar.first=a;
            auxiliar.second=b;
            return auxiliar;
        }
    }
}
ZZ inversa(ZZ x, ZZ y){
    ZZ c=gcdext(x,y).second;
	while(c<ZZ(0)){
        c+=x;
	}
	return c;
}
ZZ modulo(ZZ x, ZZ y){
    if (y == 0) {
		return ZZ(0);
	}
	ZZ r = x - (x / y)*y;
	while (r < 0) {
		r +=y;
	}
	return r;
}
ZZ generare(ZZ phi,int g){
    ZZ a;
    a=RandomLen_ZZ(g);
    while(true){
        if(a>1 && a<phi && gcd(phi,a)==1){
            return a;
        }
        else{
            a=RandomLen_ZZ(g);
        }
    }
}
string rev(string b){
    string temp;
    for(int i=0;i<b.size();i++){
        temp+=b[b.size()-1-i];
    }
    return temp;
}
string ZZ_to_string(ZZ s){
    stringstream ss;
    ss<<s;
    string aux=ss.str();
    return aux;
}
string int_to_string(int s){
    stringstream ss;
    ss<<s;
    string aux=ss.str();
    return aux;
}

int string_to_int(string s){
    stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}
ZZ string_to_ZZ(string s){
    stringstream geek(s);
    ZZ x;
    geek >> x;
    return x;
}
string ASCII_to_string(int s){
    string ss;
    ss=s;
    return ss;
}
string binario(ZZ a){
    string tmp;
    while(a!=ZZ(0)){
        tmp+=ZZ_to_string(ZZ(a%2));
        a>>=1;
   }
   tmp=rev(tmp);
   return tmp;
}
ZZ bynexpo(ZZ b, string n, ZZ m){
    ZZ x(1);
    ZZ power=ZZ(modulo(b,m));
    for(int i=n.size()-1;i>=0;i--){
        if(n[i]=='1'){
            x=modulo(ZZ(x*power),m);
        }
        power=modulo(ZZ(power*power),m);
    }
    return x;
}
string arreglar_2(ZZ a,ZZ n){
    string tmp=ZZ_to_string(a);
    string tmp_1=ZZ_to_string(n);
    if(tmp.size()<(tmp_1.size())){
        tmp.insert(0,(tmp_1.size())-tmp.size(),'0');
    }
    return tmp;
}
string arreglar_3(ZZ a,ZZ n){
    string tmp=ZZ_to_string(a);
    string tmp_1=ZZ_to_string(n);
    if(tmp.size()<(tmp_1.size()-1)){
        tmp.insert(0,(tmp_1.size()-1)-tmp.size(),'0');
    }
    return tmp;
}
ZZ Generar_raiz_primitiva(ZZ n){
    ZZ aux,q,found,g;
    q=(n-1)/2;
    found=0;aux=2;
    string aux_bin=binario(aux);
    string q_bin=binario(q);
    while(found!=1){
        g=RandomBnd(n-1);
        if((bynexpo(g,aux_bin,n)!=1)&&(bynexpo(g,q_bin,n)!=1)){
            found=1;
        }
    }
    return g;
}

ZZ Generar_num_random(int b){
    ZZ rand;
    //rand=generar_random(b);
    rand=RandomPrime_ZZ(b);
    return rand;
}

string conv_binario(ZZ num){
    string binario = "";

    if (num > 0) {
        while (num > 0) {
            if (num%2 == 0) {
                binario = "0"+binario;}
            else {
                binario = "1"+binario;}
            num/=2;
        }
    }
    else if (num == 0) {
        binario = "00000000";}

    return binario;
}

int bits(ZZ num){
    string bin="";
    bin=conv_binario(num);
    return bin.length();
}

ZZ seed(ZZ& a,ZZ& b){
    ZZ almacenar;
    POINT p;
    ZZ x;ZZ y;ZZ resul;

    do{
        if (GetCursorPos(&p)){
            x=p.x;
            y=p.y;
        }
    }while(x==a && y==b);

    a=x; b=y;

    string _xy=ZZ_to_string(x)+ZZ_to_string(y);
    ZZ z(RandomBits_ZZ(16));

    almacenar=string_to_ZZ(_xy)^z;

    return almacenar;
}

ZZ xorshiftrand(int num){
    string almacenar;
    ZZ x;ZZ y;ZZ z;ZZ w;ZZ t;
    ZZ aux_x=conv<ZZ>(0);ZZ aux_y=conv<ZZ>(0);ZZ tripl;ZZ resultado;

    do{
    long a=55;
    long b=9;
    long c=56;

    x=seed(aux_x,aux_y);
    y=seed(aux_x,aux_y);
    z=seed(aux_x,aux_y);
    w=seed(aux_x,aux_y);

    t = x ^ (LeftShift(x,a));
    x = y; y = z; z = w;
    w = (w ^ (RightShift(w,b))) ^ (t ^ (RightShift(t,c)));
    almacenar+=ZZ_to_string(w);
    }while(bits(string_to_ZZ(almacenar))<num);

    return resultado=string_to_ZZ(almacenar);
}

ZZ generar_random(int by){
    cout<<"Mover el mouse"<<endl;
    ZZ var;var=xorshiftrand(by);
    while(ProbPrime(var)==0){
        var=xorshiftrand(by);
    }
    return var;
}

