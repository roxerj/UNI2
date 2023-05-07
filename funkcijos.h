
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
#include <ostream>


class studentas {
    private:
        std::string vardas;
        std::string pavarde;
        float galutinis_vid {};
    public:

        studentas() : vardas(""), pavarde(""), galutinis_vid(0)
        {

        }
        studentas(std::string vard, std::string pavard) : vardas(vard), pavarde(pavard), galutinis_vid(0)
        {

        }
        studentas(std::string vard, std::string pavard, int egz) : vardas(vard), pavarde(pavard), galutinis_vid(egz)
        {

        }
        
        studentas(const studentas &other) //copy constructor
            :   vardas(other.vardas), 
                pavarde(other.pavarde), 
                galutinis_vid(other.galutinis_vid)  
        {
          //copy data from src to this
        }
        studentas(studentas &&other) //move constructor
            :   vardas(std::move(other.vardas)),
                pavarde(std::move(other.pavarde)),
                galutinis_vid(std::move(other.galutinis_vid))
        {
            //move data from src to this
            
        }
        studentas &operator=(const studentas &other) //copy assignment operator
        {
            //copy data from src to this
            
            if (this != &other)
            {
                this->vardas = other.vardas;
                this->pavarde = other.pavarde;
                this->galutinis_vid = other.galutinis_vid;
            }
            return *this;
        }

        studentas &operator=(studentas &&other) //move assignment operator
        {
            if (this != &other)
            {
                vardas = std::move(other.vardas);
                pavarde = std::move(other.pavarde);
                galutinis_vid = std::move(other.galutinis_vid);
            }
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &out, const studentas &s)
        {
            out << std::setw(15) << std::left << s.vardas << std::setw(20) << std::left << s.pavarde << std::setw(18) << std::left
            << std::setprecision(3) << s.galutinis_vid << std::endl;
            return out;
        }
        // studentas &operator<<(studentas)
        ~studentas() // destructor
        {
    
        }

        double count_vid(const std::vector<int> &nd_vec)
        {
            double temp = 0;
            for(auto &pazymys:nd_vec)
            {
                temp += pazymys;
            }
            return temp/double(nd_vec.size());
        }
        void vardasResize(int size)
        {
            vardas.resize(size, ' ');
        }
        void pavardeResize(int size)
        {
            pavarde.resize(size, ' ');
        }

        //getter functions
        std::string getVardas() const
        {
            return vardas;
        }

        std::string getPavarde() const
        {
            return pavarde;
        }

        double getGalutinis() const
        {
            return galutinis_vid;
        }
        void setGalutinis(const std::vector<int>& nd_vec, int egz) 
        {
            galutinis_vid = 0.4 * count_vid(nd_vec) + 0.6 * egz;
        }
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

std::vector<studentas> skaidymas(std::vector<studentas> &studentai);

std::string generuoti(int count);

template<typename T>
void rusiavimas(T& studentai, T& vargsai)
{
    auto it = std::stable_partition(studentai.begin(), studentai.end(), [](const studentas& s) { return s.getGalutinis() >= 5; });
    if (it == studentai.end()) {
        // partition failed, do not modify vectors
        std::cout << "partition failed\n";
        return;
    }
    std::move(it, studentai.end(), std::back_inserter(vargsai));
    studentai.erase(it, studentai.end());
}


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

    std::vector<int> nd_vec {};
    int egz = 0;
    while(in_file >> temp_vardas >> temp_pavarde)
    {
        studentas stud(temp_vardas, temp_pavarde);
        for(int i = 0; i < nd_count; i++)
        {
            in_file >> temp_nd;
            nd_vec.push_back(temp_nd);
            temp_nd = 0;
        }
        in_file >> egz;

        // stud.galutinis_med = 0.4 * count_med(nd_vec) + 0.6 * stud.egz;
        stud.setGalutinis(nd_vec, egz);

        studentai.emplace_back(temp_vardas, temp_pavarde, egz);
        nd_vec.clear();
    }
};

template<typename T>
void isvedimas(T &studentai, std::string failo_pav)
{
    std::string output = "Vardas         Pavarde           Galutinis(vid.)\n";
    output += "-----------------------------------------------------\n";
    
    Timer isvedimas_timer;
    isvedimas_timer.start();
    for (studentas &studentas : studentai)
    {
        char a[20];
        sprintf(a, "%5.2f", studentas.getGalutinis());

        studentas.vardasResize(15);
        studentas.pavardeResize(17);  

        output += studentas.getVardas() + studentas.getPavarde() + std::string(a) + "\n";
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
