#include <iostream>
#include <algorithm>
#include <iomanip>
#include "funkcijos.h"
#include <fstream>
#include <chrono>
#include <stdexcept>
#include <filesystem>
#include <limits>

int main(){
    
    int choice, studentu_skaicius;
    std::string testas, failo_pavadinimas;

    
    while (true) 
    {
        std::cout << "Iveskite 1, jei norite generuoti studentu faila, iveskite 2, jei norite atlikti veiksmus su esamu failu, arba 3, jei norite iseiti: ";
        std::cin >> choice;

        try 
        {
            if (std::cin.fail()) 
            {
                throw std::runtime_error("Klaida: blogas pasirinkimas. Pasirinkite 1, 2 arba 3");
            }

            if (choice == 1) 
            {
                std::cout << "Kiek bus studentu? ";
                std::cin >> studentu_skaicius;

                try {
                    if (std::cin.fail() || studentu_skaicius <= 0) 
                    {
                        throw std::runtime_error("Klaida: neteisingai ivestas studentu skaicius");
                    }

                    testas = generuoti(studentu_skaicius);
                    failo_pavadinimas = "stud" + std::to_string(studentu_skaicius) + ".txt";

                    std::ofstream out_file(failo_pavadinimas);

                    if (!out_file.is_open()) 
                    {
                        throw std::runtime_error("Klaida: nepavyko sukurti failo");
                    }

                    out_file << testas;
                    out_file.close();
                }
                catch (const std::runtime_error& e) 
                {
                    std::cout << e.what() << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }

            else if (choice == 2) 
            {
                std::cout << "Esami failai:\n";

                for (const auto& entry : std::filesystem::directory_iterator(".")) {
                    if (entry.is_regular_file()) {
                        std::cout << entry.path().filename() << std::endl;
                    }
                }


                std::cout << "Iveskite failo pavadinima: ";
                std::cin >> failo_pavadinimas;

                std::ifstream in_file(failo_pavadinimas);

                if (!in_file) 
                {
                    throw std::runtime_error("Klaida: failas " + failo_pavadinimas + " neegzistuoja");
                }

                in_file.close();
                break;
            }

            else if (choice == 3) 
            {
                std::cout << "Programa baige darba" << std::endl;
                return 0;
            }

            else 
            {
                throw std::runtime_error("Klaida: blogas pasirinkimas. Pasirinkite 1, 2 arba 3");
            }
        }
        catch (const std::runtime_error& e) 
        {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    
    
    Timer bendras_timer;
    bendras_timer.start();

    std::vector<studentas> studentai;
    
    Timer nuskaitymas_timer;
    nuskaitymas_timer.start();
    nuskaitymas(studentai, failo_pavadinimas);
    nuskaitymas_timer.stop();
    std::cout << "Duomenu nuskaitymas ir galutiniu pazymiu skaiciavimas uztruko " << nuskaitymas_timer.elapsed() << " sec." << std::endl;

    Timer sort_timer;
    sort_timer.start();
    std::vector<studentas> vargsai;
    std::vector<studentas> malaciai;
    rusiavimas(studentai, vargsai, malaciai);
    sort_timer.stop();
    std::cout << "Studentu rusiavimas i vargsus ir malacius uztruko " << sort_timer.elapsed() << " sec." << std::endl;
    

    isvedimas(vargsai, "vargsai.txt");
    isvedimas(malaciai, "malaciai.txt");

    bendras_timer.stop();
    std::cout << "Visos programos veikimo laikas " << bendras_timer.elapsed() << " sec." << std::endl;
    std::cout << "Malaciu skaicius: " << malaciai.size() << ", vargsu skaicius: " << vargsai.size();

    

    return 0;
}

