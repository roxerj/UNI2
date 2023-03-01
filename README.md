# UNI
su 1,000,000 studentu is failo:
Outputo formatavimas uztruko 5.9888 sec.
Outputo isvedimas i faila uztruko 0.301486 sec.
Duomenu nuskaitymas ir galutiniu pazymiu skaiciavimas uztruko 14.3994 sec.

v0.2 versijoje papildymai: is failo nuskaito, kiek yra namu darbu pazymiu. Taip pat naudoju chrono biblioteka, kad ismatuociau, kiek laiko uztrunka tam tikros kodo dalys. Su 1,000,000 studentu is studentai1000000.txt failo kodas ivykdomas per ~20 sekundziu.

v0.3 atnaujinimai: 
Duomenu nuskaitymas ir galutiniu pazymiu skaiciavimas uztruko 2.9925 sec.
Studentu rusiavimas pagal varda/pavarde uztruko 1.04931 sec.
Outputo formatavimas uztruko 1.35488 sec.
Outputo isvedimas i faila uztruko 0.355263 sec.

Taigi v0.3 veikia zymiai sparciau, taip pat programos pradzioje, jei ivedamas neteisingas ar neegzistuojancio failo pavadinimas, veikia try-catch block, kuris leidzia bandyti ivesti failo pavadinima tol, kol failas sekmingai atsidaro.

