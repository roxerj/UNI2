#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "funkcijos.h"
#include <chrono>
#include <fstream>

void print(std::vector<studentas> &studentai)
{
    std::string output = "Vardas         Pavarde           Galutinis(vid.) Galutinis(med.)\n";
    output += "-----------------------------------------------------------------------\n";
    
    auto start2 = std::chrono::high_resolution_clock::now();
    for (auto &studentas : studentai)
    {
        char a[20];
        sprintf(a, "%5.2f           %5.2f", studentas.galutinis_vid, studentas.galutinis_med);

        studentas.vardas.resize(15, ' ');
        studentas.pavarde.resize(17, ' ');

        output += studentas.vardas + studentas.pavarde + std::string(a) + "\n";
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    
    
    auto start3 = std::chrono::high_resolution_clock::now();
    std::ofstream out_file("output.txt");

    if (out_file.is_open()) { 
        out_file.close();
        std::cout << "Output isvestas i faila \"output.txt\"\n";
    } else {
        std::cout << "Isvesties failo atidaryti nepavyko.\n";
    }
    auto end3 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration2 = end2 - start2;
    std::chrono::duration<double> duration3 = end3 - start3;
    std::cout << "\nOutputo formatavimas uztruko " << duration2.count() << " sec." << std::endl;
    std::cout << "Outputo isvedimas i faila uztruko " << duration3.count() << " sec." << std::endl;

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
    for(auto pazymys:nd_vec)
    {
        temp += pazymys;
    }
    return temp/double(nd_vec.size());
}


