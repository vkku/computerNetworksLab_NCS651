#include<stdio.h>
#include<string.h>
int main()
{
    //Simulation for 4 stations
    int code[4][4], check[4][4] = {1};  //check will contain each stations's code * data word
    int transmit[4],channel[4] = {0};
    int i,j,counter = 0,station,gen = 0;
    char *desc[3];
    char *zero = "Data Bit 0";
    char *one = "Data Bit 1";
    char *sil = "Silence";

    desc[-1] = zero;
    desc[0] = sil;
    desc[1] = one;

    //code for each station (chip sequence)
    code[0][0] = code[0][1] = code[0][2] = code[0][3] = 1;

    code[1][0] = code[1][2] = 1;
    code[1][1] = code[1][3] = -1;

    code[2][0] = code[2][1] = 1;
    code[2][2] = code[2][3] = -1;

    code[3][0] = code[3][3] = 1;
    code[3][1] = code[3][2] = -1;
    printf("\nSimulation of CDMA for 4 stations\n");
    printf("\nEnter transmission bit for each station : [ -1 : Bit 0, 1 : Bit 1, 0 : Silence ]");
    for(i = 0 ; i < 4 ; i++)
    {
        printf("\nStation %d    :   ",i+1);
        scanf("%d",&transmit[i]);
    }

    for(i = 0 ; i < 4 ; i++)
    {
        for(j = 0 ; j < 4 ; j++)
        {
            check[i][j] = transmit[i] * code[i][j];
        }
    }

    printf("\nData for : \n");
    for(i = 0 ; i < 4 ; i++)
    {
        printf("\nStation %d : [",i+1);
        for(j = 0 ; j < 4 ; j++)
        {
            printf("\t%d",check[i][j]);
        }
        printf("]");
    }
    printf("\n\n********************************************************************\n");
    printf("\nData sent over channel    :   [");
    for(i = 0 ; i < 4 ; i++)
    {
        for(j = 0 ; j < 4 ; j++)
        {
            channel[counter] += check[j][i];
        }
        counter++;
    }

    for(i = 0 ; i < counter ; i++)
        printf("\t%d",channel[i]);

    printf("]");
    printf("\n\n********************************************************************\n");

    printf("\nEnter station to be listened to   :   ");
    scanf("%d",&station);
    for(i = 0 ; i < 4 ; i++)
    {
        gen += code[station-1][i] * channel[i];
        //printf("\nCalculated : %d",code[station][i] * channel[i]);
        //printf("\ngen : %d",gen);
    }
    printf("\nSTATION %d TRANSMITS BIT : %d [%s]\n",station,gen/4,desc[gen/4]);

    return 0;
}
