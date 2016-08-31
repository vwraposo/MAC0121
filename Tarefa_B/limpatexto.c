 #include <stdio.h> 

 int main () {
 	int i;
 	unsigned char c;
 	while (scanf ("%c", &c) != EOF) {
 		if ((c >= 32 && c <= 126) || c == 10)
 			printf ("%c", c);
 		else if (c == 9) {
 			for (i=0;i<7;i++) 
 				printf(" ");
 			printf ("%c", 32);
 		}
 		 else if (c >= 192 && c <= 195) 
 			printf ("A");
 		else if (c == 199) 
 			printf ("C");
 		else if (c >= 201 && c <= 202) 
 			printf ("E");
 		else if (c == 205) 
 			printf ("I");
 		else if (c >= 211 && c <= 213) 
 			printf ("O");
 		else if (c == 218) 
 			printf ("U");
 		else if (c >= 224 && c <= 227) 
 			printf ("a");
 		else if (c == 231) 
 			printf ("c");
 		else if (c >= 233 && c <= 234) 
 			printf ("e");
 		else if (c == 237) 
 			printf ("i");
 		else if (c >= 243 && c <= 245) 
 			printf ("o");
 		else if (c == 250) 
 			printf ("u");
 	}
 	printf ("\n");
 	
 	return 0;
 }