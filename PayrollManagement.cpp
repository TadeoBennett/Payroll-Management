//Tadeo Bennett, Joram Castillo, Marlon Brown
//semester Project using OOP
//Payroll Management System(Hourly vs Salary vs Commission)
/*Features: Addition of New Employees, Modification of Employee Records, Delete Employee Record, 
Calculating Employee Salary, Print Employee Salary Slip.
//Types of Employees:
    Full-time
    Part-time
    Fixed term
    Shiftworkers
    Daily hire and weekly hire
    Probation
    Apprentices and trainees
    Outworkers
--------------------------------------------------------------------------------
User should edit the income tax (as integer).
Security Tax is fixed
Tax classes are inherited by the employee classes
All employees are added at the start of the program in object arrays
uUer can optionally add a bonus.
--------------------------------------------------------------------------------
Overtime hours are entered seperately and paid is calculated and added to the final wage.
..If yes, then enter the amount of extra hours and if no, it will proceed with the program.
types of overtime: double, time and a half.
--------------------------------------------------------------------------------
*/

#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>//library that contains the rad function
using namespace std;

//CLASSES THAT ALTER WAGES----------------------------------------------------------------------------------------------------
class IncomeTax{//must be inherited by all classes
private:
	float rate;
	float tax;
public:
	//constructor
	IncomeTax(){
		rate = 0.03;
		tax =0;
	}

	//mehthods to return tax and rate
	float returnrate(){return rate;}
	float returntax(){return tax;}
		
	void setIncomeTax(){
		cin>> rate;
		rate = rate / 100;
	}
	
	float calIncomeTax(float wage){
		tax = (rate * wage);
		return tax; //returns the amount of tax on the final wage; must be subtracted from wage
	}
};

class SocialSecurityTax{//must be inherited by all classes
private:
	float const rate = 0.124;
	float tax;
public:
	//constructor
	SocialSecurityTax(){		
		tax = 0;				
	}

	//method	
	float calSocialSecuritytax(float wage){		
		tax = (rate * wage);
		return tax; //returns the amount of social security tax on the final wage; must be subtracted from wage
	}
	
	//mehthods to return tax and rate
	float returnrate(){return rate;}
	float returntax(){return tax;}
};

class Overtime{//must be inherited by all classes
private:
	//instance variables for the payrates
	float const timeandahalf = 1.5;
	float const doubletime = 2;
	string overtimerateused;
	//instance variable that holds the overtime pay
	float overtimemoney;
public:
	//constructor
	Overtime(){
		overtimemoney = 0;
		overtimerateused = "No Rate";
	}
	
	//method
	string returnOrate(){return overtimerateused;}
	
	//method
	float calOvertime(int hrs, float hrlyrate){				
		cout<<"***Enter the option of when the overtime was provided***"<<endl;
		cout<<"1. New Years Day 1.5"<<endl;
		cout<<"2. Baron Bliss Day (9th March) 1.5"<<endl;
		cout<<"3. Good Friday 2.0"<<endl;
		cout<<"4. Holy Saturday 1.5"<<endl;
		cout<<"5. Easter Monday 2.0"<<endl;
		cout<<"6. Labour Day (1st May) 1.5"<<endl;
		cout<<"7. Commonwealth Day (24th May) 1.5"<<endl;
		cout<<"8. National Day (10th September) 1.5"<<endl;
		cout<<"9. Independence Day (21st September) 1.5"<<endl;
		cout<<"10. Pan-American Day (12th October) 1.5"<<endl;
		cout<<"11. Garifuna Settlement Day (19th November) 1.5"<<endl;		
		int choice;
		overtimerateused = "No Rate"; 
		do{
			cout<<"choice here: "; cin>>choice;		
		}while(choice<1 || choice>11);
		
		if(choice == 3 || choice == 5){//checks the 
			overtimemoney = hrlyrate * hrs* doubletime;
			overtimerateused = "Double Time";
		}
		else{
			overtimemoney = hrlyrate * hrs* timeandahalf;
			overtimerateused = "Time and a half";
		}
		
		return overtimemoney; //return the amount of money gotten from their overtime; must be added to wage
	}
};

//END OF CLASSES THAT ALTER WAGES---------------------------------------------------------------------------------------------


//_____________________START OF EMPLOYEE CLASS TYPES____________________________

//BASICEMPLOYEE START OF CLASSES----------------------------------------------------------------------------------------------
class BasicEmployee{ //class will be inherited by all employee classes
private:
	//instance that each class will have
	string firstname, middlename, lastname;
	float hourlyrate;
	int hoursworked;
	string sex; //male or female
	string streetaddress;
	int appartmentnum;
	string towncity; //town or city
	string district;
	int ZIPcode;
	string homephone;
	string email;
	int SSN; //social security number
	string birthdate; 
	string maritalstatus; //single, married, or unstated
	bool multilingual;
	float wage;
public:
	
	//constructors
	BasicEmployee(){
		firstname = "Not Set";
		middlename = "Not Set";
		lastname = "Not Set";
		hourlyrate = 3.30;
		hoursworked = 0;
		string sex= "Not Set"; //male or female
		streetaddress = "Not Set";
		appartmentnum = 0;
		towncity = "Not Set"; //town or city
		district = "Not Set";
		ZIPcode = 00000;
		homephone = "Not Set";
		email= "Not Set";
		SSN = 000000000; //social security number
		birthdate = "Not Set"; 
		maritalstatus = "Not Set"; //single, married, or unstated
		wage = 0;
		multilingual = false;			
	}
	
	//Basic Employee Constructor that will be utilized by all employee classes
	BasicEmployee(string fn, string mn, string ln, int hrs, float hrlyrate, string sx, string stad, int apnm, string tc, string dis, int zc, string hp, string em, int ssn, string bd, string ms, bool ml){
		firstname =fn;
		middlename = mn;
		lastname = ln;
		hoursworked = hrs;
		hourlyrate = hrlyrate;
		sex= sx; //male or female
		streetaddress = stad;
		appartmentnum = apnm;
		towncity = tc; //town or city
		district = dis;
		ZIPcode = zc;
		homephone = hp;
		email= em;
		SSN = ssn; //social security number
		birthdate = bd; 
		maritalstatus = ms; //single, married, or unstated
		multilingual = ml;		
	}
	
	
	//methods that return each detail of basic employee; used for the Salary Slip
	string returnfirstname(){return firstname;}
	string returnmiddlename(){return middlename;}
	string returnlastname(){return lastname;}
	int returnhoursworked(){return hoursworked;}
	float returnhourlyrate(){return hourlyrate;}
	string returnsex(){return sex;}
	string returnstreetaddress(){return streetaddress;}
	int returnappartmentnum(){return appartmentnum;}
	string returntowncity(){return towncity;}
	string returndistrict(){return district;}
	int returnZIPcode(){return ZIPcode;}
	string returnhomephone(){return homephone;}
	string returnemail(){return email;}
	int returnSSN(){return SSN;}
	string returnbirthdate(){return birthdate;}
	string returnmaritalstatus(){return maritalstatus;}
	bool returnmultilingual(){return multilingual;}
	float returnnontaxwage(){
		wage = hourlyrate * hoursworked;
		return wage;
	}
	float returnwage(){ return wage;}
	
	//allows this class's derived classes to change their hours worked and rate in constructor
	void setHRSandRATE(float rate, int hours){
		hourlyrate = rate;
		hoursworked = hours;
	}
	
	void setWage(float wg){
		wage = wg;
	}
	
	//method gets an array of details to edit
	void modifyBasicEmployee(char * editchoices){
		for(int i = 0; i<17; i++)
		{
			if(editchoices[i]=='A'){cout<<"Enter first name: "; cin>>firstname; cin.ignore();}
			if(editchoices[i]=='B'){cout<<"Enter middle name: "; cin>>middlename; cin.ignore();}		
			if(editchoices[i]=='C'){cout<<"Enter last name: "; cin>>lastname; cin.ignore();}		
			if(editchoices[i]=='D'){cout<<"Enter hours worked: "; cin>>hoursworked; cin.ignore();}		
			if(editchoices[i]=='E'){cout<<"Enter hourly rate: $"; cin>>hourlyrate; cin.ignore();}		
			if(editchoices[i]=='F'){cout<<"Enter sex (Male, Female, Other): "; cin>>sex; cin.ignore();}		
			if(editchoices[i]=='G'){cout<<"Enter street address: "; getline(cin, streetaddress);}		
			if(editchoices[i]=='H'){cout<<"Enter appartment number(2 digits): "; cin>>appartmentnum; cin.ignore();}		
			if(editchoices[i]=='I'){cout<<"Enter town/city: "; getline(cin, towncity);}		
			if(editchoices[i]=='J'){cout<<"Enter District: "; getline(cin, district);}		
			if(editchoices[i]=='K'){cout<<"Enter ZIP code(5 digits): "; cin>>ZIPcode; cin.ignore();}		
			if(editchoices[i]=='L'){cout<<"Enter Homephone(contact#): "; cin>>homephone; cin.ignore();}
			if(editchoices[i]=='M'){cout<<"Enter Email: "; cin>>email; cin.ignore();}		
			if(editchoices[i]=='N'){cout<<"Enter Social Security Number(9 digits): "; cin>>SSN; cin.ignore();}					
			if(editchoices[i]=='O'){
				string month, day, year;
				cout<<"Enter Birth month: ";cin>>month;
				cout<<"Enter Birth day: ";cin>>day;
				cout<<"Enter Birth year: ";cin>>year; cin.ignore();
				birthdate = month + " " + day + "," + " " + year;
			}		
			if(editchoices[i]=='P'){cout<<"Enter Marital Status: "; cin>>maritalstatus;}		
			if(editchoices[i]=='Q'){cout<<"Bilingual or Better enter (1). If not, enter (0): ";
				int choice;
				cin>>choice;
				if(choice == 1){multilingual = true;}
				else{multilingual = false;}	
			}//end if				
		}//end for loop
	}//end of method
};
//BASICEMPLOYEE END OF CLASSES------------------------------------------------------------------------------------------------


//FULLTIME WORKER START OF CLASS----------------------------------------------------------------------------------------------
class FullTimeWorker:public BasicEmployee, public IncomeTax, public SocialSecurityTax, public Overtime{ 
private:
	//instance variables for fulltime employees
	int numberofleaves;
	int leavestaken;
	int cashedleavesamount;
	string department;
	string datejoined;
	int overtimehours;//used in the salary slip and calculating wages
public:
	//default constructor
	FullTimeWorker(){
		numberofleaves = 3;
		leavestaken = 0;
		cashedleavesamount = 0;
		department = "Not Set";
		datejoined = "Not Set";
		overtimehours = 0;
		BasicEmployee::setHRSandRATE(15, 40);
	}
	
	//utilized constructor from the BasicEmployee Class
	FullTimeWorker(int nl, int lt, int ll, int cla, string dep, string dj, /*split*/string fn, string mn, string ln, int hrs, float hrlyrate, string sx, string stad, int apnm, string tc, string dis, int zc, string hp, string em, int ssn, string bd, string ms, bool ml):BasicEmployee( fn, mn, ln, hrs, hrlyrate, sx, stad, apnm, tc, dis, zc, hp, em, ssn, bd, ms, ml){
		numberofleaves = nl;
		leavestaken = lt;
		cashedleavesamount = cla;
		department = dep;
		datejoined = dj;
	}
	
	//method gets an array of details to MODIFY	
	void modifyFullTimeWorker(char * editchoices){
		BasicEmployee::modifyBasicEmployee(editchoices); //if a number less than 18 is shown then it will carry out one of the procedures in the BasicEmployee Class
		int i;
		for(i =0 ; i<30; i++){ //if it is more than 18 then it works this loop out.
			if(editchoices[i]=='\0'){break;}	
			if(editchoices[i]=='R'){cout<<"Enter the number of leaves: ";cin>>numberofleaves;}	
			if(editchoices[i]=='S'){cout<<"Enter the leaves taken: ";cin>>leavestaken;}	
			if(editchoices[i]=='T'){cout<<"Enter the cashed leaves amount: $";cin>>cashedleavesamount;}	
			if(editchoices[i]=='U'){cout<<"Enter the department name: ";getline(cin, department);}
			if(editchoices[i]=='V'){
		   		time_t now = time(0); 
		   		// convert now to string form
		  		char* dt = ctime(&now);
				datejoined = dt;		
				cout<<"Date set automatically: "<<datejoined;
			}	
		}//end for
		cout<<"Edit Success!"<<endl;		
	}//end method
	
	//method that returns all details in the fulltime worker class/helps with printing the employee details
	int returnnumberofleaves(){return numberofleaves;}
	int returnleavestaken(){return leavestaken;}
	int returncashedleavesamount(){return cashedleavesamount;}
	string returndepartment(){return department;}
	string returndatejoined(){return datejoined;}
	int returnovertimehours(){return overtimehours;}
	
	//method that CALCULATES wage
	void calFullTimeWorkerWage(){
		int choice;
		float itax, sstax, hrs, newwage;
		float overtime = 0;
		newwage = BasicEmployee::returnnontaxwage(); //making the newwage variable equal to the current wage
		cout<<"Edit the IncomeTax?(1) for Yes. Any# for No: ";
		cin>>choice;
		if(choice == 1){
			cout<<"Enter new IncomeTax in percent: "; IncomeTax::setIncomeTax();
		}
		itax = IncomeTax::calIncomeTax(BasicEmployee::returnnontaxwage());//gets the income tax amount
		sstax = SocialSecurityTax::calSocialSecuritytax(BasicEmployee::returnnontaxwage());//gets the ss tax amount
		cout<<"Add Overtime pay? Enter (1) for yes. Any # for no: "; cin>>choice;
		if(choice == 1){
			cout<<"Enter the number of overtime hours: "; cin>>hrs;
			overtime = Overtime::calOvertime(hrs, BasicEmployee::returnhourlyrate());
			overtimehours = hrs;		
		}
		else{cout<<"No overtime"<<endl;}

		newwage = (newwage+overtime) - (itax + sstax); //making the newwage be the newage minus the taxes.
		BasicEmployee::setWage(newwage); //sets the wage as the new wage
		cout<<"Wage calculated ($"<<BasicEmployee::returnwage(); cout<<")"<<endl;
	}//new wage has been set
	
	//method for the payslip of this employee class
	void FullTimeWorkerSalarySlip();
};

void FullTimeWorker::FullTimeWorkerSalarySlip(){
string date;
time_t now = time(0); 
char* dt = ctime(&now);
date = dt;
//information will return many details about a Full Time Worker
cout<<"Note that this slip may represent incorrect data unless the wage is calculated first."<<endl;
cout<<"*************************************************************************************"<<endl;
cout<<"JOB TITLE:              Full Time Employee"<<endl;
cout<<"Employee Name:          "<<BasicEmployee::returnfirstname()<<" "<<BasicEmployee::returnlastname()<<endl;
cout<<"Employee ID:            "<<(rand() % 2048) + 1024<<endl;
cout<<"Employee Email:         "<<BasicEmployee::returnemail()<<endl;
cout<<"Employee Department:    "<<FullTimeWorker::returndepartment()<<endl;
cout<<"Date:                   "<<date;
cout<<"Total Hours Worked:     "<<BasicEmployee::returnhoursworked()<<endl;
cout<<"Hourly rate:            "<<BasicEmployee::returnhourlyrate()<<endl;
cout<<"SocialSec. Tax Rate:    "<<SocialSecurityTax::returnrate()<<endl;
cout<<"Income Tax Rate:        "<<IncomeTax::returnrate()<<endl;
cout<<"Overtime Hours Served:  "<<FullTimeWorker::returnovertimehours(); cout<<endl;
cout<<"Overtime Rate:          "<<Overtime::returnOrate()<<endl;
cout<<"Cashed Leaves Amount:   "<<FullTimeWorker::returncashedleavesamount()<<endl;
cout<<"Final Wage:             "<<BasicEmployee::returnwage()<<endl;
cout<<"*************************************************************************************"<<endl;
}
//FULLTIME WORKER END OF CLASS------------------------------------------------------------------------------------------------


//PARTTIME WORKER START OF CLASS----------------------------------------------------------------------------------------------
class PartTimeWorker:public BasicEmployee, public IncomeTax{ //does not have social security benefits
private:
	string department;
	string datejoined;
public:
	//Default constructor
	PartTimeWorker(){
		department = "Not Set";
		datejoined = "Not Set";
		BasicEmployee::setHRSandRATE(13.30, 38);
	}
	
	//utilized constructor	
	PartTimeWorker(string dp, string dj, /*split*/ string fn, string mn, string ln, int hrs, float hrlyrate, string sx, string stad, int apnm, string tc, string dis, int zc, string hp, string em, int ssn, string bd, string ms, bool ml):BasicEmployee(fn, mn, ln, hrs, hrlyrate, sx, stad, apnm, tc, dis, zc, hp, em, ssn, bd, ms, ml){
		department = dp;
		datejoined = dj;
	}
	
	//method gets an array of details to MODIFY	
	void modifyPartTimeWorker(char * editchoices){
		BasicEmployee::modifyBasicEmployee(editchoices); //if a number less than 18 is shown then it will carry out one of the procedures in the BasicEmployee Class
		for(int i =0 ; i<30; i++){ //if it is more than 18 then it works this loop out.
			if(editchoices[i]=='\0'){break;}
			if(editchoices[i]=='R'){cout<<"Enter the department: ";getline(cin, department);}
			if(editchoices[i]=='S'){
		   		time_t now = time(0); 
		   		// convert now to string form
		  		char* dt = ctime(&now);
				datejoined = dt;
				cout<<"Date set automatically: "<<datejoined<<endl;	
			}
		}//end for
		cout<<"Edit Success!"<<endl;
	}//end method
	
	//method that returns all details in the part time worker class/helps with printing the employee details
	string returndepartment(){return department;}
	string returndatejoined(){return datejoined;}	
	
	//method that CALCULATES wage
	void calPartTimeWorkerWage(){
		int choice;
		float itax;
		float newwage = BasicEmployee::returnnontaxwage();
		cout<<"Edit the IncomeTax?(1) for Yes. Any other# for No: ";
		cin>>choice;
		if(choice == 1){
			cout<<"Enter new IncomeTax in percent: "; IncomeTax::setIncomeTax();
		}
		itax = IncomeTax::calIncomeTax(BasicEmployee::returnnontaxwage());//gets the income tax amount
		newwage = newwage - itax;
		BasicEmployee::setWage(newwage);
		cout<<"Wage calculated ($"<<BasicEmployee::returnwage()<<")"<<endl;
	}//new wage has been set
	
	//method for the payslip of this employee class	
	void PartTimeWorkerSalarySlip();
};

void PartTimeWorker::PartTimeWorkerSalarySlip(){
string date;
time_t now = time(0); 
char* dt = ctime(&now);
date = dt;
//information will return many details about a Full Time Worker
cout<<"Note that this slip may represent incorrect data unless the wage is calculated first."<<endl;
cout<<"*************************************************************************************"<<endl;
cout<<"JOB TITLE:              Full Time Employee"<<endl;
cout<<"Employee Name:          "<<BasicEmployee::returnfirstname()<<" "<<BasicEmployee::returnlastname()<<endl;
cout<<"Employee ID:            "<<(rand() % 2048) + 1024<<endl;
cout<<"Employee Email:         "<<BasicEmployee::returnemail()<<endl;
cout<<"Date:                   "<<BasicEmployee::returnhomephone()<<endl;
cout<<"Date Joined:            "<<PartTimeWorker::returndatejoined()<<endl;
cout<<"Total Hours Worked:     "<<BasicEmployee::returnhoursworked()<<endl;
cout<<"Hourly rate:            "<<BasicEmployee::returnhourlyrate()<<endl;
cout<<"Income Tax Rate:        "<<IncomeTax::returnrate()<<endl;
cout<<"Final Wage:             "<<BasicEmployee::returnwage()<<endl;
cout<<"*************************************************************************************"<<endl;
}
//PARTTIME WORKER END OF CLASS------------------------------------------------------------------------------------------------


//SHIFTWORKER START OF CLASS--------------------------------------------------------------------------------------------------
class ShiftWorkers:public BasicEmployee{//no benefits
private://still set shift name, hrly rate, and hrs and wage
	string nameofshift;
public:	

	//defalt constructor
	ShiftWorkers(){
		nameofshift = "Not Set";
		BasicEmployee::setHRSandRATE(5.75, 15);
	}
	
	//utilized constructor
	ShiftWorkers(string nos, /*split*/ string fn, string mn, string ln, int hrs, float hrlyrate, string sx, string stad, int apnm, string tc, string dis, int zc, string hp, string em, int ssn, string bd, string ms, bool ml):BasicEmployee(fn, mn, ln, hrs, hrlyrate, sx, stad, apnm, tc, dis, zc, hp, em, ssn, bd, ms, ml){
		nameofshift = nos;
	}

	//method gets an array of details to MODIFY	
	void modifyShiftWorker(char * editchoices){
		BasicEmployee::modifyBasicEmployee(editchoices); //if a number less than 18 is shown then it will carry out one of the procedures in the BasicEmployee Class
		for(int i =0 ; i<30; i++){ //if it is more than 18 then it works this loop out.
			if(editchoices[i]=='\0'){break;}	
			if(editchoices[i]=='R'){cout<<"Enter the name of the shift: ";getline(cin, nameofshift);}	
		}//end for
		cout<<"Edit Success!"<<endl;
	}//end method
	
	//method that returns all details in this class
	string returnnameofshift(){return nameofshift;}

	//method that CALCULATES wage
	void calShiftWorkerWage(){
		float newwage = BasicEmployee::returnnontaxwage();
		BasicEmployee::setWage(newwage);
		cout<<"Wage calculated ($"<<BasicEmployee::returnwage()<<")"<<endl;
	}//new wage has been set
	
	//method for the payslip of this employee class	
	void ShiftWorkersSalarySlip();	
};

void ShiftWorkers::ShiftWorkersSalarySlip(){
string date;
time_t now = time(0); 
char* dt = ctime(&now);
date = dt;
//information will return many details about a Full Time Worker
cout<<"Note that this slip may represent incorrect data unless the wage is calculated first."<<endl;
cout<<"*************************************************************************************"<<endl;
cout<<"JOB TITLE:              Shift Working Employee"<<endl;
cout<<"Employee Name:          "<<BasicEmployee::returnfirstname()<<" "<<BasicEmployee::returnlastname()<<endl;
cout<<"Employee ID:            "<<(rand() % 2048) + 1024<<endl;
cout<<"Employee Email:         "<<BasicEmployee::returnemail()<<endl;
cout<<"Date:                   "<<BasicEmployee::returnhomephone()<<endl;
cout<<"Total Hours Worked:     "<<BasicEmployee::returnhoursworked()<<endl;
cout<<"Hourly rate:            "<<BasicEmployee::returnhourlyrate()<<endl;
cout<<"Final Wage:             "<<BasicEmployee::returnwage()<<endl;
cout<<"*************************************************************************************"<<endl;
}
//SHIFTWORKER END OF CLASS----------------------------------------------------------------------------------------------------


//TRAINEE START OF CLASS------------------------------------------------------------------------------------------------------
class Trainee:public FullTimeWorker{//works just as a fulltimeworker except with less pay
private:
	
public:
	//default constructor
	Trainee(){	
		BasicEmployee::setHRSandRATE(10.5, 40);//sets wage		
	}
		
	//utilized constructor from the FullTimeWorkerBasicEmployee Class
	Trainee(int nl, int lt, int ll, int cla, string dep, string dj, /*split*/string fn, string mn, string ln, int hrs, float hrlyrate, string sx, string stad, int apnm, string tc, string dis, int zc, string hp, string em, int ssn, string bd, string ms, bool ml):FullTimeWorker(nl, lt, ll, cla, dep, dj, fn, mn, ln, hrs, hrlyrate, sx, stad, apnm, tc, dis, zc, hp, em, ssn, bd, ms, ml){	
	}
	
	//method gets an array of details to MODIFY	
	void modifyTrainee(char * editchoices){
		FullTimeWorker::modifyFullTimeWorker(editchoices);
	}//end method
	
	//method that CALCULATES wage
	void calTraineeWage(){
		FullTimeWorker::calFullTimeWorkerWage();
	}//new wage has been set
	
	//method to display the salary slip
	void TraineeSalarySlip();
};

void Trainee::TraineeSalarySlip(){
string date;
time_t now = time(0); 
char* dt = ctime(&now);
date = dt;
//information will return many details about a Full Time Worker
cout<<"Note that this slip may represent incorrect data unless the wage is calculated first."<<endl;
cout<<"*************************************************************************************"<<endl;
cout<<"JOB TITLE:              TRAINEE"<<endl;
cout<<"Employee Name:          "<<BasicEmployee::returnfirstname()<<" "<<BasicEmployee::returnlastname()<<endl;
cout<<"Employee ID:            "<<(rand() % 2048) + 1024<<endl;
cout<<"Employee Email:         "<<BasicEmployee::returnemail()<<endl;
cout<<"Employee Department:    "<<FullTimeWorker::returndepartment()<<endl;
cout<<"Date:                   "<<BasicEmployee::returnhomephone()<<endl;
cout<<"Total Hours Worked:     "<<BasicEmployee::returnhoursworked()<<endl;
cout<<"Hourly rate:            "<<BasicEmployee::returnhourlyrate()<<endl;
cout<<"SocialSec. Tax Rate:    "<<SocialSecurityTax::returnrate()<<endl;
cout<<"Income Tax Rate:        "<<IncomeTax::returnrate()<<endl;
cout<<"Overtime Hours Served:  "<<FullTimeWorker::returnovertimehours(); cout<<endl;
cout<<"Overtime Rate:          "<<Overtime::returnOrate()<<endl;
cout<<"Cashed Leaves Amount:   "<<FullTimeWorker::returncashedleavesamount()<<endl;
cout<<"Final Wage:             "<<BasicEmployee::returnwage()<<endl;
cout<<"*************************************************************************************"<<endl;
}
//TRAINEE END OF CLASS--------------------------------------------------------------------------------------------------------


//_____________________END OF EMPLOYEE CLASS TYPES____________________________



//NORMAL FUNCTIONS FOR MENUS----------------------------------------------------
void DecisionMenu(){
	cout<<"\n********************"<<endl;
	cout<<"1. Modify"<<endl;
	cout<<"2. Calculate Salary"<<endl;
	cout<<"3. Print Salary Slip"<<endl;
	cout<<"4. Show All Workers"<<endl;
	cout<<"5. Exit"<<endl;
	cout<<"********************"<<endl;
	cout<<"choice here: ";
}

void WorkerTypeMenu(){
	cout<<"\n**CHOOSE WORKER TYPE**"<<endl;	
	cout<<"1. Full Time Worker"<<endl;
	cout<<"2. Part Time Worker"<<endl;
	cout<<"3. Shift Worker"<<endl;
	cout<<"4. Trainee"<<endl;
	cout<<"5. Exit"<<endl;
	cout<<"**********************"<<endl;
	cout<<"choice here: ";	
}

void BEModifyChoices(){
cout<<"A.)First name            B.)Middle name            C.)Last name           D.)Hours worked           E.)Hourly rate $"<<endl;
cout<<"F.)Sex(M, F, Other)      G.)Street address         H.)Appartment number   I.)Town/city              J.)District"<<endl;	
cout<<"K.)ZIP code              L.)Homephone #            M.)Email               N.)Social Security Number"<<endl;		
cout<<"O.)Birth date            P.)Marital Status         Q.)Bilingual or Better"<<endl;		
}

void FTWandTREModifyChoices(){
BEModifyChoices();
cout<<"R.)Number of leaves      S.)Leaves taken           T.)Cashed leaves amount $                U.)Department name"<<endl;	
cout<<"V.)Date Joined"<<endl;
}

void PTWModifyChoices(){
BEModifyChoices();
cout<<"R.)Department            S.)Date Joined"<<endl;	
}

void SWEModifyChoices(){
BEModifyChoices();	
cout<<"R.)Name of Shift"<<endl;	
}

//END OF NORMAL FUNCTIONS FOR MENUS---------------------------------------------


//______________________________________________________________________________


//START OF MAIN FUNCTION--------------------------------------------------------

int main(){
/*//current date/time based on current system
   time_t now = time(0); 
   // convert now to string form
   char* dt = ctime(&now);
   cout << "The local date and time is: " << dt << endl;*///FULL TIME
srand(time(NULL));//seeds a new value for every rand() function called  
//Welcome Message------------------------------
cout<<"WELCOME TO PAYROLL MANAGEMENT. "<<endl; 
cout<<"Since this is a new setup for your business, you must state beforehand the\n";
cout<<"number of each employee type. They can be edited later. "<<endl;
cout<<"Please enter the options as instructed in the program."<<endl;
cout<<"Press enter to continue.";cin.ignore();
cout<<endl;
//Welcome Message------------------------------

int numofFTE, numofPTE, numofSWE, numofTRE;
cout<<"Enter the # of FullTime Employees: "; cin>>numofFTE;
cout<<"Enter the # of PartTume Employees: "; cin>>numofPTE;
cout<<"Enter the # of ShiftWork Employees: "; cin>>numofSWE;
cout<<"Enter the # of Trainee: "; cin>>numofTRE;
cout<<endl;
//Here I got the number of employees of each type
system("CLS");

FullTimeWorker fte[numofFTE];
PartTimeWorker pte[numofPTE];
ShiftWorkers swe[numofSWE];
Trainee tre[numofTRE];
//CREATED THE OBJECT ARRAYS

DecisionMenu();
int DecisionMenuChoice;
cin>>DecisionMenuChoice;

int choice;//a variables that stores general choices
int modifychoice;
int slipchoice;
char modifylist[30];//variable that stores the options of details to edit
int numofoptions = 30; //variable that controls the input into arrays
int employeechoice; //variable records a specific employee chosen
int i; //variable used for loops

//LOOP FOR THE ENTIRE PROGRAM---------------------------------------------------
while(DecisionMenuChoice != 5)
{
	switch(DecisionMenuChoice){//is either in the range of 1-4	
		case 1: //Modify Details
			WorkerTypeMenu();
			cin>>choice;//new selection for a specific type of employee.
			while(choice != 5){
			cout<<endl;				
				switch(choice){
					case 1: //Modify a FullTime Worker's details
						cout<<"Which employee to modify?: "<<endl;
						for(i = 0; i<numofFTE; i++){
							cout<<i+1<<".)"<<fte[i].returnfirstname()<<" "<<fte[i].returnlastname()<<endl;//prints the number of employees of that type
						}
						cin>>employeechoice;
						employeechoice -= 1; //adjusting for the indexes of the object array
						cout<<"Which details to edit? List them and press ENTER to continue: "<<endl;
						FTWandTREModifyChoices(); //Prints the menu with all details of the Full time worker
						cout<<"choice(s) here: "; cin.ignore();
						cin.getline(modifylist, 30); //gets all the options to modify the details
						fte[employeechoice].modifyFullTimeWorker(modifylist); //calls method to edit the FullTime Worker
						choice = 5;//exits the loop				
					break;
					
					case 2://Modify a Part Time Worker's details
						cout<<"Which employee to modify?: "<<endl;
						for(i = 0; i<numofPTE; i++){
							cout<<i+1<<".)"<<pte[i].returnfirstname()<<" "<<pte[i].returnlastname()<<endl;//prints the number of employees of that type
						}
						cin>>employeechoice;
						employeechoice -= 1; //adjusting for the indexes of the object array
						cout<<"Which details to edit? List them and press ENTER to continue: "<<endl;
						PTWModifyChoices(); //Prints the menu with all details of the Part Time worker
						cout<<"choice(s) here: "; cin.ignore();
						cin.getline(modifylist, 30); //gets all the options to modify the details
						pte[employeechoice].modifyPartTimeWorker(modifylist); //calls method to edit the Part Time Worker
						choice = 5;	//exits the loop	
					break;	
													
					case 3: ////Modify a Shift Worker's details
						cout<<"Which employee to modify?: "<<endl;
						for(i = 0; i<numofSWE; i++){
							cout<<i+1<<".)"<<swe[i].returnfirstname()<<" "<<swe[i].returnlastname()<<endl;//prints the number of employees of that type
						}
						cin>>employeechoice;
						employeechoice -= 1; //adjusting for the indexes of the object array
						cout<<"Which details to edit? List them and press ENTER to continue: "<<endl;
						SWEModifyChoices(); //Prints the menu with all details of the Part Time worker
						cout<<"choice(s) here: "; cin.ignore();
						cin.getline(modifylist, 30); //gets all the options to modify the details
						swe[employeechoice].modifyShiftWorker(modifylist); //calls method to edit the Part Time Worker
						choice = 5;	//exits the loop							
					break;

					case 4://Modify a Trainee Worker's details
						cout<<"Which employee to modify?: "<<endl;
						for(i = 0; i<numofTRE; i++){
							cout<<i+1<<".)"<<tre[i].returnfirstname()<<" "<<tre[i].returnlastname()<<endl;//prints the number of employees of that type
						}
						cin>>employeechoice;
						employeechoice -= 1; //adjusting for the indexes of the object array
						cout<<"Which details to edit? List them and press ENTER to continue: "<<endl;
						FTWandTREModifyChoices(); //Prints the menu with all details of the Part Time worker
						cout<<"choice(s) here: "; cin.ignore();
						cin.getline(modifylist, 30); //gets all the options to modify the details
						tre[employeechoice].modifyTrainee(modifylist); //calls method to edit the Part Time Worker
						choice = 5;//exits the loop		
					break;

					default:
						cout<<"-->>Invalid Option<<--"<<endl;
						choice = 5;
				}//end of switch
			}//end of while
			cout<<"-->>Exited<<--"<<endl;
		break;
		
		
		case 2: //Calculate Salary(prints the wage) OF ALL EMPLOYEES
			cout<<"To calculate salary of specific employees enter (1). For all, enter (0): "; cin>>choice;			
			if(choice == 0){
				system("CLS");
				cout<<"You have chosen to CALCULATE THE SALARY of ALL EMPLOYEES"<<endl<<endl;

				cout<<"--------------------------------------------->>>>>>>>Full Time Employees"<<endl;
				for(i = 0; i<numofFTE; i++){//calculating all FullTime Employee wages
					cout<<"Full Time Employee "<<i+1<<": "<< fte[i].returnfirstname()<<" "<<fte[i].returnlastname()<<endl;
					fte[i].calFullTimeWorkerWage();
					cout<<endl;
				}//end loop displaying FullTime Worker
				cout<<"--------------------------------------------->>>>>>>>Part Time Employees"<<endl;
		
				for(i = 0; i<numofPTE; i++){//calculating all PartTime Employee wages
					cout<<"Part Time Employee "<<i+1<<": "<< pte[i].returnfirstname()<<" "<<pte[i].returnlastname()<<endl;
					pte[i].calPartTimeWorkerWage();
					cout<<endl;
				}//end loop displaying PartTime Worker

				cout<<"--------------------------------------------->>>>>>>>Shift Workers"<<endl;				
				for(i = 0; i<numofSWE; i++){//calculating all ShiftWorking Employee wages
					cout<<"Shift Worker "<<i+1<<": "<< swe[i].returnfirstname()<<" "<<swe[i].returnlastname()<<endl;
					swe[i].calShiftWorkerWage();
					cout<<endl;
				}//end loop displaying ShiftWorking Employee
				
				cout<<"--------------------------------------------->>>>>>>>Trainees"<<endl;				
				for(i = 0; i<numofTRE; i++){//calculating all Trainee wages
					cout<<"Trainee "<<i+1<<": "<< tre[i].returnfirstname()<<" "<<tre[i].returnlastname()<<endl;
					tre[i].calTraineeWage();
					cout<<endl;
				}//end loop displaying Trainees
				cout<<"_____________________________________________"<<endl;
				cout<<"-->>Exited<<--"<<endl;
			}
			else if(choice == 1){//SPECIFIC EMPLOYEE
				WorkerTypeMenu();
				cin>>choice;
				switch(choice){
					case 1: //finding a specific FullTime Worker to calculate wage for
						cout<<"Which employee to calculate the wage for?: "<<endl;
						for(i = 0; i<numofFTE; i++){
							cout<<i+1<<".)"<<fte[i].returnfirstname()<<" "<<fte[i].returnlastname()<<endl;//prints the number of employees of that type
						}
						cout<<"choice here: "; cin>>employeechoice;
						employeechoice -= 1; //adjusting for the indexes of the object array
						fte[employeechoice].calFullTimeWorkerWage(); //calls method to calculate the FullTime Worker wag
						cout<<"-->>Exited<<--"<<endl;	
					break;
					
					case 2: //finding a specific Part Time Worker to calculate wage for
						cout<<"Which employee to calculate the wage for?: "<<endl;
						for(i = 0; i<numofPTE; i++){
							cout<<i+1<<".)"<<pte[i].returnfirstname()<<" "<<pte[i].returnlastname()<<endl;//prints the number of employees of that type
						}
						cout<<"choice here: "; cin>>employeechoice;
						employeechoice -= 1; //adjusting for the indexes of the object array
						pte[employeechoice].calPartTimeWorkerWage(); //calls method to calculate the PartTime Worker wage
						cout<<"-->>Exited<<--"<<endl;	
					break;
					
					case 3://finding a specific ShiftWorker to calculate wage for
						cout<<"Which employee to calculate the wage for?: "<<endl;
						for(i = 0; i<numofSWE; i++){
							cout<<i+1<<".)"<<swe[i].returnfirstname()<<" "<<swe[i].returnlastname()<<endl;//prints the number of employees of that type
						}
						cout<<"choice here: "; cin>>employeechoice;
						employeechoice -= 1; //adjusting for the indexes of the object array
						swe[employeechoice].calShiftWorkerWage(); //calls method to calculate the Shift Worker wage
						cout<<"-->>Exited<<--"<<endl;	
					break;
						
					case 4:	//finding a specific Trainee to calculate wage for
						cout<<"Which employee to calculate the wage for?: "<<endl;
						for(i = 0; i<numofTRE; i++){
							cout<<i+1<<".)"<<tre[i].returnfirstname()<<" "<<tre[i].returnlastname()<<endl;//prints the number of employees of that type
						}
						cout<<"choice here: "; cin>>employeechoice;
						employeechoice -= 1; //adjusting for the indexes of the object array
						tre[employeechoice].calTraineeWage(); //calls method to calculate the Trainee wage
						cout<<"-->>Exited<<--"<<endl;	
					break;
					
					default:
						if (choice == 5){
							cout<<"-->>Exited<<--"<<endl;
						}else{cout<<"-->>Invalid Option<<--"<<endl;}
				}//end of switch
			}// end else if
			else{
				cout<<"-->>Exited<<--"<<endl;
			}
		break;
		
		case 3://Print the Salary(prints wage and other details)
			WorkerTypeMenu();
			cin>>choice;
			while(choice != 5){
				switch(choice){
					case 1:	//Print the FullTime Worker salary
						cout<<"Which Employee's details to show?:"<<endl;						
						for(i = 0; i<numofFTE; i++){//prints the number of employees of that type
							cout<<i+1<<".)"<<fte[i].returnfirstname()<<" "<<fte[i].returnlastname()<<endl;
						}
						cin>>employeechoice;
						employeechoice -= 1; //adjusting for the indexes of the object array
						fte[employeechoice].FullTimeWorkerSalarySlip();
						choice = 5;
					break;
					
					case 2: //print the part time worker salary
						cout<<"Which Employee's details to show?:"<<endl;						
						for(i = 0; i<numofPTE; i++){//prints the number of employees of that type
							cout<<i+1<<".)"<<pte[i].returnfirstname()<<" "<<pte[i].returnlastname()<<endl;
						}
						cin>>employeechoice;
						employeechoice -= 1; //adjusting for the indexes of the object array
						pte[employeechoice].PartTimeWorkerSalarySlip();
						choice = 5;
					break;
					
					case 3://print the shift worker salary
						cout<<"Which Employee's details to show?:"<<endl;						
						for(i = 0; i<numofSWE; i++){//prints the number of employees of that type
							cout<<i+1<<".)"<<swe[i].returnfirstname()<<" "<<swe[i].returnlastname()<<endl;
						}
						cin>>employeechoice;
						employeechoice -= 1; //adjusting for the indexes of the object array
						swe[employeechoice].ShiftWorkersSalarySlip();
						choice = 5;
					break;
					
					case 4://print the trainee salary
						cout<<"Which Employee's details to show?:"<<endl;						
						for(i = 0; i<numofTRE; i++){//prints the number of employees of that type
							cout<<i+1<<".)"<<tre[i].returnfirstname()<<" "<<tre[i].returnlastname()<<endl;
						}
						cin>>employeechoice;
						employeechoice -= 1; //adjusting for the indexes of the object array
						tre[employeechoice].TraineeSalarySlip();
						choice = 5;												
					break;
					
					default:
						cout<<"-->>Invalid Option<<--"<<endl;
						choice = 5;										
				}//end of switch			
			}//end of while
			cout<<"-->>Exited<<--"<<endl;	

		break;
		
				
		case 4://Shows the name of all workers of each type
			cout<<"\n         SHOWING ALL WORKERS        "<<endl;
			cout<<"-------------------------------------->>>>>Full Time employees"<<endl;
			for(i = 0; i<numofFTE; i++){//calculating all FullTime Employee wages
				cout<<"Full Time Employee "<<i+1<<": "<< fte[i].returnfirstname()<<" "<<fte[i].returnlastname()<<endl;
				cout<<endl;
			}//end loop displaying FullTime Worker

			cout<<"-------------------------------------->>>>>Part Time employees"<<endl;		
			for(i = 0; i<numofPTE; i++){//calculating all PartTime Employee wages
				cout<<"Part Time Employee "<<i+1<<": "<< pte[i].returnfirstname()<<" "<<pte[i].returnlastname()<<endl;
				cout<<endl;
			}//end loop displaying PartTime Worker
			
			cout<<"-------------------------------------->>>>>Shift Workers"<<endl;		
			for(i = 0; i<numofSWE; i++){//calculating all ShiftWorking Employee wages
				cout<<"Shift Worker "<<i+1<<": "<< swe[i].returnfirstname()<<" "<<swe[i].returnlastname()<<endl;
				cout<<endl;
			}//end loop displaying ShiftWorking Employee

			cout<<"-------------------------------------->>>>>Trainees"<<endl;			
			for(i = 0; i<numofTRE; i++){//calculating all Trainee wages
				cout<<"Trainee "<<i+1<<": "<< tre[i].returnfirstname()<<" "<<tre[i].returnlastname()<<endl;
				cout<<endl;
			}//end loop displaying Trainees
			cout<<"______________________________________"<<endl;
			cout<<"-->>Exited<<--"<<endl;		
		break;		
				
		default:
		cout<<"-->>Invalid Option<<--"<<endl;
	}//end of main switch
	
DecisionMenu();
cin>>DecisionMenuChoice;
}//END OF LOOP FOR ENTIRE PROGRAM-----------------------------------------------

cout<<"\n\nProgram Ended"<<endl;
cout<<"Created by TadeoB. JoramC. and MarlonB."<<endl;
	

    return 0;
}
