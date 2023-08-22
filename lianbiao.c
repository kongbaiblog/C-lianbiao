#include <stdio.h>
#include <stdlib.h>
int len; //������
struct student{
	char name[30];
	float number;
	struct student *pNext;
};
/*����*/ 
struct student *create(){
	struct student *pHead=NULL;
	struct student *pNew,*pEnd;
	pNew=pEnd=(struct student*)malloc(sizeof(struct student));
	printf("���� ѧ�ţ�");
	scanf("%s %f",&pNew->name,&pNew->number);
	while(pNew->number!=0){
		len++;
		if(len==1){
			pNew->pNext=NULL;
			pEnd=pNew;
			pHead=pNew;
		}
		else{
			pNew->pNext=NULL;
			pEnd->pNext=pNew;
			pEnd=pNew;
		}
		pNew=(struct student*)malloc(sizeof(struct student));
		scanf("%s %f",&pNew->name,&pNew->number);
	}
	free(pNew);
	return pHead;
}
/*ͷ������*/
struct student *addah(struct student *pHead){
	struct student *pNew,*tep;
	pNew=(struct student*)malloc(sizeof(struct student));
	printf("���� ѧ�ţ�");
	scanf("%s %f",&pNew->name,&pNew->number);
	pNew->pNext=pHead->pNext;
	pHead->pNext=pNew;
	len+=1;
	return pHead;
}
/*�����β*/ 
struct student *addend(struct student *pHead){
	struct student *tep,*pNew;
	pNew=(struct student*)malloc(sizeof(struct student));
	tep=pHead;
	printf("���� ѧ�ţ�");
	scanf("%s %f",&pNew->name,&pNew->number);
	pNew->pNext=NULL;
	while(tep->pNext!=NULL){
		tep=tep->pNext;
	}
	tep->pNext=pNew;
	len+=1;
	return pHead;
}
/*ָ��λ��ɾ��*/ 
struct student *del(struct student *pHead){
	struct student *before,*next,*search;
	char data_name[30];
	float data_number;
	int lead,i=2;
	before=pHead;
	search=pHead->pNext;
	next=search->pNext;
	printf("����Ҫɾ����λ�ã�");
	scanf("%d",&lead);
	while(1){
		if(lead==1){
			len--;
			return search;
		}
		if(i==lead){
			before->pNext=next;
			free(search);
			break;
		}
		i++;
		before=before->pNext;
		search=search->pNext;
		next=next->pNext;
	}
	len--;
	return pHead;
}
/*ָ��λ�ü���*/ 
struct student *addlocation(struct student *pHead){
	struct student *pBefore,*p,*pNew;
	p=pHead->pNext;
	pBefore=pHead;
	int location,n=2;
	pNew=(struct student*)malloc(sizeof(struct student));
	printf("���� ѧ�ţ�");
	scanf("%s %f",&pNew->name,&pNew->number);
	printf("Ҫ�����λ�ã�");
	scanf("%d",&location);
	if(location==1){
		pNew->pNext=pHead;
		len+=1;
		return pNew;
	}
	if(location==(len+1)){
		while(p->pNext!=NULL){
			p=p->pNext;
		}
		pNew->pNext=NULL;
		p->pNext=pNew;
		len+=1;
		return pHead;
	}
	else{
		while(n!=location){
			n++;
			p=p->pNext;
			pBefore=pBefore->pNext;
		}
		pNew->pNext=p;
		pBefore->pNext=pNew;
		len+=1;
		return pHead;
	}
}
/*����*/ 
void print(struct student *pHead){
	struct student *tep;
	int i=1;
	tep=pHead;
	printf("----------��%d����Ա----------\n",len);
	while(tep!=NULL){
		printf("No.%d����:%s\n",i,tep->name);
		printf("ѧ��:%g\n\n",tep->number);
		i++;
		tep=tep->pNext;
	}
	printf("\n\n");
}
int main(){
	struct student *pHead;
	pHead=create();
	print(pHead);
	pHead=addah(pHead);
	print(pHead);
	pHead=addend(pHead);
	print(pHead);
	pHead=addlocation(pHead);
	print(pHead);
	pHead=del(pHead);
	print(pHead);
}
