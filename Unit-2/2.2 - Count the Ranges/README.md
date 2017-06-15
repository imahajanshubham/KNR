!(https://drive.google.com/uc?export=download&id=1n4pyGD3HDhtOsPzUlzaCzzxRrqqExKzS1w)
##		Print the range of various Data-Structures.

###		Logic Used

1. Use of Bitwise Operators.
2. **~** ( Binary One's Complement ) 0 will give bits in 1s.
3. **>>** ( Binary Right Shift Operator ) 1 shifts 1 bit to remove the sign bit.
4. Use of type-casting.

###		Explanation

```
1. The left-most bit is usually the sign bit. To make it unsigned,
   we only need toremove the sign bit and store 0 in it’s place.
```
```
2. Size of char is 1 Byte.
   So, (unsigned char) 0 = 0000 0000.
   And, to get negative value, Let's take it's complement,
	
	(unsigned char) ~ 0 = 1111 1111.
```
```
3. Now, How to remove left-most bit i.e. 1?
   We'll simply do Right Shift 1 will shift the entire sequence to the right,
   and simply insert 0 from the left side,
   
   So it will give 0111 1111 and converting **0111 1111** to integer will be: 127!
```
## Cheers!
