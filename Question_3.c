/*
Rahul Jauhari 2020A7PS0106H
Abhiraj Khare 2020A7PS0161H
Samyu Kamtam 2020A7PS1309H
Vaibhav Nemani 2020A7PS2195H
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
#ifndef ONLINE_JUDGE
    freopen("i2.txt", "r", stdin);
#endif

    // number of propositions 
    int p;
    scanf("%d", &p);

    // number of clauses
    int n;
    scanf("%d", &n);

    // storing clauses in 2d character array
    char str[n][100];

    for (int a = 0; a < n; a++)
    {
        scanf("%s", str[a]);
    }

    int num[n];
    int right[n];       //right side of implication
    int left[n][11];    //left side of implication

    // Initialising nt array to zero
    for (int a = 0; a < n; a++)
    {
        num[a] = 0;
    }

    // Delimiters d and d2">" & "^"
    const char d[2] = ">";
    const char d2[2] = "^";

    // Creating token t
    char *t;

    for (int k = 0; k < n; k++)
    {
        int i = 0;
        t = strtok(str[k], d);  //string str[k] is broken down into smaller strings also knowns as token
        char *a[50];

        // Bracket start
        printf("(");

        while (t != NULL)
        {
            a[i] = t;
            // printf("%s\n", a[i]);
            t = strtok(NULL, d);
            i++;
        }

        right[k] = *a[1] - '0';

        t = strtok(a[0], d2);
        while (t != NULL)
        {
            if (*t == 'T'){
                left[k][num[k]] = 10;
            }
            else if (*t == 'F')
            {
                   left[k][num[k]] = 11;
            }
            else
                {
                    left[k][num[k]] = atoi(t);
                }
            t = strtok(NULL, d2);
            num[k]++;
        }

        for (int j = 0; j < num[k]; j++)
        {
            if (j == num[k] - 1)
            {
                if (left[k][j] == 10){
                    printf("T");
                }
                else if (left[k][j] == 22)
                    {
                        printf("F");
                    }
                else{
                    printf("p%d", left[k][j]);
                }
                break;
            }
            if (left[k][j] == 10)
            {
                printf("T^");
            }
            else if (left[k][j] == 22)
            {
                   printf("F^");
            }
            else{
                printf("p%d^", left[k][j]);
        }
        }

        if (right[k] == 10){
            printf(">T");
        }
        else if (right[k] == 22)
        {
               printf(">F");
        }
        else{
            printf(">p%d", right[k]);
        }
        if (k == n - 1)
        {
            //Bracket end
            
            printf(")");
            break;
        }
        printf(")^");
    }
}
