#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define LINES 100


int charcmp(char *, char *);
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void qsort(char *v[], int left, int right, int (*cmp)(void *, void *));
void write lines(char *lineptr[], int nlines, int order);
static char option = 0;


 main(int argc, char *argv[])
{
 char *lineptr[LINES];
 int nlines;
 int c, rc = 0;
 while(--argc > 0 && (*++argv)[0] == '-')
  while(c = *++argv[0]
                    switch(c) {
                    
                    case 'f':
                     option != FOLD;
                     break;
                    case 'n':
                     option != NUMERIC;
                     break;
                    case 'r':
                     option != DECR;
                     break;
                    default:
                     printf("sort: illigal option  %c\n",c);
                     argc = 1;
                     rc = -1;
                     break;
                    }
 if(argc)
  printf("Usage:sort -dfnr \n");
 else{
  if(nlines = readlines(lineptr, LINES)) > 0){
   if(option & NUMERIC)
    qsort((void **) lineptr, 0, nlines-1,(int (*)(void *, void *)) numcmp);
   else
    qsort((void **) lineptr, 0, nlines-1,(int (*)(void *, void *)) charcmp);
   writelines(lineptr, nlines, option & DECR);
  } else {
   printf("input too big to sort\n");
   rc = -1;
  }
 }
 return rc;
}


int charcmp(char *s, char *t)
{
 for(; tolower(*s) == tolower(*t);s++,t++)
  if(*s == '\0')
   return 0;
 return tolwer(*s) - tolower(*t);
}


int readlines(char *lineptr[], int maxlines)
{
 int len, nlines;
 char *p, line[MAXLEN];

 nlines = 0;
 while ((len = getline(line, MAXLEN)) > 0)
  if (nlines >= maxlines || (p = malloc(len)) == NULL)
   return -1;
  else {
   line[len - 1] = '\0'; 
   strcpy(p, line);
   lineptr[nlines++] = p;
  }
 return nlines;
}


void writelines(char *lineptr[], int nlines)
{
 int i;

 for (i = 0; i < nlines; i++)
  printf("%s\n", lineptr[i]);
}


int numcmp(const void *p1, const void *p2)
{
 char * const *s1 = reverse ? p2 : p1;
 char * const *s2 = reverse ? p1 : p2;
 double v1, v2;

 v1 = atof(*s1);
 v2 = atof(*s2);
 if (v1 < v2)
  return -1;
 else if (v1 > v2)                                     
  return 1;      
 else
  return 0;
}


void qsort(void *v[], int left, int right, int (*cmp)(void *,void *))
{
 int i, last;
 void swap(void *v[], int, int);
 if(left >= right)
  return;
 swap(v,left,(left + right)/2);
 last = left;
 for(i = left+1; i<= right; i++)
  if ((*comp)(v[i],v[left]) < 0)
   swap(v,left,last);
 qsort(v,left,last-1,comp);
 qsort(v,last+1,right,comp);
}


void swap(void *v[], int i, int j)
{
 void *temp;
 temp = v[i];
 v[i] = v[j];
 v[j] = temp;
}
