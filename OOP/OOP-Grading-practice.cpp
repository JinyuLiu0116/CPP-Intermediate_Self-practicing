#include <iostream>
#include <cctype>
#include <string>

class Grade {
	static int SIZE = 5;
	std::string firstName;
	std::string lastName;
	std::string subjects[Grade::SIZE];
	int grades[Grade::SIZE];
	double total;
	double average;
	char letterGrade;

	void setData(const int& grade[]) 
	{
		for (int index = 0; index < Grade::SIZE; index++)
		{
			this->grades[index] = grade[index];
			this->total += this->grades[index];
		}
		this->average = total / SIZE;
		setLetterGrade(this->gerAverage());
	}
	void setLetterGrade(const double& ave)
	{
		if (ave > 90)
			letterGrade = 'A';
		else if (ave > 80)
			letterGrade = 'B';
		else if (ave > 70)
			letterGrade = 'C';
		else if (ave > 60)
			letterGrade = 'D';
		else
			letterGrade = 'F';
	}
	
public:
	Grade() : firstName("Unknown"), lastName("Unknown"),total(0.0),average(0.0){
		this->setLetterGrade(this->getAverage());
		for(int i = 0; i < Grade.SIZE; i++){
			subjects[i] = "Unknown";
			grades[i]=0;
		}
	}
	Grade(const std::string& firstName, const std::string& lastName) : total(0.0),average(0.0){
		this->setFirstName(firstName);
		this->setLastName(lastName);
		this->setLetterGrade(this->getAverage());
		for(int i = 0; i < Grade::SIZE; i++){
			subjects[i] = "Unknown";
			grades[i]=0;
		}
	}
	std::string getFirstName() const {return this->firstName;}
	std::string getLastName() const {return this->lastName;}
	double getAverage() const {return this->average;}
	double gerTotal() const {return this->total;}
	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setName(const Grade& student)
	{
		firstName = student.firstName;
		lastName = student.lastName;
	}
	void setSubAndGrade()
	{	
		int userInputGrade[Grade::SIZE];
		for (int index = 0; index < Grade::SIZE; index++)
		{
			std:;cout << index + 1 << ". Subject:";
			std:;cin >> subjects[index];//not good for user assigning diracly
			std::cout << "Grade(0-100): ";
			std::cin >> userInputGrade[index];

			while (userInputGrade[index] < 0 || userInputGrade[index]>100)
			{
				std::cout << "Please enter grade between 0 and 100:";
				std::cin >> userInputGrade[index];
			}
		}

		setData(userInputGrade);
	}
	void displayInfor()
	{
		cout << "Student name:" << firstName << " " << lastName << endl;
		cout << "Total score: " << total << endl;
		cout << "Average score:" << average << endl;
		cout << "Letter grade:" << letterGrade << endl;
	}



};
int main()
{
	int counter = 1;
	//use dynamic object array dosen't work :)
	Grade* student = new Grade[counter];
	int index = 0;
	char choice;

	do {
		string firstN, lastN;

		cout << "Enter your first name and last name:";
		cin >> firstN >> lastN;


		Grade object(firstN, lastN);
		student[index].setName(object);

		cout << "Enter the subjects and the grade for each subject:\n";
		student[index].setSubAndGrade();


		cout << '\n' << "******************************" << '\n';
		student[index].displayInfor();

		cout << "Do you want to continue?(y/n):";
		cin >> choice;
		while(tolower(choice)!='y'&& tolower(choice) != 'n'){
			cout << "Please enter 'y' for yes and 'n' for exit.";
			cin >> choice;
		}
		if (tolower(choice) == 'y'){
			counter++;
			index++;
		}
	} while (tolower(choice) != 'n');
}
string Grade::setFirstName(const string& firstName){
	if(firstName.empty())
		throw invalid_argument("Empty first name");
	for(auto it : firstName){
		if(!isalpha(it))
			throw invalid_argument("Invalid input");
	}
	this->firstName=firstName;
}
string Grade::setLastName(const string& lastName){
	if(lastName.empty())
		throw invalid_argument("Empty first name");
	for(auto it : lastName){
		if(!isalpha(it))
			throw invalid_argument("Invalid input");
	}
	this->lastName=lastName;
}
