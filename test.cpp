#include "funkcijos.h"
#include <vector>

int main() {
    std::vector<int> nd_vec{10, 9, 8};
    studentas s1("Jonas", "Jonaitis");
    s1.setGalutinis(nd_vec, 7);

    // Copy constructor
    studentas s2(s1);
    std::cout << "s2.getVardas() = " << s2.getVardas() << std::endl; // should print "Jonas"
    std::cout << "s2.getGalutinis() = " << s2.getGalutinis() << std::endl; // should print the same value as s1

    // Copy assignment operator
    studentas s3("Rokas", "Burokas");
    s3.setGalutinis(nd_vec, 8);
    s3 = s2;
    std::cout << "s3.getVardas() = " << s3.getVardas() << std::endl; // should print "Jonas"
    std::cout << "s3.getGalutinis() = " << s3.getGalutinis() << std::endl; // should print the same value as s2

    // Move constructor
    studentas s4(std::move(s3));
    std::cout << "s4.getVardas() = " << s4.getVardas() << std::endl; // should print "Jonas"
    std::cout << "s4.getGalutinis() = " << s4.getGalutinis() << std::endl; // should print the same value as s2

    // Move assignment operator
    studentas s5("Varnas", "Varnaitis");
    s5.setGalutinis(nd_vec, 9);
    s5 = std::move(s4);
    std::cout << "s5.getVardas() = " << s5.getVardas() << std::endl; // should print "Jonas"
    std::cout << "s5.getGalutinis() = " << s5.getGalutinis() << std::endl; // should print the same value as s2

    // Destructor
    // no need to test explicitly, as it should be called automatically when each object goes out of scope

    studentas s6("Arturas", "Arturaitis");
    std::cout << s6;

    return 0;
}
