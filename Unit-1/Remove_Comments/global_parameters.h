/*Macros.*/
#define MAXLENGTH 250   /*Maximum length of file-name.*/
#define START 0         /* Starting point of Line No.*/
#define READMODE "r"    /*Open the file in read-mode.*/
#define WRITEMODE "w"   /*Open the file in write-mode.*/
#define FOUND 0         /*Indicates missplaced comment.*/
#define NOTFOUND 1      /*Indicates no missplaced comments.*/
#define INSIDECMNT 2    /*Indicates that multi-line comment has started.*/
#define NULLCHAR '0'
#define WRITE 'w'
#define READ 'r'
#define ERROR 0
#define SUCCESS 1       /*No errors were found.*/
#define FAIL 0          /*Errors were found, Terminate.*/
#define ON 1
#define OFF 0

/*Global variables.*/
int newCharacter, missplacedComment = NOTFOUND, lineNo = START, flag = OFF;
char fileName[MAXLENGTH], mode = READ;
