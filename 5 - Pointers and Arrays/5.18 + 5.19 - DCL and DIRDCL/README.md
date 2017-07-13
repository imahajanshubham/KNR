# DCL and DIRCL.
![DCL and DIRDCL](https://drive.google.com/uc?export=download&id=1HIkvFhVOqm4UEGYr78WO1IXEdhR6uRSPCw "DCL and DIRDCL")

### Key Functions

1. DCL + DIRDCL - complimentary functions used to convert statements into expressions (DCL - Declarator).
2. DIRDCL = DCL within Parenthesis.
3. gettoken - gets next token from the user.

### Explanation

```
1. Let's say, user wants to write -

    'x is a function returning a pointer to an array of pointers to function returning char'

    In expression form, This statement would become -
        x () * [] * () char

        where,
() -> Function,
[] -> Array
*  -> Pointer.
```
```
2. Let's try to analyze it step-by-step...

    1. First, x                      -> It's a DIRDCL.

    2. Next, x()                     -> It becomes DCL.

    3. Next token is '*', So now we have

            x() * i.e. Token will preceed the DCL as follows:
        ( * x() )                    -> It becomes DIRDCL
    NOTE - As soon as a new Token is encountered,
    DCL has to be enclosed inside parenthesis to convert it into DIRDCL.


    4. Next up, [],
        ( * x() ) []                 -> It becomes DCL.


    5. Next is, '*', another token! So, it'll preceed previous DCL as follows:

          * ( * x() ) []               -> It's still a DCL, eclose it in parenthesis.
        ( * ( * x() ) [] )           -> It now became DIRDCL.


    6. Next up, ()...
          ( * ( * x() ) [] )()        -> It's now DCL.
        ( ( * ( * x() ) [] )() )      -> It's DIRCLR.


    7. Last token is 'char' so,
        char ( ( * ( * x() ) [] )() )
```
```
That's it,

From the statement... x () * [] * () char,
    we get the expression, char ( ( * ( * x() ) [] )() )


That's DCL and DIRDCL !
```
## Cheers!
