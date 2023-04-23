
#ifndef FUNKCIJOS_H_
#define FUNKCIJOS_H_
#include <iomanip>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <list>
#include <deque>


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

std::string generavimas();

extern char sub_choice;

double count_med(std::vector<int> &nd_vec);

double count_vid(const std::vector<int> &nd_vec);

bool compare(const studentas& s1, const studentas& s2);

std::string generuoti(int count);

template<typename T>
void rusiavimas(T &studentai, T &vargsai, T &malaciai)
{
    for(auto &stud:studentai)
    {
        if(stud.galutinis_vid < 5)
        {
            vargsai.push_back(stud);
        }
        else
        {
            malaciai.push_back(stud);
        }
    }
};

template<typename T>
void nuskaitymas(T &studentai, std::string failo_pavadinimas)
{
    std::string failas;
    std::ifstream in_file;

    in_file.open(failo_pavadinimas);

    int temp_nd, nd_count, word_count = 0;
    std::string line, word;
    getline(in_file, line);

    std::istringstream iss(line);
    while(iss >> word)
    {
        word_count++;
    }
    nd_count = word_count - 3;

    std::string temp_vardas, temp_pavarde;

    while(in_file >> temp_vardas >> temp_pavarde)
    {
        studentas stud;
        stud.vardas = temp_vardas;
        stud.pavarde = temp_pavarde;
        for(int i = 0; i < nd_count; i++)
        {
            in_file >> temp_nd;
            stud.nd_vec.push_back(temp_nd);
            temp_nd = 0;
        }
        in_file >> stud.egz;

        stud.galutinis_med = 0.4 * count_med(stud.nd_vec) + 0.6 * stud.egz;
        stud.galutinis_vid = 0.4 * count_vid(stud.nd_vec) + 0.6 * stud.egz;

        studentai.push_back(stud);

    }
};

template<typename T>
void isvedimas(T &studentai, std::string failo_pav)
{
    std::string output = "Vardas         Pavarde           Galutinis(vid.) Galutinis(med.)\n";
    output += "-----------------------------------------------------------------------\n";
    
    Timer isvedimas_timer;
    isvedimas_timer.start();
    for (auto &studentas : studentai)
    {
        char a[20];
        sprintf(a, "%5.2f           %5.2f", studentas.galutinis_vid, studentas.galutinis_med);

        studentas.vardas.resize(15, ' ');
        studentas.pavarde.resize(17, ' ');  

        output += studentas.vardas + studentas.pavarde + std::string(a) + "\n";
    }
    
    
    
    
    std::ofstream out_file(failo_pav);

    if (out_file.is_open()) 
    { 
        out_file << output;
        out_file.close();
    }else 
    {
        std::cout << "Isvesties failo atidaryti nepavyko.\n";
    }
    isvedimas_timer.stop();

    
    std::cout << failo_pav << " isvedimas i faila uztruko " << isvedimas_timer.elapsed() << " sec." << std::endl;

};


#endif
