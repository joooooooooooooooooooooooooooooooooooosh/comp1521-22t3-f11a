        .text
main:
        lw      $t0, d
        jr      $ra

        .data
aa: .word 42
bb: .word 666
cc: .word 1
    .word 3
    .word 5
    .word 7

a:  .word   42
b:  .space  4
c:  .asciiz "abcde"
    .align  2
d:  .byte   1, 2, 3, 4
e:  .word   1, 2, 3, 4
f:  .space  1

# 0x10010000
# a: 00 00 00 2a
# b: ?? ?? ?? ??
# c: 61 62 63 64
#    65 00 ?? ??
# d: 01 02 03 04
# e: 00 00 00 01
#    00 00 00 02
#    00 00 00 03
#    00 00 00 04
# f: ??

u: .space 4
v: .word 42
w: .space 1
x: .byte 'a'
y: .space 8
z: .space 20 * 4
