;; Render
.include "cpctelera.h.s"
.include "globales.h.s"

;;_palette: .db HW_BLACK, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE

;;render_init::
;;    ld  c, #0                   ;;Modo 1
;;    call cpct_setVideoMode_asm
;;    ld  hl, #_palette         ;;Carga paleta
;;    ld  de, #16
;;    call cpct_setPalette_asm
;;    cpctm_setBorder_asm HW_BLACK;;posar borde blanc
;;    ret

;; INPUT:
;;      IX: Pointer to first entity to render
;;       A: Number of entities to render
render_update::
;; algo?
_update_loop:
    
    ;;--------------------OPTIMITZABLE-----------------------
    ;;Calculate a video-memory location for printing (Borrar)
    ;ld  de, #0xC000     ;;DE: pointer to star of the screen
    ;ld  a, e_x(ix)      
    ;dec e_y(ix)         ;;calculem pos - vel
    ;ld   c, a           ;;x
    ;ld   b, e_y(ix)     ;;y
    ;call cpct_getScreenPtr_asm
    ;ex de, hl
    ;xor a               ;;color = 0
    ;ld   b, #2          ;;width
    ;ld   c, #6         ;;height
    ;call cpct_drawSolidBox_asm
    

    ;;Calculate a video-memory location for printing (Pintar)
    ld  de, #0xC000     ;;DE: pointer to star of the screen
    ld   c, e_x(ix)     ;;x
    ld   b, e_y(ix)     ;;y
    call cpct_getScreenPtr_asm

    ;;Draw Entity Sprite
    ex  de, hl
    ld   a, e_c(ix) ;;color
    ld   b, #6          ;;height
    ld   c, #2          ;;width
    call cpct_drawSolidBox_asm

;_ent_counter = .+1
;    ld  a, #0
;    dec a
;    ret z
;
;    ld (_ent_counter), a    ;;actualitza contador
;    ld  bc, #sizeof_e
;    add ix, bc              ;;IX: apunta al següent
;    jr _update_loop