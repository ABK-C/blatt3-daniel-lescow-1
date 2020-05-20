#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
double mu=3.11538, n_dof = 233;

long double prob(vector<int> daten, double mu) {
  
  long double L = 1;
  for(int k : daten) {
    L *= pow(mu, k) * exp(-mu) /(tgamma(k + 1));
  }
  return L;
}

double prob2(vector<int> daten) {
  double L = 1;
  for (int k : daten){
    L *= pow(k, k)*exp(-k)/tgamma(k+1);
  }
 return L;
}

int main() {

  vector<int> daten(0);
  ifstream fin("datensumme.txt");
  int n_i;
  for(int i = 0 ; i < 234 ; ++i) {

    fin >> n_i;
    daten.push_back(n_i);

  }
  
  fin.close();

  double i=0;
  ofstream fout("likelihood.txt");
  ofstream fout2("nll.txt");
  ofstream fout3("deltall.txt");
  do{ 
    
   fout << i << " " << prob(daten,i) << endl;
   fout2 << i << " " << -2*log(prob(daten,i)) << endl;
   fout3 << i << " " << -2*log(prob(daten,mu))+2*log(prob(daten,i)) << endl;

   i+=0.1;

  } while(i<6);

  fout.close();
  fout2.close();
  fout3.close();

  cout << prob(daten , mu) << endl;
  double A = -2*log(prob(daten,mu)/prob2(daten));
  cout << A << endl;
  double z = (A-n_dof)/(sqrt(2*n_dof));
  cout << z << endl;
}