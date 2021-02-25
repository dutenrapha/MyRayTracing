#include "../include/header.h"

float	ft_atof(const char *nptr)
{
    double   val;
    int i;
    int j;
    int flag;
    bool neg;
    char c;

    i=0;
    j=0;
    val=0;
    flag=0;
    c = *(nptr+i);
    neg = false;
    if(c == '-')
    {
        i++;
        neg = true;
        c = *(nptr+i);
    }
    while (c !='\0')
    {
        if (c!='.')
        {
            val =(val*10)+(c-'0');
            if (flag == 1)
            {
                --j;
            }
        }
        if (c=='.')
        { 
            if (flag == 1) 
            {
                return 0; 
            }
            flag=1;
        }
        ++i;
        c = *(nptr+i);
    }
    val = val*pow(10,j);
    if (neg)
    {
        val = val*-1;
    }
    return ((float)val);
}