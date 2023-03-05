
#ifndef FUNKCIJOS_H_
#define FUNKCIJOS_H_
#include <vector>
#include <string>
#include <chrono>

struct studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd_vec {};
    int egz {};
    float galutinis_vid {};
    float galutinis_med {};
};

class Timer 
{
public:
    Timer() {}

    void start() 
    {
        start_time_ = std::chrono::high_resolution_clock::now();
    }

    void stop() 
    {
        end_time_ = std::chrono::high_resolution_clock::now();
    }

    double elapsed() const 
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(end_time_ - start_time_).count() / 1000000.0;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time_;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time_;
};

void isvedimas(std::vector<studentas> &studentai, std::string failo_pav);

double count_med(std::vector<int> &nd_vec);

double count_vid(const std::vector<int> &nd_vec);

bool compare(const studentas& s1, const studentas& s2);

std::string generuoti(int count);

void rusiavimas(std::vector<studentas> &studentai, std::vector<studentas> &vargsai, std::vector<studentas> &malaciai);

void nuskaitymas(std::vector<studentas> &studentai, std::string failo_pavadinimas);

#endif
