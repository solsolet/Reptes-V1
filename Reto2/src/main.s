;; Include all CPCtelera constant definitions, macros and variables
;;.include "cpctelera.h.s"

.area _DATA
.area _CODE

;; Plantilla de datos iniciales de un copo
plantilla_copo:
   .db 25,    0   ;; ( X,   Y  ) Coordenadas de pantalla
   .db  1, 0xF0   ;; (VY, Color) Velocidad en Y, Color del copo
tam_copo = . - plantilla_copo  ;; Tamaño de un copo

;; Array de copos
max_copos = 10                            ;; Máximo número de copos
num_copos = 0
tam_array_de_copos = max_copos * tam_copo ;; Tamaño del array
array_de_copos:                           ;; Array (bytes)
   .ds tam_array_de_copos
last_elem_ptr: .dw array_de_copos

;;---------------------------------------------------------------
;; INICIALIZAR EL ARRAY DE COPOS
;;---------------------------------------------------------------
man_copos_inicializar:
   ld hl, #array_de_copos     ;; HL = array_de_copos
   ld (hl), #0                ;; Escribir un cero
   ld  d, h                   ;; / DE = HL + 1
   ld  e, l                   ;; |    = array_de_copos + 1
   inc de                     ;; \ 
   ld bc, #tam_array_de_copos - 1 ;; BC = tam_array_de_copos - 1
   ldir                           ;; Escribir los ceros
   
   ret

;;meu codi
iniciar_valores:: 
   ld  bc, #tam_copo          ;;contador
   ld  hl, #plantilla_copo
   ldir
   ret

_main::
   call man_copos_inicializar

   ld de, #array_de_copos
   call iniciar_valores
   call iniciar_valores

   jr .