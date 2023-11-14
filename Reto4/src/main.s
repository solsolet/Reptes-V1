.include "cpctelera.h.s"
.include "globales.h.s"

.area _DATA

;; bixo datos
bixo: .db 0, 0, #0xF0 ;;X, Y, color

;; Define one Zero-terminated string to be used later on
string: .asciz "CPCtelera up and running!";

.area _CODE

;; FUNCIONS
init_bixo:
   ;; posar al bixo en pos random
   ret

_main::
   ;; Disable firmware to prevent it from interfering with string drawing
   call cpct_disableFirmware_asm

   ;; inicio juego
   ld ix, #bixo
   call init_bixo

   ;; Set up draw char colours before calling draw string
   ;;ld    d, #0         ;; D = Background PEN (0)
   ;;ld    e, #3         ;; E = Foreground PEN (3)

   ;;call cpct_setDrawCharM1_asm   ;; Set draw char colours

   ;; Calculate a video-memory location for printing a string
   ;;ld   de, #CPCT_VMEM_START_ASM ;; DE = Pointer to start of the screen
   ;;ld    b, #24                  ;; B = y coordinate (24 = 0x18)
   ;;ld    c, #16                  ;; C = x coordinate (16 = 0x10)

   ;;call cpct_getScreenPtr_asm    ;; Calculate video memory location and return it in HL

   ;; Print the string in video memory
   ;; HL already points to video memory, as it is the return
   ;; value from cpct_getScreenPtr_asm
   ;;ld   iy, #string    ;; IY = Pointer to the string 

   ;;call cpct_drawStringM1_asm  ;; Draw the string

   ;; Loop forever
loop:
   call  fis_update
   call  render_update

   halt
   call cpct_waitVSYNC_asm

   jr    loop