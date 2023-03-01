#include <iostream>
#include <algorithm>
#include <iomanip>
#include "funkcijos.h"
#include <fstream>
#include <chrono>
#include <stdexcept>

int main(){
    

    // system("dir");
    // system("pause");
    std::string failas;
    std::ifstream in_file;

    while (true) 
    {
        std::cout << "Iveskite failo pavadinima: ";
        std::cin >> failas;
        try 
        {
            in_file.open(failas);
            if (!in_file) 
            {
                throw std::runtime_error("Failo atidaryti nepavyko.");
            }
            std::cout << "Failas atidarytas sekmingai" << std::endl;
            break;
        } catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }
    }

    std::vector<studentas> studentai;
    studentai.reserve(1000000);
    int temp_nd, nd_count, word_count = 0;
    std::string line, word;
    getline(in_file, line);
 
    std::istringstream iss(line);
    while(iss >> word)
    {
        word_count++;
    }
    nd_count = word_count - 3;
    std::cout << "ND skaicius: " << nd_count << std::endl;

    auto start1 = std::chrono::high_resolution_clock::now(); //start timing
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

    
    auto end1 = std::chrono::high_resolution_clock::now(); // stop timing
    std::chrono::duration<double> duration1 = end1 - start1;
    std::cout << "Duomenu nuskaitymas ir galutiniu pazymiu skaiciavimas uztruko " << duration1.count() << " sec." << std::endl;

    auto start_sort = std::chrono::high_resolution_clock::now(); //start timing
    std::sort(studentai.begin(), studentai.end(), compare);
    auto end_sort = std::chrono::high_resolution_clock::now(); // stop timing
    std::chrono::duration<double> duration_sort = end_sort - start_sort;
    std::cout << "Studentu rusiavimas pagal varda/pavarde uztruko " << duration_sort.count() << " sec." << std::endl;

    print(studentai);

    

    studentai.clear();
    in_file.close();
    return 0;
}

