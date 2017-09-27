#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "sets.h"

enum {SET_POWER = 16};

char* set_gen();

int main(int argc, char **argv) {
	srand(time(NULL));

    using namespace std; 
    using namespace SetsOperations;
	using namespace ListOperations;
	using namespace BitsOperations;

	int n = 0;

    char st_A[SET_POWER + 1] = {"012"};
    char st_B[SET_POWER + 1] = {"1356"};
    char st_C[SET_POWER + 1] = {"2895"};
    char st_D[SET_POWER + 1] = {"0126985"};
    char* E = nullptr;
	
	cout << "Input: " << endl;
    cout << st_A << endl
         << st_B << endl
         << st_C << endl
         << st_D << endl;

	E = unite(st_A, triple_cross(st_B, st_C, st_D));

    cout << "Result: " << endl;
    cout << E << endl;
	
	

	char* A{ nullptr };
	char* B{ nullptr };
	char* C{ nullptr };
	char* D{ nullptr };

	char choice = 0;
	cout << "Generate, input from keyboard or run benchmark? (G\\K\\B) ";
	cin >> choice;
	
	if (choice == 'G' || choice == 'g')	{
		A = set_gen();
		B = set_gen();
		C = set_gen();
		D = set_gen();
	}
	else if (choice == 'K' || choice == 'k') {
		A = new char[SET_POWER + 1];
		B = new char[SET_POWER + 1];
		C = new char[SET_POWER + 1];
		D = new char[SET_POWER + 1];

		cout << "Type hexadecimal numbers in one string, without duplicates." << endl;
		cout << "Set A: ";
		cin >> A;
		cout << "Set B: ";
		cin >> B;
		cout << "Set C: ";
		cin >> C;
		cout << "Set D: ";
		cin >> D;
	}
	else if (choice == 'B' || choice == 'b') {
		enum {REPEAT_NUM = 1000000};
		unsigned long start_time = clock();
		for (int z = 0; z < REPEAT_NUM; z++) {
			char* C_D = cross(st_C, st_D);
			char* B_C_D = cross(st_B, C_D);
			E = unite(st_A, B_C_D);

			delete[] C_D;
			delete[] B_C_D;
			delete[] E;
		}
		unsigned long finish_time = clock();
		double tick_time = (finish_time - start_time) / static_cast<double>(REPEAT_NUM);
		cout << "Set clocks: " << tick_time << endl;
	}
    
	
	// ARRAYS
    E = unite(A, triple_cross(B, C, D));

    cout << "Sets as arrays: " << endl;
    cout << "Input: " << endl;
    cout << A << endl
         << B << endl
         << C << endl
         << D << endl;

    cout << "Result: " << endl;
    cout << E << endl;

	// LIST
	ListNode* list_A = str_to_list(A);
	ListNode* list_B = str_to_list(B);
	ListNode* list_C = str_to_list(C);
	ListNode* list_D = str_to_list(D);

	ListNode* list_E = unite(list_A, cross(list_B, cross(list_C, list_D)));
	//ListNode* list_E = unite(list_A, list_B);

	cout << "Sets as lists: " << endl;
	cout << "Input: " << endl;
	show(list_A);
	show(list_B);
	show(list_C);
	show(list_D);

	cout << "Result: " << endl;
	show(list_E);

	// BIT ARRAY
	int bits_A = stb(A);
	int bits_B = stb(B);
	int bits_C = stb(C);
	int bits_D = stb(D);

	int bits_E = bits_A | (bits_B & bits_C & bits_D);
	
	cout << "Sets as arrays: " << endl;
	cout << "Input: " << endl;
	cout << bts(bits_A) << endl
		<< bts(bits_B) << endl
		<< bts(bits_C) << endl
		<< bts(bits_D) << endl;

	cout << "Result: " << endl;
	cout << bts(bits_E) << endl;

	cin >> A;
	
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;

    return 0;
}

char* set_gen()
{
	char* A = new char[SET_POWER + 1];
	char mask[] = "0123456789ABCDEF";
	int j = 0;
	for (int i = 0; i < 15; i++)
		if (rand() % 2 == 1)
			A[j++] = mask[i];
	A[j] = '\0';

	return A;
}
