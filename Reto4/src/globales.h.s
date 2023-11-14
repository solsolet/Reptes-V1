e_x = 0
e_y = 1
e_c = 2

.globl render_update
.globl fis_update

;; cpct functions
.globl cpct_getScreenPtr_asm
.globl cpct_drawSolidBox_asm
.globl cpct_disableFirmware_asm
.globl cpct_setDrawCharM1_asm
.globl cpct_drawStringM1_asm
.globl cpct_waitVSYNC_asm