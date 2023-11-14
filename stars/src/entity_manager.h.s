;; CABECERA

;; ací podriem posar els .globl

;; Macros (em dona errors aixina que la deixem de moment)
;.macro DefineEntityAnnonimous _name, _tipo, _x, _y, _v, _color
;   .db _tipo
;   .db _x
;   .db _y
;   .db _v
;   .db _color
;.endm
;.macro DefineEntity _name, _tipo, _x, _y, _v, _color
;_name::
;    DefineEntityAnnonimous
;.endm

;; cte.
e_tipo = 0      ;;0 = inválida / 1 = válida
e_x = 1
e_y = 2
e_v = 3
e_color = 4
sizeof_e = 5 ;; 0:tipo 1:x 2:y 3:vel 4:color

;.macro DefineEntityArray _N
;    .rept _N
;        DefineEntityAnnonimous 0, 0, 0, 0, 0
;    .endm
;.endm
