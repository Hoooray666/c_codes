#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
static char  char_list[11] ;
static int char_list_len =10;
static int check_flag = 1;
static int test_no = 1;
//char * hint_test_no="\12-----------------------------test-%d\12\0";
//char * hint_given_array="The given array:  %s\12\0";
//char * hint_sorted_array="The sorted array: %s\12\0";
//char * hint_test_error_bar="\12--!--!--!--!--!--!--!--!--!--test-%d\12\12\0";
char * hint_test_error="Sorry but try it again!\12\0";
//char * hint_test_success_bar="\12--*--*--*--*--*--*--*--*--*--passed!\12\12\0";
char * hint_test_success="Well done!\12\0";

int gen_random_list(){
	time_t t0;
	int i;
	for(i = 0; i< char_list_len;i++){
		t0 = time(0);
		srand(i + t0 + test_no);
    	if ( (rand() & 1) != 0 ){
    		char_list[i] = rand() % 26 + 65;
		}
		else{
			char_list[i] = rand() % 26 + 97;
		}
	}
	char_list[char_list_len] = 0;
	printf("\n-----------------------------test-%d\n",test_no);
	return printf("The given array:  %s\n", char_list);
}

void do_swap(char*a,char*b){
	char t = *a;
	*a = *b;
	*b = t;
}
int check_sort(){ 
	int result;
	unsigned int i;
	printf("The sorted array: %s\n", char_list);
  	for(i =0 ;;++i){
  		if(i >= char_list_len-1){
  			break;
		}
		if(char_list[i] <= char_list[i+1]){
			if(char_list[i]<=90){// A-Z
				result = char_list[i+1];
			if(result > 96){// next is a-z
				check_flag = 0;// wrong
				return result;
			}
		}
	}
		else{//a-z
			result = char_list[i];
			if((result <= 96) || ( char_list[i+1] > 90)){// 90-96 or  
				check_flag = 0;
				result = char_list[i+1];
				return result;
			}
		}
	}
}

void do_bubble_sort(){
	int i,j;
	for(i =0 ;i<char_list_len-1;i++){
		char *p  = char_list;
		for(j = 0;j<char_list_len-i-1;j++){
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

int main(){
	while(test_no <= 100){
		gen_random_list();
    	do_bubble_sort();
    	check_sort();
    	if ( !check_flag )
    	{
      		printf("\n--!--!--!--!--!--!--!--!--!--test-%d\n\n",test_no);
      		puts(hint_test_error);
      		break;
    	}
    	++test_no;
	}
	if ( check_flag )
  	{
    	printf("\n--*--*--*--*--*--*--*--*--*--passed!\n\n");
    	puts(hint_test_success);
  	}
	return 0;
}





