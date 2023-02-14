#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd_vec {};
    int egz {};
    double galutinis_vid {};
    double galutinis_med {};
};

void print(const std::vector<studentas> &studentai);

double count_med(std::vector<int> &nd_vec);

double count_vid(const std::vector<int> &nd_vec);

void ivesti_pazymius(studentas &stud);

void generuoti_pazymius(studentas &stud);

int main(){

    std::vector<studentas> studentai;


    while(true)
    {
        char testi;
        char generuoti;
        studentas stud;
        std::cout << "Iveskite studento varda: ";
        std::cin >> stud.vardas;
        std::cout << "Iveskite studento pavarde: ";
        std::cin >> stud.pavarde;
        
        while(generuoti != '1' && generuoti != '2')
        {
            std::cout << "Iveskite 1, jei norite, kad namu darbu ir egzamino pazymiai butu generuojami atsitiktinai. Iveskite 2, jei norite ivesti pazymius rankiniu budu." << std::endl;
            std::cin >> generuoti;
        }

        if(generuoti == '1')
        {
            generuoti_pazymius(stud);
        }
        else
        {
            ivesti_pazymius(stud);
        }

        stud.galutinis_med = 0.4 * count_med(stud.nd_vec) + 0.6 * stud.egz;
        stud.galutinis_vid = 0.4 * count_vid(stud.nd_vec) + 0.6 * stud.egz;

        studentai.push_back(stud);
        std::cout << "Ar norite ivesti dar viena studenta? iveskite y jei taip, n jei ne ";
        std::cin >> testi;
        if(testi != 'y')
        {
            break;
        } 

    }


    print(studentai);




    return 0;
}



void print(const std::vector<studentas> &studentai)
{
    std::cout << "\nVardas       Pavarde        Galutinis(vid.) / Galutinis(med.)" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    
    for(auto studentas:studentai)
    {
        std::cout << std::left;
        std::cout << std::setw(13) << studentas.vardas << std::setw(15) << studentas.pavarde << std::setprecision(3) << std::setw(18)<< studentas.galutinis_vid << studentas.galutinis_med << std::endl;
    }
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

void ivesti_pazymius(studentas &stud)
{
    int temp_nd = 11;

    std::cout << "Iveskite studento namu darbu pazymius balais nuo 1 iki 10, atskirkite juos tarpais. Iveskite 0, jei norite baigti ivedima" << std::endl;

    while(true)
    {
        std::cin >> temp_nd;
        if((0 < temp_nd) && ( temp_nd < 11))
        {
            stud.nd_vec.push_back(temp_nd);
        }
        else
        {
            if(temp_nd == 0)
            {
                if(stud.nd_vec.size() == 0)
                {
                    std::cout << "Iveskite bent viena namu darbu pazymi" << std::endl;
                }
                else
                {
                    break;
                }
            }
            else
            {
                std::cout << "Pazymis turi buti nuo 1 iki 10" << std::endl;
            }
        }

    }

    std::cout << "Iveskite studento egzamino pazymi nuo 1 iki 10" << std::endl;
    std::cin >> stud.egz;
    while(stud.egz < 1 || stud.egz > 10)
    {
        std::cout << "Pazymis turi buti nuo 1 iki 10" << std::endl;
        std::cin >> stud.egz;
    }
    
}

void generuoti_pazymius(studentas &stud)
{
    int n = 0;
    srand((unsigned) time(NULL));
    while(n <= 0)
    {
        std::cout << "Kiek bus namu darbu pazymiu? Iveskite teigiama skaiciu" << std::endl;
        std::cin >> n;
    }

    for(int i = 0; i < n; i++)
    {
        int random = rand() % 10 + 1;
        stud.nd_vec.push_back(random);
    }

    stud.egz = rand() % 10 +1;

}
