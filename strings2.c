#include"main.h"
/**
 * str_cmp-compares two strings together
 * @s1:string to be compared
 * @s2:string to be compared
 *
 * Return:0
 */
int str_cmp(char *s1, char *s2)
{
        int length_s1 = 0, length_s2 = 0, short_str = 0,subscript= 0, difference = 0;
        length_s1 = str_len(s1);
        length_s2 = str_len(s2);
        if(length_s1 <= length_s2)
        {
                short_str = length_s1;
        }
        else
        {
                short_str = length_s2;
        }
        while(subscript <= short_str)
        {
                if(s1[subscript] == s2[subscript])
                {
                        subscript++;
                        continue;
                }
                else
                {
                        difference = s1[subscript] - s2[subscript];
                        break;
                }
                subscript++;
        }
        return(difference);
}
