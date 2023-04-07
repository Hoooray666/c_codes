#include<windows.h>
#include<TlHelp32.h>			//���ڻ�ȡ���̿���
#include<stdio.h>				
#include<stdlib.h>
#include<string.h>
struct  ListNode{
   int pid;
   char name[100];
   struct ListNode *next;
};
bool create (ListNode* head);
void show(ListNode* head );
bool search (int pid,ListNode* head);
bool kill_process(int pid,ListNode* head);
ListNode* removeElements(ListNode* head, int pid);
char* toString(int iVal);
bool kill(int pid);
ListNode* addelement(ListNode* head,int pid,char* shuzu);
int main(){
	struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
	create(head);
//	show (head);
	int a,b ;
	char *str = (char*)malloc(sizeof(char)*20);
        do{
            printf ("---------welcome to student management system ---------\n");
            printf ("1.add process \n");
            printf ("2.kill process \n");
            printf ("3.view all processes \n");
            printf ("4.query process \n");
            printf ("5.quit\n");
            printf ("what is your choice? \n");
            scanf("%d",&a);
            switch(a){
				case 1: 
					printf("adding process...\n");
					printf("input the pid of the process you want to add:\n");
					scanf("%d",&b);
					getchar();
//					printf("input the name of the process you want to add:\n");
					fgets(str,20,stdin);
//					printf("666\n");
					ListNode*o;
					o = head;
					addelement(o,b,str);
					continue;
				case 2:
					printf("killing process...\n");
					printf("input the pid of the process you want to delete:\n");
					scanf("%d",&b);
					ListNode*q;
					q =head;
					removeElements(q->next,b);
//					show(removeElements(head->next,b));
					continue;
				case 3: 
					printf("viewing processes\n");
					ListNode*p;
					p =head->next;
					show(p);
					continue;
				case 4: 
					printf("querying process...\n");
					printf("input the pid of the process you want to query:\n");
					scanf("%d",&b);
					ListNode*m;
					m =head->next;
					search(b,m);
					continue;
				case 5: break;	 
			}
		}while(a != 5);
	return 0;
}

bool create (ListNode* head){
    head->next = NULL;
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = head ;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);	//�ýṹ��Ĵ�С
	//��ϵͳ�ڵ����н�����һ������
	HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcess == INVALID_HANDLE_VALUE)
	{
		printf("ʧ��");
		getchar();
		return -1;
	}
	
	//�������̿��գ�������ʾÿ�����̵���Ϣ
	BOOL bMore = Process32First(hProcess, &pe32);
	while (bMore)
	{
		//pe32.szExeFileΪ���ֽ�
//		printf("�������ƣ�%s\n����ID:%u\n\n", pe32.szExeFile,pe32.th32ParentProcessID);
		struct ListNode* s = (struct  ListNode*)malloc(sizeof(struct ListNode));
		s->pid = pe32.th32ParentProcessID;
		strcat(s->name,pe32.szExeFile);
		s->next = NULL;
		p->next = s;
		p = s;
		bMore = Process32Next(hProcess, &pe32);
	}
	//���رղ�����ɺ�ľ��
	CloseHandle(hProcess);
//	getchar();
	return true;
}

void show(struct ListNode* head ){
    printf(" pid : %d\n name : %s\n\n",head->pid,head->name);
    head = head ->next;
    while(head != NULL){
        printf(" pid = %d\n name = %s\n\n",head->pid,head->name);
        if(head -> next ==NULL){
	  	  break;
	    }
        head = head ->next;
    } 
//    printf(" ]\n");
}

bool search (int pid,ListNode* head){
	int flag = 0 ;
	head = head->next;
	printf("%d\n",pid);
	while(head != NULL){
		flag =0;
		if(head->pid == pid){
			printf(" pid : %d\n name : %s\n\n",head->pid,head->name);
			flag =1;
//			continue;
		}
		if(head->next == NULL){
			break;
		}
		head = head -> next;
	}
	if(flag == 0){
		printf("no pid matched!\n");
		return false;
	} 
	else{
		printf(" pid : %d\n name : %s\n\n",head->pid,head->name);
		return true;
	}
}

bool kill_process(int pid,ListNode* head){
	int flag = 0;
	ListNode*p = head;
	while(p->next != NULL){
		flag = 0;
		if(p -> next ->pid == pid){
			flag =1;
//			kill(pid);
			p->next =  p -> next -> next;
			printf("666");
		}
		else{
			p = p-> next;
		}
	}
	if(flag == 0){
		printf("no pid matched!");
		return false;
	} 
	else{
		printf("deleted!");
		return true;
	}
}

ListNode* removeElements(ListNode* head, int pid) {
    ListNode* dummyHead = (ListNode*)malloc(sizeof(ListNode));
    dummyHead->next = head;
    ListNode* temp = dummyHead;
    int flag =0;
    while (temp->next != NULL) {
//    	flag =0;
        if (temp->next->pid == pid) {
        	flag =1;
            temp->next = temp->next->next;
            kill(pid);
        } else {
            temp = temp->next;
        }
    }
    if(flag == 0){
		printf("no pid matched!\n");
	} 
	else{
		printf("deleted!\n");
	}
    return dummyHead->next;
}

bool kill(int pid){
	char * str1 = "taskkill /pid ";
	char * str2;
	str2 = toString(pid);
//	printf("%s",str2);
	char * shuzu = (char*)malloc(strlen(str1)+strlen(str2));
	strcpy(shuzu,str1);
	strcat(shuzu,str2);
//	for(int i =0 ;i< strlen(shuzu)+1;i++){
//		printf("%c",shuzu[i]);
//	}
	system(shuzu);
	return true;
}

char* toString(int iVal){
       /* �Ż���:
       *  1,��ͨ����ջ�ķ�ʽ,�������ջ,�����Ƕ��ַ�����������,ֱ��ͨ��ָ������,�ڴ濽����ʽ�������ս��
  7      */ 
       char str[1024] = {'\0',};
     char *pos = NULL;
      int sign = 0;   //���� ������ 0
  
     int abs = iVal;
  
      pos = str + 1023; //�ƶ�ָ��,ָ���ջ�ײ�
      *pos-- = '\0';  //end
 
      if(iVal < 0)
      {
          sign = 1;
          abs = -abs;
      }
      
      int dit = 0;
      while(abs > 0)
      {
          dit = abs % 10;
          abs = abs / 10;
  
          *pos-- = (char)('0' + dit); 
      }
  
      if(sign)
          *pos-- = '-';
  
      char *ret = (char*)malloc(1024 - (pos - str));
  
      if(iVal == 0)               //0��һ������
          strcpy(ret, "0");
      else                        //iVal��0�Ŀ���
          strcpy(ret, pos+1);
  
      return(ret);    
 }
 
 ListNode* addelement(ListNode* head,int pid,char* shuzu){
 	while(head->next != NULL){
 		head = head -> next;
	 }
	 ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	 head -> next = p;
	 p->pid = pid;
	 strcpy(p->name,shuzu);
	 system(p->name);
	 return head;
 }
