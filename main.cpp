#include <iostream>
#include <algorithm>
#include <iomanip>
#include "funkcijos.h"
#include "vector.h"
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
    
    manoVector<studentas> studentai_vector;
    // std::vector<studentas> studentai_vector;


    Timer bendras_timer;
    bendras_timer.start();
    
    Timer nuskaitymas_timer;
    nuskaitymas_timer.start();

    nuskaitymas(studentai_vector, failo_pavadinimas);
    
    nuskaitymas_timer.stop();
    std::cout << "Duomenu nuskaitymas ir galutiniu pazymiu skaiciavimas uztruko " << nuskaitymas_timer.elapsed() << " sec." << std::endl;

    Timer sort_timer;
    sort_timer.start();

    manoVector<studentas>vargsai_vector = skaidymas(studentai_vector);
    // std::vector<studentas>vargsai_vector = skaidymas(studentai_vector);

    // vargsai_vector.swap(studentai_vector); testavimui

    sort_timer.stop();
    std::cout << "Studentu skaidymas i vargsus ir malacius uztruko " << sort_timer.elapsed() << " sec." << std::endl;
    
    isvedimas(vargsai_vector, "vargsai.txt");
    isvedimas(studentai_vector, "malaciai.txt");

    bendras_timer.stop();
    std::cout << "Visos programos veikimo laikas " << bendras_timer.elapsed() << " sec." << std::endl;
    
    std::cout << "vargsai dydis: " << vargsai_vector.getSize() << ", malaciai dydis: " << studentai_vector.getSize() << std::endl;
    // std::cout << "vargsai dydis: " << vargsai_vector.size() << ", malaciai dydis: " << studentai_vector.size() << std::endl;
    

    return 0;
}

