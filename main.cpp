/**
 * @mainpage Program Documentation
 *
 * @section intro Introduction
 * This documentation provides an overview of the program and instructions on how to use it.
 *
 * @section usage Usage
 * To use the program, follow these steps:
 * - download the source files using <git clone https://github.com/roxerj/uni2/tree/v2.0> or download the zip file
 * - open terminal in the directory where the files are located
 * - type make and press enter (make sure you have make installed)
 * - follow the steps in the program, you can generate a file that contains a chosen number of students or use an existing file
 * - the program will generate two files: vargsai.txt and malaciai.txt, containing the students that failed and passed the course, respectively
 *
 * @section additional Additional Information
 * There is also a custom myVector class implemented in the source code, feel free to use it and test it out!
 */

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

/**
 * @brief Main function to process student data.
 *
 * @return The exit status of the program.
 */
int main(){

    std::string failo_pavadinimas;

    failo_pavadinimas = generavimas();

    myVector<studentas> studentai_vector;
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

    myVector<studentas>vargsai_vector = skaidymas(studentai_vector);
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
