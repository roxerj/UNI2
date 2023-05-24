#include "funkcijos.h"
#include "vector.h"
#include <vector>

int main() {
    std::vector<int> stdVec;
    myVector<int> myVec;
    myVector<studentas> studentVec;
    
    Timer stdVecTimer;
    stdVecTimer.start();
    int stdVecCount = 0;
    for (int i = 0; i < 10000000; i++) {
        
        stdVec.push_back(i);
        if(stdVec.capacity() == stdVec.size())
        {
            stdVecCount++;
        }
    }
    stdVecTimer.stop();

    Timer myVecTimer;
    myVecTimer.start();
    for (int i = 0; i < 10000000; i++) {
        
        myVec.push_back(i);
    }
    myVecTimer.stop();

    Timer studentVecTimer;
    studentVecTimer.start();
    for(int i = 0; i < 10000000; i++)
    {
        studentVec.push_back(studentas("vardas", "i"));
    }
    studentVecTimer.stop();
    std::vector<studentas> stdStud;
    Timer studentai;
    studentai.start();
    for(int i = 0; i < 10000000; i++)
    {
        stdStud.push_back(studentas("vardas", "i"));
    }
    studentai.stop();
    
    std::cout << "STDstudentVec uztruko " << studentai.elapsed() << " sec" << std::endl;
    std::cout << "studentVec uztruko " << studentVecTimer.elapsed() << " sec" << std::endl;
    std::cout << "std::vector uztruko " << stdVecTimer.elapsed() << " sec, pertvarkymu: " << stdVecCount << std::endl; 
    std::cout << "myVector uztruko " << myVecTimer.elapsed() << " sec, pertvarkymu: " << myVec.myVecCount << std::endl;

    //testing 5 myVector functions against std::vector
    stdVec.clear();
    myVec.clear();
    stdVec.emplace_back(1);
    myVec.emplace_back(1);
    for(int i = 0; i < stdVec.size(); i++)
    {
        std::cout << stdVec[i] << " ";
    }
    std::cout << std::endl;

    myVec.print();

    stdVec.resize(10);
    myVec.resize(10);

    for(int i = 0; i < stdVec.size(); i++)
    {
        std::cout << stdVec[i] << " ";
    }
    std::cout << std::endl;
    
    myVec.print();


    

    
   

    return 0;
}
