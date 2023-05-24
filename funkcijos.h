
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
template <class T, class... Args>
class myVector; // forward declaration

/**
 * @brief Base class representing a person.
 */
class Zmogus
{
protected:
    std::string vardas; ///< Person's first name
    std::string pavarde; ///< Person's last name

    /**
     * @brief Constructor with parameters.
     * @param vard First name of the person.
     * @param pavard Last name of the person.
     */
    Zmogus(std::string vard, std::string pavard)
    {
        vardas = vard;
        pavarde = pavard;
    }

     /**
     * @brief Default constructor that sets the name to empty string.
     */
    Zmogus()
    {
        vardas = "";
        pavarde = "";
    }

    /**
     * @brief Virtual destructor.
     */
    virtual ~Zmogus()
    {
        vardas.clear();
        pavarde.clear();
    }
    virtual std::string getVardas() const = 0;
};

class studentas : public Zmogus
{
    private:
        float galutinis_vid; //< Student's final grade (based on average calculation of homework grades, and exam grade)
    public:

        /**
         * @brief Default constructor that sets the name to empty string.
         */
        studentas() : Zmogus(), galutinis_vid(0)
        {
            // std::cout << "Default constructor called for " << this->vardas << ", "<< this->galutinis_vid << ", " << this << std::endl;
        }

        /**
         * @brief Constructor with parameters.
         * @param vard First name of the person.
         * @param pavard Last name of the person.
         */
        studentas(std::string vard, std::string pavard) : Zmogus(vard, pavard), galutinis_vid(0)
        {
            // std::cout << "VardPavard constructor called for " << this->vardas << ", "<< this->galutinis_vid << ", " << this << std::endl;
        }

        /**
         * @brief Constructor with parameters.
         * @param vard First name of the person.
         * @param pavard Last name of the person.
         * @param galutinis_vi Final grade of the student.
         */
        studentas(std::string vard, std::string pavard, float galutinis_vi) : Zmogus(vard, pavard), galutinis_vid(galutinis_vi)
        {
            // std::cout << "VardPavardGal Constructor called for " << this->vardas << ", "<< this->galutinis_vid << ", " << this << std::endl;
        }
        
        /**
         * @brief copy constructor
         * 
         * @param other Another student object to be copied.
         */
        studentas(const studentas &other) : Zmogus(other.vardas, other.pavarde), galutinis_vid(other.galutinis_vid)
        {
            // std::cout << "copy Constructor called for " << this->vardas << ", "<< this->galutinis_vid << ", " << this << std::endl;
        }

        /**
         * @brief move constructor
         * 
         * @param other Another student object to be moved.
         */
        studentas(studentas &&other) : Zmogus(std::move(other.vardas), std::move(other.pavarde)), 
        galutinis_vid(std::move(other.galutinis_vid))
        {
            // other.~studentas();
            // std::cout << "move Constructor called for " << this->vardas << ", "<< this->galutinis_vid << ", " << this << std::endl;
            other.galutinis_vid = 0;
        }
        
        /**
         * @brief Copy assignment operator.
         * @param other Another student object to be assigned.
         * @return Reference to the assigned student object.
         */
        studentas &operator=(const studentas &other)
        {
            //copy data from other to this
            // std::cout << "copy ass Constructor called for " << this->vardas << ", "<< this->galutinis_vid << ", " << this << std::endl;
            if (this != &other)
            {
                this->vardas = other.vardas;
                this->pavarde = other.pavarde;
                this->galutinis_vid = other.galutinis_vid;
            }
            return *this;
        }

        /**
         * @brief Move assignment operator.
         * @param other Another student object to be moved.
         * @return Reference to the moved student object.
         */
        studentas &operator=(studentas &&other)
        {
            // std::cout << " move ass Constructor called for " << this->vardas << ", "<< this->galutinis_vid << ", " << this << std::endl;
            if (this != &other)
            {
                this->vardas = std::move(other.vardas);
                this->pavarde = std::move(other.pavarde);
                this->galutinis_vid = std::move(other.galutinis_vid);
            }
            return *this;
        }

        /**
         * @brief Overloaded stream insertion operator for studentas class, prints student's name, surname and grade
         * @param out Output stream object.
         * @param s Student object to be outputted.
         * @return Reference to the output stream object.
         */
        friend std::ostream &operator<<(std::ostream &out, const studentas &s)
        {
            out << std::setw(15) << std::left << s.vardas << std::setw(20) << std::left << s.pavarde << std::setw(18) << std::left
            << std::setprecision(3) << s.galutinis_vid << std::endl;
            return out;
        }

        /**
         * @brief Destructor.
         */
        ~studentas()
        {
            // std::cout << "destructor called for " << this->vardas << ", "<< this->galutinis_vid << ", " << this << std::endl;
            galutinis_vid = 0;
        }

        /**
         * @brief resize the first name string to the specified size
         * 
         * @param size Size of the string to resize to.
         */
        void vardasResize(int size)
        {
            vardas.resize(size, ' ');
        }

        /**
         * @brief resize the last name string to the specified size
         * 
         * @param size Size of the string to resize to.
         */
        void pavardeResize(int size)
        {
            pavarde.resize(size, ' ');
        }

        /**
         * @brief Getter of string Vardas
         * 
         * @return std::string 
         */
        std::string getVardas() const override
        {
            return vardas;
        }

        /**
         * @brief Getter of string Pavarde
         * 
         * @return std::string 
         */
        std::string getPavarde() const
        {
            return pavarde;
        }

        /**
         * @brief Getter of galutinis_vid
         * 
         * @return float 
         */
        float getGalutinis() const
        {
            return galutinis_vid;
        }

        /**
         * @brief Setter of galutinis_vid
         * 
         * @param nd_vec 
         * @param egz 
         */
        void setGalutinis(const std::vector<int>& nd_vec, int egz) 
        {
            galutinis_vid = (float)0.4 * count_vid(nd_vec) + (float)0.6 * egz;
        }

        /**
         * @brief counts the average grade of the homework grades
         * 
         * @param nd_vec homework grade vector
         * @return float 
         */
        float count_vid(const std::vector<int> &nd_vec)
        {
            float temp = 0;
            for(auto &pazymys:nd_vec)
            {
                temp += pazymys;
            }
            return temp/float(nd_vec.size());
        }
};

/**
 * @brief Timer class for measuring time.
 * 
 */
class Timer 
{
public:
    Timer() {}

    /**
     * Start the timer by recording the current time.
     */
    void start()
    {
        start_time_ = std::chrono::high_resolution_clock::now();
    }

    /**
     * Stop the timer by recording the current time.
     */
    void stop() 
    {
        end_time_ = std::chrono::high_resolution_clock::now();
    }

    /**
     * Calculate the elapsed time in seconds.
     *
     * @return The elapsed time in seconds.
     */
    double elapsed() const 
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(end_time_ - start_time_).count() / 1000000.0;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time_;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time_;
};

std::string generavimas();

float count_med(std::vector<int> &nd_vec);

float count_vid(const std::vector<int> &nd_vec);

float countGalutinis(const std::vector<int>& nd_vec, int egz); 

bool compare(const studentas& s1, const studentas& s2);

std::string generuoti(int count);

/**
 * Partition the elements in the container based on a predicate and remove the elements that satisfy the predicate.
 *
 * @param studentai The container of studentas objects.
 * @return A new container with the removed elements.
 */
template <typename T>
T skaidymas(T &studentai)
{
    auto it = std::stable_partition(studentai.begin(), studentai.end(), [](const auto &s)
                                    { return s.getGalutinis() >= 5; });
    T temp(it, studentai.end());
    // studentai.resize(studentai.getSize() - temp.getSize()); // using myVector
    studentai.resize(studentai.size() - temp.size()); // using std::vector
    studentai.shrink_to_fit();

    return temp;
}

/**
 * Read student data from a file and populate the container.
 *
 * @param studentai The container of studentas objects.
 * @param failo_pavadinimas The name of the input file.
 */
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
    float galutinis = 0;
    while(in_file >> temp_vardas >> temp_pavarde)
    {
        // studentas stud(temp_vardas, temp_pavarde);
        for(int i = 0; i < nd_count; i++)
        {
            in_file >> temp_nd;
            nd_vec.push_back(temp_nd);
            temp_nd = 0;
        }
        in_file >> egz;

        // stud.galutinis_med = 0.4 * count_med(nd_vec) + 0.6 * stud.egz;
        galutinis = countGalutinis(nd_vec, egz);

        studentai.emplace_back(temp_vardas, temp_pavarde, galutinis);
        nd_vec.clear();
    }
    studentai.shrink_to_fit();
};

/**
 * Write student data to a file.
 * @param studentai The container of studentas objects.
 * @param failo_pav The name of the output file.
 */
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
