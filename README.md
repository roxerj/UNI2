Naudojimo instrukcija: parsisiuntus failus įveskite "make" į komandinę eilutę, tada paleiskite exe failą. Sekite instrukcijas konsolėje

# v1.1

v1.1 atnaujinimai: ankstesnėse versijose naudojau struct studentas, dabar naudoju class studentas. Programa veikia truputį sparčiau, bet nežymiai.

Naudojant vector:
|   | 100k  |1M   |10M   |
|---|---|---|---|
|**struct**   |_0.002255_   |_0.020398_   |_0.204996_   |
|**class**   |_0.000178_   |_0.001654_   |_0.019641_   |

Optimizavimo flag'ų testavimas (10M):
|   | laikas(s)  |exe failo užimama vieta   |
|---|---|---|
|**-**   |_29.8815_   |_1059KB_   |
|**-O1**   |_26.2167_   |_1302KB_   |
|**-O2**   |_25.8021_   |_1343KB_   |
|**-O3**   |_25.3347_   |_1457KB_   |



# v1.0 

v1.0 atnaujinimai:
Skaidydamas studentai konteinerį į malaciai ir vargsai praeitose versijose sukurdavau du naujus konteinerius malaciai ir vargsai, kopijuodamas studento objektą į vieną arba kitą konteinerį, tokia programos realizacija yra neefektyvi atminties atžvilgiu.
v1.0 versijoje studentai konteinerį skaidau naudodamas tik vieną naują konteinerį vargsai, perkeldamas studento objektą iš studentai į vargsai, tad konteineryje studentai lieka "malaciai".
Sukurtas makefile, parašius komandinę eilutę "make", programa yra sukompiliuojama ir paruošiamas exe failas.

Mano kompiuterio specifikacijos : 16gb RAM, CPU - AMD Ryzen 5 4600H, GPU - Nvidia Geforce GTX 1650 TI

Programos veikimo principas:

Programa paklausia vartotojo, ar generuoti studentų failą, ar atlikti veiksmus su jau esamu failu.
Jei pasirenkama generuoti failą, vartotojo klausiama, kiek studentų bus faile.
Prieš atliekant veiksmus su failu, vartotojo klausiama, kurį konteinerį naudoti veiksmams su failu. (Vector, list, deque)
Atliekami veiksmai su pasirinktu failu:
1) Nuskaitomi duomenys, suskaičiuojami studentų galutiniai pažymiai
2) Studentai išskaidomi į "malacius" ir "vargsus" naudojant studentai ir vargsai konteinerius: studentai konteineryje lieka studentai, kurių gal. pažymys >=5, o vargsai konteineryje atsiranda studentai, kurių gal. pažymys <5, jie ištrinami iš studentai konteinerio.
3) Suformatuojami duomenys iš vargsai konteinerio, rezultatas išvedamas į "vargsai.txt"
4) Suformatuojami duomenys iš studentai konteinerio, rezultatas išvedamas į "malaciai.txt"

Matome, kad atnaujintoje programos versijoje programa atlieka darbą truputį sparčiau, bet nedaug. Su 10m studentų programa veikia gal 5sec trumpiau nei praeitoje versijoje.

Naudojant list:
|**LIST**   | 1k  |10k   |100k   |1M   |10M   |
|---|---|---|---|---|---|
|**Nuskaitymas**   |_0.002255_   |_0.020398_   |_0.204996_   |_1.76657_   |_18.8843_   |
|**Rūšiavimas**   |_0.000178_   |_0.001654_   |_0.019641_   |_0.180727_   |_0.30544_   |
|**Vargsai išvedimas**   |_0.020804_   |_0.004767_   |_0.043911_   |_0.450671_   |_3.2987_   |
|**Malaciai išvedimas**   |_0.033024_   |_0.006826_   |_0.063624_   |_0.627831_   |_4.66719_   |
|**Viso**   |_0.03805_   |_0.037109_   |_0.33603_   |_2.73121_   |_27.981_   |


Naudojant deque:
|**DEQUE**   | 1k  |10k   |100k   |1M   |10M   |
|---|---|---|---|---|---|
|**Nuskaitymas**   |_0.002619_   |_0.019049_   |_0.201048_   |_1.94471_   |_18.5413_   |
|**Rūšiavimas**   |_0.000167_   |_0.001469_   |_0.015256_   |_0.130697_   |_0.49566_   |
|**Vargsai išvedimas**   |_0.019543_   |_0.00548_   |_0.039213_   |_0.439459_   |_2.97396_   |
|**Malaciai išvedimas**   |_0.028777_   |_0.007408_   |_0.056731_   |_0.661483_   |_4.49107_   |
|**Viso**   |_0.054019_   |_0.036882_   |_0.316761_   |_3.18256_   |_26.532_   |

# v0.5

v0.5 atnaujinimai:
Dabar programa leidžia pasirinkti konteinerį, su kuriuo bus atliekami veiksmai - vector, list arba deque.
Naudoju šablonines funkcijas, kurios veikia su bet kokiu naudojamu konteineriu.

Mano kompiuterio specifikacijos : 16gb RAM, CPU - AMD Ryzen 5 4600H, GPU - Nvidia Geforce GTX 1650 TI

Programos veikimo principas:

Programa paklausia vartotojo, ar generuoti studentų failą, ar atlikti veiksmus su jau esamu failu.
Jei pasirenkama generuoti failą, vartotojo klausiama, kiek studentų bus faile.
Prieš atliekant veiksmus su failu, vartotojo klausiama, kurį konteinerį naudoti veiksmams su failu. (Vector, list, deque)
Atliekami veiksmai su pasirinktu failu:
1) Nuskaitomi duomenys, suskaičiuojami studentų galutiniai pažymiai
2) Studentai išrūšiuojami į du naujus konteinerius: malaciai, jei galutinis pažymis >=5, vargsai, jei pažymys <5
3) Suformatuojami duomenys iš vargsai konteinerio, rezultatas išvedamas į "vargsai.txt"
4) Suformatuojami duomenys iš malaciai konteinerio, rezultatas išvedamas į "malaciai.txt"

Matome, kad naudojant list arba deque vietoj vector, programos veikimo sparta beveik nesikeičia.


Naudojant list:
|**LIST**   | 1k  |10k   |100k   |1M   |10M   |
|---|---|---|---|---|---|
|**Nuskaitymas**   |_0.002255_   |_0.020398_   |_0.204996_   |_1.76657_   |_19.2724_   |
|**Rūšiavimas**   |_0.000178_   |_0.001654_   |_0.019641_   |_0.180727_   |_1.84553_   |
|**Vargsai išvedimas**   |_0.020804_   |_0.004767_   |_0.043911_   |_0.450671_   |_4.40405_   |
|**Malaciai išvedimas**   |_0.033024_   |_0.006826_   |_0.063624_   |_0.627831_   |_6.41769_   |
|**Viso**   |_0.03805_   |_0.037109_   |_0.33603_   |_3.03121_   |_31.981_   |
|**Generavimas**   |_0.001879_   |_0.020029_   |_0.17398_   |_1.72649_   |_12.9375_   |

Naudojant deque:
|**DEQUE**   | 1k  |10k   |100k   |1M   |10M   |
|---|---|---|---|---|---|
|**Nuskaitymas**   |_0.002619_   |_0.019049_   |_0.201048_   |_1.94471_   |_19.258_   |
|**Rūšiavimas**   |_0.000167_   |_0.001469_   |_0.015256_   |_0.130697_   |_1.60812_   |
|**Vargsai išvedimas**   |_0.019543_   |_0.00548_   |_0.039213_   |_0.439459_   |_4.32674_   |
|**Malaciai išvedimas**   |_0.028777_   |_0.007408_   |_0.056731_   |_0.661483_   |_6.0704_   |
|**Viso**   |_0.054019_   |_0.036882_   |_0.316761_   |_3.18256_   |_31.2998_   |
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
