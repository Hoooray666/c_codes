#include <iostream>
using namespace std; 
class node{
 public:
 int data;
 node *next;
};

node* input()
{
 node* head=NULL;
 node* tail;
 cout<<"����������";
 int x;
 cin>>x;
 while(x!=-1)
 {
  node* p=new node;
  p->data=x;
  p->next=NULL;
  if(head == NULL)
   head=p;//����p�ڵ���head 
  else
   tail->next=p;
  tail=p;
  cin>>x;  
 }
 return head; 
}
void output(node* head)
{
 node *p=new node;
 p=head;
 if(p==NULL)
 cout<<"����Ϊ��"<<endl; 
 while(p!=NULL)
 {
  cout<<p->data<<endl;
  p=p->next;
 }
 delete p;
}
int getlength(node* head)
{
 node* p; int i;
 p=head;
 if(p==NULL)
 return 0;
 i=0;
 while(p!=NULL)
 {
  i++;
  p=p->next;
 }
 return i;
}
int getvalue(node* head,int index)//������ŵ������� 
{
 int len;
 len=getlength(head);
 node *p=head;
 if(index>len&&len==0)
 return 0;
 for(int i=1;i<index;i++)
 p=p->next;
 return p->data; 
}
int indexof(node *head,int thedata)
{
 node *p=new node;
 p=head;
 int index=1;
 while(p!=NULL&&p->data!=thedata)
 {
  p=p->next;
  index++;
 }
 if(p==NULL)
     return -1;
 else
     return index;
} 
int main()
{
    node* L;int len,value,n1,n2;
    L=input();
    output(L);
    len=getlength(L);
    value=getvalue(L,n1);
    cout<<"�����ȣ�"<<len<<endl;
    cout<<"����Ҫ���ҵ���ţ�"; 
    cin>>n1;
    /*cout<<"�������֣�"<<value<<endl; 
    n2=indexof(L,5);
    cout<<"���ҵ���ţ�"<<n2;*/
}
