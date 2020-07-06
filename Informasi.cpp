#include <iostream>
#include <cstdio>
#include <string.h>
#include <conio.h>
#include "Booking_tiket.cpp"
#include "Registrasi_akun.cpp"

using namespace std;


void Informasi() {
	FILE *handle;
	char tmp_nama[32];
	struct User user;
	struct Tiket tiket;


	handle = fopen(file_database_user,"rb+");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
		getchar();
	} else {
		while(!feof(handle)) {
			if (fread(&user, 1, sizeof(user), handle) == 0)
			{
				break;
			}
			strcpy(tmp_nama, user.nama);
		}
		fclose(handle);
	}


	// handle = fopen(file_database_tiket_pesawat, "rb+");
	// if (handle == NULL)
	// {
	// 	cout << "Database Kosong" << endl;
	// 	getchar();
	// } else {
	// 	while(!feof(handle)){
	// 		if (fread(&tiket, 1, sizeof(tiket), handle) == 0)
	// 		{
	// 			break;
	// 		}
	// 	}
	// 	fclose(handle);		
	// }
	

	handle = fopen(file_database_tiket_pesawat,"rb+");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
		getch();
	} else {
		while(!feof(handle)) {
			if (fread(&tiket, 1, sizeof(tiket), handle) == 0)
			{
				break;
			}

			if (strcmp(tiket.nama_pengguna, tmp_nama) == 0)
			{
				system("cls");
				cout << "===============================" << endl;
				cout << "Informasi Keberangkatan" << endl;
				cout << "===============================" << endl;
				for (int i = 0; i < 7; ++i)
				{
					cout << "Nama Maskapai\t\t: " << tiket.jadwal_buf[i].nama_maskapai << endl;
					cout << "Tgl Keberangkatan\t: " << tiket.jadwal_buf[i].tgl_keberangkatan << endl;
					cout << "Tujuan\t\t\t: " << tiket.jadwal_buf[i].tujuan << endl;
					cout << "Keberangkatan\t\t: " << tiket.jadwal_buf[i].keberangkatan << endl;
					cout << "Terminal\t\t: " << tiket.jadwal_buf[i].terminal << endl;
					cout << endl;
				}
				break;
				// cout << "Tujuan\t\t\t: " << tiket.jadwal_buf.tujuan << endl;
				// cout << "Keberangkatan\t\t: " << tiket.jadwal_buf.keberangkatan << endl;
				// cout << "Terminal\t\t: " << tiket.jadwal_buf.terminal << endl;
				
			}
		}
		// getch();
		fclose(handle);
	}

	return;
	
}