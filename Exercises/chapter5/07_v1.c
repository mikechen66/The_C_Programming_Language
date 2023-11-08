/**
 * Exercise: 5-07 - Rewrite readlines to store lines in an array supplied by main, 
 * rather than calling alloc to maintain storage. How much faster is the program?
 * 
 * Please note the original snippet is not a complete program. For more details, 
 * please see the version 2. 
 **/


/* readlines: read input lines */
int readlines(char *lineptr[], char *linestor, int maxlines) {

    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *linestop = linestor + MAXLINES

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || p + len > linestop) {
            return -1;
        } 
        else {
            line[len-1] = '\0';           // delete new line
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

/* get_line: read a line into s, return length */
int get_line(char *s, int lim) {

    int c;
    char *t = s;

    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right) {

    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {

    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}