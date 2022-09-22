//---------------------------------------------------------------------------

#pragma hdrstop

#include "matriz.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void cargarTipoVector(TStringGrid*v, byte N){
  if (N > 0) {
	cargarTipoVector(v,N-1);
	byte m=v->ColCount;
	v->Cells[(N-1)%m][(N-1)/m] = N;
  }
}
//---------------------------------------------------------------------------
//	1	1	1	1	1	1	1
//	2	3	3	3	3	3   1
//	2   4	5	5	5	3	1
//	2   4   6   7	5   3	1
//	2	4   6   6	6	3	1
//	2	4	4   4	4	4	1
//	2	2	2	2	2	2   2
void llenarf1(TStringGrid*v,byte fa,byte ca,byte cb,byte &k){
	byte c = cb-ca+1;
	if (c> 0) {
	 llenarf1(v,fa,ca,cb-1,k);
	 v->Cells[cb][fa]=k;
 }
}
void llenarc2(TStringGrid*v,byte fa,byte fb,byte cb,byte &k){
  byte f = fb-fa+1;
  if (f > 0) {
	llenarc2(v,fa,fb-1,cb,k);
	v->Cells[cb][fb]=k;
  }
}
void llenarf2(TStringGrid*v,byte fa,byte ca,byte cb,byte &k){
  byte c = cb-ca+1;
  if (c> 0) {
	llenarf2(v,fa,ca+1,cb,k);
	v->Cells[ca][fa]=k;
  }
}
void llenarc1(TStringGrid*v,byte fa,byte fb,byte ca,byte &k){
	byte f = fb-fa+1;
   if (f > 0) {
	llenarc1(v,fa+1,fb,ca,k);
	v->Cells[ca][fa]=k;
   }
}
void cargar2019_2B(TStringGrid*v,byte fa,byte fb,byte ca,byte cb,byte &k){
  byte f = fb-fa+1;
  byte c = cb-ca+1;
  if (f*c>0) {
	if (f*c == 1)
	  v->Cells[ca][fa]=k;
	else{
	  llenarf1(v,fa,ca,cb-1,k);
	  llenarc2(v,fa,fb-1,cb,k);
	  k++;
	  llenarf2(v,fb,ca+1,cb,k);
	  llenarc1(v,fa+1,fb,ca,k);
	  k++;
	  cargar2019_2B(v,fa+1,fb-1,ca+1,cb-1,k);
    }
  }
}
//-------------------------------------------------------------
//					1
//				2	3
//			6	5	4
//		7	8	9   10
//	15  14  13	12	11
void cargarCol2019_32(TStringGrid *v, byte ca, byte cb, byte f, byte &z){
	byte c = cb - ca + 1;
	if (c > 0) {
	  if (f % 2 == 0) {
		c = cb;
		cb--;
	  }else {
		c = ca;
		ca++;
	  }
	  v->Cells[c][f] = z;
	  z++;
	  cargarCol2019_32(v,ca, cb, f, z);
	}
}


void cargarFila2019_32(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte &z){
  byte f = fb - fa + 1;
  if (f > 0) {
	cargarCol2019_32(v, fb-fa, cb, fa, z);
	cargarFila2019_32(v, fa+1, fb, ca, cb, z);
  }
}
//-------------------------------------------------------------
void cargar2020_1Segunda(TStringGrid *v, byte m, byte k, byte &f, byte &c){
  if (k == 1) {
	f = m-1;
	c = 0;
  } else {
	cargar2020_1Segunda(v,m,k-1,f,c); 
	if ((m-1)%2 == (f%2)) {
	  if (c==f){                                                 
		f = f-1;
		c = c - 1;
	  } else{
		c = c + 1;								  
	  }
	} else {
	  if (c == 0) f = f - 1; else  c = c - 1;	
    }
  }
  v->Cells[c][f] = k;
}
//-------------------------------------------------------------
//  1   3	6   10	15
//  2	5	9   14	19
//  4	8   13  18	22
//  7	12  17	21  24
//  11  16	20	23	25
void cargar2020_2(TStringGrid *v, byte m, byte k, byte &f, byte &c){
	if (k == 1) {
		f = 0;
		c = 0;
	} else {
	   cargar2020_2(v, m, k-1, f, c);
	   if (c == m-1) {
		c = f + 1;
		f = m - 1;
	   } else{
		  if (f == 0) {
			 f =c + 1;
			 c = 0;
		 } else { //
			 c++;
			 f--;
		 }
	   }
	}
	v->Cells[c][f] = k;
}
//---------------------------------------------------------------------------
//	1	2	3	4	5
//	2	3   4	5	6
//	3	4	5	6   7
//	4	5	6   7	8
//	5	6   7	8	9
void cargarCol2021_1(TStringGrid *v, byte f, byte ca, byte cb, byte x){
  byte c = cb - ca + 1;
  if (c > 0) {
	cargarCol2021_1(v, f, ca+1, cb, x+1);
	v->Cells[ca][f] = x;
  }
}

void cargarFila2021_1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb){
  byte f = fb-fa+1;
  if (f > 0) {
	cargarCol2021_1(v, fa, ca, cb, fa+1);
	cargarFila2021_1(v, fa+1, fb, ca, cb);
  }
}

//---------------------------------------------------------------------------
//	12	15	20  40
//	6	5	2	30
//	35	27  9	21
//	may=40, men = 2  maximo 2 procesos
void MayorMenorCol2021_2(TStringGrid *v,byte f, byte c, byte &men, byte &may){
	if (c == 0){
		may = 0;
		men = 0;
	}else {
	   byte x = v->Cells[c-1][f].ToInt();
	   if (c == 1) {
		   if (x > may) may = x;
		   if (x < men) men = x;
	   }else {
		   MayorMenorCol2021_2(v, f, c-1, men, may);
		   if (x > may) may = x;
		   if (x < men) men = x;
       }
    }
}

void MayorMenorFil2021_2(TStringGrid *v,byte f, byte c, byte &men, byte &may){
  if (f == 0){
	may = 0;
	men = 0;
  }else {
	if (f == 1) {
	  may = v->Cells[0][0].ToInt();
	  men = v->Cells[0][0].ToInt();
	}else {
	  MayorMenorFil2021_2(v, f-1, c, men, may);
	}
	MayorMenorCol2021_2(v, f-1, c, men, may);
  }
}
//---------------------------------------------------------------------------
//	1	1	1   1
//	1	2	2	2
//	1   2	3	3
//	1	2	3	4     matriz cuadrada
void cargarCol2022_1(TStringGrid *v, byte f, byte ca, byte cb){
  byte c = cb-ca+1;
  if (c > 0) {
	cargarCol2022_1(v, f, ca+1, cb);
	v->Cells[ca][f] = f+1;
	v->Cells[f][ca] = f+1;
  }
}
void cargarFila2022_1(TStringGrid *v, byte f, byte c){
  if (f > 0) {
	cargarFila2022_1(v, f-1, c);
	cargarCol2022_1(v, f-1, f-1, c-1);
  }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------




//dunnia-------------------------------------------------------
//	0	0	0   0   1
//	0	0	0	1   2
//	0	0	1	2   3
//	0	1	2	3	4
//	1	2	3	4   5
void cargarM1(TStringGrid * v, int f, int c, int m, int x){
		if (f < m) {
			  v->Cells[c][f] = x;
			if (c == (m - 1)) {
					f = f + 1;
					c = c - f - 1;
					x = 0;
			}
			cargarM1(v, f, c + 1 , m, x + 1);
		}
}


//	0	0	0   0   1
//	0	0	0	1   2
//	0	0	1	2   3
//	0	1	2	3	4
//	1	2	3	4   5
void cargarM2(TStringGrid * v, int f, int c, int m, int x){
  if (f < m) {
	v->Cells[c][f] = x;
	if ((f==0)||(f==(m-1))) {
	 v->Cells[c][f] = x++;
	 c = c + 1;
		if (c == (m)) {
		 c = 0;
		 f = f + 1;
		 x = 1;
		}
	} else {
	  v->Cells[0][f] = 1;
	  v->Cells[m-1][f] = m;
	  f = f + 1;
	}
	cargarM2(v, f, c , m, x);
  }
}




void cargarM(TStringGrid * v,int m, int f, int ca, int k){
  if (f < m) {
	 if (ca == m) {
		f++;
		ca = f;
		k = m-1;
	 }
	 v->Cells[ca][f] = k;
	 cargarM(v, m, f, ca + 1, k - 1);
  }
}