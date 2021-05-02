###### 2.1
  Sukurta programa kuri skaito iš įvestų duomenų CLI ir rušiuoja studentus pagal mediana arba vidurkį pasirinktinai. 
###### 2.2 
  Modifikuota 2.1 versija ir pridėtas pasirinkimas skaityti duomenis iš paruoštų duomenų.
###### 2.3
  įdėti keli try catch metodai skirti išvesti patikrinti ar failas iš kurio norima skaityti egzistuoja
###### 2.4
  nuskaityti duomenys yra rušiuojami į 2 failus pagal studentų vidurkį ir matuojamas jų laikas.
###### 2.5 
yra skirta patikrinti duomenu išsaugojimo spartumo būdus naudojant vector, list bei deque. Vectorius buvo greičiausias.

List laikai:
1000 failo skaitymas užtruko: 0.0062024 sekundžių    
1000 studentų rušiavimas užtruko: 0.0004345 sekundžių

10000 failo skaitymas užtruko: 0.0543333 sekundžių    
10000 studentų rušiavimas užtruko: 0.0060865 sekundžių

100000 failo skaitymas užtruko: 0.546861 sekundžių
100000 studentų rušiavimas užtruko: 0.0749402 sekundžių

1000000 failo skaitymas užtruko: 5.29329 sekundžių
1000000 studentų rušiavimas užtruko: 1.00853 sekundžių

10000000 failo skaitymas užtruko: 54.4872 sekundžių
10000000 studentų rušiavimas užtruko: 15.1819 sekundžių

Deque laikai: 
1000 failo skaitymas užtruko: 0.006104 sekundžių     
1000 studentų rušiavimas užtruko: 0.0004461 sekundžių

10000 failo skaitymas užtruko: 0.0534222 sekundžių    
10000 studentų rušiavimas užtruko: 0.0058478 sekundžių

100000 failo skaitymas užtruko: 0.530247 sekundžių
100000 studentų rušiavimas užtruko: 0.0704389 sekundžių

1000000 failo skaitymas užtruko: 5.3066 sekundžių
1000000 studentų rušiavimas užtruko: 0.889723 sekundžių

10000000 failo skaitymas užtruko: 53.2172 sekundžių
10000000 studentų rušiavimas užtruko: 10.9039 sekundžių

Vector laikai: 
1000 failo skaitymas užtruko: 0.006228 sekundžių
1000 studentų rušiavimas užtruko: 0.0003433 sekundžių

10000 failo skaitymas užtruko: 0.0541851 sekundžių
10000 studentų rušiavimas užtruko: 0.0039269 sekundžių

100000 failo skaitymas užtruko: 0.539999 sekundžių
100000 studentų rušiavimas užtruko: 0.0520185 sekundžių

1000000 failo skaitymas užtruko: 5.29033 sekundžių
1000000 studentų rušiavimas užtruko: 0.634036 sekundžių

10000000 failo skaitymas užtruko: 52.7618 sekundžių
10000000 studentų rušiavimas užtruko: 7.79611 sekundžių
###### 2.6
  buvo implemetuoti optimizuoti metodai visiem trim kontenriam, vietoj dalyjimo į 2 skirtingus vargšų ir kietų konteinerius buvo ištrinami duomenys iš orginalaus konteinerio ir ištrinti duomenys perkelti į naują konteinerį. Taip pat buvo naudojami visokie optimizavimo algoritmai, taičiau deque nepavyko padaryti greitesnio negu orginalaus skirstymo į 2 konteinerius būdo. Gauti rezultatai:
  
=============Vector=============

100 Neoptimizuotas: 0.000028s Optimizuotas: 0.000006s 

1000 Neoptimizuotas: 0.000332s Optimizuotas: 0.000062s 

10000 Neoptimizuotas: 0.001827s Optimizuotas: 0.000502s 

100000 Neoptimizuotas: 0.019267s Optimizuotas: 0.005002s 

1000000 Neoptimizuotas: 0.184124s Optimizuotas: 0.050846s 

=============List=============

100 Neoptimizuotas: 0.000025s 100 Optimizuotas: 0.000034s

1000 Neoptimizuotas: 0.000230s 1000 Optimizuotas: 0.000329s

10000 Neoptimizuotas: 0.002501s 10000 Optimizuotas: 0.001833s

100000 Neoptimizuotas: 0.024582s 100000 Optimizuotas: 0.018813s

1000000 Neoptimizuotas: 0.251622s 1000000 Optimizuotas: 0.179687s

=============Deque=============

100 Neoptimizuotas: 0.000014s Optimizuotas: 0.000023s

1000 Neoptimizuotas: 0.000207s Optimizuotas: 0.000129s

10000 Neoptimizuotas: 0.001291s Optimizuotas: 0.001532s

100000 Neoptimizuotas: 0.017840s Optimizuotas: 0.017593s

1000000 Neoptimizuotas: 0.134575s Optimizuotas: 0.154991s
