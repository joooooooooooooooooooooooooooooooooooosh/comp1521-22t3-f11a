        .text
SQUARE_MAX = 46340
main:
        # v0 needs to be 4, a0 needs the string
        li      $v0, 4
        la      $a0, 0x10010000
        syscall

        # t0 holds x
        li      $v0, 5
        syscall
        move    $t0, $v0

if_label:
        ble     $t0, SQUARE_MAX, else_label
        beq     $t0, 50000, else_label

        li      $v0, 4
        la      $a0, error
        syscall

        b       end_label

else_label:
        # t1 holds y
        mul     $t1, $t0, $t0

        # print("%d")
        li      $v0, 1
        move    $a0, $t1
        syscall

        # print("\n")
        li      $v0, 11
        li      $a0, '\n' # li  $a0, 10
        syscall

end_label:
        li      $v0, 0
        jr      $ra

        .data

prompt_string:
alsdkf:
asdlkfdk:
        .asciiz "Enter a number: "
error:
        .asciiz "square too big for 32 bits\n"
