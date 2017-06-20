	// Macros.


#define NUMERIC   1
#define DECR      2
#define FOLD      4
#define MDIR      8
#define LINES     100
#define MAXLEN    500
#define ALLOCSIZE 1000


	// With Arguements.


#define EXTRACT(X,Y)     X=fold?tolower(*Y):*Y;
#define GET_NEXT_ITEM(A) !isalnum(A)&&A!=' '&&A!='\0'
#define DIRECTORY_SORT   option|=MDIR
#define FOLDED_SORT      option|=FOLD
#define NUMBERIC_SORT    option|=NUMERIC
#define REVERSE_SORT     option|=DECR
#define ITEM1            atof(first_Item)
#define ITEM2            atof(second_Item)
#define NO_FREE_MEMORY   (p=alloc(len))==NULL
