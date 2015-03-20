#include <stdio.h>
#include <math.h>
#include "c_plus.hpp"


int main(int argc, char **argv)
{
  FILE *fp;
  char fname[200];

  C_Plus C;

  int i;
  int n = 1000;
  double X_min = -2.0;
  double X_max =  2.0;
  double logX;
  double X;

  double logtau;
  double tau_0;
  double tau_0_min = -2.0;
  double tau_0_max =  3.5;

  double T_250, T_100, T_50;
  double T_250_bkg, T_100_bkg, T_50_bkg;
  double T_100_60, T_100_90;
  double G_0, G_40, G_60, G_90;
  double X100, X10, X1, X01, X001, X0001;
  double T100, T10, T1, T01, T001, T0001;
  double t100, t10, t1, t01, t001, t0001;
  double tau_out;

  //G factors
  G_0  = C.G_bkg(0);
  G_40 = C.G_bkg(40);
  G_60 = C.G_bkg(60);
  G_90 = C.G_bkg(90);

  //first, optically thin regime
  //figure 1 of goldsmith ea 2012
  tau_0 = 1.0e-4;

  sprintf(fname,"optically_thin.txt");
  fp = fopen(fname,"w");
  fprintf(fp,"%d\n",n);
  for(i=0;i<n;i++)
  {
    logX = (X_max - X_min)*((double) i)/((double) (n-1)) + X_min;
    X = pow(10., logX);
    T_50      = log10(C.Delta_T_A( 50., X,  G_0, tau_0)/tau_0);
    T_50_bkg  = log10(C.Delta_T_A( 50., X, G_40, tau_0)/tau_0);
    T_100     = log10(C.Delta_T_A(100., X,  G_0, tau_0)/tau_0);
    T_100_bkg = log10(C.Delta_T_A(100., X, G_40, tau_0)/tau_0);
    T_250     = log10(C.Delta_T_A(250., X,  G_0, tau_0)/tau_0);
    T_250_bkg = log10(C.Delta_T_A(250., X, G_40, tau_0)/tau_0);
    fprintf(fp,"%e\t%e\t%e\t%e\t%e\t%e\t%e\n",logX,T_50,T_50_bkg,T_100,T_100_bkg,T_250,T_250_bkg);
  }
  fclose(fp);

  //second, figure 2, optically thick regime

  tau_0 = 1.0e4;

  sprintf(fname,"optically_thick.txt");
  fp = fopen(fname,"w");
  fprintf(fp,"%d\n",n);
  for(i=0;i<n;i++)
  {
    logX = (X_max - X_min)*((double) i)/((double) (n-1)) + X_min;
    X = pow(10., logX);
    T_50      = log10(C.Delta_T_A( 50., X,  G_0, tau_0));
    T_100     = log10(C.Delta_T_A(100., X,  G_0, tau_0));
    T_250     = log10(C.Delta_T_A(250., X,  G_0, tau_0));
    fprintf(fp,"%e\t%e\t%e\t%e\n",logX,T_50,T_100,T_250);
  }
  fclose(fp);

  //third, figure 3, optically thick with bkg

  tau_0 = 1.0e4;

  sprintf(fname,"optically_thick_with_bkg.txt");
  fp = fopen(fname,"w");
  fprintf(fp,"%d\n",n);
  for(i=0;i<n;i++)
  {
    logX = (X_max - X_min)*((double) i)/((double) (n-1)) + X_min;
    X = pow(10., logX);
    X100 = 100.;
    T_100      = log10(C.Delta_T_A(100., X,  G_0,  tau_0));
    T_100_60   = log10(C.Delta_T_A(100., X,  G_60, tau_0));
    T_100_90   = log10(C.Delta_T_A(100., X,  G_90, tau_0));
    fprintf(fp,"%e\t%e\t%e\t%e\n",logX,T_100_90,T_100_60,T_100);
  }
  fclose(fp);


  //fourth, figure 4, TA vs. tau_0

  sprintf(fname,"TA_vs_tau0.txt");
  fp = fopen(fname,"w");
  fprintf(fp,"%d\n",n);
  for(i=0;i<n;i++)
  {
    logtau = (tau_0_max - tau_0_min)*((double) i)/((double) (n-1)) + tau_0_min;
    tau_0 = pow(10., logtau);
    X100  = C.find_X(100., G_0, tau_0, 100., &tau_out);
    X10   = C.find_X(100., G_0, tau_0, 10.,  &tau_out);
    X1    = C.find_X(100., G_0, tau_0, 1.,   &tau_out);
    X01   = C.find_X(100., G_0, tau_0, .1,   &tau_out);
    X001  = C.find_X(100., G_0, tau_0, .01,  &tau_out);         
    X0001 = C.find_X(100., G_0, tau_0, .001, &tau_out);
    T100  = log10(C.Delta_T_A(100., X100, G_0, tau_0));
    T10  = log10(C.Delta_T_A(100., X10, G_0, tau_0)); 
    T1  = log10(C.Delta_T_A(100., X1, G_0, tau_0)); 
    T01  = log10(C.Delta_T_A(100., X01, G_0, tau_0)); 
    T001  = log10(C.Delta_T_A(100., X001, G_0, tau_0)); 
    T0001  = log10(C.Delta_T_A(100., X0001, G_0, tau_0));          
    fprintf(fp,"%e\t%e\t%e\t%e\t%e\t%e\t%e\n",logtau,T100,T10,T1,T01,T001,T0001);
  }
  fclose(fp);

  //fifth, figure 5, TA vs. tau
    sprintf(fname,"TA_vs_tau.txt");
  fp = fopen(fname,"w");
  fprintf(fp,"%d\n",n);
  tau_0_max = 5.0;
  for(i=0;i<n;i++)
  {
    logtau = (tau_0_max - tau_0_min)*((double) i)/((double) (n-1)) + tau_0_min;
    tau_0 = pow(10., logtau);
    X100  = C.find_X(100., G_0, tau_0, 100., &t100);
    X10   = C.find_X(100., G_0, tau_0, 10.,  &t10);
    X1    = C.find_X(100., G_0, tau_0, 1.,   &t1);
    X01   = C.find_X(100., G_0, tau_0, .1,   &t01);
    X001  = C.find_X(100., G_0, tau_0, .01,  &t001);         
    X0001 = C.find_X(100., G_0, tau_0, .001, &t0001);
    T100  = log10(C.Delta_T_A(100., X100, G_0, tau_0));
    T10  = log10(C.Delta_T_A(100., X10, G_0, tau_0)); 
    T1  = log10(C.Delta_T_A(100., X1, G_0, tau_0)); 
    T01  = log10(C.Delta_T_A(100., X01, G_0, tau_0)); 
    T001  = log10(C.Delta_T_A(100., X001, G_0, tau_0)); 
    T0001  = log10(C.Delta_T_A(100., X0001, G_0, tau_0));  
    t100 = log10(t100);
    t10 = log10(t10);
    t1 = log10(t1);
    t01 = log10(t01);
    t001 = log10(t001);
    t0001 = log10(t0001);        
    fprintf(fp,"%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\n",t100,T100,t10,T10,t1,T1,t01,T01,t001,T001,t0001,T0001);
  }
  fclose(fp);

  //carbon abundance
  double x_c = 1.4e-4;      //kaufman ea 1999, savage & sembach 1996
  double n_H = 1.0e2;       //H density (cm^-3)
  double N_C = 1e21 * x_c;  //Carbon column density at N_H = 10^21 cm^-2
  double dv  = 1.5;         //km/s, Kaufman 1999 S2.1, Hollenbach& Tielens 99
  double T = 100;
  printf("I_nu = %e\n",C.I_nu(N_C,dv,1e-6,n_H,1e-6,T,3));
  printf("I_nu = %e\n",C.I_nu(N_C,dv,1e-6,1e-6,n_H,1000,3));


  return 0;
}
