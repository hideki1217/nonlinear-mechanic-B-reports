#include <cmath>
#include <iostream>
#include <random>
#include <vector>

std::mt19937 rng(34);

const double g_E = 0.001;
const double r_E = 1;
const int N_E = 50;
const double g_I = 0.5;
const double r_I = 0.02;
const int N_I = 10;

const double dt = 1e-3;
const double T = 100;

void main_impl(const double v0) {
  const int iteration = int(T / dt) + 1;

  std::vector<std::vector<double> > t_E_list;
  for (int i = 0; i < N_E; i++) {
    std::vector<double> t_E;
    {
      std::exponential_distribution<> exp_dist(r_E);

      double t = 0;
      while (t <= T) {
        t += exp_dist(rng);
        t_E.push_back(t);
      }
    }
    t_E_list.push_back(t_E);
  }

  std::vector<std::vector<double> > t_I_list;
  for (int i = 0; i < N_I; i++) {
    std::vector<double> t_I;
    {
      std::exponential_distribution<> exp_dist(r_I);

      double t = 0;
      while (t <= T) {
        t += exp_dist(rng);
        t_I.push_back(t);
      }
    }
    t_I_list.push_back(t_I);
  }

  double v = v0;
  double t = 0;
  std::vector<int> next_t_E_list(N_E, 0);
  std::vector<int> next_t_I_list(N_I, 0);
  for (int i = 0; i < iteration; i++) {
    std::printf("%.6f %.8f\n", t, v);

    double dv = -v * dt;

    for (int j = 0; j < N_E; j++) {
      int& next_t_E = next_t_E_list[j];
      if (t_E_list[j][next_t_E] < t) {
        next_t_E += 1;
        dv += g_E;
      }
    }

    for (int j = 0; j < N_I; j++) {
      int& next_t_I = next_t_I_list[j];
      if (t_I_list[j][next_t_I] < t) {
        next_t_I += 1;
        dv += g_I;
      }
    }

    v += dv;
    t += dt;

    if (v >= 1) {
      v = 0;
    }
  }
}

int main() { main_impl(0.1); }