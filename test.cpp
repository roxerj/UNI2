#include "funkcijos.h"
#include <vector>

int main() {
    std::vector<int> nd_vec{10, 9, 8};
    studentas s1("Jonas", "Jonaitis");
    s1.setGalutinis(nd_vec, 7);

    studentas s2(std::move(s1));
    std::cout << "s1 vardas: " << s1.getVardas() << ", s1 galutinis: " << s1.getGalutinis() << std::endl;
    std::cout << "s2 vardas: " << s2.getVardas() << ", s2 galutinis: " << s2.getGalutinis() << std::endl;
    s2.setGalutinis(nd_vec, 0);
    std::cout << "s1: " << s1.getGalutinis() << ", s2: " << s2.getGalutinis() << std::endl;
    std::cout << &s1 << ", " << &s2 << std::endl;
    // Copy constructor
    // studentas s2(s1);
    // std::cout << "s2.getVardas() = " << s2.getVardas() << std::endl; // should print "Jonas"
    // std::cout << "s2.getGalutinis() = " << s2.getGalutinis() << std::endl; // should print the same value as s1

    // // Copy assignment operator
    // studentas s3("Rokas", "Burokas");
    // s3.setGalutinis(nd_vec, 8);
    // s3 = s2;
    // std::cout << "s3.getVardas() = " << s3.getVardas() << std::endl; // should print "Jonas"
    // std::cout << "s3.getGalutinis() = " << s3.getGalutinis() << std::endl; // should print the same value as s2

    // // Move constructor
    // studentas s4(std::move(s3));
    // std::cout << "s4.getVardas() = " << s4.getVardas() << std::endl; // should print "Jonas"
    // std::cout << "s4.getGalutinis() = " << s4.getGalutinis() << std::endl; // should print the same value as s2
    // std::cout << "s3.getVardas() = " << s3.getVardas() << std::endl; // should print ""
    // std::cout << "s3.getGalutinis() = " << s3.getGalutinis() << std::endl; // should print 0

    // // Move assignment operator
    // studentas s5("Varnas", "Varnaitis");
    // s5.setGalutinis(nd_vec, 9);
    // s5 = std::move(s4);
    // std::cout << "s5.getVardas() = " << s5.getVardas() << std::endl; // should print "Jonas"
    // std::cout << "s5.getGalutinis() = " << s5.getGalutinis() << std::endl; // should print the same value as s2

    // // Destructor
    // no need to test explicitly, as it should be called automatically when each object goes out of scope

    // studentas s6("Arturas", "Arturaitis");
    // std::cout << s6;

    return 0;
}
