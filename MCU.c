#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>
using namespace std;

double timeconvert (string str){
	string min;
	string sec;
	string subsec;
	int minute;
	int second;
	double subsecond;
	double timesum;

  	min = str.substr(0,2);
  	sec = str.substr(3,2);
  	subsec = str.substr(6,6);
  	minute = atoi(min.c_str());
  	second = atoi(sec.c_str());
  	subsecond = atoi(subsec.c_str());
  	timesum = minute*60+second+subsecond/1000000;
  	cout.precision(10);

  	return timesum;
}
double dataconvert (string str){
	string numint;
	string numsub;
	string numexp;
	int numberint;
	double numbersub;
	double numbersum;
	bool posi;
	int exp;
	double expnumber=1;
	bool expposi;

	if (str.substr(0,1)=="-"){
		posi = false;
		str=str.substr(1);
	}
	else
		posi = true;

	numint = str.substr(0,str.find("."));
  	numsub = str.substr(str.find(".")+1,6);
  	numexp = str.substr(str.find("E")+2);

  	if (str.substr(str.find("E")+1,1)=="+"){
  		expposi=true; //cout <<"haha posi";
  	}
  	else if (str.substr(str.find("E")+1,1)=="-"){
  		expposi=false; //cout <<"haha nega";
  	}

  	numberint = atoi(numint.c_str());
  	numbersub = atoi(numsub.c_str());
  	exp = atoi(numexp.c_str());
  	while (exp!=0){
  		if (expposi)
	  		expnumber=expnumber*10;
	  	else
	  		expnumber=expnumber/10;
	  	exp--; //cout <<"ha";
  	}

  	if (posi)
  		numbersum = expnumber*(numberint+numbersub/1000000);
  	else
	  	numbersum = (-1)*expnumber*(numberint+numbersub/1000000);

  	return numbersum;
}

int main(int argc, char *argv[])
{
  string str;

  string time1;
  double time_sum1;
  string num1;
  double number1;
  string time2;
  double time_sum2;
  string num2;
  double number2;

  ifstream fin(argv[1]);
  ofstream fout(argv[2]);

  int count =0;
  fout.precision(15);

  while (!fin.eof()){
  	getline(fin,str);

  	if (str.substr(0,1)!="T"){
  		if (count ==1){

  		str=str.substr(str.find(":")+1);//delete anything before first :
  		//cout << str << endl;
  		time1 = str.substr(0,12);// get time 1, 
  		time_sum1 = timeconvert(time1);
  		fout <<time_sum1<<", ";

  		str=str.substr(13); //remove the part of time1
  		num1=str.substr(0,str.find(' '));
  		number1 = dataconvert(num1);
  		fout << number1 <<", ";

  		str=str.substr(str.find(":")+1);
  		time2=str.substr(0,12);
  		time_sum2 = timeconvert(time2);
  		fout <<time_sum2<<", ";

  		str=str.substr(13);
  		num2=str.substr(0,str.find(' '));
  		number2 = dataconvert(num2);
  		fout << number2 <<", ";
  		fout<<endl;}
  	}
  	else {
  		count +=1;
  		if (count ==2){
  			cout <<" incontinue!!";
	  		break;
  		}
  	}
  }
}
