#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

// This is a function used to compute f(x, y).
int display_menu(string x, string y)
{
	int option;
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("        Main Menu  \n\n");
	printf("Option        Item \n");
	printf("   1.       Enter x\n");
	printf("   2.       Enter y\n");
	printf("   3.       Sum:           x + y\n");
	printf("   4.       Difference:    x - y\n");
	printf("   5.       Multiply:      x * y\n");
	printf("   6.       pow(x,y):      x ^ y\n");
	printf("   7.       Display x in binary: \n");
	printf("   8.       Display y in binary: \n");
	printf("   9.       Display x in decimal: \n");
	printf("   10.      Display y in decimal: \n");
	printf("   11.      Display # of decimal digits for x: \n");
	printf("   12.      Display # of decimal digits for y: \n");
	printf("   13.      Display # of binary digits for x: \n");
	printf("   14.      Display # of binary digits for y: \n");
	printf("   15.      Check divisibility of x by 2,3,5,7,11,13,17: \n");
	printf("   16.      Check divisibility of y by 2,3,5,7,11,13,17: \n");
	printf("   17.      Find quotient of x/y: \n");
	printf("   18.      Find remainder of x/y: \n");
	printf("   19.      Find approx natural log of x: \n");
	printf("   20.      Find approx natural log of y: \n");
	printf("   21.      Find approx reciprocal of x: \n");
	printf("   22.      Find approx reciprocal of y: \n\n");
	printf("   0.       QUIT\n\n\n\n");
	
	cout<<"x = "<< x<<endl<<endl;
	cout<<"y = "<< y<<endl<<endl;
	
	
	printf("Enter option:  1 - 22, or 0 to quit:     ");
	
   cin >> option;
	   
	return(option);
}

string subtract(string x, string y)
{
string X [max(x.length(),y.length())];
string Y [max(x.length(),y.length())];		//initialize X and Y array as max of two because one will eventually be 0 padded to same length
string difference [max(x.length(),y.length())];
string final;
int adjust = 0;
bool xbigger = false;
bool ybigger = false;


for(int i=0;i<x.length();i++)        		//create X and Y array with each cell being a single digit of strings x and y respectively
	X[i] = x.substr(x.length()-1-i,1); 

for(int j=0;j<y.length();j++)
	Y[j] = y.substr(y.length()-1-j,1);

	if(x.length() > y.length())						//0 padding depending on largest of two
	{
		for(int i=y.length();i<x.length();i++)
			Y[i] = "0";
	}
	else if (y.length() > x.length())
	{
		for(int i=x.length();i<y.length();i++)
			X[i] = "0";
	}
int it = (sizeof(X)/sizeof(X[0]))-1;	
do
{
if(X[it]>Y[it])	
	xbigger = true;
else if (Y[it]>X[it])
	ybigger = true;
else
	it--;
}
while((xbigger == false) && (ybigger == false) && it>=0);	


if(xbigger == true)
{
	
	for(int k=0;k<(sizeof(X)/sizeof(X[0]));k++)
	{
		int num1 = atoi(X[k].c_str());						//cast string digit to integer 
		int num2 = atoi(Y[k].c_str());
		string temp;
			
			temp = static_cast<ostringstream*>( &(ostringstream() << (10+((num1-num2-adjust)%10))%10 ))->str();			//convert mod summation to string and store in difference array
			difference[k] = temp;

			if((num1-num2-adjust) < 0)					//check if need to adjust next left digit by subtracting one
				adjust = 1;
			else
				adjust = 0;
	}
	for(int l=(sizeof(difference)/sizeof(difference[0]))-1;l>=0;l--)
		final = final + difference[l];									//create string based on difference array to return to main function
	
}
else if(ybigger == true)
{
	for(int k=0;k<(sizeof(X)/sizeof(X[0]));k++)
	{
		int num1 = atoi(X[k].c_str());						//cast string digit to integer 
		int num2 = atoi(Y[k].c_str());
		string temp;
			
	
				temp = static_cast<ostringstream*>( &(ostringstream() << (10+((num2-num1-adjust)%10))%10 ))->str();			//convert mod summation to string and store in difference array
				difference[k] = temp;

			if((num2-num1) < 0)					//check if need to adjust next left digit by subtracting one
				adjust = 1;
			else
				adjust = 0;
	}
	for(int l=(sizeof(difference)/sizeof(difference[0]))-1;l>=0;l--)
		final = final + difference[l];									//create string based on difference array to return to main function
		
	final = "-"+final;
}

else
	final = "0";
	


for(int i=0;i<final.length();i++)
{
	if(final.substr(0,1) == "0" && final.length()>1)
		final.erase(0,1);
	else if(final.substr(0,1) == "-" && final.substr(1,1) == "0")
		final.erase(1,1);
	else
		break;
}
	
if(x == y)
	final = "0";

	
return final;
}

string add(string x, string y)
{
string X [max(x.length(),y.length())];
string Y [max(x.length(),y.length())];		//initialize X and Y array as max of two because one will eventually be 0 padded to same length
string sum [max(x.length(),y.length())];
string final;
int carry = 0;
bool negative = false;

if(x.substr(0,1) == "-" && y.substr(0,1) != "-")
{
	x = x.substr(1,x.length()-1);
	final = subtract(y,x);
	return final;
}
else if(x.substr(0,1) != "-" && y.substr(0,1) == "-")
{
	y = y.substr(1,y.length()-1);
	final = subtract(x,y);
	return final;
}
else if(x.substr(0,1) == "-" && y.substr(0,1) == "-")
{
	negative = true;
	x = x.substr(1,x.length()-1);
	y = y.substr(1,y.length()-1);
}


for(int i=0;i<x.length();i++)        		//create X and Y array with each cell being a single digit of strings x and y respectively
	X[i] = x.substr(x.length()-1-i,1); 

for(int j=0;j<y.length();j++)
	Y[j] = y.substr(y.length()-1-j,1);

	if(x.length() > y.length())						//0 padding depending on largest of two
	{
		for(int i=y.length();i<x.length();i++)
			Y[i] = "0";
	}
	else if (y.length() > x.length())
	{
		for(int i=x.length();i<y.length();i++)
			X[i] = "0";
	}

for(int k=0;k<(sizeof(X)/sizeof(X[0]));k++)
{
int num1 = atoi(X[k].c_str());						//cast string digit to integer 
int num2 = atoi(Y[k].c_str());
string temp;

if(k!=(sizeof(X)/sizeof(X[0]))-1)	
{	
	temp = static_cast<ostringstream*>( &(ostringstream() << ((num1+num2+carry)%10)) )->str();			//convert mod summation to string and store in sum array
	sum[k] = temp;	
}
else
{
	temp = static_cast<ostringstream*>( &(ostringstream() << (num1+num2+carry)) )->str();             //if last position mod does not matter
	sum[k] = temp;
}
if((num1+num2+carry) > 9)					//check if need for carry
	carry = 1;
else
	carry = 0;
}
	
for(int l=(sizeof(sum)/sizeof(sum[0]))-1;l>=0;l--)
	final = final + sum[l];							//create string based on sum array to return to main function
	
if(negative == true)
	final.insert(0,"-");
	
for(int i=0;i<final.length();i++)
{
	if(final.substr(0,1) == "0" && final.length()>1)
		final = final.substr(1,final.length()-1);
	else if(final.substr(0,1) == "-" && final.substr(1,1) == "0")
		final = "-" + final.substr(2,final.length()-2);
	else
		break;
}
	
return final;
}

string multiply(string x, string y)
{
string X [x.length()];
string Y [y.length()];		
string tempstring, tempstring1, result;
int carry, temp;
bool negative;

if(x.substr(0,1) == "-" && y.substr(0,1) != "-")				//check negative cases so dont use "-" as character, only add at end if negative == true
{
	negative = true;
	x = x.substr(1,x.length()-1);
}
else if(y.substr(0,1) == "-" && x.substr(0,1) != "-")
{
	negative = true;
	y = y.substr(1,y.length()-1);
}
else if(y.substr(0,1) == "-" && x.substr(0,1) == "-")
{
	x = x.substr(1,x.length()-1);
	y = y.substr(1,y.length()-1);
	negative = false;
}
else
	negative = false;

for(int i=0;i<x.length();i++)        		//create X and Y array with each cell being a single digit of strings x and y respectively
	X[i] = x.substr(x.length()-1-i,1); 

for(int j=0;j<y.length();j++)
	Y[j] = y.substr(y.length()-1-j,1);


for(int i=0;i<=min(x.length(),y.length())-1;i++)
{	
	carry = 0;
	for(int j=0;j<=max(x.length(),y.length())-1;j++)
	{
		if(x.length() >= y.length())
		{
			int num1 = atoi(X[j].c_str());						//cast string digit to integer 
			int num2 = atoi(Y[i].c_str());
		
			temp = (carry + num2*num1) % 10;
			tempstring += static_cast<ostringstream*>( &(ostringstream() << (temp )))->str();				//mult algorithm
			carry = (carry + num2*num1)/10;
			
			if(j == max(x.length(),y.length())-1)
				tempstring += static_cast<ostringstream*>( &(ostringstream() << (carry )))->str();
				
		}
		else
		{
			int num1 = atoi(X[i].c_str());						//cast string digit to integer, switch if Y happens to be more digits than X
			int num2 = atoi(Y[j].c_str());
			
			temp = (carry + num2*num1) % 10;
			tempstring += static_cast<ostringstream*>( &(ostringstream() << (temp )))->str();
			carry = (carry + num2*num1)/10;
			
			if(j == max(x.length(),y.length())-1)
				tempstring += static_cast<ostringstream*>( &(ostringstream() << (carry )))->str();
				
			
		}
	}
	
	for(int b=tempstring.length()-1;b>=0;b--)
		tempstring1 += tempstring.substr(b,1);
		
	for(int a=0;a<i;a++)
		tempstring1 += "0";

	if(i == 0)
		result = tempstring1;
	else
		result = add(result,tempstring1);					//use "add" method to add each consecutive digit place
	
	tempstring.clear();
	tempstring1.clear();
	
}
if(negative == true)
	result = result.insert(0,"-");
if(result.substr(0,1) == "0")												//deal with extra 0's in front, and placement of "-" if negative == true
	result = result.substr(1,result.length()-1);
if(result.substr(0,1) == "-" && result.substr(1,1) == "0")
	result = result.substr(0,1) + result.substr(2,result.length()-2);
	
return result;
}

string power(string x, string y)
{
string temp,result;
string iterations = "0";
bool negative;


if(x.substr(0,1) == "-" && (y.substr(y.length()-1,1) == "0" || y.substr(y.length()-1,1) == "2" || y.substr(y.length()-1,1) == "4" || y.substr(y.length()-1,1) == "6" || y.substr(y.length()-1,1) == "8"))				//check negative cases so dont use "-" as character, only add at end if negative == true
{
	negative = false;
	x = x.substr(1,x.length()-1);
}
else if(x.substr(0,1) == "-" && (y.substr(y.length()-1,1) == "1" || y.substr(y.length()-1,1) == "3" || y.substr(y.length()-1,1) == "5" || y.substr(y.length()-1,1) == "7" || y.substr(y.length()-1,1) == "9"))
{
	negative = true;
	x = x.substr(1,x.length()-1);
}

do				//power algorithm which has iterative use of multiply function
{
	if(iterations == "0")
		temp = multiply(x,x);
	else
		temp = multiply(temp,x);
	
	iterations = add(iterations,"1");
}while(subtract(subtract(y,"2"),iterations).substr(0,1) != "-");

result = temp;	
if(negative == true)							//add "-" if negative x and odd y
	result = result.insert(0,"-");

if(y == "0")									//error checking
	result = "1";
if(y == "1")
	result = x;
if(atoi(y.c_str()) < 0)
	result = "Y input was invalid";	
	
return result;	
}

string dectobin(string x)
{

x = x.insert(0,"0");
string divstring = "";
string binstring = "";
string result;
string tempstring;
int num1, num2;
int iterations = 0;
bool condition = false;
bool negative = false;

if(x.substr(0,1) == "-")
{
	negative = true;
	x = x.substr(1,x.length()-1);
}


do
{
iterations++;
string tempstring = "0";
	for(int i=1;i<x.length();i++)
	{
		if(iterations == 1)
		{
			num1 = atoi(x.substr(i-1,1).c_str());
			num2 = atoi(x.substr(i,1).c_str());
		}
		else
		{
			num1 = atoi(divstring.substr(i-1,1).c_str());
			num2 = atoi(divstring.substr(i,1).c_str());
		}
		if(num1 % 2 == 0)
		{
			if(num2 == 0 || num2 == 1)
			{
				tempstring += "0";
			}
			else if(num2 == 2 || num2 == 3)
			{
				tempstring += "1";
			}
			else if(num2 == 4 || num2 == 5)
			{
				tempstring += "2";
			}
			else if(num2 == 6 || num2 == 7)
			{
				tempstring += "3";
			}
			else
			{
				tempstring += "4";
			}
		}
		else
		{
			if(num2 == 0 || num2 == 1)
			{
				tempstring += "5";
			}
			else if(num2 == 2 || num2 == 3)
			{
				tempstring += "6";
			}
			else if(num2 == 4 || num2 == 5)
			{
				tempstring += "7";
			}
			else if(num2 == 6 || num2 == 7)
			{
				tempstring += "8";
			}
			else
			{
				tempstring += "9";
			}
		}
	
	}

	if(iterations == 1)
	{
		if(atoi(x.substr(x.length()-1,1).c_str()) % 2 == 0)
			binstring += "0";
		else
			binstring += "1";
	}
	else
	{
		if(atoi(divstring.substr(x.length()-1,1).c_str()) % 2 == 0)
			binstring += "0";
		else
			binstring += "1";	
	}
	
	divstring = tempstring;
	
	for(int i=0;i<tempstring.length();i++)
	{
		if(tempstring.substr(i,1) == "0")
			condition = true;
		else
		{
			condition = false;
			break;
		}
	}
	
}while(condition == false);
	
for(int j = binstring.length()-1;j>=0;j--)
	result += binstring.substr(j,1);
	
if(negative == true)
	result = result.insert(0,"-");

return result;	
}

string bintodec(string x)
{
string tempstring;	
string decstring = "0";
string result;
bool decimal = false;
	
for(int i=0;i<x.length();i++)
{
	if(x.substr(i,1) != "1" && x.substr(i,1) != "0")
	{
		decimal = true;
		break;
	}
}	
	
if(decimal == false)	
{
	for(int i=0;i<x.length();i++)
	{
		if(x.substr(i,1) == "1")
		{
			tempstring = power("2",static_cast<ostringstream*>( &(ostringstream() << (x.length()-1-i )))->str());
			decstring = add(decstring,tempstring);
		}
	}
	result = decstring;	
}
else
	result = x;

	
return result;	
}

int ddigitcount(string x)
{
string decstring;
int result;

if(x.substr(0,1) == "-")
	x = x.substr(1,x.length()-1);

decstring = bintodec(x);
result = decstring.length();	
		
return result;	
}

int bdigitcount(string x)
{
string binstring;
int result;

if(x.substr(0,1) == "-")
	x = x.substr(1,x.length()-1);

binstring = dectobin(x);
result = binstring.length();	
	
return result;	
}

string divisibility(string x)
{
string result = "";
bool divisible = false;
string temp,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9;
int iterations = 0;

if(x.substr(0,1) == "-")
	x = x.substr(1,x.length()-1);

if(atoi(x.substr(x.length()-1,1).c_str()) % 2 == 0)	
{
	result += "2, ";
	divisible = true;
}

do
{
iterations++;
temp = "";
if(iterations == 1)
{
	for(int i=0;i<x.length();i++)
		temp = add(temp,x.substr(i,1));	
}
else
{
	for(int i=0;i<temp1.length();i++)
		temp = add(temp,temp1.substr(i,1));
}
	temp1 = temp;
	
}while(temp1.length() > 1);

if(atoi(temp.c_str()) == 3 || atoi(temp.c_str()) == 6 || atoi(temp.c_str()) == 9)
{
	result +="3, ";
	divisible = true;
}
	
if(x.substr(x.length()-1,1) == "0" || x.substr(x.length()-1,1) == "5")
{	
	result += "5, ";	
	divisible = true;
}

iterations = 0;
do
{
	temp2 = "";
	iterations ++;
	if(iterations == 1)
	{
		temp2 = x.substr(0,x.length()-1);
		temp2 = subtract(temp2, multiply("2",x.substr(x.length()-1,1)));
	}
	else
	{
		temp2 = temp3.substr(0,temp3.length()-1);
		temp2 = subtract(temp2, multiply("2",temp3.substr(temp3.length()-1,1)));
	}

	temp3 = temp2;
	
	/*for(int j=0;j<temp3.length()-1;j++)
	{
		if(temp3.substr(j,1) == "0")
			temp3 = temp3.substr(j+1,temp3.length()-1);
		else
			break;
	}*/

}while(temp3.length() > 1 && temp3.substr(0,1) != "-");

if(atoi(temp3.c_str()) % 7 == 0)
{
	result += "7, ";
	divisible = true;
}


	temp4 = "0";
	//x = "5743673106436941681736804386153461304354314593609";
	
		for(int i=0;i<x.length();i++)
		{
			if(i%2 == 0)
				temp4 = add(temp4,x.substr(i,1));
			else
				temp4 = subtract(temp4,x.substr(i,1));
				
			//cout<<temp4<<endl;		
		}

temp5 = temp4;
//cout<<temp5<<endl;

if(atoi(temp5.c_str()) % 11 == 0)
{
	result += "11, ";
	divisible = true;
}

iterations = 0;
do
{
	temp6 = "";
	iterations ++;
	
	if(iterations == 1)
	{
		temp6 = x.substr(0,x.length()-1);
		temp6 = add(temp6, multiply("4",x.substr(x.length()-1,1).c_str()));
	}
	else
	{
		temp6 = temp7.substr(0,temp7.length()-1);
		temp6 = add(temp6, multiply("4",temp7.substr(temp7.length()-1,1).c_str()));
	}

	temp7 = temp6;

}while(temp7.length() > 2 && temp7.substr(0,1) != "-");

if(atoi(temp7.c_str()) % 13 == 0)
{
	result += "13, ";
	divisible = true;
}


iterations = 0;
do
{
	temp8 = "";
	iterations ++;
	
	if(iterations == 1)
	{
		temp8 = x.substr(0,x.length()-1);
		temp8 = subtract(temp8, multiply("5",x.substr(x.length()-1,1).c_str()));
	}
	else
	{
		temp8 = temp9.substr(0,temp9.length()-1);
		temp8 = subtract(temp8, multiply("5",temp9.substr(temp9.length()-1,1).c_str()));
	}

	temp9 = temp8;

}while(temp9.length() > 2 && temp9.substr(0,1) != "-");

if(atoi(temp9.c_str()) % 17 == 0)
{
	result += "17, ";
	divisible = true;
}


if(divisible == false)
	result = "It is not divisible by any of those numbers.";
	
	
return result;
}

string quotient(string x, string y)
{
string result;
string iterations = "1";
string multiple,currentdiff,yorig;
bool negative = false;

if(x.substr(0,1) == "-" && y.substr(0,1) != "-")				//check negative cases so dont use "-" as character, only add at end if negative == true
{
	negative = true;
	x = x.substr(1,x.length()-1);
}
else if(y.substr(0,1) == "-" && x.substr(0,1) != "-")
{
	negative = true;
	y = y.substr(1,y.length()-1);
}
else if(y.substr(0,1) == "-" && x.substr(0,1) == "-")
{
	x = x.substr(1,x.length()-1);
	y = y.substr(1,y.length()-1);
	negative = false;
}
else
	negative = false;
	
	yorig = y;
	
if(atoi(x.substr(0,1).c_str())>atoi(y.substr(0,1).c_str()) && x.length()>y.length())
{
	for(int i=0;i<(x.length() - y.length());i++)
	{
		y += "0";
		iterations += "0";
	}
}
else if(atoi(x.substr(0,1).c_str())<atoi(y.substr(0,1).c_str()) && x.length()>y.length())
{
	for(int i=0;i<(x.length() - y.length()-1);i++)
	{
		y += "0";
		iterations += "0";
	}
}

currentdiff = subtract(x,y);

do
{
currentdiff =subtract(currentdiff,yorig);	
iterations = add(iterations,"1");
}while(currentdiff.substr(0,1) != "-");
	
result = subtract(iterations,"1");

if(negative == true)
	result = result.insert(0,"-");

	
return result;
}

string remain(string x, string y)
{

string multiple,temp,result;
bool negative = false;

if(x.substr(0,1) == "-" && y.substr(0,1) != "-")				//check negative cases so dont use "-" as character, only add at end if negative == true
{
	negative = true;
	x = x.substr(1,x.length()-1);
}
else if(y.substr(0,1) == "-" && x.substr(0,1) != "-")
{
	negative = true;
	y = y.substr(1,y.length()-1);
}
else if(y.substr(0,1) == "-" && x.substr(0,1) == "-")
{
	x = x.substr(1,x.length()-1);
	y = y.substr(1,y.length()-1);
	negative = false;
}
else
	negative = false;
	
multiple = quotient(x,y);
temp = multiply(multiple,y);
result = subtract(x,temp);
	
if(negative == true)
	result = result.insert(0,"-");
	
return result;
}

string naturallog(string x)
{
string ln2 = "6931471806";
string iterations = "0";
string result,temp,powerprod,neg,top,bottom,modification,modification1;
double dtop,dbottom;

if(x.substr(0,1) == "-")
{
	result = "Invalid entry!";
	return result;
}

if(x == "1")
{
	result = "0";
	return result;
}

do
{
temp = powerprod;
powerprod = power("2",iterations);
iterations = add(iterations,"1");
neg = subtract(x,powerprod);
}while(neg.substr(0,1) != "-");
	
if(subtract(subtract(powerprod,x),subtract(x,temp)).substr(0,1) != "-")
{
	iterations = subtract(iterations,"2");
	result = multiply(ln2,iterations);
}
else
{
	result = multiply(ln2,subtract(iterations,"1"));
}
	
if(atoi(iterations.c_str())< 1.445)
	result.insert(0,".");
else if(atoi(iterations.c_str())>= 1.445 && atoi(iterations.c_str()) < 14.425)
	result.insert(1,".");
else if(atoi(iterations.c_str())>= 14.425 && atoi(iterations.c_str()) < 144.27)
	result.insert(2,".");
else
	result.insert(3,".");
	

return result;	
}

string reciprocal(string x)
{
string numerator = "1";
string multiple;
string append = "";
string result = "";
for(int i=0;i<x.length()+3;i++)
	numerator += "0";

multiple = quotient(numerator,x);

for(int j=0;j<x.length()-1;j++)
	append += "0";
	
result = "." + append + multiple;

return result;	
}



// This is the main program.
main()
{
	int option;
	int carry_on;
	int xdigitcount, ydigitcount;
	string x, y;
	string sum,difference,product,powerprod,divisresult,remainder,quot,natlog,recip;
	bool binary = false;
	
   do {
	   option = display_menu(x, y);
	   switch (option)
	   {
	   	case 1:  cout << "Option " << option << "  Enter x" << endl;    
			         cin  >> x;
						break;
	   	case 2:  cout << "Option " << option << "  Enter y" << endl;    
			         cin  >> y;
						break;
	   	case 3:  if(binary == true)
	   			 {
	   				x = bintodec(x);
	   				y = bintodec(y);
	   				sum = add(x,y);
	   				sum = dectobin(sum);
	   				cout << "x + y = " << sum << endl;    
	   				x = dectobin(x);
	   				y = dectobin(y);
			        cin  >> carry_on;
	   			 }
		   		 else
		   		 {
		   		    sum = add(x,y);
			        cout << "x + y = " << sum << endl;    
			        cin  >> carry_on;	
		   		 }
				break;
	   	case 4:  if(binary == true)
		   		 {
	   				x = bintodec(x);
	   				y = bintodec(y);
	   				if(x.substr(0,1) == "-" && y.substr(0,1) != "-")
	   				{
	   					x = x.substr(1,x.length()-1);
	   					difference = add(x,y);
	   					difference.insert(0,"-");
	   				}
	   				else if(x.substr(0,1) != "-" && y.substr(0,1) == "-")
	   				{
	   					y = y.substr(1,y.length()-1);
	   					difference = add(x,y);	
	   				}
	   				else if(x.substr(0,1) == "-" && y.substr(0,1) == "-")
	   				{
	   					x = x.substr(1,x.length()-1);
	   					y = y.substr(1,y.length()-1);
	   					difference = subtract(y,x);
	   				}
	   				else
	   				{
	   					difference = subtract(x,y);
	   				}
	   				difference = dectobin(difference);
	   				cout << "x - y = " << difference << endl;    
	   				x = dectobin(x);
	   				y = dectobin(y);
			        cin  >> carry_on;
	   			 }
	   			 else
	   			 {
	   				if(x.substr(0,1) == "-" && y.substr(0,1) != "-")
	   				{
	   					x = x.substr(1,x.length()-1);
	   					difference = add(x,y);
	   					difference.insert(0,"-");
	   					x = "-" + x;
	   				}
	   				else if(x.substr(0,1) != "-" && y.substr(0,1) == "-")
	   				{
	   					y = y.substr(1,y.length()-1);
	   					difference = add(x,y);	
	   					y = "-" + y;
	   				}
	   				else if(x.substr(0,1) == "-" && y.substr(0,1) == "-")
	   				{
	   					x = x.substr(1,x.length()-1);
	   					y = y.substr(1,y.length()-1);
	   					difference = subtract(y,x);
	   					x = "-" + x;
	   					y = "-" + y;
	   				}
	   				else
	   				{
	   					difference = subtract(x,y);
	   				}
			        cout << "x - y = "<< difference << endl;
			        cin  >> carry_on;	
	   			 }
				 break;
	   	case 5:  if(binary == true)
		   		 {
	   				x = bintodec(x);
	   				y = bintodec(y);
	   				product = multiply(x,y);
	   				product = dectobin(product);
	   				cout << "x * y = " << product << endl;    
	   				x = dectobin(x);
	   				y = dectobin(y);
			        cin  >> carry_on;
	   			 }
	   			 else
	   			 {
	   			 	product = multiply(x,y);    
			        cout << "x * y = "<< product << endl;
			        cin  >> carry_on;
	   			 }
		   		 break;
	   	case 6:  if(binary == true)
		   		 {
	   				x = bintodec(x);
	   				y = bintodec(y);
	   				powerprod = power(x,y);
	   				powerprod = dectobin(powerprod);
	   				cout << "x^(y) = " << powerprod << endl;    
	   				x = dectobin(x);
	   				y = dectobin(y);
			        cin  >> carry_on;
	   			 }
		   		 else
		   		 {
		   		 	powerprod = power(x,y);    
			        cout << "x^(y) = " << powerprod << endl;
			        cin  >> carry_on;
		   		 }
				 break;
	   	case 7:  if(binary == true)
	   			 {
	   			    cout << "X  has been changed to binary. Enter any number to refresh display: " << endl;
			        binary = true;
			        cin  >> carry_on;
	   			 }
				 else
				 {
				 	x = dectobin(x);    
			        cout << "X  has been changed to binary. Enter any number to refresh display: " << endl;
			        binary = true;
			        cin  >> carry_on;
				 }		   
		   	     break;
	   	case 8:  if(binary == true)
	   			 {
	   			    cout << "Y  has been changed to binary. Enter any number to refresh display: " << endl;
			        binary = true;
			        cin  >> carry_on;
	   			 }
				 else
				 {
				 	y = dectobin(y);    
			        cout << "Y  has been changed to binary. Enter any number to refresh display: " << endl;
			        binary = true;
			        cin  >> carry_on;
				 }		   
		   	     break;
		case 9:  x = bintodec(x);    
			         cout << "X  has been changed to decimal. Enter any number to refresh display: " << endl;
			         binary = false;
			         cin  >> carry_on;
			         break;
	   	case 10:  y = bintodec(y);    
			         cout << "Y has been changed to decimal. Enter any number to refresh display: " << endl;
			         binary = false;
			         cin  >> carry_on;
			         break;
		case 11:  xdigitcount = ddigitcount(x);
				if(binary == true)    
				{
			         cout << "The number of decimal digits for x is: " <<xdigitcount<<endl;
			         cin  >> carry_on;
				}
			    else
			    {
			    	cout<<"The number of decimal digits for x is: " <<x.length()<<endl;
			    	cin >> carry_on;
				}
			         break;
		case 12:  ydigitcount = ddigitcount(y);    
			    if(binary == true)    
				{
			         cout << "The number of decimal digits for y is: " <<ydigitcount<<endl;
			         cin  >> carry_on;
				}
			    else
			    {
			    	cout<<"The number of decimal digits for y is: " <<y.length()<<endl;
			    	cin >> carry_on;
				}
			         break;
		case 13:  xdigitcount = bdigitcount(x);    
			    if(binary == true)    
				{
			         cout << "The number of binary digits for x is: " <<x.length()<<endl;
			         cin  >> carry_on;
				}
			    else
			    {
			    	cout<<"The number of binary digits for x is: " <<xdigitcount<<endl;
			    	cin >> carry_on;
				}
			         break;
		case 14:  ydigitcount = bdigitcount(y);    
			    if(binary == true)    
				{
			         cout << "The number of binary digits for y is: " <<y.length()<<endl;
			         cin  >> carry_on;
				}
			    else
			    {
			    	cout<<"The number of binary digits for y is: " <<ydigitcount<<endl;
			    	cin >> carry_on;
				}
			         break;
		case 15:   if(binary == true)
		   		   {
	   					x = bintodec(x);
	   					divisresult = divisibility(x);
	   					cout << "Out of 2, 3, 5, 7, 11, 13, 17, x is divisible by: " << divisresult << endl;    
	   					x = dectobin(x);
			        	cin  >> carry_on;
	   			   }
				   else
				   {
				   	 divisresult = divisibility(x);    
			         cout << "Out of 2, 3, 5, 7, 11, 13, 17, x is divisible by: " <<divisresult<<endl;
			         cin  >> carry_on;
				   }
					 break;
		case 16:  if(binary == true)
		   		   {
	   					y = bintodec(y);
	   					divisresult = divisibility(y);
	   					cout << "Out of 2, 3, 5, 7, 11, 13, 17, y is divisible by: " << divisresult << endl;    
	   					y = dectobin(y);
			        	cin  >> carry_on;
	   			   }
				   else
				   {
				   	 divisresult = divisibility(y);    
			         cout << "Out of 2, 3, 5, 7, 11, 13, 17, y is divisible by: " <<divisresult<<endl;
			         cin  >> carry_on;
				   }
					 break;
		case 17:  if(binary == true)
		   		 {
	   				x = bintodec(x);
	   				y = bintodec(y);
	   				quot = quotient(x,y);
	   				quot = dectobin(quot);
	   				cout << "The quotient of x/y is: " << quot << endl;    
	   				x = dectobin(x);
	   				y = dectobin(y);
			        cin  >> carry_on;
	   			 }
				 else
				 {
				 	quot = quotient(x,y);    
			        cout << "The quotient of x/y is: " <<quot<<endl;
			        cin  >> carry_on;		
				 }
				 break;
		case 18:  if(binary == true)
		   		 {
	   				x = bintodec(x);
	   				y = bintodec(y);
	   				remainder = remain(x,y);
	   				remainder = dectobin(remainder);
	   				cout << "The remainder of x/y is: " << remainder << endl;    
	   				x = dectobin(x);
	   				y = dectobin(y);
			        cin  >> carry_on;
	   			 }
				 else
				 {
				 	remainder = remain(x,y);    
			        cout << "The remainder of x/y is: " <<remainder<<endl;
			        cin  >> carry_on;
				 }
				 break;
		case 19:   if(binary == true)
		   		   {
	   					x = bintodec(x);
	   					natlog = naturallog(x);
	   					cout << "ln(x) = " << natlog << endl;    
	   					x = dectobin(x);
			        	cin  >> carry_on;
	   			   }
				   else
				   {
				   	 natlog = naturallog(x);    
			         cout << "ln(x) = " <<natlog<<endl;
			         cin  >> carry_on;
				   }
				break;
		case 20:   if(binary == true)
		   		   {
	   					y = bintodec(y);
	   					natlog = naturallog(y);
	   					cout << "ln(y) = " << natlog << endl;    
	   					y = dectobin(y);
			        	cin  >> carry_on;
	   			   }
				   else
				   {
				   	 natlog = naturallog(y);    
			         cout << "ln(y) = " <<natlog<<endl;
			         cin  >> carry_on;
				   }
				break;
		case 21:   if(binary == true)
		   		   {
	   					x = bintodec(x);
	   					recip = reciprocal(x);
	   					cout << "1/x = " << recip << endl;    
	   					x = dectobin(x);
			        	cin  >> carry_on;
	   			   }
				   else
				   {
				   	 recip = reciprocal(x);    
			         cout << "1/x = " <<recip<<endl;
			         cin  >> carry_on;
				   }
				break;
		case 22:   if(binary == true)
		   		   {
	   					y = bintodec(y);
	   					recip = reciprocal(y);
	   					cout << "1/y = " << recip << endl;    
	   					y = dectobin(y);
			        	cin  >> carry_on;
	   			   }
				   else
				   {
				   	 recip = reciprocal(y);    
			         cout << "1/y = " <<recip<<endl;
			         cin  >> carry_on;
				   }
				break;
			default: break;
		}
	} while (option != 0);
			  
   
   return 0;
}

