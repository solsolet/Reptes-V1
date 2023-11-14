.include "cpctelera.h.s"

.area _DATA

.area _CODE

.globl cpct_disableFirmware_asm
.globl cpct_setDrawCharM1_asm
.globl cpct_drawCharM1_asm
.globl cpct_scanKeyboard_asm
.globl cpct_isKeyPressed_asm
.globl cpct_isAnyKeyPressed_asm

_main::
   ;; Disable firmware to prevent it from interfering with string drawing
   call cpct_disableFirmware_asm

   ;; Set up draw char colours before calling draw string
   ld    d, #0         ;; D = Background PEN (0)
   ld    e, #1         ;; E = Foreground PEN (3)

   call cpct_setDrawCharM1_asm   ;; Set draw char colours

   ld e, #'H'
   ld hl, #0xC000

   call cpct_drawCharM1_asm    ;; Dibuja caracteres

   ld e, #'I'
   ld hl, #0xC001

   call cpct_drawCharM1_asm    ;; Dibuja caracteres

   ;; Loop forever
loop:
   call cpct_scanKeyboard_asm ;;llig i emmagatzema teclat
   call cpct_isAnyKeyPressed_asm 

   jr nz, letraA ;;si A pulsada cambia color

   jr    loop

letraA:
   ld hl, #Key_A ;;detecta tecla A
   call cpct_isKeyPressed_asm 
   jr nz, cian
   jr z, fallo
cian:
   ld    d, #0         ;; D = Background PEN (0)
   ld    e, #2         ;; E = Foreground PEN (2) cian

   call cpct_setDrawCharM1_asm   ;; Set draw char colours

   ld e, #65
   ld hl, #0xC000

   call cpct_drawCharM1_asm    ;; Dibuja caracteres

   jr infinito          ; bucle infinito;

fallo:
   ld    d, #0         ;; D = Background PEN (0)
   ld    e, #3         ;; E = Foreground PEN (2) cian

   call cpct_setDrawCharM1_asm   ;; Set draw char colours

   ld e, #'-'
   ld hl, #0xC000

   call cpct_drawCharM1_asm    ;; Dibuja caracteres

   jr infinito          ; bucle infinito;

infinito:
   jr infinito