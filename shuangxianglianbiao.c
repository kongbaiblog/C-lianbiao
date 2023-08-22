#include <stdio.h>
#include <stdlib.h>

struct List{
	char Nam[30];
	float Num;
	struct List *pNext,*pLast;
};

int len=0;

struct List *Create (struct List *pHead){
	struct List *pNew,*pEnd;
	pNew=(struct List*)malloc(sizeof(struct List));
	printf("�������� ѧ�ţ�");
	scanf("%s %f",&pNew->Nam,&pNew->Num);
	pHead=pNew;
	len+=1;
	while (pNew->Num!=0){
		if (len==1){
			pEnd=pNew;
			pNew->pNext=NULL;
			pNew->pLast=NULL;
		}
		else{
			pNew->pLast=pEnd;
			pEnd->pNext=pNew;
			pEnd=pEnd->pNext;
			pNew->pNext=NULL;
		}
		pNew=(struct List*)malloc(sizeof(struct List));
		printf("�������� ѧ�ţ�");
		scanf("%s %f",&pNew->Nam,&pNew->Num);
		len+=1;
	}
	len-=1;
	free(pNew);
	return pHead;
}

void Print(struct List *pHead){
	struct List *pA,*pB;
	pA=pHead;
	printf("\n\n\n�������\n\n----------��%d����Ա---------\n",len);
	while (pA!=NULL){
		printf("������%s\nѧ�ţ�%g\n\n",pA->Nam,pA->Num);
		if(pA->pNext==NULL){
			pB=pA;
		}
		pA=pA->pNext;
	}
	printf("\n\n\n�������\n\n----------��%d����Ա---------\n",len);
	while (pB->pLast!=NULL){
		printf("������%s\nѧ�ţ�%g\n\n",pB->Nam,pB->Num);
		pB=pB->pLast;
	}
	printf("������%s\nѧ�ţ�%g\n\n",pB->Nam,pB->Num);
}

int main(){
	struct List *pHead;
	pHead=Create(pHead);
	Print(pHead);
}
