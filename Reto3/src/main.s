.include "cpctelera.h.s"

.area _DATA
.area _CODE

;;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
;; DECLARATION OF GLOBAL SYMBOLS TO BE USED
;;    This informs the linker, who will link the translation of this
;; file against the files containing these symbols
;;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.globl cpct_disableFirmware_asm
.globl cpct_setVideoMode_asm
.globl cpct_setPalette_asm
.globl cpct_px2byteM0_asm
.globl cpct_getRandom_xsp40_u8_asm

;;##########################################################
;;## PALETTE
;;##  Hardware values for the colors of the Mode 0 Palette
;;##########################################################
palette:
   .db   HW_BLACK, HW_BLUE, HW_MAUVE, HW_RED
   .db   HW_BRIGHT_RED, HW_BRIGHT_RED, HW_BRIGHT_RED, HW_PASTEL_YELLOW
   .db   HW_PASTEL_YELLOW, HW_PASTEL_YELLOW, HW_BRIGHT_YELLOW, HW_BRIGHT_YELLOW
   .db   HW_BRIGHT_YELLOW, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE, HW_BRIGHT_WHITE

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; INITIALIZE
;;  Initializes the Amstrad CPC: no firmware, mode 0, palette, border black.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
initialize:
   call cpct_disableFirmware_asm
   ld  c, #0
   call cpct_setVideoMode_asm
   ld  hl, #palette
   ld  de, #16
   call cpct_setPalette_asm

   cpctm_setBorder_asm HW_BLACK

   ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; TEST1
;;  Tests mode and palette, by drawing it to video memory.
;;  test_vals are the values for the pixels
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

test_vals:
   .db 0x40, 0x4C, 0x70, 0x7C, 0x43, 0x4F, 0x73, 0x7F
test1:
   ;; amb px2byte
   ;ld h, #0
   ;ld l, #1
   ;call cpct_px2byteM0_asm

   ;;; amb test vals
   ;ld hl, (test_vals)
   ;ld (#0xC000), hl

   ;ld hl, (test_vals+2)
   ;ld (#0xC002), hl

   ;ld hl, (test_vals+4)
   ;ld (#0xC004), hl

   ;ld hl, (test_vals+6)
   ;ld (#0xC006), hl

   ld hl, #test_vals
   ld de, #0xC000
   ld bc, #8

   ldir

   ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; FILL WITH RANDOMS 0-15
;;    Must fill an array with random bytes from 0 to 15
;; INPUT:
;;    - DE: Address where the array starts (pointer to array)
;;    -  B: Number of randoms to generate (Size)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
fill_with_randoms:
   ;;
   ;; @@@@@ IMPLEMENT @@@@@
   ;;
   call cpct_getRandom_xsp40_u8_asm
   and a ;;truca

   ret

width = 40
height = 40                
_num_entities:: .db 0               
_last_elem_ptr:: .dw _array  ;;define word, posa 2bytes que li digues ...
_array::                     ;;define space, reserva nº de bytes que li ...
    .ds width * height
;create_array:
   ;ld  de, (_last_elem_ptr)    ;;puntero on vull copiar 
   ;ld  bc, #width           ;;contador
   ;ldir
;
   ;ld  a, (height)
   ;inc a
   ;
   ;ld  (_num_entities), a      ;;"_num_entities++"
   ;ld  hl, (_last_elem_ptr)
   ;ld  bc, #width           ;;reestablim
   ;add hl, bc                  ;;preparem següent pos array
;
   ;ld  (_last_elem_ptr), hl    ;;actualitzem
;
   ;ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; MAIN: Start of the program
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_main::
   call initialize
   call test1

   call create_array

   ld de, #_array    ;;4040
   ld b, #width 
   call fill_with_randoms
loop:
   jr loop