#include <iostream>
#include <algorithm>
#include <iomanip>
#include "funkcijos.h"
#include <fstream>
#include <chrono>
#include <stdexcept>
#include <filesystem>
#include <limits>
#include <list>
#include <deque>

char sub_choice;

int main(){
    
    std::string failo_pavadinimas;

    failo_pavadinimas = generavimas();
    
    std::vector<studentas> studentai_vector;
    std::vector<studentas> malaciai_vector;
    std::vector<studentas> vargsai_vector;
    
    std::list<studentas> studentai_list;
    std::list<studentas> malaciai_list;
    std::list<studentas> vargsai_list;

    std::deque<studentas> studentai_deque;
    std::deque<studentas> malaciai_deque;
    std::deque<studentas> vargsai_deque;



    Timer bendras_timer;
    bendras_timer.start();
    
    Timer nuskaitymas_timer;
    nuskaitymas_timer.start();
    if(sub_choice == '1')
    {
        nuskaitymas(studentai_vector, failo_pavadinimas);
    }
    else if(sub_choice == '2')
    {
        nuskaitymas(studentai_list, failo_pavadinimas);
    }
    else if(sub_choice == '3')
    {
        nuskaitymas(studentai_deque, failo_pavadinimas);
    }

    
    nuskaitymas_timer.stop();
    std::cout << "Duomenu nuskaitymas ir galutiniu pazymiu skaiciavimas uztruko " << nuskaitymas_timer.elapsed() << " sec." << std::endl;

    Timer sort_timer;
    sort_timer.start();
    
    if(sub_choice == '1')
    {
        rusiavimas(studentai_vector, vargsai_vector, malaciai_vector);
    }
    else if(sub_choice == '2')
    {
        rusiavimas(studentai_list, vargsai_list, malaciai_list);
    }
    else if(sub_choice == '3')
    {
        rusiavimas(studentai_deque, vargsai_deque, malaciai_deque);
    }
    sort_timer.stop();
    std::cout << "Studentu rusiavimas i vargsus ir malacius uztruko " << sort_timer.elapsed() << " sec." << std::endl;
    
    if(sub_choice == '1')
    {
        isvedimas<std::vector<studentas>>(vargsai_vector, "vargsai.txt");
        isvedimas<std::vector<studentas>>(malaciai_vector, "malaciai.txt");
    }
    else if(sub_choice == '2')
    {
        isvedimas<std::list<studentas>>(vargsai_list, "vargsai.txt");
        isvedimas<std::list<studentas>>(malaciai_list, "malaciai.txt");
    }
    else if(sub_choice == '3')
    {
        isvedimas<std::deque<studentas>>(vargsai_deque, "vargsai.txt");
        isvedimas<std::deque<studentas>>(malaciai_deque, "malaciai.txt");
    }

    bendras_timer.stop();
    std::cout << "Visos programos veikimo laikas " << bendras_timer.elapsed() << " sec." << std::endl;
    

    

    return 0;
}

