#include <stdio.h>
#include <stdlib.h>

 struct node
{
	char kelime[30];
    int adet;
    struct node *next;
};

struct node *ilk=NULL, *son=NULL ;

void BasaEkle(char kelimee[30],int veri)
{
    struct node *yeni = (struct node*) malloc(sizeof(struct node));
    yeni->adet=veri;
    int i;
    for(i=0;kelimee[i]!=NULL;i++)
    yeni->kelime[i]=kelimee[i];

    if(ilk==NULL)
    {
        ilk=yeni;
        son=yeni;
        son->next=NULL;
    }
    else
    {
        yeni->next=ilk;
        ilk=yeni;
    }
}

void ArayaEkle(char kelimee[30],int veri)
{
	struct node *yeni = (struct node*) malloc(sizeof(struct node));
	struct node *konum = (struct node*) malloc(sizeof(struct node));
	konum=ilk;
	yeni->adet=veri;
	int i;
    for(i=0;kelimee[i]!=NULL;i++)
    yeni->kelime[i]=kelimee[i];
	
	while(konum->next->adet>veri)
	{
	
		konum=konum->next;
	}
	
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp=konum->next;
	konum->next=yeni;
	yeni->next=temp;
	
}

void SonaEkle(char kelimee[30],int veri)
{
    struct node *yeni = (struct node*) malloc(sizeof(struct node));
    yeni->adet=veri;
    int i;
    for(i=0;kelimee[i]!=NULL;i++)
    yeni->kelime[i]=kelimee[i];
    if(ilk==NULL)
    {
        ilk=yeni;
        son=yeni;
        son->next=NULL;
    }
    else
    {
        son->next=yeni;
        son=yeni;
        son->next=NULL;
    }
}

void Listele(struct node *node)
{
	while(node!=NULL)
	{
		printf("%s %d\n",node->kelime,node->adet);
		node=node->next;
	}
}

int *varMi(char kelimee[30])
{
    struct node *ara=ilk;

    while(ara!=NULL)
    {
        if(strcmp(ara->kelime,kelimee)==0)
            return 1;
        ara=ara->next;
    }
    return 0;
}
	
int main() {
   


FILE *dosya=fopen("test.txt","r");

    
    char kelime[30];
    char kelime2[30];
    int ftelll=0;
    int feoff=0;


int i,j;
	if((dosya = fopen("test.txt","r"))!= NULL)
   {
   	    
        	for(i=0;i<100;i++)
        {
        
        		
   			fscanf(dosya,"%s",&kelime);
   			if(feof(dosya)) feoff=1;
   			strlwr(kelime);
   	   	    ftelll=ftell(dosya);
   	   	    rewind(dosya);
   	   	    int veri=0;
   	   	    for( j=0;j<100;j++){
   	   	     	fscanf(dosya,"%s",&kelime2);
   			  	strlwr(kelime2);
   			    if(strcmp(kelime,kelime2)==0){				  
   			    	veri++;
				
				}
				 	   	     	
   	   	    if(feof(dosya)) break;
			}
			
			if(varMi(kelime)==0)
			{
				if(son==NULL)
				SonaEkle(kelime,veri);
				else {
				
				
				if(veri<=son->adet)
				SonaEkle(kelime,veri);
				
			    if(veri>=ilk->adet)
				BasaEkle(kelime,veri);
				
				if(ilk->adet>veri && veri>son->adet)
				ArayaEkle(kelime,veri);
				}
			}
			
			
			rewind(dosya);
   	   	    fseek(dosya,ftelll,SEEK_CUR);
   	   	    if(feoff==1) break;
		}
        	
     }
           

	

	else printf("dosya yok");
	
	printf("-----------------\n");
	
	
	
	
Listele(ilk);
	

       fclose(dosya);

}
