#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h> 
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

struct point{
	int x, y;
};
enum {black,blue,green,cyan,red,purple,brown,lightgray,
	darkgray,lightblue,lightgreen,lightcyan,lightred,lightpurple,yellow,white};
	
int cnt=0;	
int ary[28][28]={0};	
	
void setcolor(int forground,int background){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),forground|(background*16));
}
void gotoxy(int x, int y){ // x,y��ǥ �� �� 
	COORD Pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
 } 
void cursordraw(int x, int y){ // x,y��ǥ �� �� 
	gotoxy(x,y);
	setcolor(0,6); 
	if(ary[y+5][x/2+5]==0)
		{
		if(x==0&&y==0)
		    printf("�� ");
		else if(x==36&&y==0)
			printf("�� ");
		else if(x==36&&y==0)
			printf("�� "); 		
		else if(x==36&&y==18)
			printf("�� "); 
		else if(y==0)
		    printf("�� ");
		else if(y==18)
		    printf("�� ");
		else if(x==0)
		    printf("�� ");
		else if(x==36)
		    printf("�� ");
		else 
			printf("�� ");
		}
	else if(ary[y+5][x/2+5]==1){
		setcolor(0,6);
		printf("��");
	}
	else {
		setcolor(15,6);
		printf("��");
	}
		return;
 } 
 
int keypress(){
	char temp=getch();
		if(temp==27){
		setcolor(0,0);
		system("cls");
		setcolor(15,0);
		gotoxy(22, 10);
		printf("������ ����Ǿ����ϴ�.");
		gotoxy(0,19); 
		Sleep(500);
		exit(0);
		}
		else if(temp=='A' || temp=='a'){
			return LEFT;
		}
		else if(temp=='S' || temp=='s'){
			return DOWN;
		}
		else if(temp=='w'|| temp=='W'){
			return UP;
		}
		else if(temp=='d'|| temp =='D'){
			return RIGHT;
		}
		else if(temp ==' '){
			return SUBMIT;
		}
}
void showinfo(){
	system("cls");
	printf("\n                           <���۹��>\n\n\n\n");
	printf("      �� ������ ��:W, �Ʒ�:D, ��: A, ����: D,  SpaceBar �Դϴ�.\n");
	printf("\n                  �� ������ ȭ��ǥ�� ����Ű �Դϴ�.\n\n\n\n\n\n");
	printf("             [�����̽��ٸ� ������ ���� �����մϴ�]");
	while(1){
		int n=keypress();
		if(n==SUBMIT)
		return;
	}
}
void init(){
	system("mode con cols=65 lines=22| title �������");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle , &ConsoleCursor);
}
void drawmap() {
	int i,j;
	system("cls");
	gotoxy(0,0);
	setcolor(0,6);
    for(i=5; i<=23; i++) 
	{ 
    	for(j=5; j<=23; j++){
    		if(i==5&&j==5)
    		printf("�� ");
			else if(i==5&&j==23)
			printf("�� ");
			else if(i==23&&j==5)
			printf("�� "); 
			else if(i==23&&j==23)
			printf("�� "); 
    		else if(i==5)
    		printf("�� ");
			else if(i==23)
    		printf("�� ");
    		else if(j==5)
    		printf("�� ");
			else if(j==23)
    		printf("�� ");
    		else 
			printf("�� ");
		}
		printf("\n");	
	}
	setcolor(15,0);
	gotoxy(0,20);
	printf("_________________________________________________________________");
	gotoxy(48,21);
	printf(":ESC�� ���� ����");
}
int check(int m, int n ){ // x,y��ǥ �� �� 
	int i;
	int y=m/2+5;
	int x=n+5;
	for(i=0; i<5; i++)
	{
		if(ary[x-4+i][y]==ary[x-3+i][y] && ary[x-3+i][y]==ary[x-2+i][y] && ary[x-2+i][y]==ary[x-1+i][y] && ary[x-1+i][y]==ary[x+i][y] && ary[x][y]!=0)
			return 1;
		if(ary[x][y-4+i]==ary[x][y-3+i] &&ary[x][y-3+i]==ary[x][y-2+i] &&ary[x][y-2+i]==ary[x][y-1+i] &&ary[x][y-1+i]==ary[x][y+i] &&ary[x][y]!=0)
			return 1;
		if(ary[x-4+i][y-4+i]==ary[x-3+i][y-3+i] &&ary[x-3+i][y-3+i]==ary[x-2+i][y-2+i] )
		if(ary[x-2+i][y-2+i]==ary[x-1+i][y-1+i] &&ary[x+i-1][y+i-1]==ary[x+i][y+i] && ary[x][y]!=0)
			return 1;
		if(ary[x-4+i][y+4-i]==ary[x-3+i][y+3-i] &&ary[x-3+i][y+3-i]==ary[x-2+i][y+2-i] &&ary[x-2+i][y+2-i]==ary[x-1+i][y+1-i] )
		if(ary[x-1+i][y+1-i]==ary[x+i][y-i] &&ary[x][y]!=0)
			return 1;
	}
	return 0;
}
void playing(){
	int x=18, y=8,i;
	int t=0;
	gotoxy(x,y);
	setcolor(4,6); 
	printf("��");
	while(1){
		if(t==1){
			if(cnt%2==1){
				gotoxy(40,5);
				printf("::�浹�� �̰���ϴ�::");
				return; 
			}
			else{
				gotoxy(40,5);
				printf("::�鵹�� �̰���ϴ�::");
				return; 
			}
		}
		int n=keypress();
		switch(n){
			case UP:
			{
				if(y>0)
				{
					cursordraw(x,y);
					gotoxy(x,--y);
					setcolor(4,6);
					printf("��");
				
				}
				break;
			}
			case DOWN:
			{
				if(y<18)
				{
					cursordraw(x,y); 
					gotoxy(x,++y);
					setcolor(4,6);
					printf("��");
				}
				break;
			}
			case LEFT:
			{
				if(x>=2)
				{
					cursordraw(x,y);
					gotoxy(x-=2,y);
					setcolor(4,6);
					printf("��");
				}
				break;
			}
			case RIGHT:
			{
				if(x<36)
				{
					cursordraw(x,y);
					gotoxy(x+=2,y);
					setcolor(4,6);
					printf("��");
				}
				break;
			}
			case SUBMIT:
			{
				if(x%2==0 && x<=36 && y<=18)
				{ 
					if(ary[y+5][x/2+5]==0)
					{
						cnt++; 
						if(cnt%2==1) // �浹 �� �� 
						{
							setcolor(0,6);
							gotoxy(x,y);
							printf("��");
							gotoxy(43,8);
							setcolor(15,0);
							printf("�鵹 �����Դϴ�"); 
							gotoxy(x,y);
							ary[y+5][x/2+5]=1;
							t=check(x,y);
						}
						else // �鵹 ���� 
						{
							setcolor(15,6);
							gotoxy(x,y); 
							printf("��");
							gotoxy(43,8);
							setcolor(15,0);
							printf("�浹 �����Դϴ�");
							gotoxy(x,y);
							ary[y+5][x/2+5]=2;
							t=check(x,y);
						}
					}
					else
					{
						gotoxy(40,7);
						setcolor(15,0);
						printf("�̹� ���� �ֽ��ϴ�.");
						Sleep(500);
						gotoxy(40,7);
						printf("                   ");
					}
				}
				break;
			}

			if(cnt%2==1) // �浹 �� �� 
			{ 
				gotoxy(43,8);
				setcolor(15,0);
				printf("�鵹 �����Դϴ�"); 
				gotoxy(x,y);
			}
			else // �鵹 ���� 
			{
				gotoxy(43,8);
				setcolor(15,0);
				printf("�浹 �����Դϴ�");
				gotoxy(x,y);	
			}
		}
	}	 
}
int main(){
	init();	
	showinfo();
	while(1){
	cnt=0;
	for(int i=1; i<=27; i++){  
		for(int j=1; j<=27; j++)
			ary[i][j]=0;
	}
	system("cls");
	drawmap();
	playing();
	Sleep(2000);
	setcolor(15,0);
	system("cls");
	gotoxy(17,10);
	printf("3�� �� ������ ����� �մϴ�.");
	Sleep(3000);
	}
}
