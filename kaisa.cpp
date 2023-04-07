#include<stdio.h>
#include<stdint.h>
int main () {
char miwen;
	miwen = getchar();
	while (miwen != '\n') {
		if (miwen >= 'A' && miwen <= 'Z')
			putchar(((miwen - 'A' + 3) * 21) % 26 + 'A');
		else if (miwen >= 'a' && miwen <= 'z')
			putchar(((miwen - 'a' + 3) * 21) % 26 + 'a');
		else putchar(miwen);

	}




return 0;
}

	
