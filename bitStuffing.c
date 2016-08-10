#include<stdio.h>
#include<string.h>
void moveIndex(char *arr, int size, int index);
int main()
{
    char bit[50], arr[50];
    char header[20];
    char check[20] = {0};
    int i = 0, size = 0, j = 0;
    int trunc;  //To truncate the check
    printf("\nEnter the header : \n");
    fgets(header, sizeof(header), stdin);
    //printf("\nHeader : %s\n",header);
    printf("\nEnter the bit pattern : \n");
    fgets(bit, sizeof(bit), stdin);
    //printf("\nBit : %s\n",bit);
    size = strlen(bit) - 1;
    //printf("\nSize of bit : %d\n",size);
    strcpy(arr, bit);
    for(i = 0 ; i < size ; i++)
    {
        check[j++] = bit[i];
        check[j] = '\n';
        //trunc = strlen(check);
        //printf("\nCurrent check size : %d\n",trunc);
        //check[trunc] = '\0';
        printf("\nCheck : %s\n",check);
        printf("\nCheck vs Header : %s vs %s",check,header);
        if( strncmp(check, header, strlen(header)) == 0 )
        {
            printf("\nIntel\n");
            moveIndex(arr, size, i);
            bit[i] = !bit[i];
            //i++;
            check[0] = '\0';
            j = 0;
        }
    }
    printf("\nStuffed Bit : %s\n",arr);



    return 0;
}
void moveIndex(char *arr, int size, int index)
{
    int i = 0;
    for(i = index ; i < size ; i++)
    {
        arr[i + 1] = arr[i];
    }
}
