;; Física
.include "cpctelera.h.s"
.include "globales.h.s"
screen_width = 80
screen_height = 200

;fis_init::
;    ret

fis_update::
    ld  b, #screen_height   ;;Alto

    ld a, e_y(ix)
    inc a
    ld e_y(ix), a
    cp b
    jr  nc, invalid_y       ;;no carry, posició > permesa

;_update_loop:
;    ;;update Y
;    ld  a, #screen_height - #6     ;;si el width de les estrelles fora +1, fariem altra cosa
;    ld  c, a
;
;    ld  a, e_y(ix)          ;;A: Entity.y
;    inc a                  ;;sumem y + 1 = nova posició
;    cp  c                   ;;comprovem
;    jr  nc, invalid_y       ;;no carry, posició > permesa
;valid_y:
;    ld  e_y(ix), a          ;;nova x
;    jr  endif_y
invalid_y:
;    ;; mueres
    ;;ld e_y(ix), #200
    ret 
;endif_y:
;    dec b                   ;;entitat--
;    ret z                   ;;si es 0 acabe
;
;    ;ld  de, #sizeof_e
;    ;add ix, de              ;;passem al següent
;    jr  _update_loop