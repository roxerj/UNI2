#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "funkcijos.h"
#include <chrono>
#include <fstream>
#include <cstring>

void isvedimas(std::vector<studentas> &studentai, std::string failo_pav)
{
    std::string output = "Vardas         Pavarde           Galutinis(vid.) Galutinis(med.)\n";
    output += "-----------------------------------------------------------------------\n";
    
    Timer formatavimas_timer;
    formatavimas_timer.start();
    for (auto &studentas : studentai)
    {
        char a[20];
        sprintf(a, "%5.2f           %5.2f", studentas.galutinis_vid, studentas.galutinis_med);

        studentas.vardas.resize(15, ' ');
        studentas.pavarde.resize(17, ' ');

        output += studentas.vardas + studentas.pavarde + std::string(a) + "\n";
    }
    formatavimas_timer.stop();
    
    
    Timer isvedimas_timer;
    isvedimas_timer.start();
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

    std::cout << failo_pav <<" formatavimas uztruko " << formatavimas_timer.elapsed() << " sec." << std::endl;
    std::cout << failo_pav << " isvedimas i faila uztruko " << isvedimas_timer.elapsed() << " sec." << std::endl;

}


double count_med(std::vector<int> &nd_vec)
{
    std::sort(nd_vec.begin(), nd_vec.end());
    if(nd_vec.size() % 2 != 0)
    {
        return nd_vec.at((nd_vec.size() - 1) / 2);
    }
    else
    {
        return (double(nd_vec.at((nd_vec.size()/2) - 1)) + double(nd_vec.at(nd_vec.size()/2))) / 2;
    }
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

bool compare(const studentas& s1, const studentas& s2) {
    if(s1.pavarde == s2.pavarde)
    {
        return s1.vardas < s2.vardas;
    }
    else
    {
        return s1.pavarde < s2.pavarde;
    }
}

std::string generuoti(int count)
{
    Timer generate_timer;
    generate_timer.start();

    std::string failas;
    std::string temp_vardas = "Vardas";
    std::string temp_pavarde = "Pavarde";
    srand((unsigned) time(NULL));
    
    
    const int vardas_width = 25;
    const int pazymys_width = 8;
    const int line_width = (vardas_width * 2) + (pazymys_width * 7) + pazymys_width + 1;
    
    
    char header[line_width + 1];
    std::sprintf(header, "%-*s%-*s", vardas_width, "Vardas", vardas_width, "Pavarde");
    for(int i = 1; i <= 7; i++) 
    {
        std::sprintf(header + strlen(header), "%-*s", pazymys_width, ("ND" + std::to_string(i)).c_str());
    }
    std::sprintf(header + strlen(header), "%-*s\n", pazymys_width, "Egz.");
    failas += header;
    
    
    for(int i = 0; i < count; i++)
    {
        char line[line_width + 1];
        std::string vardas = temp_vardas + std::to_string(i+1);
        std::string pavarde = temp_pavarde + std::to_string(i+1);
        std::sprintf(line, "%-*s%-*s", vardas_width, vardas.c_str(), vardas_width, pavarde.c_str());
        
        
        for(int j = 0; j < 7; j++) 
        {
            int random = rand() % 10 + 1;
            std::sprintf(line + strlen(line), "%-*d", pazymys_width, random);
        }
        
    
        int random = rand() % 10 + 1;
        std::sprintf(line + strlen(line), "%-*d\n", pazymys_width, random);
        failas += line;
    }
    generate_timer.stop();
    std::cout << "Generavimas uztruko " << generate_timer.elapsed() << " sec" << std::endl;
    return failas;

    
}

void rusiavimas(std::vector<studentas> &studentai, std::vector<studentas> &vargsai, std::vector<studentas> &malaciai)
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
}

void nuskaitymas(std::vector<studentas> &studentai, std::string failo_pavadinimas)
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
}


