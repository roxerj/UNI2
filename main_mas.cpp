#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

struct studentas {
    std::string vardas;
    std::string pavarde;
    int egz {};
    double galutinis_vid {};
    double galutinis_med {};
};

void print(const studentas stud_masyvas[], int count);

double count_med(int nd_mas[], int nd_count);

double count_vid(int nd_mas[], int nd_count);

void ivesti_pazymius(studentas &stud);

void generuoti_pazymius(studentas &stud);

bool arskaicius(std::string test);

int main(){

    studentas *stud_masyvas;

    std::string n = "";
    std::cout << "Kiek bus studentu? Iveskite teigiama skaiciu ";
    std::cin >> n;
    while(!arskaicius(n) || stoi(n) <= 0)
    {
        std::cout << "Iveskite teigiama skaiciu ";
        std::cin >> n;
    }
    int count = stoi(n);
    stud_masyvas = new studentas[count];

    for(int i = 0; i < count; i++)
    {
        char generuoti = 0;
        studentas stud;

        
        std::cout << "\nIveskite studento varda: ";
        std::cin >> stud.vardas;
        std::cout << "Iveskite studento pavarde: ";
        std::cin >> stud.pavarde;
        
        while(generuoti != '1' && generuoti != '2')
        {
            std::cout << "Iveskite 1, jei norite, kad namu darbu ir egzamino pazymiai butu generuojami atsitiktinai. Iveskite 2, jei norite ivesti pazymius rankiniu budu. ";
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

        stud_masyvas[i] = stud;

    }


    print(stud_masyvas, count);

    delete [] stud_masyvas;


    return 0;
}



void print(const studentas stud_masyvas[], int count)
{
    std::cout << "\nVardas       Pavarde        Galutinis(vid.) / Galutinis(med.)" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    
    for(int i = 0; i < count; i++)
    {
        std::cout << std::left;
        std::cout << std::setw(13) << stud_masyvas[i].vardas << std::setw(15) << stud_masyvas[i].pavarde << std::setprecision(3) << std::setw(18)<< stud_masyvas[i].galutinis_vid << stud_masyvas[i].galutinis_med << std::endl;
    }
}

double count_med(int nd_mas[], int nd_count)
{
    std::sort(nd_mas, nd_mas + nd_count);
    if(nd_count % 2 != 0)
    {
        return double(nd_mas[(nd_count - 1) / 2]);
    }
    else
    {
        return (double(nd_mas[(nd_count/2) - 1]) + double(nd_mas[nd_count/2])) / 2;
    }
}

double count_vid(int nd_mas[], int nd_count)
{
    double temp = 0;
    for(int i = 0; i < nd_count; i++)
    {
        temp += nd_mas[i];
    }
    return temp/double(nd_count);
}

void ivesti_pazymius(studentas &stud)
{
    std::string temp,temp1 = "a";
    int nd_count {};

    std::cout << "Kiek bus pazymiu? Iveskite teigiama skaiciu ";
    std::cin >> nd_count;

    int *nd_mas;

    nd_mas = new int[nd_count];

    std::cout << "Iveskite studento namu darbu pazymius balais nuo 1 iki 10, atskirkite juos tarpais. Iveskite 0, jei norite baigti ivedima" << std::endl;

    for(int i = 0; i < nd_count; i++)
    {
        std::cin >> temp;
        
        if(!arskaicius(temp))
        {
            std::cout << "Iveskite skaiciu be simboliu ar raidziu" << std::endl;
            i--;
            continue;
        }
         
        int temp_nd = stoi(temp);
        
        if((0 < temp_nd) && ( temp_nd < 11))
        {
            nd_mas[i] = temp_nd;
        }
        else
        {
            std::cout << "Iveskite skaiciu nuo 1 iki 10" << std::endl;
            i--;
        }

    }

    std::cout << "Iveskite studento egzamino pazymi nuo 1 iki 10" << std::endl;
    std::cin >> temp1;
    while(!arskaicius(temp1))
    {
        std::cout << "Iveskite skaiciu nuo 1 iki 10 be raidziu ar simboliu" << std::endl;
        std::cin >> temp1;
    }
    stud.egz = stoi(temp1);
    while(stud.egz < 1 || stud.egz > 10)
    {
        std::cout << "Pazymis turi buti nuo 1 iki 10" << std::endl;
        std::cin >> stud.egz;
    }
    
    stud.galutinis_med = 0.4 * count_med(nd_mas, nd_count) + 0.6 * stud.egz;
    stud.galutinis_vid = 0.4 * count_vid(nd_mas, nd_count) + 0.6 * stud.egz;

    delete [] nd_mas;
}

void generuoti_pazymius(studentas &stud)
{
    int *nd_mas;
    
    int n = 0;
    srand((unsigned) time(NULL));
    while(n <= 0)
    {
        std::cout << "Kiek bus namu darbu pazymiu? Iveskite teigiama skaiciu" << std::endl;
        std::cin >> n;
    }

    nd_mas = new int[n];

    for(int i = 0; i < n; i++)
    {
        int random = rand() % 10 + 1;
        nd_mas[i]= random;
    }

    stud.egz = rand() % 10 +1;

    stud.galutinis_med = 0.4 * count_med(nd_mas, n) + 0.6 * stud.egz;
    stud.galutinis_vid = 0.4 * count_vid(nd_mas, n) + 0.6 * stud.egz;

    delete [] nd_mas;
}

bool arskaicius(std::string test)
{
    for(int i = 0; i < test.length(); i++)
    {
        if(!isdigit(test[i]))
        {
            return 0;
        }
    }
    return 1;
}
