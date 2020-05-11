#include <iostream>
#include <fstream>
#include <cmath> 
#include <vector>

using namespace std;

vector<int> zaehler(11);
int j = 0;
double p, mu = 3.11538, e=2.71828;

double poisson(int k) {

  p = pow(mu,k)*pow(e,-mu)/(tgamma(k+1));
  return p;
}

int main() {

  ifstream fin("datensumme.txt");
  int n_i;
  for(int i = 0 ; i < 234 ; ++i) {

      fin >> n_i;
      ++ zaehler[n_i]; //zaehler[n_i] += 1;

  }
  fin.close();

  ofstream fout("histpoi.txt");
  for(auto g : zaehler) {
   
    //cout << g << endl;
    fout << j << " " << g << " " << poisson(j) << endl;
    ++j;
  }

  fout.close();
}