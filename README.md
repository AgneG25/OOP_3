# OOP_antra_uzduotis
VU ISI OOP 2 užduotis. Reikalavimus galite rasti [čia](https://github.com/objprog/paskaitos2019/wiki/2-oji-u%C5%BEduotis).

## [V0.1](https://github.com/AgneG25/OOP_antra_uzduotis/releases/tag/v0.1) (2019-02-17)
* Pirmoji programos versija.

## [V0.2](https://github.com/AgneG25/OOP_antra_uzduotis/releases/tag/vo.2) (2019-02-19)
* Atsirado galimybė nuskaityti duomenis iš failo.
* Nuskaityti duomenys surikiuojami pagal vardą.

## [v0.3](https://github.com/AgneG25/OOP_antra_uzduotis/releases/tag/v0.3) (2019-02-24)
* Panaudotas Exception Handling (bet tik vienoje vietoje, reiks pildyti).
* Naudojami header'iai.
* Neatnaujintas makefile.

## [v0.4](https://github.com/AgneG25/OOP_antra_uzduotis/releases/tag/v0.4) (2019-03-03)
* Sugeneruojami 5 nauji duomenų failai.
* Mokiniai sugrupuojami ir išspausdinami į du skirtingus failus.
* Matuojamas laikas(tiek kievieno naujo failo sugeneravimas, nuskaitymas ir sugrupavimas, tiek bendras programos laikas).

## [v0.5](https://github.com/AgneG25/OOP_antra_uzduotis/releases/tag/v0.5) (2019-03-10)
* Pakeistas atsitiktinių skaičių generavimas.
* Mokiniai sugrupuojami į du vektorius (v0.4 versijoje studentai buvo tiesiog išspausdinami į du skirtingus failus).
* Sukurti trys aplankalai: vector, list ir deque.

##### Programos veikimo laikai, naudojant skirtingus konteinerius:

###### STD::VECTOR
`10 elementų užpildymas užtruko: 0.000458382 s/n`

`100 elementų užpildymas užtruko: 0.00274016 s/n`

`1000 elementų užpildymas užtruko: 0.00913537 s/`

`10000 elementų užpildymas užtruko: 0.0201894 s/n`

`100000 elementų užpildymas užtruko: 0.186875 s/n`

`Visos programos veikimas užtruko: 0.5089 s/n`

---
###### STD::LIST
`10 elementų užpildymas užtruko: 0.000730686 s/n`

`100 elementų užpildymas užtruko: 0.00124828 s/n`

`1000 elementų užpildymas užtruko: 0.0124355 s/n`

`10000 elementų užpildymas užtruko: 0.0286396 s/n`

`100000 elementų užpildymas užtruko: 0.238687 s/n`

`Visos programos veikimas užtruko: 0.548188 s/n`

---
###### STD::DEQUE
`10 elementu uzpildymas užtruko: 0.000673002 s/n`

`100 elementų užpildymas užtruko: 0.000816094 s/n`

`1000 elementų užpildymas užtruko: 0.00447744 s/n`

`10000 elementų užpildymas užtruko: 0.0317397 s/n`

`100000 elementų užpildymas užtruko: 0.267393 s/n`

`Visos programos veikimas užtruko: 0.56778 s/n`


---
## [v1.0]
##### 1 scenarijus
Duomenys iš bendro Studentų konteinerio išskaidomi į du: Strong ir Weak.

###### STD::VECTOR
10 elementu rusiavimas uztruko: 0.0000243400 s/n

10 elementu spausdinimas uztruko: 0.0005911700 s/n

100 elementu rusiavimas uztruko: 0.0001747690 s/n

100 elementu spausdinimas uztruko: 0.0012181070 s/n

1000 elementu rusiavimas uztruko: 0.0018891290 s/n

1000 elementu spausdinimas uztruko: 0.0091860260 s/n

10000 elementu rusiavimas uztruko: 0.0065936000 s/n

10000 elementu spausdinimas uztruko: 0.0241980220 s/n

100000 elementu rusiavimas uztruko: 0.0517505590 s/n

100000 elementu spausdinimas uztruko: 0.2338830680 s/n

Visos programos veikimas uztruko: 0.5563735260 s/n

###### STD::LIST

10 elementu rusiavimas uztruko: 0.0000159940 s/n

10 elementu spausdinimas uztruko: 0.0005599050 s/n

100 elementu rusiavimas uztruko: 0.0001457720 s/n

100 elementu spausdinimas uztruko: 0.0004429700 s/n

1000 elementu rusiavimas uztruko: 0.0005196130 s/n

1000 elementu spausdinimas uztruko: 0.0033575030 s/n

10000 elementu rusiavimas uztruko: 0.0049818810 s/n

10000 elementu spausdinimas uztruko: 0.0270387750 s/n

100000 elementu rusiavimas uztruko: 0.0370642370 s/n

100000 elementu spausdinimas uztruko: 0.2280732290 s/n

Visos programos veikimas uztruko: 0.4932038040 s/n

###### STD::DEQUE

10 elementu rusiavimas uztruko: 0.0000154860 s/n

10 elementu spausdinimas uztruko: 0.0005208370 s/n

100 elementu rusiavimas uztruko: 0.0001381620 s/n

100 elementu spausdinimas uztruko: 0.0011169290 s/n

1000 elementu rusiavimas uztruko: 0.0016535360 s/n

1000 elementu spausdinimas uztruko: 0.0104824100 s/n

10000 elementu rusiavimas uztruko: 0.0039641510 s/n

10000 elementu spausdinimas uztruko: 0.0210640090 s/n

100000 elementu rusiavimas uztruko: 0.0299174970 s/n

100000 elementu spausdinimas uztruko: 0.2005428870 s/n

Visos programos veikimas uztruko: 0.4539827490 s/n

##### 2 scenarijus
Tikrinami vidurkiai ir pagal juos sukuriamas naujas konteineris - Weak. Studentai, kurių vidurkiai mažesni nei 5, ištrinami iš bendro Studentų konteinerio.

###### STD::VECTOR

10 elementu rusiavimas uztruko: 0.0000099650 s/n

10 elementu spausdinimas uztruko: 0.0001944810 s/n

100 elementu rusiavimas uztruko: 0.0005331840 s/n

100 elementu spausdinimas uztruko: 0.0003901860 s/n

1000 elementu rusiavimas uztruko: 0.0353722400 s/n

1000 elementu spausdinimas uztruko: 0.0027051590 s/n

10000 elementu rusiavimas uztruko: 3.0878440760 s/n

10000 elementu spausdinimas uztruko: 0.0203226890 s/n

100000 elementu rusiavimas uztruko: 307.6575085890 s/n

100000 elementu spausdinimas uztruko: 0.2071213460 s/n

Visos programos veikimas uztruko: 311.1773747950 s/n

###### STD::LIST

10 elementu rusiavimas uztruko: 0.0000093820 s/n

10 elementu spausdinimas uztruko: 0.0005290310 s/n

100 elementu rusiavimas uztruko: 0.0000872540 s/n

100 elementu spausdinimas uztruko: 0.0008157820 s/n

1000 elementu rusiavimas uztruko: 0.0002282080 s/n

1000 elementu spausdinimas uztruko: 0.0024728660 s/n

10000 elementu rusiavimas uztruko: 0.0022942860 s/n

10000 elementu spausdinimas uztruko: 0.0236559080 s/n

100000 elementu rusiavimas uztruko: 0.0196709560 s/n

100000 elementu spausdinimas uztruko: 0.1979247210 s/n

Visos programos veikimas uztruko: 0.4074659810 s/n

###### STD::DEQUE

10 elementu rusiavimas uztruko: 0.0000333990 s/n

10 elementu spausdinimas uztruko: 0.0006278310 s/n

100 elementu rusiavimas uztruko: 0.0009192610 s/n

100 elementu spausdinimas uztruko: 0.0012885280 s/n

1000 elementu rusiavimas uztruko: 0.0221422810 s/n

1000 elementu spausdinimas uztruko: 0.0029115740 s/n

10000 elementu rusiavimas uztruko: 1.5468713770 s/n

10000 elementu spausdinimas uztruko: 0.0237437000 s/n

Šioje versijoje panaudotas std::stable_partitionion algoritmas.
Programos greitis, naudojant šį algoritmą:

###### STD::VECTOR

10 elementu rusiavimas uztruko: 0.0000236620 s/n

10 elementu spausdinimas uztruko: 0.0006508120 s/n

100 elementu rusiavimas uztruko: 0.0002176750 s/n

100 elementu spausdinimas uztruko: 0.0006770840 s/n

1000 elementu rusiavimas uztruko: 0.0005846560 s/n

1000 elementu spausdinimas uztruko: 0.0031081930 s/n

10000 elementu rusiavimas uztruko: 0.0058959810 s/n

10000 elementu spausdinimas uztruko: 0.0300132480 s/n

100000 elementu rusiavimas uztruko: 0.0495097510 s/n

100000 elementu spausdinimas uztruko: 0.2557404340 s/n

Visos programos veikimas uztruko: 0.4582516000 s/n

Galime pastebėti, kad programa veikia žymiai greičiau, kai naudojama std:stable_partition.
##### Programos paleidimas:
* `git clone https://github.com/AgneG25/OOP_antra_uzduotis.git`

* `make`

* `./main`
