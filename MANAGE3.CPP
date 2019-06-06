



#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<process.h>

class hotel
{
 private :
	 char name[30] , address[50] , emailid[20] , type ;
	 long double  phoneno , charge ;
	 int  nm , roomno ;
 public :
	 void checkin() ;
	 void checkout () ;
	 void search() ;
	 int  check(int) ;
	 void modify() ;
	 void rooms() ;
	 void calculate() ;
	 void display() ;
}  h ;

 void hotel :: checkin()
  {
   clrscr () ;
   int t , r ;
   ofstream hfile("hoten.dat",ios :: app | ios :: binary ) ;
   cout << "\nEnter the customer details\n" ;
   cout << "Enter the room number of the person : " ;
   cin >> r ;
   t = check(r) ;
   if(t)
    cout << "\nSorry....!!!Room is already booked" ;
   else
    {
     roomno = r ;
     cout << "Enter the name of the person : " ;
     gets(name) ;
     cout << "Enter the address of the person : "  ;
     gets(address) ;
     cout << "Enter the phone number of the person : " ;
     cin >> phoneno ;
     cout << "Enter the email id of the person : " ;
     gets(emailid) ;
     calculate() ;
     cout << "\nYour room is booked !!!!!!!!!!!" ;
     hfile.write((char*)&h,sizeof(h)) ;
    }
     hfile.close() ;
  }
  int hotel :: check(int r)
  {
   int t = 0 ;
   ifstream hfilt("hoten.dat",ios :: binary) ;
   while(hfilt.read((char*)&h,sizeof(h)) )
    if(roomno == r)
     {
      t = 1 ;
      break ;
     }
   hfilt.close() ;
   return(t) ;
  }
 void hotel :: checkout()
 {
  clrscr() ;
  int f = 0 , i = 1 , rmno ;
  cout << "\nEnter the room number of the person who want to check out : " ;
  cin >> rmno ;
  ifstream hfile1("hoten.dat" , ios :: binary ) ;
  ofstream temp("temp.dat",ios :: app | ios :: binary  )  ;
  while(hfile1.read((char*)&h,sizeof(h)) )
   if(roomno == rmno)
     f = 1 ;
   else
     temp.write((char*)&h,sizeof(h)) ;
  hfile1.close() ;
  temp.close() ;
  remove("hoten.dat");
  rename("temp.dat","hoten.dat");
  if(f)
   {
    ifstream hfile2("hoten.dat" , ios :: binary ) ;
    gotoxy(1,1) ;    cout << "\n*********************The new record list after modification******************" ;
    gotoxy(4,3)  ; cout  <<    "NAME"   ;
    gotoxy(16,3) ; cout  <<    "ADDRESS" ;
    gotoxy(28,3) ; cout  <<    "PHONE NUMBER" ;
    gotoxy(45,3) ; cout  <<    "EMAIL ID" ;
    gotoxy(59,3) ; cout  <<    "ROOMNUMBER" ;
    gotoxy(74,3) ; cout  <<    "TYPE"       ;
    while(hfile2.read((char*)&h,sizeof(h)))
    {
     gotoxy(4,5+i)  ; cout  <<   name   ;
     gotoxy(16,5+i) ; cout  <<   address ;
     gotoxy(34,5+i) ; cout  <<   phoneno ;
     gotoxy(45,5+i) ; cout  <<   emailid ;
     gotoxy(59,5+i) ; cout  <<   roomno  ;
     gotoxy(74,5+i) ; cout  <<   type ;
     i+=2 ;
     getch() ;
     }
    hfile2.close() ;
   }
  if(!f)
   cout << "\nDoes not match to the record" ;
 }


  void hotel :: search ()
 {
   clrscr () ;
   int flag = 0 , rno ;
   ifstream hf("hoten.dat" , ios :: binary ) ;
   cout << "\nEnter the room number of the person who you want to find : " ;
   cin >> rno ;
   while(hf.read((char*)&h,sizeof(h)))
   {
    if(roomno ==  rno)
     {
      cout << "\n" << "Name of the guest is registered in the record" ;
      cout << "\n" << "The name of the person : " << name ;
      cout << "\n" << "The address of the person : " << address ;
      cout << "\n" << "The phone number of the person : " <<  phoneno ;
      cout << "\n" << "The email id of the person : " << emailid ;
      cout << "\n" << "The room number of the person : " << roomno ;
      flag = 1 ;
      break ;
     }
   }
   if(!flag)
     cout << "\nDoes not match to our hotel record" ;
    hf.close();
 }


 void hotel :: modify()
 {
   clrscr() ;
   int r ;
   long pos ;
   int t = 0 ;
   cout << "\nEnter the room number in which you made changes : " ;
   cin >> r ;
   fstream file("hoten.dat",ios :: in | ios :: out | ios :: binary) ;
   while(!file.eof())
   {
    pos = file.tellg() ;
    file.read((char*)&h,sizeof(h));
    if(roomno ==  r)
     {
      cout << "\nThe modified detail of the customer\n" ;
      cout << "\nEnter the name of the person = " ;
      gets(name) ;
      cout << "\nEnter the address of the person = " ;
      gets(address) ;
      cout << "\nEnter the phone number of the person = " ;
      cin >>  phoneno ;
      cout << "\nEnter the email id of the person = " ;
      gets(emailid) ;
      file.seekg(pos) ;
      file.write((char*)&h,sizeof(h)) ;
      cout << "\nRecord is modified !!!!!\n" ;
      t = 1 ;
      break ;
     }
     }
    if(!t)
     cout << "\nRoom number not found or vacant.......!!!!\n" ;
     file.close() ;
 }
 void hotel :: rooms()
 {
  clrscr() ;
  int i = 1 ;
  ifstream fil("hoten.dat",ios :: binary);
  cout << "***************************The list of all records************************"   ;
  gotoxy(4,3)  ; cout  <<    "NAME"   ;
  gotoxy(16,3) ; cout  <<    "ADDRESS" ;
  gotoxy(28,3) ; cout  <<    "PHONE NUMBER" ;
  gotoxy(45,3) ; cout  <<    "EMAIL ID" ;
  gotoxy(59,3) ; cout  <<    "ROOMNUMBER" ;
  gotoxy(74,3) ; cout  <<    "TYPE"       ;
   while(fil.read((char*)&h,sizeof(h)))
    {
     gotoxy(4,5+i)  ; cout  <<   name   ;
     gotoxy(16,5+i) ; cout  <<   address ;
     gotoxy(34,5+i) ; cout  <<   phoneno ;
     gotoxy(45,5+i) ; cout  <<   emailid ;
     gotoxy(59,5+i) ; cout  <<   roomno  ;
     gotoxy(74,5+i) ; cout  <<   type ;
     i+=2 ;
     getch() ;
    }
   fil.close() ;
 }

 void hotel :: calculate ()
   {
    // clrscr() ;
     gotoxy(2,10) ;   cout << "PRESS FOR              " ;
     gotoxy(4,11) ;   cout << " S   SUPER LUXARY ROOM " ;
     gotoxy(4,12) ;   cout << " L   LUXARY ROOM " ;
     gotoxy(4,13) ;   cout << " D   DELUX ROOM " ;
     gotoxy(4,14) ;   cout << " C   CABANA ROOM " ;
     gotoxy(4,15) ;   cout << " K   KING BEDROOM " ;
     gotoxy(4,16) ;   cout << " Q   QUEEN BEDROOM " ;
     cout << "\n\nSelect the type of room : " ;
     cin >> type ;
     cout << "Enter the number of day for which you want to book a room : " ;
     cin >> nm ;
     if(toupper(type) == 'S')
      charge = 10000 * nm  ;
     else if(toupper(type) == 'L')
      charge = 7000 * nm ;
     else if(toupper(type) == 'D')
      charge = 5000 * nm ;
     else if(toupper(type) == 'C')
      charge = 9000 * nm ;
     else if(toupper(type) == 'K')
       charge = 11000 * nm ;
     else if(toupper(type) == 'Q')
       charge = 10500 ;
     else
      {
       cout<< "\nWrong choice... " ;
       exit(0) ;
      }
   }

 void hotel :: display()
  {
   clrscr() ;
   int f = 0 ;
   int rmno ;
   cout << "\n\nEnter the room number for which you want to see the bill details : " ;
   cin  >> rmno ;
   ifstream hfile9("hoten.dat" , ios :: binary ) ;
   while(hfile9.read((char*)&h,sizeof(h)) )
    if(roomno == rmno)
     {
      f = 1 ;
      cout << " \n*********************SHYAM HOTEL*********************" ;
      cout << "\n\n\n          $$$$$$ YOUR TOTAL BILL DETAIL S$$$$$$" ;
      cout << "\n\n             CUSTOMER NAME      : "  << name ;
      cout << "\n\n             STAYED FOR         : "  << nm << " DAYS" ;
      cout << "\n\n             ROOM CHARGE        : "  << charge ;
      cout << "\n\n             SERVICE TAX(5%)    : "  << charge * 0.05  ;
      cout << "\n\n             TOTAL AMOUNT       : "  << charge + (charge * 0.05)  ;
     }
     if(!f)
     cout << "\nDOES NOT MATCH TO OUR LIST " ;
  }
  void main ()
   {
     clrscr () ;
     int choice ;
     char ch ;
     do
     {
      clrscr() ;
      cout << "\n\n     ******************* WELCOME TO THE SHYAM HOTEL *********************\n\n" ;
      cout << "\nPress for                  \n"
	    << "1       Add a guest        \n"
	    << "2       Remove a guest     \n"
	    << "3       Search for a guest \n"
	    << "4       To modify the record\n"
	    << "5       To show list of all record\n"
	    << "6       To show the total bill    \n"
	    << "0       To exit the program \n" ;
       cout << "\nEnter the choice of the user : " ;
       cin >> choice ;
       switch(choice)
       {
	  case 1 :
		 h.checkin() ;
		 break ;
	  case 2 :
		 h.checkout() ;
		 break ;
	  case 3 :
		 h.search() ;
		 break ;
	  case 4 :
		 h.modify() ;
		 break ;
	  case 5 :
		 h.rooms() ;
		 break ;

	  case 6 :
		 h.display() ;
		 break ;
	  case 0 :
		  exit(0);
		  break ;

	  default :
		  cout << "\n\nDoes not match to our options" ;

	}
	cout << "\n\n\nWant to go back to the options again(y\n) :  "  ;
	cin >> ch ;
     }
       while(toupper(ch) == 'Y') ;
       getch() ;
   }










































































































































































































