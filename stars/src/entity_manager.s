;; STAR MANAGER

.include "entity_manager.h.s"

;; DADES
max_entities == 10   ;;cte                  
_num_entities:: .db 0               ;;define byte, posa byte que li digues en la pos mem que representa _num_entities 
_last_elem_ptr:: .dw _entity_array  ;;define word, posa 2bytes que li digues ...
_entity_array::                     ;;define space, reserva nº de bytes que li ...
    .ds max_entities * sizeof_e

;; GETTERS
entityman_getArray::
    ld  ix, #_entity_array
    ld   a, (_num_entities)
    ret

entityman_init::
    ;;Reset all component values
    xor a                       ;;_entity_num = 0
    ld  (_num_entities), a

    ld  hl, #_entity_array      ;;_last_elem_ptr = &ent[0]
    ld  (_last_elem_ptr), hl

    ret

;;  INPUT
;;      HL: Pointer to entity initializer bytes
entityman_create::              ;;man = manager
    ld  de, (_last_elem_ptr)    ;;puntero on vull copiar 
    ld  bc, #sizeof_e           ;;contador
    ldir

    ld  a, (_num_entities)
    inc a
    ld  (_num_entities), a      ;;"_num_entities++"

    ld  hl, (_last_elem_ptr)
    ld  bc, #sizeof_e           ;;reestablim
    add hl, bc                  ;;preparem següent pos array
    ld  (_last_elem_ptr), hl    ;;actualitzem

    ret

entityman_generate_entity:
    ;; Generar dades estrella psudoaleatòriament
    ret

entityman_destroy:: ;;OJO no va be (arreglar que només esta implementat per a la última entitat i vore com passem el tipo 0)
    ;;passar última entitat a primera posició
    ld  hl, #_entity_array
    ld  de, (_last_elem_ptr)    ;;puntero on vull copiar 
    ld  bc, #sizeof_e           ;;contador
    ldir

    ;;última entitat inválida
    ld ix, (_last_elem_ptr)
    ld  e_tipo(ix), #0

    ;;actualitzar puntero last
    ld  hl, (_last_elem_ptr)
    ;ld  bc, #sizeof_e           ;;reestablim
    ;sub hl, bc                  ;;preparem següent pos array
    ld a, l
    sub #sizeof_e
    ld l, a
    ld  (_last_elem_ptr), hl    ;;actualitzem
    ret