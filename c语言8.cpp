#include<stdio.h>
#include<string.h>
#define DENSITY 62.4;
int main() {
	float weight, volume;
	int sizes, letters;
	char name[40];
	printf("hi!what's your first name?\n");
	scanf("%s", &name);
	printf("%s,what's your weight in pounds\n",name);
	scanf("\n%f",&weight);
	sizes = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("well, %s, your volume is %2.2f cubic feet.\n",name,volume);
	printf("also your first name is %d letters\n", letters);
	printf("and you have %d bytes to store it.\n", sizes);


	

	return 0;
}
