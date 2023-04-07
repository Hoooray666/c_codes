#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
static char  char_list[11] ={'J','t','D','G','q','B','d','n','Y','a'};
static unsigned int char_list_len =10;
static int check_flag = 1;
static int test_no = 1;
void static do_swap(char*a,char*b){
	char t = *a;
	*a = *b;
	*b = t;
}
void do_bubble_sort(){
	unsigned int i,j;
	for(i =0 ;i<(unsigned int)(char_list_len-1);i++){
		char *p  = char_list;
		for(j = 0;j<(unsigned int)(char_list_len-i-1);j++){
//			if((*(p+j+1) >= 96 && *(p+j) <= 90)||(*(p+j) <=90 && *(p+j+1)< *(p+j)&& *(p+j+1)<=90)||(*(p+j+1) >= 96 && *(p+j+1) < *(p+j)&& *(p+j)>= 96)){
//				do_swap(p+j,p+j+1);
//			}
			if(*(p+j+1) >= 96){
				if(*(p+j) <= 90 || *(p+j+1) < *(p+j)){
					do_swap(p+j,p+j+1);
				}
			}
			if(*(p+j) <= 90){
				if( *(p+j+1)< *(p+j)){
					do_swap(p+j,p+j+1);
				}
			}
		}
	}
}
int main () {
//	char**shuzu=(char**)malloc(sizeof(char*)*9);
//	for(int i=0;i<9;i++){
////		char*shuzu[i]=(char*)malloc(sizeof(char)*8);
//		shuzu[i]="         ";
//		trans(1,shuzu[i]);
//		puts(shuzu[i]);
//	}
//	char_list="JtDGqBdnYa";
	do_bubble_sort();
	printf("%s",char_list); 
	



return 0;
}


