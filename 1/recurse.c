#include <stdio.h>

void print_array(int nums[], int len, int i) {
    if (i == len) return;

    printf("%d\n", nums[i]);

    print_array(nums, len, i + 1);
}

void print_array2(int nums[], int len) {
    if (len == 0) return;

    print_array2(nums, len - 1);
    printf("%d\n", nums[len - 1]);
}

int main(void)
{
    int nums[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    print_array2(nums, 10);

    return 0;
}
