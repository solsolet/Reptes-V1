;; RENDER (stars) SYSTEM

.include "cpctelera.h.s"
.include "entity_manager.h.s"

_palette: .db HW_BLACK, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE

rendersys_init::
    ld  c, #0                   ;;Modo 1
    call cpct_setVideoMode_asm
    ld  hl, #_palette         ;;Carga paleta
    ld  de, #16
    call cpct_setPalette_asm
    cpctm_setBorder_asm HW_BLACK;;posar borde blanc
    ret

;; INPUT:
;;      IX: Pointer to first entity to render
;;       A: Number of entities to render
rendersys_update::
    call rendersys_render_entities  ;;render all entities
    ret

rendersys_render_entities::
    ld  (_ent_counter), a

_update_loop:
    ;;--------------------OPTIMITZABLE-----------------------
    ;;Calculate a video-memory location for printing (Borrar)
    ld  de, #0xC000     ;;DE: pointer to star of the screen
    ld  a, e_x(ix)      
    sub e_v(ix)         ;;calculem pos - vel
    ld   c, a           ;;x
    ld   b, e_y(ix)     ;;y
    call cpct_getScreenPtr_asm

    ex de, hl
    xor a               ;;color = 0
    ld   b, #1          ;;width
    ld   c, #1          ;;height
    call cpct_drawSolidBox_asm

    ;;Calculate a video-memory location for printing (Pintar)
    ld  de, #0xC000     ;;DE: pointer to star of the screen
    ld   c, e_x(ix)     ;;x
    ld   b, e_y(ix)     ;;y
    call cpct_getScreenPtr_asm

    ;;Draw Entity Sprite
    ex  de, hl
    ld   a, e_color(ix) ;;color
    ld   b, #1          ;;width
    ld   c, #1          ;;height
    call cpct_drawSolidBox_asm

_ent_counter = .+1
    ld  a, #0
    dec a
    ret z

    ld (_ent_counter), a    ;;actualitza contador
    ld  bc, #sizeof_e
    add ix, bc              ;;IX: apunta al següent
    jr _update_loop