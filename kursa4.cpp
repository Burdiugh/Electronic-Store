#include<iostream>
#include<ctime>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;

struct Device {
	string type = "none type";
	string name = "none name";
	string model = "none model";
	int price = 0;
};

// prototypes
int search(Device* obj, int& length, string& model);
//

void Show(Device obj) {
	cout << "--------------------" << endl;
	cout << "Type: " << obj.type << endl;
	cout << "Name: " << obj.name << endl;
	cout << "Model: " << obj.model << endl;
	cout << "Price: " << obj.price <<"$"<< endl;
	cout << "--------------------" << endl;
}

void Fill(Device& obj){
	cout << "___Input info___ " << endl;
	cout << "Type: ";
	cin >> obj.type;
	cout << "Name: ";
	cin >> obj.name;
	cout << "Model: ";
	cin >> obj.model;
	do {
		cout << "Price in usd: ";
		cin >> obj.price;
		if (obj.price <= 0) {
			cout << "Input price more than 0." << endl;
		}
	} while (obj.price <= 0);
}

void Push(Device*& obj, int& length) {

	Device* mas = new Device[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		mas[i] = obj[i];
	}
	Fill(mas[length]);
	delete[] obj;
	length++;
	obj = mas;
}

void RemoveByModel(Device*& obj, int& length, string& model){

	int index = search(obj, length, model);
	if (index == -1 || length == 0) { cout << "\t\tNot found!!!!" << endl; }
	else if (length == 1) {
		delete[] obj;
		obj = nullptr;
	}
	else {
		length--;
		Device* mas = new Device[length];
		for (size_t i = 0; i < length; i++)
		{
			if (i < index) { mas[i] = obj[i]; }
			else
			{
				mas[i] = obj[i + 1];
			}
		}
		delete[] obj;
		obj = mas;
	}
}

int search(Device* obj, int& length, string &model) {
	for (size_t i = 0; i < length; i++)
	{
		if (model == obj[i].model) { return i; }
	}
	return -1;
}

void Read(ifstream& file, Device* arr, int size) {
	char temp[255];
	for (size_t i = 0; i < size; i++)
	{
		file.ignore();
		file.getline(temp, 255);
		arr[i].type = temp;
		file.getline(temp, 255);
		arr[i].name = temp;
		file >> arr[i].model;
		file >> arr[i].price;
		file.ignore();
	}
}

void Write(ofstream& file, Device*& arr, int size) {
	file << size << endl;
	for (size_t i = 0; i < size; i++)
	{
		file << arr[i].type << "\n";
		file << arr[i].name << "\n";
		file << arr[i].model << " ";
		file << arr[i].price << " ";
		file << endl;
	}
}
void BetterShow(Device *arr,int length) {
	for (size_t i = 0; i < length; i++)
	{
		cout << "--- device #" << i + 1 << " ---" << endl;
		Show(arr[i]);
	}
}
template < typename T >
void SortByName(T* arr, int length) {
	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - 1 - i; j++)
		{
			if (strcmp(arr[j].name.c_str(), arr[j + 1].name.c_str()) == 1) {
				swap(arr[j], arr[j+1]);
				
			}
		}
	}
}

template < typename T >
void SortByPrice(T* arr, int length) {
	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - 1 - i; j++)
		{
			if (arr[j].price > arr[j + 1].price) {
				swap(arr[j], arr[j+1]);
				
			}
		}
	}
}

template < typename T >
void EditType(T*& obj, int& length, string model, string NewType) {
	for (size_t i = 0; i < length; i++)
	{
		if (model == obj[i].model) 
		{ 
			obj[i].type = NewType; 
			break;
		}
	}
}


template < typename T >
void EditModel(T*& obj, int& length, string model, string NewModel) {
	for (size_t i = 0; i < length; i++)
	{
		if (model == obj[i].model) 
		{ 
			obj[i].model = NewModel; 
			break;
		}
	}
}

template < typename T >
void EditName(T*& obj, int& length, string model, string NewName) {
	for (size_t i = 0; i < length; i++)
	{
		if (model == obj[i].model) 
		{ 
			obj[i].name = NewName; 
			break;
		}
	}
}

template < typename T >
void EditPrice(T*& obj, int& length, string model, int NewPrice) {
	for (size_t i = 0; i < length; i++)
	{
		if (model == obj[i].model) 
		{ 
			obj[i].price = NewPrice; 
			break;
		}
	}
}

void searchByName(Device* arr, int& length, string& name) {
	for (size_t i = 0; i < length; i++)
	{
		if (name == arr[i].name) { Show(arr[i]); }
	}
}

void searchByType(Device* arr, int& length, string& type) {
	for (size_t i = 0; i < length; i++)
	{
		if (type == arr[i].type) { Show(arr[i]); }
	}
}

float AverageTV(Device* arr, int& length, string& type) {
	int counter = 0;
	float sum = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (type == arr[i].type) 
		{ 
			counter++;
			sum += arr[i].price;
		}
	}
	return sum / counter;
}

float AverageMG(Device* arr, int& length, string& type) {
	int counter = 0;
	float sum = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (type == arr[i].type) 
		{ 
			counter++;
			sum += arr[i].price;
		}
	}
	return sum / counter;
}

float AverageByName(Device* arr, int& length, string& name) {
	int counter = 0;
	float sum = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (name == arr[i].name) 
		{ 
			counter++;
			sum += arr[i].price;
		}
	}
	return sum / counter;
}

void Discount(Device* arr, int length, string name, string type, int disc) {
	int res;
	int proc;
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i].name == name && arr[i].type == type) {
			proc = arr[i].price / 100;
			res = proc * disc;
			arr[i].price -= res;
		}
	}
}

void deleteInfo(Device* arr, int length, string type) {
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i].type == type) {
			arr[i].type = " ";
			arr[i].name = " ";
			arr[i].model = arr[i].model;
			arr[i].price = 0;
		}
	}
}

void deleteInfoName(Device* arr, int length, string type) {
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i].type == type) {
			arr[i].type = arr[i].type;
			arr[i].name = " ";
			arr[i].model = arr[i].model;
			arr[i].price = arr[i].price;
		}
	}
}

void deleteInfoType(Device* arr, int length, string type) {
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i].type == type) {
			arr[i].type = " ";
			arr[i].name = arr[i].name;
			arr[i].model = arr[i].model;
			arr[i].price = arr[i].price;
		}
	}
}

void deleteInfoPrice(Device* arr, int length, string type) {
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i].type == type) {
			arr[i].type = arr[i].type;
			arr[i].name = arr[i].name;
			arr[i].model = arr[i].model;
			arr[i].price = 0;
		}
	}
}

void FilterByType(Device* arr, int length, string type, int start, int end) {

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i].type == type&&arr[i].price>=start&&arr[i].price<=end) { Show(arr[i]); }
	}
}


int main() {
	int option = 0;
	int size=0;
	ifstream file;
	file.open("DataBase.txt");
	if (!file.is_open()) { cout << "Error, file not found!" << endl; }
	else {
		file >> size;
		Device* arr = new Device[size];
		Read(file, arr, size);
		file.close();
		cout << "Hello, choose options please " << endl;
		do
		{
			cout << "\n";
			cout << "1. Add devices to DB\n2. Add device to other devices to DB\n3. Show all devices\n4. Delete device by model\n5. Edit device by model\n6. Sort\n7. Search device by name or type\n8. Get average price\n9. Delete info about Device or give Discount\n10. Price filter by type\n0. Exit\n" << endl;
			
			cin >> option;
			switch (option)
			{
			case 1: {
				int value = 0;
				system("cls");
				cout << "How much devices you want to add to DB?: ";
				cin >> value;
				for (size_t i = 0; i < value; i++)
				{
					cout << "Devise #" << i + 1 << endl;
					cout << "--------" << endl;
					Push(arr, size);
					cout << "--------" << endl;
				}
				break; }
			case 2: {
				Push(arr, size);
				system("cls");
				BetterShow(arr, size);
				break; }
			case 3: {
				system("cls");
				BetterShow(arr, size);
				break;
			}
			case 4: {
				system("cls");
				cout << "select otion:\n1. Delete one device\n2. Delete several devices" << endl;
				switch (_getch())
				{
				case '1': {
					system("cls");
					BetterShow(arr, size);
					cout << "Input model of device which you want to delete: ";
					string model;
					cin >> model;
					RemoveByModel(arr, size, model);
					system("cls");
					BetterShow(arr, size);
					break;
				}
				case '2': {
					system("cls");
					BetterShow(arr, size);
					cout << "How much devices do you want to delete? : ";
					int value;
					cin >> value;
					string model;
					for (size_t i = 0; i < value; i++)
					{
						cout << "Input model of device which you want to delete: ";
						cin >> model;
						RemoveByModel(arr, size, model);
						system("cls");
						BetterShow(arr, size);
					}
					break; }
				default:
					break;
				}
				break; }
			case 5: {
				BetterShow(arr, size);
				cout << "\tInput model of device which you want to edit and choose operation again :)\n" << endl;
				cout << "Model: ";
				string model;
				cin >> model;
				cout << "1. Edit type\n2. Edit name\n3. Edit model\n4. Edit price" << endl;
				switch (_getch())
				{
				case '1': {
					cout << "New type: ";
					string edit;
					cin >> edit;
					EditType(arr, size, model, edit);
					system("cls");
					BetterShow(arr, size);
					break; }
				case '2': {
					cout << "New name: ";
					string edit;
					cin >> edit;
					EditName(arr, size, model, edit);
					system("cls");
					BetterShow(arr, size);
					break; }
				case '3': {
					cout << "New model: ";
					string edit;
					cin >> edit;
					EditModel(arr, size, model, edit);
					system("cls");
					BetterShow(arr, size);
					break; }
				case '4': {
					cout << "New price: ";
					int price;
					do {
						cin >> price;

						if (price <= 0) {
							cout << "Input price more than 0." << endl;
						}
					} while (price <= 0);
					EditPrice(arr, size, model, price);
					system("cls");
					BetterShow(arr, size);
					break; }
				default: {cout << "Error, select true option!" << endl; }
					   break;
				}
				break; }
			case 6: {
				cout << "How we will sort devices?\n1. By name\n2. By price" << endl;
				switch (_getch())
				{
				case'1': {
					system("cls");
					SortByName(arr, size);
					for (size_t i = 0; i < size; i++)
					{
						Show(arr[i]);
					}
					break; }
				case'2': {
					system("cls");
					SortByPrice(arr, size);
					BetterShow(arr, size);
					break; }
				default:
					break;
				}
				break; }
			case 7: {
				cout << "Choose option:\n1. Search devices by name\n2. Search devices by type" << endl;
				switch (_getch())
				{
				case '1': {
					cout << "Name: ";
					string name;
					cin >> name;
					system("cls");
					searchByName(arr, size, name);
					break; }
				case '2': {
					cout << "Type: ";
					string type;
					cin >> type;
					system("cls");
					if (type != "tv" && type != "mg") { cout << "Wrong type, try to input (tv)-TV or (mg)-Magnitifon" << endl; }
					else
					{
						searchByType(arr, size, type);
					}
					break; }
				default:
					break;
				}
				break; }
			case 8: {
				system("cls");
				cout << "Choose option for get average price in that category:\n1. TV or Magnitofons\n2. By name\n";
				switch (_getch())
				{
				case '1': {
					cout << "choose:\n1. TV\n2. MAGNITOFONS" << endl;
					switch (_getch())
					{
					case'1': {
						string type = "tv";
						cout << "Average price of all TV = " << AverageTV(arr, size, type) << endl;
						break; }
					case '2': {
						string type = "mg";
						cout << "Average price of all TV = " << AverageMG(arr, size, type) << endl;
						break; }
					default:cout << "Wrong select" << endl;
						break;
					}
					break; }
				case '2': {
					system("cls");
					cout << "Input name for get average price in this category:" << endl;
					cout << "Name: ";
					string name;
					cin >> name;
					cout << "Average by name " << name << " = " << AverageByName(arr, size, name) << endl;
					break; }
				default:cout << "Select true option!" << endl;
					break;
				}
				break; }
			case 9: {
				cout << "Select option:\n1. Delete any info about devices\n2. Add discount" << endl;
				switch (_getch())
				{
				case '1': {
					system("cls");
					cout << "select option:\n1. Delete all info except model\n2. Delete only names of devices\n3. Delete only types of devices\n4. Delete only prices of devices\n";
					switch (_getch())
					{
					case '1': {
						system("cls");
						BetterShow(arr, size);
						cout << "Input type of devices which do you want to \"clear/delete\"all info except model. Input: (tv) or (mg): ";
						string type;
						cin >> type;
						deleteInfo(arr, size, type);
						system("cls");
						BetterShow(arr, size);
						break; }
					case '2': {
						system("cls");
						cout << "Input type of devices which do you want to \"clear/delete\" name. Input: (tv) or (mg): ";
						string type;
						cin >> type;
						deleteInfoName(arr, size, type);
						system("cls");
						BetterShow(arr, size);
						break; }
					case '3': {
						system("cls");
						cout << "Input type of devices which do you want to \"clear/delete\" type. Input: (tv) or (mg): ";
						string type;
						cin >> type;
						deleteInfoType(arr, size, type);
						system("cls");
						BetterShow(arr, size);
						break; }
					case '4': {
						system("cls");
						cout << "Input type of devices which do you want to \"clear/delete\" type. Input: (tv) or (mg): ";
						string type;
						cin >> type;
						deleteInfoPrice(arr, size, type);
						system("cls");
						BetterShow(arr, size);
						break; }
					default:cout << "Error, select true option!" << endl;
						break;
					}
					break; }
				case '2': {
					system("cls");
					cout << "Input name and type of device: " << endl;
					string name, type;
					cout << "Type: ";
					cin >> type;
					cout << "Name: ";
					cin >> name;
					cout << "Input discount in % : ";
					int dsc;
					cin >> dsc;
					Discount(arr, size, name, type, dsc);
					system("cls");
					BetterShow(arr, size);
					break; }
				default:cout << "Error, select true option!" << endl;
					break;
				}
				break; }
			case 10: {
				system("cls");
				cout << "Input type of devices: (tv) or (mg) : ";
				string type;
				cin >> type;
				cout << "Input range of price:\n";
				int start;
				int end;
				cout << "Start price: ";
				cin >> start;
				cout << "End price: ";
				cin >> end;
				system("cls");
				FilterByType(arr, size, type, start, end);
				break; }
			case 0: {cout << "Bye!" << endl; break; }
			default: {cout << "Error, select true option!" << endl; }
				   break;
			}

		} while (option!=0);
		

		ofstream file2("DataBase.txt");
		Write(file2, arr, size);
		file2.close();
		delete[] arr;
	}
}
