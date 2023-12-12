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
Ara de la base de dos caixes que baixen fem les següents arreglos.

#### Contador en _Component_ per a automatitzar els returns
* no val posar una variable global en un `.hpp` per que s'incluirà en molts llocs i donará problemes de compilació (per que estarà repetida)
* **solució** creem un `.cpp` on li posem eixa variable i en main usem `extern` en primera instància, encara que segons el cas usarem `static` és millor
    - _Volem vore quan ocupa RenderComponent_. Mostrar **memoria** amb les funcions `sizeof` i `alineof`
        - apareix en la memoria un puntero (_28 7D C6..._) que apunta on estan les funcions que hem de quidrar quan quidrem a una virtual (direccions de memòria modificables).
        - per aixó em de tindre en compte el que ocupen les dades per a que no apareguen coses rares.
#### Fer addComponent, getComponent, hasComponent
Aniran en `entity.hpp`. Hem de tindre en compte que render va a la seua bola (s'actualitza diferent a la resta de components).
* addComponent: `void addComponent(nosequeComponent& cmp) { noseque = &cmp; }` 
* getComponent: `nsComponent* [...] getComponent(nsComponent) [...] noexcept { ... }`
_tag dispatching_
* hasComponent: no es necessari si fas el getComponent i en el main ho poses de certa manera
#### Debuggejar
Per defecte tenim el gdb. Executar en la terminal (revisar com). Posar un breakpoint i tal

#### Componente de vida
Nuestras entidades deben ser "matables". Atributo de vida. Flag muerte.
Necessitem que el `entity.hpp`modificarlo per a poder fer en el main un LifeComponent`
