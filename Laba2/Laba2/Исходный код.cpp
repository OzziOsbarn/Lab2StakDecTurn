#include "stdlib.h"
#include "iostream"
using namespace std;

  class Stack;
  class Turn;
  class Dec;

 struct Node       //Структура являющаяся звеном списка
 {
     int x;     //Значение x будет передаваться в список
     Node *Next,*Prev; //Указатели на адреса следующего и предыдущего элементов списка
 };
 class List   //Создаем тип данных Список
 { private:
		int Po;
	    Node *Head,*Tail,*PointR,*PointL; //Указатели на адреса начала списка и его конца, а также текущей позиции
 public:
	 List():Head(NULL),Tail(NULL),PointR(NULL),PointL(NULL){Po=0;}; //Инициализируем адреса как пустые
	 ~List(){}; //Деструктор
     void Show(); //Функция отображения списка на экране
     void AddHead(int x); //Функция добавления элементов в начало списка
	 void AddTail(int x); //Функция добавления элементов в конец списка
	 void AddPointRight(int x, int i); //Функция добавления элементов после элемента с заданным ключом
	 void AddPointLeft(int x, int i); //Функция добавления элементов до элемента с заданным ключом
	 void DeleteE(int i); //Функция удаления элемента списка
	 int GetH(); // ПОлучение значения головы
	 int GetT();// получение значения хвоста
	 friend Stack;
	 friend Turn;
	 friend Dec;

};
void List::AddHead(int x)
 {
   Node *temp=new Node; //Выделение памяти под новый элемент структуры
       temp->x=x;//Записываем значение в структуру
	   Po=Po+1; //Счетчик
 
   if (Head!=NULL) //Если список не пуст
   {  
       temp->Prev=NULL; //Указываем адрес на предыдущий элемент в соотв. поле
       Head->Prev=temp; //Указываем адрес предшествующего голове элемента
	   temp->Next=Head;
       Head=temp; //Меняем адрес головы
   }
   else //Если список пустой
   {   temp->Next=NULL;
       temp->Prev=NULL; //Предыдущий элемент указывает в пустоту
       Head=Tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
   }
 }
void List::AddTail(int x)
 {
   Node *temp=new Node; //Выделение памяти под новый элемент структуры
   temp->Next=NULL;  //Указываем, что изначально по следующему адресу пусто
   temp->x=x;//Записываем значение в структуру
   Po=Po+1; //Счетчик
 
   if (Head!=NULL) //Если список не пуст
   {
       temp->Prev=Tail; //Указываем адрес на предыдущий элемент в соотв. поле
       Tail->Next=temp; //Указываем адрес следующего за хвостом элемента
       Tail=temp; //Меняем адрес хвоста
   }
   else //Если список пустой
   {
       temp->Prev=NULL; //Предыдущий элемент указывает в пустоту
       Head=Tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
   }
 }
void List::AddPointLeft(int x, int i)
{int  Ky=1;
   Node *temp=new Node; //Выделение памяти под новый элемент структуры
  if ((i>Po)||(i<=0)) {cout<<"Elementa № "<<i<<" Net"<<"\n"<<"Znachenie "<<x<<" pered '№'"<<i<<" ne dobavleno:"<<"\n";} else
	 if (i==Po) {
		 temp->Next=NULL;
		 temp->Prev=Tail;
		 Tail->Next=temp;
		 temp->x=Tail->x;
		 PointL=Tail;
		 Tail=temp;
		 temp->x=x;
		 Po=Po+1; //Счетчик
		} else
	 if (i==1) {
		 temp->Prev=NULL;
		 temp->Next=Head;
		 Head->Prev=temp;
		 Head=temp;
		 temp->x=x;
		 Po=Po+1; //Счетчик
		} else
	 {  
		 temp->Prev=NULL;
		 temp->Next=Head;
		 Head->Prev=temp;
		 PointL=Head;
		 Head=temp;
		 while(Ky!=i)
		 {
			 temp->x=PointL->x;
			 temp=PointL;
			 PointL=temp->Next;
			 Ky=Ky+1;
		 }
		 temp->x=x;
		 Po=Po+1; //Счетчик
	 }
}
void List::AddPointRight(int x, int i)
 {int  Ky=0;
   Node *temp=new Node; //Выделение памяти под новый элемент структуры
  if ((i>Po)||(i<=0)) {cout<<"Elementa № "<<i<<" Net"<<"\n"<<"Znachenie "<<x<<" posle '№'"<<i<<" ne dobavleno:"<<"\n";} else
	 if (i==Po) {
		 temp->Next=NULL;
		 temp->Prev=Tail;
		 Tail->Next=temp;
		 Tail=temp;
		 temp->x=x;
		 Po=Po+1; //Счетчик
		} else
	 if (i==1) {
		 temp->Prev=NULL;
		 temp->Next=Head;
		 Head->Prev=temp;
		 PointR=temp;
		 temp=Head;
		 Head=PointR;
		 Head->x=temp->x;
		 temp->x=x;
		 Po=Po+1; //Счетчик
		} else
	 {  
		 temp->Prev=NULL;
		 temp->Next=Head;
		 Head->Prev=temp;
		 PointR=Head;
		 Head=temp;
		 while(Ky!=i)
		 {
			 temp->x=PointR->x;
			 temp=PointR;
			 PointR=temp->Next;
			 Ky=Ky+1;
		 }
		 temp->x=x;
		 Po=Po+1; //Счетчик
	 }
 }
void List::DeleteE(int i)
{  int  Ky=2;
   Node *temp=new Node; //Выделение памяти под новый элемент структуры

   if (i==1)  
  {
	  if (i==Po) 
	  {
		  delete Head;
	  } else
	  if (Head!=NULL)
	  {if (Head->Next!=NULL){
		temp=Head;
		Head=temp->Next;
		delete temp;
				
	  }else
	  {
		  delete Head;
	  }}

  } else
	  if (i==Po)
	  {
		  temp=Tail;
		  Tail=temp->Prev;
		  delete temp;
		  
	  } else
	  if ((i>1)&&(i<Po))
	  {
		  PointL=Head;
		  temp=Head->Next;
		  PointR=temp->Next;
		  while(Ky!=i)
		  {
			  PointL=temp;
			  temp=PointR;
			  PointR=PointR->Next;
			  
		  }
		  PointL->Next=PointR;
		  PointR->Prev=PointL;
		  delete temp;
		  
	  } else
	  {
			cout<<"Elementa № "<<i<<" Net"<<"\n"<<"Znachenie '№'"<<i<<" ne udaleno:"<<"\n";
	  }
   Po=Po-1;
}
void List::Show()
{if (Po==0) {cout<<"\nДанных нет\n";} else
{cout<<"ВЫВОДИМ СПИСОК С КОНЦА\n";
     Node *temp=Tail;
      //Временный указатель на адрес последнего элемента
     while (temp!=NULL) //Пока не встретится пустое значение
     {
	 cout<<temp->x<<" "; //Выводить значение на экран
	 temp=temp->Prev; //Указываем, что нужен адрес предыдущего элемента
     }
     cout<<"\n";
 
cout<<"ВЫВОДИМ СПИСОК С НАЧАЛА\n";
     temp=Head; //Временно указываем на адрес первого элемента
      while (temp!=NULL) //Пока не встретим пустое значение
     {
	 cout<<temp->x<<" "; //Выводим каждое считанное значение на экран
	 temp=temp->Next; //Смена адреса на адрес следующего элемента
	  }}
     cout<<"\n"<<Po<<"\n";
}
int List::GetH()
{
	int T;
	T=Head->x;
	if (T==NULL) return(0); else return(T);
}
int List::GetT()
{
	int T;
	T=Tail->x;
	if (T==NULL) return(0); else return(T);
}

class Stack: public List
{	int X;
	public:
		Stack() {X=0;}
		~Stack(){};
     void AddS(int x);
	 int GetS();
	 void HmS();
	 int HmSX();
};
void Stack::AddS(int x) 
{
	AddHead(x);
}
int Stack::GetS() 
{
	int X;
	X=GetH();
	DeleteE(1);
	return(X);
}
void Stack::HmS()
{
	cout<<"\nКоличество элементов стека = "<<Po<<"\n";
}
int Stack::HmSX()
{
	return(Po);
}

class Turn: public List
{
public:
	 ~Turn(){};
     void AddT(int x);
	 int GetT();
	 void HmT();
	 int HmTX();
};
void Turn::AddT(int x) 
{
	AddTail(x);
}
int Turn::GetT() 
{
	int X;
	X=GetH();
	DeleteE(1);
	return(X);
}
void Turn::HmT()
{
	cout<<"\nКоличество элементов стека = "<<Po<<"\n";
}
int Turn::HmTX()
{
	return(Po);
}

class Dec: public List
{private:
	int X;
public:
	~Dec(){};
     void AddHD(int x);
	 void AddTD(int x);
	 int GetHD();
	 int GetTD();
	 void HmD();
	 int HmDX();
};
void Dec::AddHD(int x) 
{
	AddHead(x);
}
void Dec::AddTD(int x) 
{
	AddTail(x);
}
int Dec::GetHD() 
{
	int X;
	X=GetH();
	DeleteE(1);
	return(X);
}
int Dec::GetTD() 
{
	int X;
	X=GetT();
	DeleteE(Po);
	return(X);
}
void Dec::HmD()
{
	cout<<"\nКоличество элементов стека = "<<Po<<"\n";
}
int Dec::HmDX()
{
	return(Po);
}

int main()
{setlocale(LC_ALL, "Russian");
char A[4]={'/','*','-','+'},B='0',C;
int q=1,t,i=0,x,y,N=0,U=0,H;
int *Mas=new int [100];
char *Ts=new char [100];

// Пример Stack
cout<<"Пример Стекк";
Stack St;
St.HmS();
cout<<"Начало записи<";
St.AddS(1);
St.AddS(2);
St.AddS(3);
St.AddS(4);
St.AddS(5);
cout<<">Конец записи";
St.HmS();
i=St.GetS();
cout<<i;
St.HmS();
i=St.GetS();
cout<<i;
St.HmS();
i=St.GetS();
cout<<i;
St.HmS();
i=St.GetS();
cout<<i;
St.HmS();
i=St.GetS();
cout<<i;
St.HmS();
system("pause");

// Пример Turn
system("cls");
cout<<"Пример Очередь";
Turn Tu;
Tu.HmT();
cout<<"Начало записи<";
Tu.AddT(1);
Tu.AddT(2);
Tu.AddT(3);
Tu.AddT(4);
Tu.AddT(5);
cout<<">Конец записи";
Tu.HmT();
i=Tu.GetT();
cout<<i;
Tu.HmT();
i=Tu.GetT();
cout<<i;
Tu.HmT();
i=Tu.GetT();
cout<<i;
Tu.HmT();
i=Tu.GetT();
cout<<i;
Tu.HmT();
i=Tu.GetT();
cout<<i;
Tu.HmT();
system("pause");

// Пример Dec
system("cls");
cout<<"Пример Дек";
Dec De;
De.HmD();
cout<<"Начало записи<";
De.AddHD(1);
De.AddTD(2);
De.AddHD(3);
De.AddTD(4);
De.AddHD(5);
De.AddTD(6);
De.AddHD(7);
De.AddTD(8);
cout<<">Конец записи";
De.HmD();
i=De.GetHD();
cout<<"Начало Дека: "<<i;
De.HmD();
i=De.GetHD();
cout<<i;
De.HmD();
i=De.GetHD();
cout<<i;
De.HmD();
i=De.GetHD();
cout<<i;
De.HmD();
i=De.GetTD();
cout<<"Конец Дека : "<<i;
De.HmD();
i=De.GetTD();
cout<<i;
De.HmD();
i=De.GetTD();
cout<<i;
De.HmD();
i=De.GetTD();
cout<<i;
De.HmD();
system("pause");

// Stack задание
system("cls");
cout<<"Задание:\n";
i=0;
while(B!='.')
{one:
	cin>>C;
	if ((C=='.')&&(N==0)) {B='.';} else
		if ((C=='.')&&(N!=0)) {goto one;} else
	if ((C!='/')&&(C!='-')&&(C!='+')&&(C!='*')&&(C!='.'))
		{
		    x=(int)C-48;
			St.AddS(x);
			N=N+1;
		} else 
		{
			if (int(C)==42)
			{
				x=1;//*
			} else if (int(C)==43)
			{
				x=2;//+
			} else if (int(C)==45)
			{
				x=3;//-
			} else if (int(C)==47)
			{
				x=4;// /
			} 
				Mas[i]=N;
				N=0;
				Mas[i+1]=x;
				i=i+2;
			}
}
H=i/2;
for (t=0;t<=i-1;t++)
{cout<<Mas[t]<<" ";}
cout<<"\n";

t=i-1;
for (t;t>=0;t=t-2)
{//x-число цифр а y-знак
	Ts[q]=')';
	q=q+1;
	x=Mas[t-1];y=Mas[t];
	if (y==1)
			{
				C=42;
			} else if (y==2)
			{
				C=43;
			} else if (y==3)
			{
				C=45;
			} else if (y==4)
			{
				C=47;
			} 

			
while (x!=0)
{
	U=St.GetS();
	if((x==1)&&(t==1)) {Ts[q]=U+48;q=q+1;} else
		{
		Ts[q]=U+48;q=q+1;Ts[q]=C;q=q+1; 
		 }
	
	x=x-1;
}}
while(H!=0)
			{Ts[q]='(';
			q=q+1;
			H=H-1;}
cout<<"\n";q=q-1;
for (q;q>=1;q--)
{cout<<Ts[q];}
cout<<"\n";


return 0;}