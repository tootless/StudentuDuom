
# StudentuDuom - studentu duomenu apdorojimo aplikacija

# Testavimas - v0.2

Tyrimas buvo atliktas su Visual Studio 2022 /O2 optimizacijos nustatymais.  
Tyrimo 1 failai buvo istrinti pries kiekviena bandyma.  
Testavimo metu testavimo sistemoje nebuvo ijungtos jokios kitos programos.

## Tyrimas 1

### 1. Anksciau sugeneruotu failu nuskaitymas:

|    |  1000  | 100000 | 1000000 |
|:--:|:------:|:-----:|:------:|
| 1. | 0.0478s | 0.619s |  2.965s |
| 2. | 0.0489s | 0.616s |  2.894s |
| 3. | 0.0478s | 0.647s | 2.983s |
| 4. | 0.0479s | 0.593s |  2.979s |
| 5. | 0.0498s | 0.640s |  2.966s|
| Vid. | 0.04844s | 0.623s |  2.9574s |

# Testavimas - v0.4

Tyrimai buvo atlikti su Visual Studio 2022 /O2 optimizacijos nustatymais.  
Tyrimo 1 ir tyrimo 2 failai buvo istrinti pries kiekviena bandyma, isskyrus tyrimo 2 failus, su kuriais buvo testuojamas skaitymo greitis (Tyrimas 2.1).  
Testavimo metu testavimo sistemoje nebuvo ijungtos jokios kitos programos.

## Tyrimas 1

### 1. Failu generavimas ir uzdarymas:

|    |  1000  | 10000 | 100000 | 1000000 | 10000000 |
|:--:|:------:|:-----:|:------:|:-------:|:--------:|
| 1. | 0.003s | 0.03s |  0.31s |  3.29s  |   31.4s  |
| 2. | 0.004s | 0.03s |  0.34s |  3.36s  |  31.9s  |
| 3. | 0.004s | 0.03s |  0.34s |   3.3s  |  31.5s  |
| 4. | 0.003s | 0.04s |  0.35s |  3.32s  |   31.7s  |
| Vid. | 0.0035s | 0.0325s |  0.335s |  3.318s  |   31.625s  |

### Tyrimo 1 output ekrane:

!["test1_1.png"](/Assets/test1_1.png)  
---
Kitas nuotraukas galima rasti repozitorijos assets aplanke (v0.4/Assets/...).

## Tyrimas 2

### 1. Duomenu nuskaitymas is anksciau sugeneruotu failu:

|    |  1000  | 10000 | 100000 | 1000000 | 10000000 |
|:--:|:------:|:-----:|:------:|:-------:|:--------:|
| 1. | 0.005s | 0.04s |  0.46s |  4.62s  |   47.37s  |
| 2. | 0.007s | 0.04s |  0.47s |  4.78s  |   47.66s  |
| 3. | 0.005s | 0.05s |  0.47s |  4.75s  |   47.72s  |
| 4. | 0.006s | 0.05s |  0.47s |  4.7s  |   47.46s  |
| Vid. | 0.00575s | 0.045s |  0.4675s |  4.7125s  |   47.5525s  |

### 2. Studentu rusiavimas i "gerus" ir "blogus" pagal galutini vidurki (>= 5.0 - geras, kitaip - blogas):

|    |  1000  | 10000 | 100000 | 1000000 | 10000000 |
|:--:|:------:|:-----:|:------:|:-------:|:--------:|
| 1. | 0.0004s | 0.0015s |  0.01s |  0.11s  |   1.25s  |
| 2. | 0.0002s | 0.0013s |  0.009s |  0.11s  |   1.19s  |
| 3. | 0.0003s | 0.006s |  0.01s |  0.11s  |   1.28s  |
| 4. | 0.0003s | 0.0012s |  0.01s |  0.11s  |   1.29s  |
| Vid. | 0.003s | 0.0025s |  0.00975s |  0.11s  |  1.2525s  |

### 3. "Geru" ir "blogu" studentu atitinkamu failu generavimas:

|    |  1000  | 10000 | 100000 | 1000000 | 10000000 |
|:--:|:------:|:-----:|:------:|:-------:|:--------:|
| 1. | 0.004s | 0.03s |  0.3s |  4.03s  |   30.72s  |
| 2. | 0.005s | 0.03s |  0.31s |  3.18s  |   30.97s  |
| 3. | 0.004s | 0.03s |  0.31s |  3.14s  |   31.12s  |
| 4. | 0.004s | 0.03s |  0.32s |  3.1s  |   31.04s  |
| Vid. | 0.017s | 0.03s |  0.31s |  3.3625s  |   30.9625s  |

### 4. Visos programos laikas:

|    |  1000  | 10000 | 100000 | 1000000 | 10000000 |
|:--:|:------:|:-----:|:------:|:-------:|:--------:|
| 1. | 0.026s | 0.09s |  0.78s |  8.83s  |   79.75s  |
| 2. | 0.013s | 0.09s |  0.8s |  8.12s  |   80.25s  |
| 3. | 0.011s | 0.099s |  0.81s |  8.04s  |   80.56s  |
| 4. | 0.011s | 0.088s |  0.81s |  7.95s  |   80.2s  |
| Vid. | 0.01525s | 0.09175s |  0.8s |  8.235s  |   80.19s  |

### Tyrimo 2 output ekrane:

!["test2_1.png"](/Assets/test2_1.png)  
---
Kitas nuotraukas galima rasti repozitorijos assets aplanke (v0.4/Assets/...).


# Testavimas - v1.0 subrelease

Tyrimai buvo atlikti su Visual Studio 2022 /O2 optimizacijos nustatymais.  
Tyrimo 1 ir tyrimo 2 failai buvo istrinti pries kiekviena bandyma, isskyrus tyrimo 2 failus, su kuriais buvo testuojamas skaitymo greitis (Tyrimas 2.1).  
Testavimo metu testavimo sistemoje nebuvo ijungtos jokios kitos programos.

## Tyrimas 1 - Aprasas

Atliktas tyrimas su trejais skirtingais STL konteineriais (Vektoriai, Sarasai (list) ir Deque).
Siame tyrime buvo ismatuoti minetu konteineriu 

Rezultatai pateikiami sekundemis suapvalinti iki simtuju (neitakoja programos vykdymo laiko).  


## Aktualus testavimo sistemos parametrai:

**CPU**:

**RAM**:

**SSD**: 

## Tyrimas 1 - Rezultatai

