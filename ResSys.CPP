
/***********************PROJECT ON RESTAURENT MANAGEMENT******
*************************BY- Ishan Bhateja**********
************************USE A BORLAND C++ Compiler***************/


//****************** HEADER FILES**********************
#include<fstream.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
//****************** GLOBAL VARIABLES *****************
int total=0,quantity[6],squantity[5];

//******************FUNCTION PROTOTYPES****************
void loading_scr();
void readfrom();
void readcustomer();
void screen();
void employee_info();
void createSides();
void createPizza();
void PizzaMenu();
void sidesMenu();

//******************STRUCTURES USED********************


	//-------- STRUCTURE OF PIZZA MENU ------------------

struct pmenu
{
	char code[3];
	char name[20], toppings[50];
	int price;
}pout,pin;


	//-------- STRUCTURE OF SIDES MENU ------------------

struct smenu
{
	char code[3];
	char name[30];
	int price;
}sout,sin;
//**********************************************************************




/****************************************************
*********************CLASSES USED********************
*****************************************************/


	//------- CLASS OF DISPLAY MENU ----------

class dp_menu
{
	public:

	void SidesMenu();
	void modSmenu();
	void PizzaMenu();
	void modPmenu();
};




	//------- CLASS OF EMPLOYEE ------------------

class employee
{
	int e_id;
	char e_name[25],e_address[35];
	unsigned long int e_ph_no;
	int e_jyear;

	public:

	employee()
	{
		e_id=0;
		strcpy(e_name,"NULL");
		strcpy(e_address,"NULL");
		e_ph_no=0;
		e_jyear=0;
	}

	void password();
	void e_menu();
	void e_search();
	void e_modify();
	void e_delete();
	void e_append();
	void e_show();
	int e_get_id();
	int e_getinfo();

}e,etemp;




	//-------- CLASS OF CUSTOMER ---------------

class customer
{
	char c_address[35],c_name1[20],c_name2[20],c_id[20];
	unsigned long int c_ph_no;


	public:
	char c_name[25], c_pass1[5];
	void c_login();
	void c_append();
	void c_show();



}c,ctemp;
//*********************************************************************

void marquee_effect(char s[], int speed)
{
	int x,y,i,l, left;
	l = strlen(s);
	left = (80-(l+(l/2)));
	y = wherey();
	do
	{
		for(x=0;x<left;x++)
		{
			gotoxy(x-1,y);
			clreol();
			gotoxy(x,y);
			cout<<s;
			delay(170-speed);
		}
	}
	while(!kbhit);

}



/*******************************************************************
***************** FUNCTIONS RELATED TO FOODITEMS ********************
*******************************************************************/



	//----------- FUNCTION TO CREATE PIZZA MENU ---------------

void createPizza()
{
	ofstream fout("pizza.dat",ios::binary);

	strcpy(pout.code,"P1");
	strcpy(pout.name,"Margherita");
	pout.price=185;
	strcpy(pout.toppings,"Single cheese topping");
	fout.write((char*)&pout,sizeof(pout));

	strcpy(pout.code,"P2");
	strcpy(pout.name,"Fresh Veggie");
	pout.price=245;
	strcpy(pout.toppings,"Onion & crisp capsicum");
	fout.write((char*)&pout,sizeof(pout));

	strcpy(pout.code,"P3");
	strcpy(pout.name,"Farmhouse");
	pout.price=245;
	strcpy(pout.toppings,"Onion,crisp capsicum,fresh tomato,mushroom");
	fout.write((char*)&pout,sizeof(pout));

	strcpy(pout.code,"P4");
	strcpy(pout.name,"Chicken Mexicana");
	pout.price=290;
	strcpy(pout.toppings,"Onion,tomato,Spicy chicken,mexican herbs");
	fout.write((char*)&pout,sizeof(pout));

	strcpy(pout.code,"P5");
	strcpy(pout.name,"Zesty Chicken");
	pout.price=290;
	strcpy(pout.toppings,"Chicken Sausage,Barbeque Chicken,Red paprika");
	fout.write((char*)&pout,sizeof(pout));

	strcpy(pout.code,"P6");
	strcpy(pout.name,"Pepperoni");
	pout.price=300;
	strcpy(pout.toppings,"100% Pork Pepperoni,Extra Cheese");
	fout.write((char*)&pout,sizeof(pout));

	fout.close();
 }


//-----------------------BILLING FUNCTION------------------


 void bill(int flag)
 {
	 clrscr();

	ifstream fin("pizza.dat",ios::binary);

	gotoxy(38,1);
	cout<<"BILL";
	gotoxy(36,3);
	cout<<"PIZZAS";
	gotoxy(3,5);
	cout<<"CODE";
	gotoxy(10,5);
	cout<<"NAME";
	gotoxy(35,5);
	cout<<"QUANTITY";
	gotoxy(71,5);
	cout<<"PRICE(Rs)";



	fin.read((char*)&pin,sizeof(pin));
	if(quantity[0]!=0)
	{
		gotoxy(3,7);
		cout<<pin.code;
		gotoxy(10,7);
		cout<<pin.name;
		gotoxy(30,7);
		cout<<quantity[0];
		gotoxy(73,7);
		cout<<pin.price*quantity[0];

		total+=pin.price*quantity[0];
	}

	fin.read((char*)&pin,sizeof(pin));
	if(quantity[1]!=0)
	{
		gotoxy(3,9);
		cout<<pin.code;
		gotoxy(10,9);
		cout<<pin.name;
		gotoxy(30,9);
		cout<<quantity[1];
		gotoxy(73,9);
		cout<<pin.price*quantity[1];

		total+=pin.price*quantity[1];
	}

	fin.read((char*)&pin,sizeof(pin));
	if(quantity[2]!=0)
	{
		gotoxy(3,11);
		cout<<pin.code;
		gotoxy(10,11);
		cout<<pin.name;
		gotoxy(30,11);
		cout<<quantity[2];
		gotoxy(73,11);
		cout<<pin.price*quantity[2];

		total+=pin.price*quantity[2];
	}


	fin.read((char*)&pin,sizeof(pin));
	if(quantity[3]!=0)
	{
		gotoxy(3,13);
		cout<<pin.code;
		gotoxy(10,13);
		cout<<pin.name;
		gotoxy(30,13);
		cout<<quantity[3];
		gotoxy(73,13);
		cout<<pin.price*quantity[3];

		total+=pin.price*quantity[3];
	}


	fin.read((char*)&pin,sizeof(pin));
	if(quantity[4]!=0)
	{
		gotoxy(3,15);
		cout<<pin.code;
		gotoxy(10,15);
		cout<<pin.name;
		gotoxy(30,15);
		cout<<quantity[4];
		gotoxy(73,15);
		cout<<pin.price*quantity[4];

		total+=pin.price*quantity[4];
	}


	fin.read((char*)&pin,sizeof(pin));
	if(quantity[5]!=0)
	{
		gotoxy(3,17);
		cout<<pin.code;
		gotoxy(10,17);
		cout<<pin.name;
		gotoxy(30,17);
		cout<<quantity[5];
		gotoxy(73,17);
		cout<<pin.price*quantity[5];

		total+=pin.price*quantity[5];
	}

	fin.close();
	getch();

       if(flag==1)
       {
		clrscr();
		fin.open("sides.dat",ios::binary);

		gotoxy(38,1);
		cout<<"MENU";
		gotoxy(36,3);
		cout<<"SIDES";
		gotoxy(3,5);
		cout<<"CODE";
		gotoxy(10,5);
		cout<<"NAME";
		gotoxy(35,5);
		cout<<"QUANTITY";
		gotoxy(71,5);
		cout<<"PRICE(Rs)";



		fin.read((char*)&sin,sizeof(sin));
		if(squantity[0]!=0)
		{
			gotoxy(3,7);
			cout<<sin.code;
			gotoxy(10,7);
			cout<<sin.name;
			gotoxy(38,7);
			cout<<squantity[0];
			gotoxy(73,7);
			cout<<sin.price*squantity[0];

			total+=sin.price*squantity[0];
		}


		fin.read((char*)&sin,sizeof(sin));
		if(squantity[1]!=0)
		{
			gotoxy(3,9);
			cout<<sin.code;
			gotoxy(10,9);
			cout<<sin.name;
			gotoxy(38,9);
			cout<<squantity[1];
			gotoxy(73,9);
			cout<<sin.price*squantity[1];
			gotoxy(3,11);

			total+=sin.price*squantity[1];
		}

		fin.read((char*)&sin,sizeof(sin));
		if(squantity[2]!=0)
		{
			cout<<sin.code;
			gotoxy(10,11);
			cout<<sin.name;
			gotoxy(38,11);
			cout<<squantity[2];
			gotoxy(73,11);
			cout<<sin.price*squantity[2];

			total+=sin.price*squantity[2];
		}

		fin.read((char*)&sin,sizeof(sin));
		if(squantity[3]!=0)
		{
			gotoxy(3,13);
			cout<<sin.code;
			gotoxy(10,13);
			cout<<sin.name;
			gotoxy(38,13);
			cout<<squantity[3];
			gotoxy(73,13);
			cout<<sin.price*squantity[3];

			total+=sin.price*squantity[3];
		}

		fin.read((char*)&sin,sizeof(sin));
		if(squantity[4]!=0)
		{
			gotoxy(3,15);
			cout<<sin.code;
			gotoxy(10,15);
			cout<<sin.name;
			gotoxy(38,15);
			cout<<squantity[4];
			gotoxy(73,15);
			cout<<sin.price*squantity[4];

		}
		total+=sin.price*squantity[4];

	}

	gotoxy(65,19);
	cout<<"TOTAL: Rs "<<total;
	getch();
	fin.close();
	clrscr();
	cout<<"\n\n\n\t\t\tTHANK YOU FOR ORDERING!";
	cout<<"\n\n\n\n\t\t\tVISIT AGAIN!";
	getch();
	screen();

 }


//-------------------------PIZZA MENU-------------------------



 void pizzaMenu()
{

	ifstream fin("pizza.dat",ios::binary);

	gotoxy(38,1);
	cout<<"MENU";
	gotoxy(36,3);
	cout<<"PIZZAS";
	gotoxy(3,5);
	cout<<"CODE";
	gotoxy(10,5);
	cout<<"NAME";
	gotoxy(35,5);
	cout<<"TOPPINGS";
	gotoxy(71,5);
	cout<<"PRICE(Rs)";

	fin.read((char*)&pin,sizeof(pin));
	gotoxy(3,7);
	cout<<pin.code;
	gotoxy(10,7);
	cout<<pin.name;
	gotoxy(27,7);
	cout<<pin.toppings;
	gotoxy(73,7);
	cout<<pin.price;

	fin.read((char*)&pin,sizeof(pin));
	gotoxy(3,9);
	cout<<pin.code;
	gotoxy(10,9);
	cout<<pin.name;
	gotoxy(27,9);
	cout<<pin.toppings;
	gotoxy(73,9);
	cout<<pin.price;
	gotoxy(3,11);

	fin.read((char*)&pin,sizeof(pin));
	cout<<pin.code;
	gotoxy(10,11);
	cout<<pin.name;
	gotoxy(27,11);
	cout<<pin.toppings;
	gotoxy(73,11);
	cout<<pin.price;

	fin.read((char*)&pin,sizeof(pin));
	gotoxy(3,13);
	cout<<pin.code;
	gotoxy(10,13);
	cout<<pin.name;
	gotoxy(27,13);
	cout<<pin.toppings;
	gotoxy(73,13);
	cout<<pin.price;

	fin.read((char*)&pin,sizeof(pin));
	gotoxy(3,15);
	cout<<pin.code;
	gotoxy(10,15);
	cout<<pin.name;
	gotoxy(27,15);
	cout<<pin.toppings;
	gotoxy(73,15);
	cout<<pin.price;

	fin.read((char*)&pin,sizeof(pin));
	gotoxy(3,17);
	cout<<pin.code;
	gotoxy(10,17);
	cout<<pin.name;
	gotoxy(27,17);
	cout<<pin.toppings;
	gotoxy(73,17);
	cout<<pin.price;


	char ch,ch1, order[5];

	cout<<"\n\n\t\t**********PLACE YOUR ORDER*******************\n";

	do
	{
		cout<<"\nWant to Order Pizzas<Y/N>";
		cin>>ch;
		cout<<"\n\nEnter the pizza code: ";
		cin>>order;


		if(!strcmpi(order,"P1"))
		{
			cout<<"\nEnter the quantity: ";
			cin>>quantity[0];

		}

		else if(!strcmpi(order,"P2"))
		{
			cout<<"\nEnter the quantity: ";
			cin>>quantity[1];

		}

		else if(!strcmpi(order,"P3") )
		 {
			cout<<"\nEnter the quantity: ";
			cin>>quantity[2];

		 }

		else if(!strcmpi(order,"P4"))
		 {
			cout<<"\nEnter the quantity: ";
			cin>>quantity[3];

		 }

		else if(!strcmpi(order,"P5"))
		 {
			cout<<"\nEnter the quantity: ";
			cin>>quantity[4];
		 }

		 else if(!strcmpi(order,"P6"))
		  {
			cout<<"\nEnter the quantity: ";
			cin>>quantity[5];

		  }

		  else
			cout<<"\nWRONG INPUT!!";



		  cout<<"\n\nORDER MORE PIZZA (y/n): ";
		  cin>>ch;

	}while(ch=='Y'||ch=='y');

	cout<<"\nPROCEED TO SIDES(Y/N)??  ";
	cin>>ch1;

	if(ch1=='y' || ch1=='Y')
	{
		sidesMenu();

	}

	else
		bill(0);



	fin.close();

	getch();
	clrscr();


}



	//-----------FUNCTION TO MODIFY PIZZA MENU -------------

void dp_menu::modPmenu()
{
	int flag;
	long pos;
	char ch,code[3];
	pmenu pio;

	fstream fio("pizza.dat",ios::in|ios::out|ios::binary);

	do
	{
		flag=0;
		fio.seekg(0);
		cout<<"Enter the product code: ";
		cin>>code;

		while(!fio.eof())
		{

			pos=fio.tellg();
			fio.read((char*)&pio,sizeof(pio));
			if(strcmpi(code,pio.code)==0)
			{
				flag=1;

				break;
			}
		}
		if(flag)
		{
			cout<<"\n\nEnter the new price: ";
			cin>>pio.price;
			fio.seekg(pos);
			fio.write((char*)&pio,sizeof(pio));
		}

		cout<<"Do you want modify more(y/n): ";
		cin>>ch;
	}while(ch=='Y'||ch=='y');

	fio.close();

}



	//-------------- FUNCTION TO DISPLAY PIZZA MENU -----------------

void dp_menu::PizzaMenu()
{
	char ch;
	ifstream fin("pizza.dat",ios::binary);

	gotoxy(38,1);
	cout<<"MENU";
	gotoxy(36,3);
	cout<<"PIZZAS";
	gotoxy(3,5);
	cout<<"CODE";
	gotoxy(10,5);
	cout<<"NAME";
	gotoxy(35,5);
	cout<<"TOPPINGS";
	gotoxy(71,5);
	cout<<"PRICE(Rs)";

	fin.read((char*)&pin,sizeof(pin));
	gotoxy(3,7);
	cout<<pin.code;
	gotoxy(10,7);
	cout<<pin.name;
	gotoxy(27,7);
	cout<<pin.toppings;
	gotoxy(73,7);
	cout<<pin.price;

	fin.read((char*)&pin,sizeof(pin));
	gotoxy(3,9);
	cout<<pin.code;
	gotoxy(10,9);
	cout<<pin.name;
	gotoxy(27,9);
	cout<<pin.toppings;
	gotoxy(73,9);
	cout<<pin.price;
	gotoxy(3,11);

	fin.read((char*)&pin,sizeof(pin));
	cout<<pin.code;
	gotoxy(10,11);
	cout<<pin.name;
	gotoxy(27,11);
	cout<<pin.toppings;
	gotoxy(73,11);
	cout<<pin.price;

	fin.read((char*)&pin,sizeof(pin));
	gotoxy(3,13);
	cout<<pin.code;
	gotoxy(10,13);
	cout<<pin.name;
	gotoxy(27,13);
	cout<<pin.toppings;
	gotoxy(73,13);
	cout<<pin.price;

	fin.read((char*)&pin,sizeof(pin));
	gotoxy(3,15);
	cout<<pin.code;
	gotoxy(10,15);
	cout<<pin.name;
	gotoxy(27,15);
	cout<<pin.toppings;
	gotoxy(73,15);
	cout<<pin.price;

	fin.read((char*)&pin,sizeof(pin));
	gotoxy(3,17);
	cout<<pin.code;
	gotoxy(10,17);
	cout<<pin.name;
	gotoxy(27,17);
	cout<<pin.toppings;
	gotoxy(73,17);
	cout<<pin.price;

	cout<<"\n\n DO YOU WANT TO MODIFY THE MENU: ";
	cin>>ch;
	if(ch=='Y'||ch=='y')
		{
			modPmenu();
			clrscr();
			PizzaMenu();
		}

	getch();


	fin.close();

	clrscr();
	SidesMenu();
}



	//----------- FUNCTION TO CREATE SIDES MENU -------------------

void createSides()
{
	ofstream fout("sides.dat",ios::binary);

	strcpy(sout.code,"S1");
	strcpy(sout.name,"Garlic Bread");
	sout.price=79;
	fout.write((char*)&sout,sizeof(sout));
	strcpy(sout.name," ");
	cout<<sout.name;


	strcpy(sout.code,"S2");
	strcpy(sout.name,"Cheese Pasta");
	sout.price=105;
	fout.write((char*)&sout,sizeof(sout));

	strcpy(sout.code,"S3");
	strcpy(sout.name,"Diet coke");
	sout.price=35;
	fout.write((char*)&sout,sizeof(sout));

	strcpy(sout.code,"S4");
	strcpy(sout.name,"Choco Lava Cake");
	sout.price=65;
	fout.write((char*)&sout,sizeof(sout));

	strcpy(sout.code,"S5");
	strcpy(sout.name,"Butterscotch Mousse cake");
	sout.price=59;
	fout.write((char*)&sout,sizeof(sout));

	fout.close();
 }



	//-------- FUNCTION TO MODIFY SIDES MENU -------------------

void dp_menu::modSmenu()
{
	int flag;
	long pos;
	char ch,code[3];
	smenu sio;

	fstream fio("sides.dat",ios::in|ios::out|ios::binary);

	do
	{
		flag=0;
		fio.seekg(0);
		cout<<"Enter the product code: ";
		cin>>code;

		while(!fio.eof())
		{

			pos=fio.tellg();
			fio.read((char*)&sio,sizeof(sio));
			if(strcmpi(code,sio.code)==0)
			{
				flag=1;

				break;
			}
		}
		if(flag)
		{
			cout<<"\n\nEnter the new price: ";
			cin>>sio.price;
			fio.seekg(pos);
			fio.write((char*)&sio,sizeof(sio));
		}

		cout<<"Do you want modify more(y/n): ";
		cin>>ch;
	}while(ch=='Y'||ch=='y');

	fio.close();

}



	//---------- FUNCTION TO DISPLAY SIDES MENU ------------------


      //FUNCTION 1

void sidesMenu()  //for customer  ordering
{
	clrscr();
	ifstream fin("sides.dat",ios::binary);

	gotoxy(38,1);
	cout<<"MENU";
	gotoxy(37,3);
	cout<<"SIDES";
	gotoxy(22,5);
	cout<<"CODE";
	gotoxy(30,5);
	cout<<"NAME";
	gotoxy(54,5);
	cout<<"PRICE(Rs)";

	fin.read((char*)&sin,sizeof(sin));
	gotoxy(23,7);
	cout<<sin.code;
	gotoxy(30,7);
	cout<<sin.name;
	gotoxy(57,7);
	cout<<sin.price;


	fin.read((char*)&sin,sizeof(sin));
	gotoxy(23,9);
	cout<<sin.code;
	gotoxy(30,9);
	cout<<sin.name;
	gotoxy(57,9);
	cout<<sin.price;
	gotoxy(23,11);

	fin.read((char*)&sin,sizeof(sin));
	cout<<sin.code;
	gotoxy(30,11);
	cout<<sin.name;
	gotoxy(57,11);
	cout<<sin.price;
	gotoxy(23,13);

	fin.read((char*)&sin,sizeof(sin));
	cout<<sin.code;
	gotoxy(30,13);
	cout<<sin.name;
	gotoxy(57,13);
	cout<<sin.price;
	gotoxy(23,15);

	fin.read((char*)&sin,sizeof(sin));
	cout<<sin.code;
	gotoxy(30,15);
	cout<<sin.name;
	gotoxy(57,15);
	cout<<sin.price;

	char ch,ch1, order[5];

	cout<<"\n\n**********PLACE YOUR ORDER*******************\n";

       do
       {

		cout<<"\n\nEnter the sides code: ";
		cin>>order;


		if(!strcmpi(order,"S1"))
		{
			cout<<"\nEnter the quantity: ";
			cin>>squantity[0];
		}

		else if(!strcmpi(order,"S2"))
		{
			cout<<"\nEnter the quantity: ";
			cin>>squantity[1];

		}

		else if(!strcmpi(order,"S3") )
		{
			 cout<<"\nEnter the quantity: ";
			 cin>>squantity[2];

		}

		else if(!strcmpi(order,"S4"))
		{
			 cout<<"\nEnter the quantity: ";
			 cin>>squantity[3];

		}

		else if(!strcmpi(order,"S5"))
		{
			 cout<<"\nEnter the quantity: ";
			 cin>>squantity[4];

		}

		else
			cout<<"\nWRONG INPUT!!";


		cout<<"\n\nORDER MORE SIDES (y/n): ";
		cin>>ch;

	}while(ch=='Y'||ch=='y');

	bill(1);
}


		//FUNCTION2


void dp_menu::SidesMenu()      //for employee modification
{
	char ch;
	ifstream fin("sides.dat");

	gotoxy(38,1);
	cout<<"MENU";
	gotoxy(37,3);
	cout<<"SIDES";
	gotoxy(22,5);
	cout<<"CODE";
	gotoxy(30,5);
	cout<<"NAME";
	gotoxy(54,5);
	cout<<"PRICE(Rs)";

	fin.read((char*)&sin,sizeof(sin));
	gotoxy(23,7);
	cout<<sin.code;
	gotoxy(30,7);
	cout<<sin.name;
	gotoxy(57,7);
	cout<<sin.price;


	fin.read((char*)&sin,sizeof(sin));
	gotoxy(23,9);
	cout<<sin.code;
	gotoxy(30,9);
	cout<<sin.name;
	gotoxy(57,9);
	cout<<sin.price;
	gotoxy(23,11);

	fin.read((char*)&sin,sizeof(sin));
	cout<<sin.code;
	gotoxy(30,11);
	cout<<sin.name;
	gotoxy(57,11);
	cout<<sin.price;
	gotoxy(23,13);

	fin.read((char*)&sin,sizeof(sin));
	cout<<sin.code;
	gotoxy(30,13);
	cout<<sin.name;
	gotoxy(57,13);
	cout<<sin.price;
	gotoxy(23,15);

	fin.read((char*)&sin,sizeof(sin));
	cout<<sin.code;
	gotoxy(30,15);
	cout<<sin.name;
	gotoxy(57,15);
	cout<<sin.price;

	cout<<"\n\n DO YOU WANT TO MODIFY THE MENU(Y/N): ";
	cin>>ch;
	if(ch=='Y'||ch=='y')
		{
			modSmenu();
			clrscr();
			SidesMenu();
		}

	getch();


	fin.close();
	clrscr();
	e.e_menu();



}
//*******************************************************************




/*********************************************************************
********************** FUNCTIONS RELATED TO EMPLOYEE******************
*********************************************************************/



	//----------- FUNCTION FOR EMPLOYEE LOGIN --------------------

void employee::password()
{
	char ch,c,pw[40];
	clrscr();


	int i=0;

	cout<<"\n\t\t\tENTER PASSWORD: ";

	for(i=0;i!='\r';i++)
	{
		c=getch();

		if(c==13)
		{
			pw[i]='\0';
			break;

		}

		else if(c!='\b')
		{
			cout<<"*";
			pw[i]=c;
		}

		else
		{
			i=i-2;
			cout<<"\b \b";

		}
	}//end of forloop
	pw[i]='\0';

	if(strcmp("perk",pw)==0)    	 //**condition to check password**
	{
	       e.e_menu();
	}

	else
	{

		clrscr();
		cout<<"\n\t\t\t\tWRONG PASSWORD! ACCESS DENIED!!!";
		getch();
		screen();

	}
}



	//----------FUNCTION TO DISPLAY EMPLOYEE MENU ----------------

void employee :: e_menu()
{
	clrscr();

	dp_menu dp_m ;
	int em_choice;
	char ch;

	cout<<"\n\n\t\t\t\t\t\tMENU";
	cout<<"\n\n\t\t\tPRESS 1:  CHANGE MENU";
	cout<<"\n\n\t\t\tPRESS 2:  EMPLOYEE INFORMATION";
	cout<<"\n\t\t\tPRESS 3: RETURN TO MAIN MENU";
	do
	{

		cout<<"\n\n\n\n\t\t\tENTER YOUR CHOICE: ";
		cin>>em_choice;

		if(em_choice==1)
		{
			clrscr();
			dp_m.PizzaMenu();
		}

		else if(em_choice==2)
		{
			employee_info();
		}
		else if(em_choice==3)
		{
			screen();
		}
		else
		{
			cout<<"\n\t\tWRONG CHOICE!!CHOOSE AGAIN!";
			cout<<"\n\t\tCHOOSE AGAIN: ";
			cin>>ch;
		}
       }while(ch=='y' || ch=='Y'); //end of do-while loop
}


	//--------- FUNCTION TO ACCESS & CHANGE EMPLOYEE INFO -------

void employee_info()
{
	clrscr();
	int ei_choice;
	char ch;

	cout<<"\n\n\t\tPRESS 1: SEARCH EMPLOYEE'S INFORMATION";
	cout<<"\n\t\tPRESS 2: DELETE EMPLOYEE'S INFORMATION";
	cout<<"\n\t\tPRESS 3: MODIFY EMPLOYEE'S INFORMATION";
	cout<<"\n\t\tPRESS 4: ADD EMPLOYEE'S INFORMATION";
	cout<<"\n\t\tPRESS 5: DISPLAY EMPLOYEE'S LIST";
	cout<<"\n\t\tPRESS 6: DISPLAY CUSTOMER'S LIST";
	cout<<"\n\t\tPRESS 7: RETURN TO EMPLOYEE'S MENU";
	cout<<"\n\t\tPRESS 8: RETURN TO MAIN MENU";
	do
	{
		cout<<"\n\n\n\n\t\tENTER YOUR CHOICE: ";
		cin>>ei_choice;

		switch(ei_choice)
		{
			case 1:		e.e_search();
					break;

			case 2:		e.e_delete();
					break;

			case 3:         e.e_modify();
					break;

			case 4:         e.e_append();
					break;

			case 5:		readfrom();
					break;

			case 6:         readcustomer();
					break;

			case 7:         e.e_menu();
					break;

			case 8:		screen();
					break;

			default:	cout<<"\n\t\tWRONG CHOICE!!CHOOSE AGAIN!";
					cout<<"\n\t\tENTER YOUR CHOICE: ";
					cin>>ch;
					break;
		}//end of switch
	}while(ch=='y'|| ch=='Y');//end of do-while loop

}

	//------------ FUNCTION TO GET EMPLOYEE ID -------------------


int employee :: e_get_id()
{
	return e_id;
}



	//------------ FUNCTION TO INPUT EMPLOYEE INFO ----------------

int employee::e_getinfo()
{

	char c;
	employee e1;
	randomize();
	ifstream fin;
	fin.open("employee.dat",ios::binary);
	do
	{
		e_id=random(49)+1;
		fin.read((char*)&e1,sizeof(e1));
	}while(e_id==e1.e_get_id());

	cout<<"\t\t\tEMPLOYEE'S ID NUMBER: "<<e_id;


	getch();

	cout<<"\n\t\t\tEMPLOYEE'S RECORD INPUT";
	cout<<"\n\t\t\tENTER EMPLOYEE'S NAME: ";
	gets(e_name);

	cout<<"\t\t\tENTER EMPLOYEE'S ADDRESS: ";
	gets(e_address);
	cout<<"\t\t\tENTER EMPLOYEE'S PHONE NUMBER: ";
	cin>>e_ph_no;
	cout<<"\t\t\tENTER EMPLOYEE'S JOINING YEAR: ";
	cin>>e_jyear;


	fin.close();
	return 0  ;

}



	//---------- FUNCTION TO READ BINARY FILE NAMED EMPLOYEE ----------

void readfrom()
{
	clrscr();

	ifstream rf;
	rf.open("employee.dat",ios::binary);
	if (!rf)
	{
		exit(1);
	}
	employee e;

	while(!rf.eof())
	{
	      rf.read((char*)&e,sizeof(e));
	      if(!rf.good())
	      {
			break;
	      }

	      e.e_show();


	}
	rf.close();


	employee_info();
	getch();

}


	//------------- FUNCTION TO SEARCH EMPLOYEE INFO --------------

void employee :: e_search()
{
	clrscr();
	employee e;
	int input;
	cout<<"\nENTER THE EMPLOYEE ID: ";
	cin>>input;

	ifstream es;
	es.open("employee.dat",ios::binary);
	if(!es)
	{
		cout<<"\nCAN'T OPEN FILE";
		exit(1);
	}

	while(!es.eof())
	{
		es.read((char*)&e,sizeof(e));
		if(input==e.e_get_id())
		{
			e.e_show();
			break;
		}
	}


	if(es.eof())
	{
		cout<<"\nRECORD OF EMPLOYEE WITH SUCH ID NUMBER DOESN'T EXISTS";
	}
	es.close();
	getch();

	employee_info();


}



	//------------- FUNCTION TO DELETE EMPLOYEE INFO -------------

void employee :: e_delete()
{
	employee e;
	ifstream edi;
	ofstream edo;

	clrscr();
	int input;
	int flag=0;

	edi.open("employee.dat", ios::binary);
	edo.open("temp.dat",ios::binary);

	cout<<"\n\t\t\tENTER THE EMPLOYEE'S ID NUMBER: ";
	cin>>input;

	while(!edi.eof())
	{
		edi.read((char*)&e,sizeof(e));
		if(!edi.good())
		{
			break;
		}

		if(input!=e.e_get_id())
		{

			edo.write((char*)&e,sizeof(e));
		}

		else
		{
			flag=1;
		}
	}
	edo.close();
	edi.close();

	if(flag==0)
	{
		cout<<"\nRECORD OF EMPLOYEE WITH SUCH ID NUMBER DOESN'T EXISTS";
	}

		remove("employee.dat");
		rename("temp.dat","employee.dat");


	getch();
	employee_info();
}



	//------------ FUNCTION TO MODIFY EMPLOYEE INFO -----------------

void employee :: e_modify()
{
	fstream em;
	clrscr();
	em.open("employee.dat",ios::binary|ios::in|ios::out);

	int id,pos,flag=0;
	cout<<"\n\t\t\tENTER THE EMPLOYEE'S ID NUMBER: ";
	cin>>id;

	while(!em.eof())
	{
		pos=em.tellg();

		em.read((char*)&e,sizeof(e));

		if(!em.good())
		break;

		if(id==e.e_get_id())
		{
			e.e_show();

			cout<<"\n\n\t\t\tEMPLOYEE'S RECORD INPUT";
			cout<<"\n\t\t\tENTER EMPLOYEE'S NAME: ";
			gets(e_name);

			cout<<"\t\t\tENTER EMPLOYEE'S ADDRESS: ";
			gets(e_address);
			cout<<"\t\t\tENTER EMPLOYEE'S PHONE NUMBER: ";
			cin>>e_ph_no;
			cout<<"\t\t\tENTER EMPLOYEE'S JOINING YEAR: "<<e_jyear;

			em.seekg(pos);
			em.write((char*)&e,sizeof(e));
			break;

		}
		else
		{
			cout<<"\nNO SUCH USER EXISTS!";
			flag=1;
		}
	}
	if(flag==1)
	{
		cout<<"\nRECORD OF EMPLOYEE WITH SUCH ID NUMBER DOESN'T EXISTS!"<<endl;
	}

	em.close();
	employee_info();

}



	//---------- FUNCTION TO ADD EMPLOYEE INFO ------------------

void employee :: e_append()
{
	clrscr();
	int flag=0;
	ofstream ea;
	ea.open("employee.dat",ios::binary|ios::app);

	char ch='y';
	while(ch=='y')
	{
		flag=e.e_getinfo();
		clrscr();
		if(!flag)
		{
			ea.write((char*)&e,sizeof(e));
		}

		cout<<"\n\t\tDO YOU WANT TO ENTER MORE(Y/N)??";
		cin>>ch;
	}
	ea.close();
	employee_info();

}



	//------------ FUNCTION TO DISPLAY EMPLOYEE INFO ---------------

void employee::e_show()
{

	cout<<"\n\n\t\t\t\tEMPLOYEE'S RECORD";
	cout<<"\n\t\tNAME : "<<e_name;
	cout<<"\n\t\tID : "<<e_id;
	cout<<"\n\t\tADDRESS : "<<e_address;
	cout<<"\n\t\tPHONE NUMBER :"<<e_ph_no;
	cout<<"\n\t\tJOINING YEAR :"<<e_jyear;
	getch();

}


//***********************************************************************




/*********************************************************************
**********************  FUNCTIONS RELATED TO CUSTOMER******************
*********************************************************************/


	//------------ FUNCTION TO DISPLAY CUSTOMER INFO ---------------

void customer::c_show()
{

	cout<<"\n\n\t\t\t\tCUSTOMER'S RECORD";
	cout<<"\n\t\tFIRST NAME : "<<c_name1;
	cout<<"\n\t\tLAST NAME : "<<c_name2;
	cout<<"\n\t\tADDRESS : "<<c_address;
	cout<<"\n\t\tPHONE NUMBER :"<<c_ph_no;
	cout<<"\n\t\tEMAIL ID :"<<c_id;
	cout<<"\n\t\tUSERNAME :"<<c_name;
	cout<<"\n\t\tPASSWORD :"<<c_pass1;
	getch();

}



	//---------- FUNCTION TO READ BINARY FILE NAMED EMPLOYEE ----------

void readcustomer()
{
	clrscr();

	ifstream rc;
	rc.open("customer.dat",ios::binary);
	if (!rc)
	{
		exit(1);
	}
	customer c;

	while(!rc.eof())
	{
	      rc.read((char*)&c,sizeof(c));
	      if(!rc.good())
	      {
			break;
	      }

	      c.c_show();


	}
	rc.close();


	employee_info();
	getch();

}

	  //----------FUNCTION OF CUSTOMER LOGIN--------
void customer::c_login()
{
clrscr();
int ch,ch1,flag=0;
char pass[5],uname[30];

while(1)
{
	cout<<"\n\n\t\t\t1>NEW USER";
	cout<<"\n\n\t\t\t2>OLD USER";
	cout<<"\n\n\t\t\t3>RETURN TO MAIN MENU";
	cout<<"\n\n\n\t\tENTER YOUR CHOICE: ";
	cin>>ch;

	clrscr();

	switch(ch)
	{
		case 1:
			c_append();
			break;

		case 2:
			cout<<"\n\n\t\t\t USERNAME: ";
			cin>>uname;

			ifstream fin;
			fin.open("customer.dat",ios::binary);
			if(!fin)
			{
				cout<<"\n\t\tNO SUCH USER EXISTS";


			}
			while(!fin.eof())
			{
				fin.read((char*)&ctemp,sizeof(ctemp));
				if(!strcmp(uname,ctemp.c_name))
				{

					flag=1;
					break;
				}
			}//end of whileloop
			cout<<"\nNAME ->"<<ctemp.c_name;

			fin.close();


			if(flag)
			{

				cout<<"\n\t\t\t PASSWORD: ";

				char ch,c1,pw[10];

				for(int i=0;i<5;i++)
				{
					c1=getch();

					if(c1==13)
					{
						pw[i]='\0';
						break;

					}

					else if(c1!='\b')
					{
						cout<<"*";
						pw[i]=c1;
					}

					else
					{
						i=i-2;
						cout<<"\b \b";

					}
				}//end of forloop
				pw[i]='\0';
				strcpy(pw,pass);

				if(!strcmp(pass,ctemp.c_pass1))
				{
					while(1)
					{
						clrscr();
						cout<<"\n\n\t\t\tWELCOME , "<<c_name1;
						cout<<"\n\n\t\t\t1> MENU";
						cout<<"\n\t\t\t2>RETURN TO MAIN MENU ";
						cout<<"\nENTER YOUR CHOICE: ";
						cin>>ch1;


						switch(ch1)
						{
							case 1 :
								clrscr();
								pizzaMenu();
								break;

							case 2:
								screen();
								break;

							default :
								clrscr();
								cout<<"\n\t\tWRONG INPUT PLEASE ENTER VALID NUMBER " ;
						}

					}//end of whileloop

				}
				else
				{
					cout<<"\n\t\t\tWRONG PASSWORD";
					getch();
				}
			}

			else
			{
				cout<<"\n\t\tNO SUCH USER EXISTS";

			}
			break;
		case 3:
			screen();
			break;

		default:
			cout<<"WRONG INPUT PLEASE ENTER VALID INPUT";
			break;
	}
}//end of while loop
}


	   //-------------FUNCTION TO ADD NEW CUSTOMER---------

void customer::c_append()
{
	clrscr();
	int ch2;
	cout<<"\n\n\t\t\tFIRST NAME:";
	cin>>c_name1;
	cout<<"\n\t\t\tLAST NAME:";
	cin>> c_name2;
	cout<<"\n\t\t\tADDRESS:";
	gets(c_address);
	cout<<"\n\t\t\tPHONE NUMBER:";
	cin>>c_ph_no;
	cout<<"\n\t\t\tEMAIL ID:";
	cin>>c_id;
	cout<<"\n\t\t\tUSERNAME: ";
	cin>>c_name;

	cout<<"\n\t\t\tPASSWORD( ATMOST 4 LETTERS ): ";

		char ch,c1,pw[10];

	for(int i=0;i<5;i++)
	{
		c1=getch();

		if(c1==13)
		{
			pw[i]='\0';
			break;

		}

		else if(c1!='\b')
		{
			cout<<"*";
			pw[i]=c1;
		}

		else
		{
			i=i-2;
			cout<<"\b \b";

		}
	}
	pw[i]='\0';
	strcpy(pw,c_pass1);

	ctemp=c;

	ofstream fout;
	fout.open("customer.dat",ios::binary|ios::app);

	fout.write((char*)&(ctemp),sizeof(ctemp));
	fout.close();

	clrscr();



	c_login();


}


void screen()
{
	clrscr();
	int s_choice;
	gotoxy(17,7);
	cout<<"WELCOME TO THE YUMMIEST PIZZA PARLOUR IN TOWN!!";
	gotoxy(10,9);
	cout<<"1> EMPLOYEE";
	gotoxy(10,11);
	cout<<"2> CUSTOMER";
	gotoxy(10,13);
	cout<<"3> EXIT";
	gotoxy(9,17);
	cout<<"ENTER YOUR CHOICE: ";

	cin>>s_choice;
	while(1)
	{
		if(s_choice==1)
		{
		       e.password();
		}
		else if(s_choice==2)
		{
			c.c_login();
		}
		else if(s_choice==3)
		{
			exit(1);
		}
		else
		{
			cout<<"\nWRONG INPUT!!CHOOSE AGAIN";
			screen();
		}
	}
}

//************************MAIN FUNCTION********************************
void main()
{
	clrscr();
	textcolor(GREEN);
	textbackground(0);
	loading_scr();
	clrscr();
	textbackground(12);
	textcolor(14);
	gotoxy(20,10);
	marquee_effect("WELCOME TO CENTRAL PERK!\n\n",60);
	marquee_effect("The One Where it All Started!!",60);
			//LOGO PRINTING and use of delay to make sequential

		textcolor(14);

	cout<<"		       	                           ______________	"<<endl;
	  delay(150);
	cout<<"                          ________________	"<<endl;
	  delay(150);
	cout<<"                        ...______________...      "<<endl;
	  delay(150);
	cout<<"                       '+++,,,,,,,,,,,,,,+++'	"<<endl;
	  delay(150);
	cout<<"                         ++++++++++++++++++ "<<endl;
	delay(2500);
getch();
clrscr();
			    //loader function using delay and gotoxy

	employee e;
	customer c;
	ifstream fin;
	fin.open("pizza.dat",ios::binary|ios::noreplace);
	if(!fin)
	{
		createPizza();
	}

	fin.close();

	fin.open("sides.dat",ios::binary|ios::noreplace);

	if(!fin)
	{       textbackground(5);
		createSides();
	}

	fin.close();
	getch();
																									screen();

	getch();
}

void loading_scr()                                 //LOADING SCREEN FUNCTION
{
	clrscr();
	textcolor(GREEN);
	int x=0;
//	cout<<endl<<"                            CENTRAL PERK"<<endl;
  //	  delay(150);
    //	cout<<"                     THE ONE WHERE IT ALL STARTED";
      //	  delay(2500);
 //	clrscr();
			    //loader function using delay and gotoxy
	gotoxy(30,13);
	cout<<"LOADING...";

	for(int i=1; i<=10; i++)
	{
		gotoxy(30+x,14);
		delay(500);

		cout<<"__";
		x+=2;

		gotoxy(52,14);
		cout<<i*10<<"%";
	}

	gotoxy(35,17);
	cout<<"COMPLETE!";

	gotoxy(50,21);
	cout<<"PRESS ANY KEY TO CONTINUE";
	getch();
	clrscr();
}

//***************************** END *****************************
