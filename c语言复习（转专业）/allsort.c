#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//冒泡
int* sortArray1(int* nums, int numsSize) {
    int t;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = numsSize - 1; j > i; j--) {
            if (nums[i - 1] > nums[i]) {
                t = nums[i - 1];
                nums[i - 1] = nums[i];
                nums[i] = t;
            }
        }
    }
    return nums;
}
//优化的冒泡
int* sortArray1_1(int* nums, int numsSize) {
    int t,index=0;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = numsSize - 1; j > index; j--) {
            if (nums[i - 1] > nums[i]) {
                t = nums[i - 1];
                nums[i - 1] = nums[i];
                nums[i] = t;
                index = i;
            }
        }
    }
    return nums;
}
//自创的某种不同于选择的算法
int* sortArray2(int* nums, int numsSize) {
    int t;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] < nums[i]) {
                t = nums[j];
                nums[j] = nums[i];
                nums[i] = t;
            }
        }
    }
    return nums;
}
//选择排序
/*int* sortArray3(int* nums, int numsSize) {
    int index;
    for(int i=0;i<numsSize-1;i++){
        index=i;
        for(int j=i+1;j<numsSize;j++)
            if(nums[j]<nums[index])
            index=j;
        }
    }
   return nums;
}*/
//插入排序
int* sortArray4(int* nums, int numsSize) {
    int end, temp;
    for (int i = 0; i < numsSize; i++) {
        end = i;//有序数列最后一个元素的下标
        temp = nums[end + 1];//待插入元素
        while (end >= 0) {
            if (temp < nums[end]) {
                nums[end + 1] = nums[end];
                end--;
            }
            else
                break;
        }
        nums[end + 1] = temp;
    }
    return nums;
}
int main() {
    int n;
    int* a;
    printf("please input the num of the array:\n");
    scanf_s("%d", &n);
    a = (int*)malloc(sizeof(int) * n);
    printf("please input elements:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }
    printf("before sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nafter sort:\n");
    a = sortArray4(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}