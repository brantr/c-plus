#include <math.h>
#include <stdio.h>
#include "c_plus.hpp"

C_Plus::C_Plus(void)
{
  //goldsmith et al. 2012 section 2
  g_l = 2;  //lower
  g_u = 4;  //upper
  g = g_u/g_l;  //ratio
  T_star  = 91.25;  //Kelvin
  A_ul    = 2.3e-6; //per second
  h       = 6.626069e-27;
  nu_C_plus = 1900.537e9; //1900.537 GHz
  lambda_C_plus = 157.74e-4;  //cm
  E_C_plus  = h*nu_C_plus;  //energy in ergs
}
double C_Plus::R_ul_e(double T)
{
  //eqn 40 of goldsmith et al. 2012
  //in cm^3 / s
  return 8.7e-8 * pow(T/2000,-0.37);
}
double C_Plus::R_ul_H0(double T)
{
  //eqn 41 of goldsmith et al. 2012
  //in cm^3 / s
  return 4.0e-11 * (16.*0.35*sqrt(T) + 48./T);
}
double C_Plus::R_ul_H2(double T)
{
  //eqn 43 of goldsmith et al. 2012
  //in cm^3 / s
  return 3.8e-10 * pow(T/100.,0.14);
}
double C_Plus::C_ul_total(double n_e, double n_H0, double n_H2, double T)
{
  //eqn 3 of goldsmith 
  return n_e*R_ul_e(T) + n_H0*R_ul_H0(T) + n_H2*R_ul_H2(T);
}
double C_Plus::beta_lvg(double tau)
{
  //eqn 5 of goldsmith
  if(tau<2e-4)
    return 1.;
  return (1-exp(-tau))/tau;
}
double C_Plus::T_ex(double T, double X, double G)
{
  //eqn 13 of goldsmith
  double K = exp(T_star/T);
  double expTT = K*(X+1.+G)/(X+G*K);
  return T_star/log(expTT);
}
double C_Plus::tau_0(double N_C_plus, double dv)
{
  //eqn 35 of goldsmith
  //N_C_plus in cm^-2
  //dv in km/s
  return 7.49e-18 * N_C_plus/dv;
}
double C_Plus::G_bkg(double T_bkg)
{
  //eqn 8 of goldsmith ea 2012
  if(T_bkg<1.0)
    return 0.0;
  return 1./(exp(T_star/T_bkg) - 1.);
}
double C_Plus::tau_XG(double T, double X, double G, double tau0)
{
  //eqn 17 of goldsmith ea 2012
  double K = exp(T_star/T);
  return tau0 * (X*(K-1) +K)/(X*(K+g) +K*(1+G*(1+g)));
}
double C_Plus::Delta_T_A(double T, double X, double G, double tau0)
{
  //eqn 18 of goldsmith eq 2012
  //in K
  double K   = exp(T_star/T);
  double tau = tau_XG(T,X,G,tau0);
  double T_exc = T_ex(T,X,G);
  return (T_star/(exp(T_star/T_exc)-1) - T_star*G)*(1-exp(-tau));
}
double C_Plus::find_X(double T, double G, double tau_0, double Cul_Aul, double *tau_out)
{
  //iterative function to find self-consistent X and tau
  //returns X, but provides tau as well
  double tau = tau_0;
  double tau_prev;
  double beta = beta_lvg(tau);
  double X = Cul_Aul/beta;
  double X_prev;
  double T_exc = T_ex(T,X,G);
  double delta_X = 1.0e9;
  double tol = 1.0e-6;
  while(delta_X > tol)
  {
    X_prev = X;
    T_exc = T_ex(T,X,G);          //eqn 13
    tau   = tau_XG(T,X,G,tau_0);  //eqn 17
    beta  = beta_lvg(tau);        //eqn 5
    X     = Cul_Aul/beta;         //eqn 11
    delta_X = fabs((X-X_prev)/X_prev); //iterate
    //printf("T %e G %e tau0 %e tau %e T_exc %e beta %e X %e\n",T,G,tau_0,tau,T_exc,beta,X);
  }

  *tau_out = tau;
  return X;
}