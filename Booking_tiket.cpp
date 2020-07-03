#ifndef TIKET
#define TIKET 
#include <iostream>
#include <cstdio>
#include <limits>
#include <string.h>
#include "Registrasi_akun.cpp"

using namespace std;

#define file_database_tiket_pesawat "database_tiket_pesawat.txt"
#define file_database_tiket_kereta "database_tiket_kereta.txt"
#define file_database_tiket_bus "database_tiket_bus.txt"

struct Tiket{
	struct Jadwal jadwal_buf;
	char nama_pengguna[32];
	string nama_kendaraan;
	int no_bangku=0;
	string kelas[2] = {"Bisnis","Ekonomi"};
	string metode_bayar[4] = {"DANA","LINK AJA","GOPAY","BANK"};
	// int jml_tiket;
	int total_bayar;
	int harga;
};

void bookPesawat();
void bookKereta();
void bookBus();

void Booking () {
	
	FILE *handle, *handle2;
	int pilih, nread=0, no_pilih, tmp_class, tipe, tipe1, bayar, metode_bayar;
	string kelas[] = {"Bisnis","Ekonomi"};
	char x;
	struct Tiket tiket;
	struct Jadwal jadwal[5];

	Menu:
	system("cls");
	cout << "=====================" << endl;
	cout << "Booking Tiket" << endl;
	cout << "=====================" << endl;
	cout << "[1] Pesawat" << endl;
	cout << "[2] Kereta Api" << endl;
	cout << "[3] Busway" << endl;
	cout << "=====================" << endl;
	cout << "\nPilih transportasi : ";
	cin >> pilih;	
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	if (pilih == 1){
		bookPesawat();
	} else if (pilih == 2){
		bookKereta();
	} else if (pilih == 3){
		bookBus();
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		getchar();
		goto Menu;

	}
	// getchar();
	return;

}

void bookPesawat() {
	FILE *handle, *handle2, *handle3;
	int pilih, nread=0, no_pilih, tmp_class, tipe, tipe1, bayar, metode_bayar;
	string kelas[] = {"Bisnis","Ekonomi"};
	char x, tmp_buffer[64] = {0};
	struct Tiket tiket;
	struct User user;
	struct Jadwal jadwal[5];

	jadwalPesawat();
	cout << "Pilih Jadwal\t: ";
	fgets(tmp_buffer, 32, stdin);
	no_pilih = atoi(tmp_buffer);

	cout << "Pilih Kelas\t: " << endl;
	for (int i = 0; i < 2; ++i)
	{
		cout << "[" << i+1 << "] " << tiket.kelas[i] << endl;
	}
	cout << "Pilih : ";
	fgets(tmp_buffer, 32, stdin);
	tmp_class = atoi(tmp_buffer);
	
	if (tmp_class == 1)
	{
		tiket.harga = 2500000;
		tipe = 1;
	} else if (tmp_class == 2) {
		tiket.harga = 800000;
		tipe = 2;
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		getchar();
		return;
	}
	
	cout << "Pilih metode pembayaran : " << endl;
	for (int i = 0; i < 4; ++i)
	{
		cout << "[" << i+1 << "] " << tiket.metode_bayar[i] << endl;
	}
	cout << "Pilih : ";
	fgets(tmp_buffer, 32, stdin);
	metode_bayar = atoi(tmp_buffer);
	
	if (metode_bayar == 1){
		tipe1 = 1;
	} else if (metode_bayar == 2){
		tipe1 = 2;
	} else if (metode_bayar == 3){
		tipe1 = 3;
	} else if (metode_bayar == 4){
		tipe1 = 4;
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		getchar();
		return;
	}

	handle = fopen(file_database_pesawat,"rb+");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
	} else {
		while(!feof(handle)) {
			nread = fread(&jadwal, 1, sizeof(jadwal), handle);
			if (nread == 0){
				break;
			}
			tiket.jadwal_buf = jadwal[no_pilih-1];

		}
	}
	fclose(handle);

	handle3 = fopen(file_database_user,"rb+");
	if (handle3 == NULL)
	{
		cout << "Database Kosong" << endl;
		getchar();
	} else {
		while(!feof(handle3)) {
			if (fread(&user, 1, sizeof(user), handle3) == 0)
			{
				break;
			}

			strcpy(tiket.nama_pengguna, user.nama);
		}
	}
	fclose(handle3);

	cout << "\nKonfirmasi Pembelian" << endl;
	cout << "Nama Kendaraan\t\t: " << tiket.jadwal_buf.nama_maskapai << endl;
	cout << "Kelas\t\t\t: " << tiket.kelas[tipe-1] << endl;
	cout << "Total bayar\t\t: " << tiket.harga << endl;
	cout << "Metode Pembayaran\t: " << tiket.metode_bayar[tipe1-1] << endl;

	cout << "\nLanjutkan pembayaran ? [y/n] : ";
	cin >> x;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	if (x == 'Y' || x == 'y')
	{
		handle2 = fopen(file_database_tiket_pesawat,"ab+");
		if (handle2 == NULL)
		{
			cout << "Database Kosong" << endl;
		} else {
			
				tiket.no_bangku++;
				fwrite(&tiket, sizeof(tiket), 1, handle2);				
				cout << "Pembayaran Berhasil" << endl;
				fclose(handle2);
		}
			
		
	} else if (x == 'N' || x == 'n')
	{
		cout << "Pembayaran Gagal" << endl;
		
	}

	getchar();
}

void bookKereta() {
	FILE *handle, *handle2;
	int pilih, nread=0, no_pilih, tmp_class, tipe, tipe1, bayar, metode_bayar;
	string kelas[] = {"Bisnis","Ekonomi"};
	char x, tmp_buffer[64] = {0};
	struct Tiket tiket;
	struct Jadwal jadwal[5];

	jadwalKereta();
	cout << "Pilih Jadwal\t: ";
	fgets(tmp_buffer, 32, stdin);
	no_pilih = atoi(tmp_buffer);

	cout << "Pilih Kelas\t: " << endl;
	for (int i = 0; i < 2; ++i)
	{
		cout << "[" << i+1 << "] " << tiket.kelas[i] << endl;
	}
	cout << "Pilih : ";
	fgets(tmp_buffer, 32, stdin);
	tmp_class = atoi(tmp_buffer);
	
	if (tmp_class == 1)
	{
		tiket.harga = 280000;
		tipe = 1;
	} else if (tmp_class == 2) {
		tiket.harga = 150000;
		tipe = 2;
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		getchar();
		return;
	}
	
	cout << "Pilih metode pembayaran : " << endl;
	for (int i = 0; i < 4; ++i)
	{
		cout << "[" << i+1 << "] " << tiket.metode_bayar[i] << endl;
	}
	cout << "Pilih : ";
	fgets(tmp_buffer, 32, stdin);
	metode_bayar = atoi(tmp_buffer);
	
	if (metode_bayar == 1){
		tipe1 = 1;
	} else if (metode_bayar == 2){
		tipe1 = 2;
	} else if (metode_bayar == 3){
		tipe1 = 3;
	} else if (metode_bayar == 4){
		tipe1 = 4;
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		getchar();
		return;
	}

	handle = fopen(file_database_kereta,"rb+");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
	} else {
		while(!feof(handle)) {
			nread = fread(&jadwal, 1, sizeof(jadwal), handle);
			if (nread == 0){
				break;
			}
			tiket.nama_kendaraan = jadwal[no_pilih-1].nama_maskapai;

		}
	}
	fclose(handle);

	cout << "\nKonfirmasi Pembelian" << endl;
	cout << "Nama Kendaraan\t\t: " << tiket.nama_kendaraan << endl;
	cout << "Kelas\t\t\t: " << tiket.kelas[tipe-1] << endl;
	cout << "Total bayar\t\t: " << tiket.harga << endl;
	cout << "Metode Pembayaran\t: " << tiket.metode_bayar[tipe1-1] << endl;

	cout << "\nLanjutkan pembayaran ? [y/n] : ";
	cin >> x;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	if (x == 'Y' || x == 'y')
	{
		handle2 = fopen(file_database_tiket_kereta,"ab+");
		if (handle2 == NULL)
		{
			cout << "Database Kosong" << endl;
		} else {
			
				tiket.no_bangku++;
				fwrite(&tiket, sizeof(tiket), 1, handle2);
				cout << "Pembayaran Berhasil" << endl;
				fclose(handle2);
		}
		
		
	} else if (x == 'N' || x == 'n')
	{
		cout << "Pembayaran Gagal" << endl;
		
	}

	getchar();
}

void bookBus() {
	FILE *handle, *handle2;
	int pilih, nread=0, no_pilih, tmp_class, tipe, tipe1, bayar, metode_bayar;
	string kelas[] = {"Bisnis","Ekonomi"};
	char x, tmp_buffer[64] = {0};
	struct Tiket tiket;
	struct Jadwal jadwal[5];

	jadwalBus();
	cout << "Pilih Jadwal\t: ";
	fgets(tmp_buffer, 32, stdin);
	no_pilih = atoi(tmp_buffer);

	cout << "Pilih Kelas\t: " << endl;
	for (int i = 0; i < 2; ++i)
	{
		cout << "[" << i+1 << "] " << tiket.kelas[i] << endl;
	}
	cout << "Pilih : ";
	fgets(tmp_buffer, 32, stdin);
	tmp_class = atoi(tmp_buffer);
	
	if (tmp_class == 1)
	{
		tiket.harga = 200000;
		tipe = 1;
	} else if (tmp_class == 2) {
		tiket.harga = 150000;
		tipe = 2;
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		getchar();
		return;
	}
	
	cout << "Pilih metode pembayaran : " << endl;
	for (int i = 0; i < 4; ++i)
	{
		cout << "[" << i+1 << "] " << tiket.metode_bayar[i] << endl;
	}
	cout << "Pilih : ";
	fgets(tmp_buffer, 32, stdin);
	metode_bayar = atoi(tmp_buffer);
	
	if (metode_bayar == 1){
		tipe1 = 1;
	} else if (metode_bayar == 2){
		tipe1 = 2;
	} else if (metode_bayar == 3){
		tipe1 = 3;
	} else if (metode_bayar == 4){
		tipe1 = 4;
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		getchar();
		return;
	}

	handle = fopen(file_database_bus,"rb+");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
	} else {
		while(!feof(handle)) {
			nread = fread(&jadwal, 1, sizeof(jadwal), handle);
			if (nread == 0){
				break;
			}
			tiket.nama_kendaraan = jadwal[no_pilih-1].nama_maskapai;

		}
	}
	fclose(handle);

	cout << "\nKonfirmasi Pembelian" << endl;
	cout << "Nama Kendaraan\t\t: " << tiket.nama_kendaraan << endl;
	cout << "Kelas\t\t\t: " << tiket.kelas[tipe-1] << endl;
	cout << "Total bayar\t\t: " << tiket.harga << endl;
	cout << "Metode Pembayaran\t: " << tiket.metode_bayar[tipe1-1] << endl;

	cout << "\nLanjutkan pembayaran ? [y/n] : ";
	cin >> x;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	if (x == 'Y' || x == 'y')
	{
		handle2 = fopen(file_database_tiket_bus,"ab+");
		if (handle2 == NULL)
		{
			cout << "Database Kosong" << endl;
		} else {
				tiket.no_bangku++;
				fwrite(&tiket, 1, sizeof(tiket), handle2);
				cout << "Pembayaran Berhasil" << endl;
				fclose(handle2);
		}
		
		
	} else if (x == 'N' || x == 'n')
	{
		cout << "Pembayaran Gagal" << endl;
		
	}

	getchar();
}

#endif