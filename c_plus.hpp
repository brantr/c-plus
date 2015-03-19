#ifndef C_PLUS_H
#define C_PLUS_H

class C_Plus
{
public:
  double g_u;     //statistical weight of upper level
  double g_l;     //statistical weight of lower level
  double A_ul;    //spontaneous decay rate
  double B_ul;    //stimulated emission coeff
  double B_lu;    //stimulated absorption coeff
  double T_star;  //equivalent temperature = h nu/k
  double nu_C_plus;     //frequency in Hz
  double E_C_plus;      //energy in ergs
  double lambda_C_plus; //wavelength in cm
  double h;             //planck's constant in cgs

  double T_bg;    //Temp of bkg radiation field
  double T_kin;   //Kinetic temperature
  double T_A_so;  //Antenna temp from bkg source

  //double G;       //Bkg term = [exp(T*/Tbg)-1]^-1
  //double K;       //Kinetic temp term = exp(T*/Tkin)
  //double X;       //ratio down coll. rate / spon decay rate
  double g;       //ratio of statistical weight gu/gl

  C_Plus(void);   //constructor
  double T_ex(double T, double X, double G);    //excitation temperature

  double R_ul_e(double T);  //collisional deexc coeff for e-
  double R_ul_H0(double T); //collisional deexc coeff for H0
  double R_ul_H2(double T); //collisional deesc coeff for H2

  //total collisional de-excitation rate
  double C_ul_total(double n_e, double n_H0, double n_H2, double T);

  //photon escape probability in the large velocity gradient model
  double beta_lvg(double tau);

  //zero excitation optical depth of C+
  double tau_0(double N_C_plus, double dv);

  //optical depth of the C+ line
  double tau_XG(double T, double X, double G, double tau0);

  //background factor for nonzero temp background
  double G_bkg(double T_bkg);

  //change in antenna temperature for C+
  double Delta_T_A(double T, double X, double G, double tau0);

  //find X from tau_0, T, G, and Cul_Aul,
  //also return the corresponding tau
  double find_X(double T, double G, double tau_0, double Cul_Aul, double *tau_out);

  //find the specific intensity in erg cm^-2 s^-1 str^-1
  //given physical properties of the gas
  double I_nu(double N_C_plus, double dv, double n_e, double n_H0, double n_H2, double T, double T_bkg);
};
#endif //C_PLUS_H