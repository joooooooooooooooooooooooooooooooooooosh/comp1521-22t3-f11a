FLAG_ROWS = 6
FLAG_COLS = 12

main:
        # row in t0, col in t1
        li      $t0, 0
main__for_start_0:
        bge     $t0, FLAG_ROWS, main__for_end_0

        li      $t1, 0
main__for_start_1:
        bge     $t1, FLAG_COLS, main__for_end_1

        # &arr[i] = &arr + i * sizeof(arr[i])
        # flag[3] = &flag + 3 * sizeof(flag[3])
        # flag[3] = &flag + 3 * (12 * sizeof(char))
        # flag[3] = &flag + 3 * (12 * 1)

        la      $t2, flag
        mul     $t3, $t0, FLAG_COLS
        mul     $t3, $t3, 1
        add     $t4, $t2, $t3

        # array[2] = &array + 2 * sizeof(array[2])
        #          = $t4 + $t1 * 1
        mul     $t5, $t1, 1
        add     $t6, $t4, $t5

        lb      $a0, ($t6)
        li      $v0, 11
        syscall

        addi    $t1, $t1, 1
        b       main__for_start_1
main__for_end_1:

        li      $v0, 11
        li      $a0, '\n'
        syscall

        addi    $t0, $t0, 1
        b       main__for_start_0
main__for_end_0:

        jr      $ra

.data
flag:
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
