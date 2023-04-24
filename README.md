# v0.5

v0.5 atnaujinimai:
Dabar programa leidžia pasirinkti konteinerį, su kuriuo bus atliekami veiksmai - vector, list arba deque.
Naudoju šablonines funkcijas, kurios veikia su bet kokiu naudojamu konteineriu.






Naudojant list:
|**LIST**   | 1k  |10k   |100k   |1M   |10M   |
|---|---|---|---|---|---|
|**Nuskaitymas**   |_0.002255_   |_0.020398_   |_0.204996_   |_1.76657_   |_19.2724_   |
|**Rūšiavimas**   |_0.000178_   |_0.001654_   |_0.019641_   |_0.180727_   |_1.84553_   |
|**Vargsai išvedimas**   |_0.020804_   |_0.004767_   |_0.043911_   |_0.450671_   |_4.40405_   |
|**Malaciai išvedimas**   |_0.033024_   |_0.006826_   |_0.063624_   |_0.627831_   |_6.41769_   |
|**Viso**   |_0.03805_   |_0.037109_   |_0.33603_   |_3.03121_   |_31.981_   |
|**Generavimas**   |_0.001879_   |_0.020029_   |_0.17398_   |_1.72649_   |_12.9375_   |





# v0.4

v0.4 atnaujinimai:
programa veikia zymiai sparciau nei v0.3, studentu vektoriu isrusiuoju naudodamas du naujus vektorius - malaciai ir vargsai.
Visos programos laikas matuojamas atskirai nuo failo generavimo laiko.
Mano kompiuterio specifikacijos : 16gb RAM, CPU - AMD Ryzen 5 4600H, GPU - Nvidia Geforce GTX 1650 TI

Programos veikimo principas:

Programa paklausia vartotojo, ar generuoti studentų failą, ar atlikti veiksmus su jau esamu failu.
Jei pasirenkama generuoti failą, vartotojo klausiama, kiek studentų bus faile.
Atliekami veiksmai su pasirinktu failu:
1) Nuskaitomi duomenys, suskaičiuojami studentų galutiniai pažymiai
2) Studentai išrūšiuojami į du naujus vektorius: malaciai, jei galutinis pažymis >=5, vargsai, jei pažymys <5
3) Suformatuojami duomenys iš vargsai vektoriaus, rezultatas išvedamas į "vargsai.txt"
4) Suformatuojami duomenys iš malaciai vektoriaus, rezultatas išvedamas į "malaciai.txt"




|   | 1k  |10k   |100k   |1M   |10M   |
|---|---|---|---|---|---|
|**Nuskaitymas**   |_0.004411_   |_0.034408_   |_0.290819_   |_2.891_   |_20.6048_   |
|**Rūšiavimas**   |_0.000471_   |_0.005166_   |_0.037893_   |_0.233474_   |_1.62612_   |
|**Vargsai išvedimas**   |_0.026193_   |_0.054142_   |_0.074769_   |_0.718508_   |_4.06602_   |
|**Malaciai išvedimas**   |_0.002301_   |_0.073061_   |_0.104735_   |_1.04496_   |_6.24776_   |
|**Viso**   |_0.03805_   |_0.171577_   |_0.51298_   |_4.89566_   |_32.5722_   |
|**Generavimas**   |_0.001879_   |_0.020029_   |_0.17398_   |_1.72649_   |_12.9375_   |
