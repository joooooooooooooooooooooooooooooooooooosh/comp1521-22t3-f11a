main:
main__prologue:
        begin
        push    $ra # addi      $sp, $sp, -4
                    # sw        $ra, ($sp)
main__body:
        li      $a0, 11
        li      $a1, 13
        li      $a2, 17
        li      $a3, 19
        jal     sum4
        move    $a0, $v0

        li      $v0, 1
        syscall

        li      $v0, 0
main__epilogue:
        pop     $ra
        end
        jr      $ra

sum4:
sum4__prologue:
        begin
        push    $ra
        push    $s0
        push    $s1
        push    $s2
sum4__body:
        move    $s1, $a2
        move    $s2, $a3

        jal     sum2
        move    $s0, $v0

        move    $a0, $s1
        move    $a1, $s2
        jal     sum2

        move    $a0, $s0
        move    $a1, $v0
        jal     sum2

sum4__epilogue:
        pop     $s2
        pop     $s1
        pop     $s0
        pop     $ra
        end
        jr      $ra

sum2:
        add     $v0, $a0, $a1
        jr      $ra
