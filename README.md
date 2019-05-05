# OOP trečia užduotis
VU ISI OOP 3 užduotis. Reikalavimus galite rasti [čia](https://github.com/objprog/paskaitos2019/wiki/3-oji-u%C5%BEduotis).

##### Programos paleidimas:
* `git clone https://github.com/AgneG25/OOP_antra_uzduotis.git`

* `make`

* `./main`


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

| Kiekis        | Trukmė (s/n) |        
| ------------- |-------------:|
| 10            | 0.000458382  |
| 100           | 0.00274016   |
| 1000          | 0.00913537   |
| 10000         | 0.0201894    |
| 100000        | 0.186875     |
| Visa programa | 0.5089       |

---
###### STD::LIST

| Kiekis        | Trukmė (s/n) |        
| ------------- |-------------:|
| 10            | 0.000730686  |
| 100           | 0.00124828   |
| 1000          | 0.0124355    |
| 10000         | 0.0286396    |
| 100000        | 0.238687     |
| Visa programa | 0.548188     |

---
###### STD::DEQUE

| Kiekis        | Trukmė (s/n) |        
| ------------- |-------------:|
| 10            | 0.000673002  |
| 100           | 0.000816094  |
| 1000          | 0.00447744   |
| 10000         | 0.0317397    |
| 100000        | 0.267393     |
| Visa programa | 0.56778      |

---
## [v1.0](https://github.com/AgneG25/OOP_antra_uzduotis/releases/tag/v1.0)(2019-03-24)
##### 1 scenarijus
Duomenys iš bendro Studentų konteinerio išskaidomi į du: Strong ir Weak.

###### STD::VECTOR

| Kiekis        | Rūšiavimas (s/n) | Spausdinimas (s/n) |        
| ------------- |:----------------:|-------------:|
| 10            | 0.0000243400 | 0.0005911700  |
| 100           | 0.0001747690  | 0.0012181070  |
| 1000          | 0.0018891290  | 0.0091860260   |
| 10000         | 0.0065936000   |0.0241980220    |
| 100000        | 0.0517505590 | 0.2338830680  |

```
Visos programos veikimas uztruko: 0.5563735260 s/n
```
###### STD::LIST

| Kiekis        | Rūšiavimas (s/n) | Spausdinimas (s/n) |        
| ------------- |:----------------:|-------------:|
| 10            | 0.0000159940 | 0.0005599050  |
| 100           | 0.0001457720  | 0.0004429700  |
| 1000          | 0.0005196130  | 0.0033575030   |
| 10000         | 0.0049818810   |0.0270387750    |
| 100000        | 0.0370642370 | 0.2280732290  |

```
Visos programos veikimas uztruko: 0.4932038040 s/n
```
###### STD::DEQUE

| Kiekis        | Rūšiavimas (s/n) | Spausdinimas (s/n) |        
| ------------- |:----------------:|-------------:|
| 10            | 0.0000154860 | 0.0005208370  |
| 100           | 0.0001381620  | 0.0011169290  |
| 1000          | 0.0016535360  | 0.0104824100   |
| 10000         | 0.0039641510   |0.0210640090    |
| 100000        | 0.0299174970 | 0.2005428870  |

```
Visos programos veikimas uztruko: 0.4539827490 s/n
```
##### 2 scenarijus
Tikrinami vidurkiai ir pagal juos sukuriamas naujas konteineris - Weak. Studentai, kurių vidurkiai mažesni nei 5, ištrinami iš bendro Studentų konteinerio.

###### STD::VECTOR

| Kiekis        | Rūšiavimas (s/n) | Spausdinimas (s/n) |        
| ------------- |:----------------:|-------------:|
| 10            | 0.0000099650 | 0.0001944810  |
| 100           | 0.0005331840  | 0.0003901860  |
| 1000          | 0.0353722400  | 0.0027051590   |
| 10000         | 3.0878440760   |0.0203226890    |
| 100000        | 307.6575085890 | 0.2071213460  |
```
Visos programos veikimas uztruko: 311.1773747950 s/n
```
###### STD::LIST
| Kiekis        | Rūšiavimas (s/n) | Spausdinimas (s/n) |        
| ------------- |:----------------:|-------------:|
| 10            | 0.0000093820 | 0.0005290310  |
| 100           | 0.0000872540  | 0.0008157820  |
| 1000          | 0.0002282080  | 0.0024728660   |
| 10000         | 0.0022942860   |0.0236559080    |
| 100000        |0.0196709560 | 0.1979247210  |
```
Visos programos veikimas uztruko: 0.4074659810 s/n
```
###### STD::DEQUE
| Kiekis        | Rūšiavimas (s/n) | Spausdinimas (s/n) |        
| ------------- |:----------------:|-------------:|
| 10            | 0.0000333990 | 0.0006278310  |
| 100           | 0.0009192610  | 0.0012885280  |
| 1000          | 0.0221422810  | 0.0029115740   |
| 10000         | 1.5468713770   |0.0237437000   |

Šioje versijoje panaudotas std::stable_partitionion algoritmas.
Programos greitis, naudojant šį algoritmą:

###### STD::VECTOR
| Kiekis        | Rūšiavimas (s/n) | Spausdinimas (s/n) |        
| ------------- |:----------------:|-------------:|
| 10            | 0.0000236620 | 0.0006508120  |
| 100           | 0.0002176750  | 0.0006770840  |
| 1000          | 0.0005846560  | 0.0031081930   |
| 10000         | 0.0058959810   |0.0300132480 |
| 100000        |0.0495097510 |  0.2557404340  |
```
Visos programos veikimas uztruko: 0.4582516000 s/n
```
Galime pastebėti, kad programa veikia žymiai greičiau, kai naudojama std:stable_partition.

## [v1.1](https://github.com/AgneG25/OOP_3/releases/tag/v1.1) (2019-04-20)

Programa pakoreguota, pritaikyta veikimui su `class'ėmis'.

| Kiekis        | Rūšiavimas (struct) | Spausdinimas (struct) | Rūšiavimas (class) | Spausdinimas (class) |    
| ------------- |:-------------------:|----------------------:|:-------------------:|----------------------:|
| 10000         | 0.007223147 | 0.030013248  | 0.007200259      | 0.028663370  |
| 100000        | 0.051575420    | 0.248939708  | 0.054419516      | 0.230109362  |

#### Optimizavimo flagų palyginimas:

| Kiekis   | Rūšiavimas (01) | Spausdinimas (01) | Rūšiavimas (02) | Spausdinimas (02) |  Rūšiavimas (03) | Spausdinimas (03) |  
| ------------- |:----------------:|------------------:|:---------------:|-----------:|:--------:|----------------:|
| 10000         | 0.001408578 | 0.027924160 | 0.001434875 | 0.024429360 | 0.001330962  | 0.024039443  |
| 100000        | 0.012667513  | 0.210542530 | 0.013069701  | 0.211190634  | 0.012780925  | 0.215842405  |

## [v1.2](https://github.com/AgneG25/OOP_3/releases/tag/v1.2) (2019-04-28)

* Realizuoti 8 skirtingi operatoriai, bet ne visi iš jų pritaikyti programoje.

## [v1.5](https://github.com/AgneG25/OOP_3/releases/tag/v1.5) (2019-05-05)

* Sukurtos dvi klasės: bazine `Person` ir išvestine `stud`.
