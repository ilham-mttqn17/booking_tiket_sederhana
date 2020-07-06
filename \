#include <iostream>
#include <cstdio>
#include <string.h>
#include "User.cpp"
#include "Admin.cpp"

using namespace std;

struct Admin
{
	char username[10][10] = {"ilham","rizka","dimas","fauzi","fandi","yuda","kiki","arini","sulis","aisyah"};
	char password[10][10] = {"19113027", "19113007","19113020","19113004","19113047","19113013","19113031","19113011","19113034","19113015"};	
}admin;

int main()
{
	
	int pilih;
	char username[10], password[10];
	char tmp_buffer[64] = {0};
	char x;
	string menu [] = {

		"User",
		"Admin",
		"Exit"
	};

	Menu:
	system("cls");
	cout << "=========================" << endl;
	cout << "Program Tiket" << endl;
	cout << "=========================" << endl;
	for (int i = 0; i < (sizeof(menu)/sizeof(menu[0])); ++i)
	{
		cout << i+1 << ". " << menu[i] << endl;
	}
	cout << "\nPilih menu : ";
	fgets(tmp_buffer, 32, stdin);
	pilih = atoi(tmp_buffer);

	if (pilih == 1){
		User();
	} else if (pilih == 2){
		cout << "Masukkan username : ";
		cin.getline(username, 10);
		cout << "Masukkan password : ";
		cin.getline(password, 10);
		for (int i = 0; i < 9; ++i)
		{
			if (!strcmp(admin.username[i],username) && !strcmp(admin.password[i], password))
			{
				Admin();
				break;
			} else {
				cout << "Username atau password salah, harap masukkan dengan benar!" << endl;
				getchar();
				goto Menu;
			}
		}
		
	} else if (pilih == 3){
		
		cout << "Apakah Anda Yakin Keluar Program ? [y/n] : ";
		cin >> x;
		cin.ignore(1);

		if (x == 'y' || x == 'Y') {
			exit(0);
		} else {
			goto Menu;
		}

	} else {

		cout << "Menu Tidak Tersedia" << endl;
		getchar();
		goto Menu;
	}
	
	goto Menu;
	return 0;
}
