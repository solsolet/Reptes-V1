;; PHYSICS SYSTEM
;; Moves entities according to the velocity
;; Takes into accoubt the Screen Borders

.include "entity_manager.h.s"

screen_width = 80
screen_height = 200

physicssys_init::
    ret

physiscssys_update::
    ld  b, a                ;;B: number of entities
_update_loop:
    ;;update x
    ld  a, #screen_width    ;;si el width de les estrelles fora +1, fariem altra cosa
    ld  c, a

    ld  a, e_x(ix)          ;;A: Entity.x
    add e_v(ix)             ;;sumem x + vel = nova posició
    cp  c                   ;;comprovem
    jr  nc, invalid_x       ;;no carry, posició > permesa
valid_x:
    ld  e_x(ix), a          ;;nova x
    jr  endif_x
invalid_x:
    ld  e_tipo(ix), #0      ;;estrella no válida
    ;;call entityman_destroy
endif_x:
    dec b                   ;;entitat--
    ret z                   ;;si es 0 acabe

    ld  de, #sizeof_e
    add ix, de              ;;passem al següent
    jr  _update_loop