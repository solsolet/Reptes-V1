# Reptes-V1

## Amstrad

## C++
### Reto1C++

### Reto2C++
Separar main en fitxers rendercomponent y physiccomponent.
Mai posar un include on no siga necessari.
#### Make
Fem per a que compile els nous arxius, fem la macro OBJ, aprenem _$@_ (el target), _$^_(el qe posa al costat de :), _$<_ ()
Requisitos de orden solo
posar el | obj

### Reto3C++
Ara de la base de dos caixes que baixen fem les següents arreglos:
* **contador en _Component_** per a automatitzar els returns
    - no val posar una variable global en un _.hpp_ per que s'incluirà en molts llocs i donará problemes de compilació (per que estarà repetida)
    - **solució** creem un _.cpp_ on li posem eixa variable i en main usem `extern` en primera instància, encara que segons el cas usarem `static` és millor
* **següent**
