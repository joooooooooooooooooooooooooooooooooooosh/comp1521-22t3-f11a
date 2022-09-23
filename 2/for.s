main:

        # t0 holds x
        li      $t0, 24
main__for_start_0:
        bge     $t0, 42, main__for_end_0

        li      $v0, 1
        move    $a0, $t0
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall


        addi    $t0, $t0, 3
        b       main__for_start_0

main__for_end_0:
        li      $v0, 0
        jr      $ra
