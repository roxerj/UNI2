
#ifndef FUNKCIJOS_H_
#define FUNKCIJOS_H_
#include <vector>
#include <string>

struct studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd_vec {};
    int egz {};
    float galutinis_vid {};
    float galutinis_med {};
};


void print(std::vector<studentas> &studentai);

double count_med(std::vector<int> &nd_vec);

double count_vid(const std::vector<int> &nd_vec);

bool compare(const studentas& s1, const studentas& s2);

#endif
