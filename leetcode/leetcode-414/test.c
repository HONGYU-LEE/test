int thirdMax(int* nums, int numsSize){
    int i;
    long max = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] > max)
            max = nums[i];
    }
    //�ҳ����ֵ
    
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != max && nums[i] > second)
            second = nums[i];
    }
    //�ҳ��ڶ���

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != max && nums[i] != second && nums[i] > third)
            third = nums[i];
    }
    //�ҵ�������

    if(third != LONG_MIN)
        return third;
    else
        return max;
}
