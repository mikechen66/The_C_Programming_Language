/**
 * Exercise: 2-4 - Write an alternative version of squeeze(s1, s2) that delete 
 * each character in s1 that matches any character in the string s2.
 * 
 * Please note that it is a snippet 
 **/


// squeeze: delete each character in string s1 that match in string s2
void squeeze(char s1[], char s2[]) {

    int i, j, k;

    for (i=k=0; s1[i] != '\0'; i++) {
        for (j=0; s2[j] != '\0' && s2[j] != s1[i]; j++)
            ;
        if (s2[j] == '\0')           // end of string - no match
                s1[k++] = s1[j];
    }
    s1[k] = '\0';
}