#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max_contact 1000
#define max_name 50
#define max_img 40
#define max_phone 12
#define max_email 40

int n;

struct phone_number{
	char data[max_phone];
	struct phone_number *next;
};

struct email{
	char data[max_email];
	struct email *next;
};


struct contact{
	char name[max_name];
	char img[max_img];
	struct phone_number *T; 
	struct email *E;
};
typedef struct contact contact;
 
struct node{
	contact *data;
	struct node *next;
};

void print_data(contact *x){
	printf("\n\nHo ten : %s ",x->name);
	printf("\nDuong dan anh : %s ",x->img);
	
	printf("\nSo dien thoai : ");
	phone_number *tmp = (phone_number*)malloc(sizeof(phone_number));
	if(x->T->next == NULL)		printf("Ko co so dien thoai");
	else{
		tmp = x->T;
		while(tmp != NULL){
			if(strcmp(tmp->data,"\n") == 0 || strcmp(tmp->data,"") == 0){
				tmp = tmp->next;
				continue;
			}	
			printf("\n  %s",tmp->data);
			tmp = tmp->next;
		}
	}
	
	printf("\nEmail : ");
	email *tmp2 = (email*)malloc(sizeof(email));
	if(x->E->next ==NULL)		printf("Ko co email\n");
	else{
		tmp2 = x->E;
		while(tmp2 != NULL){
			if(strcmp(tmp2->data,"\n") == 0 || strcmp(tmp2->data,"") == 0){
				tmp2 = tmp2->next;
				continue;
			}
			printf("\n  %s",tmp2->data);
			tmp2 = tmp2->next;
		}
		printf("\n");
	}
	
}

node *make_node(contact *x){
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = x;
	new_node->next = NULL;
	return new_node;
}

void duyet(node *head){
	printf("Danh ba hien tai");
	while(head != NULL){
		print_data(head->data);
		head = head->next;	
	}
}

void push_front(node **head,contact *x){
	node *new_node = make_node(x);
	new_node->next = (*head);
	(*head) = new_node;
}

phone_number *make_phone_number(char P[]){
	phone_number *new_phone_number = (phone_number*)malloc(sizeof(phone_number));
	strcpy(new_phone_number->data,P);
	new_phone_number->next = NULL;
	return new_phone_number;
}

email *make_email(char E[]){
	email *new_email = (email*)malloc(sizeof(email));
	strcpy(new_email->data,E);
	new_email->next = NULL;
	return new_email;
}

void push_front_phone_number(phone_number **head,char P[]){
	if(*head == NULL){
		strcpy((*head)->data,P);
	}
	else{
		phone_number *new_phone = make_phone_number(P);
		new_phone->next = (*head);
		(*head) = new_phone;
	}
}

void push_front_email(email **head, char E[]){
	email *new_email = make_email(E);
	new_email->next = (*head);
	(*head) = new_email;
}

void find_name_in_address_book(node *head){
	char s[max_name];
	int count = 0;
	printf("\nNhap ten can tim : ");
	fflush(stdin);
	gets(s);
	while(head != NULL){
		if(strstr(head->data->name,s) != NULL){
			count++;
			printf("TT nguoi duoc tim la :");
			printf("\n%d) ",count);
			print_data(head->data);
		}
		head = head->next;
	}
}

int find_phone_number(node *head,char s[]){
	if(strcmp(s,"") == 0 || strcmp(s,"\n") == 0){
		return 0;
	}
	node *tmp = head;
	while(tmp != NULL){
		phone_number *tmp2 = tmp->data->T;
		while(tmp2 != NULL){
			
			if(strcmp(tmp2->data,s) == 0){
				printf("Chu so dien thoai la : %s",tmp->data->name);
				return 1;
			}
			tmp2 = tmp2->next ;
		}
		tmp = tmp->next;
	}
	return 0;
}

int find_email(node *head,char s[]){
	if(strcmp(s,"") == 0 || strcmp(s,"\n") == 0){
		return 0;
	}
	node *tmp = head;
	while(tmp != NULL){
		email *tmp2 = tmp->data->E;
		while(tmp2 != NULL){
			
			if(strcmp(tmp2->data,s) == 0){
				printf("Chu tai khoan email la : %s",tmp->data->name);
				return 1;
			}
			tmp2 = tmp2->next ;
		}
		tmp = tmp->next;
	}
	return 0;
}


int delete_contact(node **head,char s[]){
	if(strcmp((*head)->data->name,s) == 0){
//		printf("Xoa nguoi dau tien ");
		(*head) = (*head)->next;
	}
	
	else{
		node *truoc = *head;
		node *sau = *head;
		while(strcmp(truoc->data->name,s)){
			sau = truoc;
			truoc = truoc->next;
			if(truoc == NULL){
				printf("\nKhong tim thay");
				return 0;
			}
		}
		sau->next = truoc->next;
		free(truoc);
	}
	return 1;
}

void delete_phone_number(node **head){
	char s_phone[max_phone];
	printf("Nhap sdt can xoa : ");
	fflush(stdin);
	fgets(s_phone,sizeof(s_phone),stdin);
	
	node *tmp = *head;
	while(tmp != NULL){
		phone_number *tmp2 = tmp->data->T;
//		Tuong la xoa ki tu dau nhung thuc chat no la ""
		if(strcmp(tmp2->data,s_phone) == 0){
			tmp2 = tmp2->next;
		}
//		Day moi bat dau la xoa thuc su
		else{
			int flag = 1;
			phone_number *truoc = tmp2;
			phone_number *sau = tmp2;
			while(strcmp(truoc->data,s_phone) != 0){
				sau = truoc;
				truoc = truoc->next;
				if(truoc == NULL){
					flag = 0;
					break;
				}
			}
			if(flag){
				sau->next = truoc->next;
				free(truoc);
				printf("Da xoa SDT nguoi dung %s",tmp->data->name);				
				if(tmp2->next == NULL ){
					printf("Da xoa thong tin nguoi dung %s",tmp->data->name);
					n--;
					delete_contact(&(*head),tmp->data->name);
					return;				
				}
			}		
		}
		tmp = tmp->next;
	}
}

void suaTT(node **head){
	char s[max_name];
	printf("Nhap ten nguoi can sua : ");
	fflush(stdin);
	fgets(s,sizeof(s),stdin);
	
	node *tmp = *head;
	node *tmp2 = *head;

	while(tmp!= NULL){
		if(strcmp(tmp->data->name,s) == 0){
			printf("Ban can sua : ");
			printf("\n1. img");
			printf("\n2.SDT ");
			printf("\n3.email ");
			int chon;
			printf("\nNhap lua chon : ");
			scanf("%d",&chon);
			if(chon == 1){
				char s1[max_img];
				printf("Nhap lai duong dan img : ");
				fflush(stdin);
				fgets(s1,sizeof(s1),stdin);
				strcpy(tmp->data->img,s1); 
			}
			else if(chon == 2){
				char s1[max_phone];
				printf("Nhap SDT : ");
				fflush(stdin);
				fgets(s1,sizeof(s1),stdin);
				if(strcmp(s1,"") == 0 || strcmp(s1,"\n") == 0)		return;
				int t = find_phone_number(tmp2,s1);
				if(t == 1){
					printf("Da ton tai so dien thoai nay");
				}
				else{
					push_front_phone_number(&tmp->data->T,s1);
				}
				
			}
			else if(chon == 3){
				char s1[max_email];
				printf("Nhap email : ");
				fflush(stdin);
				fgets(s1,sizeof(s1),stdin);
				if(strcmp(s1,"") == 0 || strcmp(s1,"\n") == 0)		return;
				int t = find_email(tmp2,s1);
				if(t == 1){
					printf("Da ton tai email nay");
				}
				else{
					push_front_email(&tmp->data->E,s1);
				}
				
			}
			return;
		}
		tmp = tmp->next;
	}
}

void write_inf(node **head){
	
	contact *x = (contact*)malloc(sizeof(contact));
	int phone_nums = 1, email_nums = 1;
	
	x->T = (phone_number*)malloc(sizeof(phone_number));
	x->T->next = NULL;
		
	x->E = (email*)malloc(sizeof(email));
	x->E->next = NULL;
		
	printf("Nhap ten nguoi dung : ");
	fflush(stdin);
	fgets(x->name,sizeof(x->name),stdin);  // sau doi thanh fgets
	if(strcmp(x->name,"") == 0 || strcmp(x->name,"\n") == 0){
		printf("Nhap khong hop le");
		return;
	}
	
	printf("Nhap duong dan anh : ");
	fflush(stdin);
	fgets(x->img,sizeof(x->img),stdin);  // sau doi thanh fgets
	
	printf("Nhap so dien thoai : \n");	
	while(1){
		printf("Nhap so dien thoai thu %d :  ",phone_nums);
		fflush(stdin);
		fgets(x->T->data,sizeof(x->T->data),stdin);
		if(strcmp(x->T->data,"") == 0 || strcmp(x->T->data,"\n") == 0)		break;
		if(find_phone_number(*head,x->T->data) == 1){
			printf("So dien thoai nay da ton tai\n");
			continue;
		}
//		if(strcmp(x->T->data,"\n") == 0)	break;
		push_front_phone_number(&x->T,x->T->data);
		phone_nums++;
	}
		
	printf("Nhap email : \n");	
	while(1){
		printf("Nhap email thu %d :  ",email_nums);
		fflush(stdin);
		fgets(x->E->data,sizeof(x->E->data),stdin);
		if(strcmp(x->E->data,"\n") == 0)	break;
		push_front_email(&x->E,x->E->data);
		email_nums++;
	}
	push_front(&(*head),x);
	
	n++;
}

void write_file(node *head){
	FILE *f;
	f = fopen("danhba.txt","w");
	
	if((f = fopen("danhba.txt","w")) == NULL){
		printf("Khong mo duoc tep");
	}
	else {
		fprintf(f,"%d\n",n);
		while(n--){
			int phone_nums = 1, email_nums = 1;
			
			fprintf(f,"%s",head->data->name);

			fprintf(f,"Img: %s",head->data->img);	
			while(head->data->T != NULL){
				if(strcmp(head->data->T->data,"") == 0 || strcmp(head->data->T->data,"\n") == 0){
					head->data->T = head->data->T->next;
					continue;
				}
				fprintf(f,"T%d:%s",phone_nums,head->data->T->data);
				head->data->T = head->data->T->next;
				phone_nums++;
			}
			if(head->data->E->next != NULL){
				while(head->data->E != NULL){
					if(strcmp(head->data->E->data,"") == 0 || strcmp(head->data->E->data,"\n") == 0){
						head->data->E = head->data->E->next;
						continue;
					}	
					fprintf(f,"E%d:%s",email_nums,head->data->E->data);
					head->data->E = head->data->E->next;
					email_nums++;
				}			
			} 
		head = head->next;
		}
		fprintf(f,"\n");
		fclose(f);
		printf("\nLuu thong tin vao file thanh cong");
	}
} 

int main(){
	int m;
	node *head = NULL;
	
	FILE *f;
	if((f = fopen("danhba.txt","r+")) == NULL){
		printf("Khong mo duoc tep");
		return 1;
	}

	fscanf(f,"%d",&n);
	m = n;
	fgetc(f);
//	printf("n la %d",n);
	
	while(m!= 0){
		contact *x = (contact*)malloc(sizeof(contact));
		int phone_nums = 1, email_nums = 1;
		
		x->T = (phone_number*)malloc(sizeof(phone_number));
		x->T->next = NULL;
		
		x->E = (email*)malloc(sizeof(email));
		x->E->next = NULL;
//		Nhap ten
		fgets(x->name,sizeof(x->name),f);
		
//		Nhap duong dan anh
		fseek(f,5,SEEK_CUR);
		fgets(x->img,sizeof(x->img),f);
		
		while(1){
			char c,d,e;
			fscanf(f,"%c",&c);
			getc(f);
			fscanf(f,"%c",&d);
			getc(f);
			
			if(c == 'T' && d ==':'){
				fseek(f,-1,SEEK_CUR);
				fgets(x->T->data,sizeof(x->T->data),f);
				push_front_phone_number(&x->T,x->T->data);
				strcpy(x->T->data,"");//cho nay de reset nut head cua Phone_number
			}	
			else if(c == 'E' && d == ':'){
				fseek(f,-1,SEEK_CUR);
				fgets(x->E->data,sizeof(x->E->data),f);
				push_front_email(&x->E,x->E->data);
				strcpy(x->E->data,"");//cho nay de reset nut head cua email
			}	
			else	break;
		}
		fseek(f,-4,SEEK_CUR);		
		
		push_front(&head,x);
		
		m--;
	}
	
	while(1){
		printf("\n\n***-------------MENU-------------***");
		printf("\n1.Doc danh ba hien tai : ");
		printf("\n2.Nhap them thong tin : ");
		printf("\n3.Tim kiem thong tin 1 nguoi trong danh ba : ");
		printf("\n4.Tra cuu thong tin 1 SDT : ");
		printf("\n5.Cap nhap lai SDT, anh dai dien hoac thong tin : ");
		printf("\n6.Xoa 1 nguoi khoi danh ba");
		printf("\n7.Xoa 1 SDT khoi danh ba");
		printf("\n9. Kiem tra email da ton tai ");
		printf("\n8.Exit");
		
		int choice;
		printf("\nLua chon : ");
		scanf("%d",&choice);
		
		if(choice == 1){
			printf("So luong contact hien tai la : %d \n",n);
			duyet(head);
		}
		else if(choice == 2){
			write_inf(&head);
		}
		else if(choice == 3){
			find_name_in_address_book(head);
		}
		else if(choice == 4){
			char s[max_phone];
			printf("\nNhap SDT can tim : ");
			fflush(stdin);
			fgets(s,sizeof(s),stdin);			
			if(find_phone_number(head,s) == 0){
				printf("Khong ton tai SDT nay\n");
			};
		}
		else if(choice == 5){
			suaTT(&head);
		}
		else if(choice == 6){
			char s[max_name];
			printf("Nhap ten nguoi can xoa : ");
			fflush(stdin);
			fgets(s,sizeof(s),stdin);
			if(delete_contact(&head,s) == 1)	n--;
		}
		else if(choice == 7){
			delete_phone_number(&head);
		}
		else if(choice == 8){
			break;
		}
		else if(choice == 9){
			char s[max_email];
			printf("\nNhap email can tim : ");
			fflush(stdin);
			fgets(s,sizeof(s),stdin);			
			if(find_email(head,s) == 0){
				printf("Khong ton tai email nay\n");
			};
		}
		else{
			printf("Lua chon cua ban ko hop le, Nhap lai ");
		}
		
	}
	fclose(f);
	
	write_file(head);
	return 0;
}

/* Con 1 so bug
1) Ten "Anh" bi mat ky tu
2) ham delete_phone_number chua chac dung : SDT dau tien la "",can fix bug cho if() dau tien

*/

