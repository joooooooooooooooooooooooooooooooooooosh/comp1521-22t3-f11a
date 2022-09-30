N_SIZE = 10

main:
        # t0 holds i
        li      $t0, 0
main__while_start:
        bge     $t0, N_SIZE, main__while_end

        # la      $t1, numbers
        # mul     $t2, $t0, 4
        # add     $t3, $t1, $t2
        # lw      $a0, ($t3)

        mul     $t2, $t0, 4
        lw      $a0, numbers($t2)

        li      $v0, 1
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

        addi    $t0, $t0, 1
        b       main__while_start

main__while_end:

        li      $v0, 0
        jr      $ra

        .data
numbers:
        .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
