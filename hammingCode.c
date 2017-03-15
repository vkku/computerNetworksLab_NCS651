#include<stdio.h>
#include<math.h>
int main()
{
    double bit;
    int count = 0;  //no of digits in bit, it's one more than array
    double dupe;
    int pattern[200];
    int ham[200];
    int *first, *last;
    int fwd = 0;    //for entering sparse array
    int red= 0; //redundant bits
    int parity = 0; //to leave parity bits
    int iter = 0;
    int save[200];  //to save parity positions
    int yalc = 0;   //yet another loop counter for save array - the parity positions
    int ex = 0;       //for explicitly entering first hamming bit
    int jz = 0;     //Check if bit pattern starts with 0
    int noz;        //Number of preceding zeros
    int ch = 0;     //EXIT
    do
    {
        printf("\nIs the bit pattern proceeded by 0 [Press 1 to confirm, 0 to deny]\n");
        scanf("%d",&jz);
        if(jz == 1)
        {
            printf("\nEnter number of leading zeros : \n");
            scanf("%d",&noz);
        }
        printf("\nEnter the bit pattern : \n");
        scanf("%lf",&bit);
        dupe = bit;
        //printf("Proceed");
        while(dupe > 0.7)
        {
            pattern[count++] = (int)fmod(dupe, 10.0);
            dupe /= 10.0;
        }
        if(jz == 1)
        {
            while(noz--)                    //Loop until all zeros are completely absorbed
                pattern[count++] = 0;
        }

        
        while(  ( pow(2, red) < count + red + 1  )    &&   ( pow(2, red) != count + red + 1  ) )
        {
            red++;
        }
        printf("\nWord Size : %d\n",count);
        printf("\nRedundant Bits : %d\n",red);
        //putting first value explicitly
        ham[0] = ham[1] = 0;    //parity bits
        ham[2] = pattern[0];
        fwd = 1;
        parity = 1;
        iter = 3;
        //Update parity save positions
        save[yalc++] = 0;
        save[yalc++] = 1;

        while(iter < count + red)
        {
            //Is it parity position ?
            if( ( pow(2, parity + 1) - (iter + 1) )  < 0.00001 )
            {
                //printf("\nParity : %d\n",parity);
                ham[iter++] = 0;
                save[yalc++] = iter - 1;
                parity++;
            }
            else
            {
                ham[iter++] = pattern[fwd++];
            }
        }
        printf("\n\nTotal Bits : %d\n",count + red);
        printf("\nParity Positions : \n");
        for(iter = 0 ; iter < yalc ; iter++)
            printf("%3d",save[iter] + 1);   //casted according to real world
        printf("\n");   //pretty output
        /*
        Driver for individual testing [Uncomment if testing parity 0 explicitly]
            printf("\nHamming Code : [Parity bit represented as 0]\n");
        for(iter = 0 ; iter < count + red; iter++)
                printf("%3d",ham[iter]);
        */
        //*********************************** PART - 1 COMPLETE ********************************************************

        //Putting first hamming bit explicitly
        ex = ham[0];
        for(iter = 2 ; iter < count + red ; iter += 2)
        {
            //printf("\n%d ^ %d\n",ex,ham[iter]);
            ham[0] = ex ^ ham[iter];
            ex = ham[0];
            //printf("\nNOW ham : %d\n",ham[0]);
        }
        //Finding Parity bits
        for(iter = 1 ; iter < red ; iter++)
        {
            int temp = save[iter];
            int repeat = 0;
            while(temp < count + red)
            {
                ham[save[iter]] ^= ham[temp++];
                repeat++;
                if(repeat == save[iter] + 1)    //For taking and leaving bits
                {
                    temp += save[iter] + 1;  //To reach to correct position after leaving defined bits
                    repeat = 0;
                }
            }
        }

        //Reverse to display correctly
        //Set the pointers
        first = ham;
        last = ham + (count + red - 1);
        //Reversing array
        while(last > first)
        {
            int temp;
            temp = *first;
            *first = *last;
            *last = temp;
            first++;
            last--;
        }
        printf("\nHamming Code : \n");
        for(iter = 0 ; iter < count + red; iter++)
                printf("%3d",ham[iter]);
        //Arrow for parity bits -   Mark ToDo
        printf("\nPress [1] to exit [0] to continue\n");
        //scanf("%d",&ch);
        while(scanf("%d",&ch) != 1)
        {
         printf("\nONLY FOLLOWING OPTIONS ACCESSIBLE\n0  :   CONTINUE EXECUTION\n1  :   TERMINATE PROGRAM\n");
         fflush(stdin);
        }
        //flush for next iteration
        bit = 0;
        dupe = 0;
        count = 0;
        yalc = 0;

    }while(ch != 1);
    return 0;
}
