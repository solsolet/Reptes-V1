;; Include all CPCtelera constant definitions, macros and variables
.include "cpctelera.h.s"

.area _DATA
.area _CODE

;; Declare all function entry points as global symbols for the compiler
;;no cal per que hem posat Flag -g
;; es pot usar includes i fer arxius de capçalera

star::  .db 1, 20, 20, 1, #0x80 ;;estrella 1px groga
star1:: .db 1, 50, 40, 3, #0x08 

_main::
   ;; Disable firmware to prevent it from interfering with string drawing
   call cpct_disableFirmware_asm

   ;;Init systems
   call entityman_init
   call rendersys_init
   call physicssys_init

   ld hl, #star
   call entityman_create

   ld hl, #star1
   call entityman_create

;; Loop forever
loop:
   call entityman_getArray
   call physiscssys_update
   call entityman_getArray
   call rendersys_update

   ;;esperem
   halt
   halt
   call cpct_waitVSYNC_asm

   jr    loop