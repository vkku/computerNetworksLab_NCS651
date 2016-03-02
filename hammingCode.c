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
            //int temp;
            //printf("\nDivision : %lf\n",fmod(dupe, 10.0));
            //printf("\nConverted to int : %d\n",(int)fmod(dupe, 10.0));
            //temp = (int)fmod(dupe, 10.0);
            pattern[count++] = (int)fmod(dupe, 10.0);
            //printf("\nCount : %d\n",count);
            //printf("\nEntered : %d\n",pattern[count-1]);
            dupe /= 10.0;
        }
        if(jz == 1)
        {
            while(noz--)                    //Loop until all zeros are completely absorbed
                pattern[count++] = 0;
        }

        /*
        printf("\nReversed : \n");
        for(iter = 0 ; iter < count ; iter++)   //Print pattern the reverse array
        {
            printf("%3d",pattern[iter]);
        }
        */

        /*
        printf("\nReversed : \n");
        for(dupe = 0 ; dupe < count ; dupe++)
                printf("%3d",pattern[dupe]);
        */
        /* NO REVERSE NEEDED
        //Set the pointers
        first = pattern;
        last = pattern + count - 1;
        //Reversing array
        while(last > first)
        {
            //printf("\nInside");
            int temp;
            temp = *first;
            *first = *last;
            *last = temp;
            first++;
            last--;
        }
        */
        /*
        printf("\nAgain Reversed : \n");
        for(iter = 0 ; iter < count ; iter++)
                printf("%3d",pattern[iter]);
        */
        /*
        //0101-Reversing must be remembered
        count = 4;
        pattern[0] = 1;
        pattern[1] = 0;
        pattern[2] = 1;
        pattern[3] = 0;
        */
        while(  ( pow(2, red) < count + red + 1  )    &&   ( pow(2, red) != count + red + 1  ) )
        {
            red++;
            //printf("\nIntel\tred : %d",red);
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
            //printf("\nIntel\titer : %d\n",iter);
            //It is parity position ?
            if( ( pow(2, parity + 1) - (iter + 1) )  < 0.00001 )
            {
                //printf("\nParity : %d\n",parity);
                ham[iter++] = 0;
                save[yalc++] = iter - 1;
                parity++;
            }
            else
            {
                //printf("\nfwd : %d\n",fwd);

                ham[iter++] = pattern[fwd++];
                //fwd++;
            }
        }
        printf("\n\nTotal Bits : %d\n",count + red);
        printf("\nParity Positions : \n");
        for(iter = 0 ; iter < yalc ; iter++)
            printf("%3d",save[iter] + 1);   //casted according to real world
        printf("\n");   //pretty output
        /*
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
                //printf("\nBit Taken : %d\n",ham[temp - 1]);
                repeat++;
                //printf("\nRepeat++\n");
                if(repeat == save[iter] + 1)    //For taking and leaving bits
                {
                    temp += save[iter] + 1;  //To reach to correct position after leaving defined bits
                    repeat = 0;
                }
            }
            //printf("\niter = %d\nham[save[iter]] : %d\n",iter,ham[save[iter]]);
        }












        /*
        printf("\nHamming Code : \n");
        for(iter = 0 ; iter < count + red; iter++)
                printf("%3d",ham[iter]);
        */


        //Reverse to display correctly
        //Set the pointers
        first = ham;
        last = ham + (count + red - 1);
        //Reversing array
        while(last > first)
        {
            //printf("\nInside");
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
    }while(ch != 1);
    getch();
    return 0;
}
