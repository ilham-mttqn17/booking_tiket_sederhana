#include <iostream>
#include <cstdio>
#include <string.h>
#include "Booking_tiket.cpp"
#include "Registrasi_akun.cpp"

using namespace std;


void Informasi() {
	FILE *handle, *handle2;
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
	}
	fclose(handle);


	handle2 = fopen(file_database_tiket_pesawat,"rb+");
	if (handle2 == NULL)
	{
		cout << "Database Kosong" << endl;
		getchar();
	} else {
		while(!feof(handle2)) {
			if (fread(&tiket, 1, sizeof(tiket), handle2) == 0)
			{
				break;
			}

			if (strcmp(tiket.nama_pengguna, tmp_nama) == 0)
			{
				system("cls");
				cout << "===============================" << endl;
				cout << "Informasi Keberangkatan" << endl;
				cout << "===============================" << endl;
				cout << "Nama Maskapai\t\t: " << tiket.jadwal_buf.nama_maskapai << endl;
				cout << "Tgl Keberangkatan\t: " << tiket.jadwal_buf.tgl_keberangkatan << endl;
				cout << "Tujuan\t\t\t: " << tiket.jadwal_buf.tujuan << endl;
				cout << "Keberangkatan\t\t: " << tiket.jadwal_buf.keberangkatan << endl;
				cout << "Terminal\t\t: " << tiket.jadwal_buf.terminal << endl;
				
			}
		}
	}
	getchar();
	fclose(handle2);

	return;
}