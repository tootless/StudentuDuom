
# StudentuDuom - studentu duomenu apdorojimo aplikacija

## Aprasas

StudentuDuom 

# Testavimas

Testai buvo atlikti su Visual Studio 2022 C++17 -O3 optimizacijos nustatymais.  

## Tyrimas 1

### 1. Failu generavimas ir uzdarymas:

| Nr.   |  Studentu skaicius |
|    |  1000  | 10000 | 100000 | 1000000 | 10000000 |
|:--:|:------:|:-----:|:------:|:-------:|:--------:|
| 1. | 0.003s | 0.03s |  0.31s |  3.29s  |   31.4s  |
| 2. | 0.004s | 0.03s |  0.34s |  3.36s  |  31.9s  |
| 3. | 0.004s | 0.03s |  0.34s |   3.3s  |  31.5s  |
| 4. | 0.003s | 0.04s |  0.35s |  3.32s  |   31.7s  |
| Vid. | 0.0035s | 0.0325s |  0.335s |  3.318s  |   31.625s  |

## Tyrimas 2

### 1. Duomenu nuskaitymas is anksciau sugeneruotu failu:



### 2. Studentu rusiavimas i "gerus" ir "blogus" pagal galutini vidurki (>= 5.0 - geras, kitaip - blogas):



### 3. "Geru" ir "blogu" studentu atitinkamu failu generavimas:



### 4. Visos programos laikas

