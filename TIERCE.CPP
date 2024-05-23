#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>

int c[10];
int s=0,a=0,i,j,k,l[10],n,r,choix,chev[10],cheval[4],chaine[10][100];
long int fric[4],pari[4];
int continu=1,posmax=0;
char nomj[4][20];
int nbcado[4];
int position[4];
char nom[10][20]={
	"Bourico         ","L'as des as     ","le Borgne       ",
	"la Grosse Chaude","Tonerre de feu  ","Feu au cul      ",
	"Bourinos        ","Bouflegazon     ","Courtoujours    ",
	"Poil de moquette"};

char logo[7][33]={"                            /",
		"ÄÄÂÄÄ ø ÚÄÄÄÄ ÚÄÄÄ¿ ÚÄÄÄÄ ÚÄÄÄÄ",
		"  ³   ³ ³     ³   ³ ³     ³    ",
		"  ³   ³ ÃÄÄÄ  ÃÄÄÂÙ ³     ÃÄÄÄ ",
		"  ³   ³ ³     ³   ³ ³     ³    ",
		"  ³   ³ ÀÄÄÄÄ ³   ³ ÀÄÄÄÄ ÀÄÄÄÄ",
		"                               "};

char terre[1][33]={"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²"};

void classer()
{
int j,temp;
for(j=0;j<n;j++) position[j]=j;

for(j=0;j<n-1;j++)
{
	for(k=j+1;k<n;k++)
	if (fric[position[k]] > fric[position[j]])
	{
	  temp = position[k];
	  position[k]= position[j];
	  position[j] = temp;
	}
}

}

void main()
{
clrscr();



textcolor(1+BLINK);
for (i=18;i<52;i++)
	{gotoxy(i,12);
	cprintf("Ä");
	gotoxy(i,14);
	cprintf("Ä");
	}
gotoxy(17,12);
cprintf("Ú");
gotoxy(17,14);
cprintf("À");
gotoxy(52,12);
cprintf("¿");
gotoxy(52,14);
cprintf("Ù");
gotoxy(17,13);
cprintf("³");

textcolor(15);
cprintf("  Tu veux du son (oui=1 non=0) :  ");

textcolor(1+BLINK);
cprintf("³");

textcolor(15);
gotoxy(50,13);
scanf("%d",&s);





choix=1;
textcolor(5);
clrscr();

textcolor(14);
gotoxy(50,1);cprintf(" É»");
gotoxy(50,2);cprintf("±ºº");
gotoxy(50,3);cprintf("±ºÈÍÍÍ» ÉÍÍÍÍ» É»  É» ÉÍÍÍÍ»");
gotoxy(50,4);cprintf("±ºÉÍÍ»º±ºÉÍÍ»º±ºº ±ºº±ºÉÍÍ»º");
gotoxy(50,5);cprintf("±ºÈÍÍ¼º±ºÈÍÍ¼º±ºÈÍÍ¼º±ºº ±ºº");
gotoxy(50,6);cprintf("±ÈÍÍÍÍ¼±ÈÍÍÍÍ¼±ÈÍÍÍÍ¼±È¼ ±È¼");
gotoxy(50,7);cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±");
gotoxy(50,8);cprintf("Copyright(C) 1997 El Bounito");

textcolor(15);
gotoxy(3,9);
cprintf("%s",terre);
for (j=0;j<7;j++)
	{if (s==1) sound((j+1)*200);
	delay(50);
	nosound();
	for (i=0;i<j+1;i++)
		{gotoxy(3,8-j+i);
		cprintf("%s",logo[i]);
		}
	delay(100);

	}


gotoxy(13,11);
textcolor(5+BLINK);
cprintf("Version 4.11");

fflush(stdin);

textcolor(15);
n=0;
while((n>=5)||(n<1))
	{
	textcolor(15);
	gotoxy(28,14);
	cprintf("Nombre de joueur (1-4): ");
	scanf("%d",&n);
	}

for (i=0;i<n;i++)
		{fric[i]=1000;
		pari[i]=0;
		cheval[i]=15;
		l[i]=0;
		nbcado[i]=0;

		gotoxy(22,16+(2*i));
		cprintf("Nom du joueur %d : ",i+1);
		scanf("%s",nomj[i]);
		}

//---------------------------------------------
while(choix)
{
clrscr();
textcolor(15);
for (i=1;i<80;i++) printf("Ä");
gotoxy(1,2);
printf("³");
printf("Statistiques :\n");

gotoxy(65,2);
printf("%c : premier",1);
gotoxy(65,3);
printf("%c : second",2);
gotoxy(65,4);
printf("%c : troisiŠme",3);

gotoxy(1,3);
for (j=0;j<10;j++)
	{
	printf("³");
	textcolor(j+1);
	cprintf("%d :",j);
	cprintf("%s :",nom[j]);
	for(i=0;i<l[j];i++)
		cprintf("%c",chaine[j][i]);
	printf("\n");
	}

for (i=1;i<80;i++)
	{gotoxy(i,13);printf("Ä");}
for (i=1;i<14;i++)
	{gotoxy(80,i);printf("³");}
gotoxy(1,1);
printf("Ú");
gotoxy(1,13);
printf("À");
gotoxy(80,1);
printf("¿");
gotoxy(80,13);
printf("Ù");

classer();

for (i=0;i<n;i++)
  {
  gotoxy(55,7+i);
  printf("%d : ",fric[position[i]]);
  printf("%s ",&nomj[position[i]]);
  if ((nbcado[position[i]]!=0) && (nbcado[position[i]]!=10))
    for(j=0;j<nbcado[position[i]];j++)
      printf("+");
  if (nbcado[position[i]]==10)
    {textcolor(15+BLINK);
    cprintf("%c",3);
    textcolor(15);}
  }

gotoxy(1,14);


for(i=0;i<n;i++)
	{
	for(j=0;j<20;j++)
		{
		textcolor(j);
		cprintf("-");
		delay(20);
		}
	textcolor(15);
	printf("> Fric de %s : %d F",&nomj[i],fric[i]);
	if (fric[i]==1) printf(" (Minable...)");
	if (fric[i]>=2000) printf(" (T'assures, toi !)");
	if (nbcado[i]==10)
	  {
	  printf(" (V'la 100f, grosse quiche)");
	  nbcado[i]=0;
	  }
	printf("\n");
	while((pari[i]<=0)||(pari[i]>fric[i]))
		{
		printf("Tu paries combien, %s ? : ",&nomj[i]);
		fflush(stdin);
		scanf("%d",&pari[i]);
		}
	while((cheval[i]>=10)||(cheval[i]<0))
		{
		printf("Sur quel cheval (0-9) ? : ");
		scanf("%d",&cheval[i]);
		fflush(stdin);
		}
	}
//---------------------------------------------------------------

clrscr();
textcolor(7);
for (i=1;i<22;i++)
	{
	gotoxy(70,i);
	cprintf("³");
	gotoxy(1,i);
	cprintf("³");
	gotoxy(80,i);
	cprintf("³");
	}
for (i=1;i<80;i++)
	{gotoxy(i,1);
	cprintf("Ä");
	gotoxy(i,22);
	cprintf("Ä");
	}
gotoxy(1,1);
cprintf("Ú");
gotoxy(1,22);
cprintf("À");
gotoxy(80,1);
cprintf("¿");
gotoxy(80,22);
cprintf("Ù");
for (i=0;i<10;i++)
	{
	gotoxy(2,2*i+2);
	textcolor(i+1);
	cprintf("%d",i);
	gotoxy(30,2*i+2);
	cprintf("%s",nom[i]);
	k=2;
	for (j=0;j<n;j++)
		if (i==cheval[j])
			{textcolor(15);
			gotoxy(71,2*i+k);
			cprintf("%s",nomj[j]);
			k++;}
	c[i]=5;
	}
textcolor(7);
for (i=0;i<10;i++)
	{
	gotoxy(2,2*i+3);
	cprintf("Ä");
	gotoxy(3,2*i+3);
	cprintf("´");
	gotoxy(3,2*i+2);
	cprintf("³");
	}
if (s==1) sound(600);
delay(400);
nosound();
delay(400);
for (i=0;i<10;i++) {gotoxy(3,2*i+2);
		    cprintf(" ");
		    gotoxy(4,2*i+2);
		    cprintf("/");}
if (s==1) sound(600);
delay(400);
nosound();
delay(400);
for (i=0;i<10;i++) {gotoxy(4,2*i+2);
		    cprintf(" ");
		    gotoxy(4,2*i+3);
		    cprintf("Ä");}
if (s==1) sound(1200);
delay(400);
nosound();
delay(400);
for (i=0;i<10;i++) {gotoxy(4,2*i+3);
		    cprintf("\\");}

textcolor(7);
gotoxy(1,23);
cprintf("Chevaux a l'arrivee :");

k=0;
continu=0;
randomize();
posmax=0;

while(continu<=2)
{
a++;
for (i=0;i<10;i++)
	{
	if (continu>2) break;
	if (c[i]!=100)
		{
		r=random(4);
		for (j=0;j<r+1;j++)
			{
			gotoxy(c[i],2*i+2);
			printf(" ");
			gotoxy(c[i],2*i+3);
			printf(" ");
			c[i]=c[i]+1;
			}
		gotoxy(c[i],2*i+2);
		textcolor(i+1);
		cprintf("ÖÜÜÊ");
		gotoxy(c[i],2*i+3);
		if((a%2)==0) cprintf("/  \\");
		else cprintf(" \\/");

		delay(40);
		if (c[i]>=posmax)
			{
			posmax=c[i];
			textcolor(i+1);
			gotoxy(23,23+continu);
			cprintf("ÛÛÛÛÛÛÛÛ %s en tˆte !",nom[i]);
			}
		if (c[i]>=70)
			{
			continu++;
			gotoxy(23,22+continu);
			textcolor(i+1);

			cprintf("ÛÛ %d ÛÛ %s           ",continu,nom[i]);

			c[i]=100;
			chev[k]=i;
			k++;
			if (s==1) sound(900);
			delay(300);
			nosound();
			chaine[i][l[i]]=continu;
			l[i]++;
			posmax=0;
			}
		}
	}
	if (s==1) sound(50);
	delay(10);
	nosound();
	delay(30);
	if (s==1) sound(50);
	delay(10);
	nosound();
}



textcolor(15);
gotoxy(6,3);
	for (j=0;j<n;j++)
		{
		gotoxy(6,3+(j*2));
		if (chev[0]==cheval[j])
			{
			cprintf("\nSuper %s, tu remportes %d F !",nomj[j],10*pari[j]);
			fric[j]=fric[j]+(10*pari[j]);
			if (nbcado[j]==3)
			  cprintf(" (Dommage pour ton cado!)");
			nbcado[j]=0;
			}
		else
		if (chev[1]==cheval[j])
			{
			cprintf("\nBien jou‚ %s, tu as gagn‚ %d F !",nomj[j],6*pari[j]);
			fric[j]=fric[j]+(6*pari[j]);
			if (nbcado[j]==3)
			  cprintf(" (Dommage pour ton cado!)");
			nbcado[j]=0;
			}
		else
		if (chev[2]==cheval[j])
			{
			cprintf("\nPas mal %s, tu empoches %d F !",nomj[j],3*pari[j]);
			fric[j]=fric[j]+(3*pari[j]);
			if (nbcado[j]==3)
			  cprintf(" (Dommage pour ton cado!)");
			nbcado[j]=0;
			}
		else
		  if (pari[j]>=1000)
		    cprintf("\nPas de chance %s, tu perds %d F !\n",nomj[j],pari[j]);
		}



textcolor(15);
for (i=16;i<48;i++)
	{gotoxy(i,12);
	cprintf("Ä");
	gotoxy(i,14);
	cprintf("Ä");
	}
	gotoxy(15,12);
	cprintf("Ú");
	gotoxy(15,14);
	cprintf("À");
	gotoxy(48,12);
	cprintf("¿");
	gotoxy(48,14);
	cprintf("Ù");
	gotoxy(15,13);
	cprintf("³ Continuer(1) ou Quitter(0) :   ³");
	gotoxy(45,13);
	scanf("%d",&choix);


for (i=0;i<n;i++)
	{
	fric[i]=fric[i]-pari[i];
	if (fric[i]<=0)
	  {
	  fric[i]=1;
	  nbcado[i]++;
	  if (nbcado[i]>=4)
	    {
	    fric[i]=100;
	    nbcado[i]=10;
	    }
	  }
	pari[i]=fric[i]+1;
	cheval[i]=13;
	}



}
clrscr();
cprintf("\n             Merci d'avoir jou‚ … TIERCE, Bonne Journ‚e !");
delay(2000);
}





