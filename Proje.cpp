/****************************************************************************
**						SAKARYA ÜNİVERSİTESİ
**				 BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**		    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ PROGRAMLAMAYA GİRİŞİ DERSİ
**							
**
**					ÖDEV NUMARASI.....: 2
**					ÖĞRENCİ ADI.......: Eren Kara
**					ÖĞRENCİ NUMARASI..: B211210031
**					DERS GRUBU........: 1.Öğretim A Grubu
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "TR");
	srand(time(NULL));
	int Asecim;
	ifstream DosyaOku; // Dosyadan veri okumak için
	ofstream DosyaYaz; // Dosyaya veri yazmak için

	//1
	string uisim;
	string uretici;
	int gun;
	int yil;
	double fiyat;
	double KDV;
	int stok;

	//2
	int fNoo;
	string fAd;
	long fTel;
	string fSorumlu;
	char kategori;
	string fAdres;

	//3
	int fNo;
	int siparisTarihG;
	int siparisTarihA;
	int siparisTarihY;
	double siparisFiyat;
	string siparisiAlan;
	int uKod;
	int uAdet;

	do    
	{
		// Ana Menü
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);   //renkli yazmak için.
		cout << "Yapmak istediğiniz işlemi seçiniz: " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "1.Ürün için işlemler " << endl;
		cout << "2.Müşteri için işlemler " << endl;
		cout << "3.Sipariş için işlemler " << endl;
		cout << "4.Programdan çıkmak için" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "Seçiminiz: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> Asecim; 
		cout << endl;

		if (Asecim == 1)
		{
			int Usecim;
			do
			{
				// Ürün için işlemler menüsü
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "Yapmak istediğiniz işlemi seçiniz: " << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << "1.Ürün eklemek için" << endl;
				cout << "2.Ürün aramak için" << endl;
				cout << "3.Ürün listelemek için" << endl;
				cout << "4.Ürün üzerinde değişiklik yapmak için" << endl;
				cout << "5.Ürün silmek için" << endl;
				cout << "0.Ana menüye dönmek için"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << "Seçiminiz: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cin >> Usecim;
				cout << endl;

				string aranan;

				if (Usecim == 1)  // Ürün eklemek için
				{
					DosyaYaz.open("Urun.txt",ios::app);

					cout << "Ürünün ismi: ";
					cin >> uisim;
					cout << "Ürünün üreticisi: ";
					cin >> uretici;
					cout << "Ürünün temini kaç gün: ";
					cin >> gun;
					cout << "Üretim tarihi yıl: ";
					cin >> yil;
					cout << "Ürünün fiyatı: ";
					cin >> fiyat;
					cout << "Ürünün KDV oranı: ";
					cin >> KDV;
					cout << "Ürünün stok sayısı: ";
					cin >> stok;
					
					DosyaYaz << uisim << " " << uretici << " " << gun << " " << yil << " " << fiyat << " " << KDV << " " << stok<<endl;
					DosyaYaz.close();
					cout << endl;
				}
				else if (Usecim == 2)  // Ürün aramak için
				{
					cout << "Aradığınız ürünün ismini giriniz: ";
					cin >> aranan;
					DosyaOku.open("Urun.txt");
					while (!DosyaOku.eof())
					{
						DosyaOku >> uisim >> uretici >> gun >> yil >> fiyat >> KDV >> stok;

						if (aranan==uisim)
						{
							cout <<"Ürünün ismi: " << uisim << endl;
							cout <<"Ürünün üreticisi: "<< uretici << endl;
							cout <<"Ürünün kaç günde temin edileceği: "<< gun << endl;
							cout <<"Üretim tarihi: "<<yil << endl;
							cout <<"Ürünün fiyatı: "<< fiyat << endl;
							cout <<"Ürünün KDV oranı: "<< KDV << endl;
							cout <<"Ürünün stok sayısı: "<<stok << endl;
						}
					}
					DosyaOku.close();
					cout << endl;
				}
				else if (Usecim == 3)  // Ürünleri listelemek için.
				{
					int sayac = 0;
					DosyaOku.open("Urun.txt");
					while (!DosyaOku.eof())
					{
						sayac++;
						DosyaOku >> uisim >> uretici >> gun >> yil >> fiyat >> KDV >> stok;
						cout <<sayac<<". ürün ---> "<< uisim << endl;
					}
					DosyaOku.close();
					cout << endl;
				}
				else if (Usecim == 4)  // Ürün üzerinde değişiklik yapmak için
				{
					cout << "Düzeltmek istediğiniz veriyi giriniz: ";
					DosyaOku.open("Urun.txt");
					DosyaYaz.open("Urun.tmp");
					while (!DosyaOku.eof())
					{
						DosyaOku >> uisim >> uretici >> gun >> yil >> fiyat >> KDV >> stok;
						if (aranan == uisim)
						{
							cout << "Ürünün ismi: ";
							cin >> uisim;
							cout << "Ürünün üreticisi: ";
							cin >> uretici;
							cout << "Ürünün temini kaç gün: ";
							cin >> gun;
							cout << "Üretim tarihi yıl: ";
							cin >> yil;
							cout << "Ürünün fiyatı: ";
							cin >> fiyat;
							cout << "Ürünün KDV oranı: ";
							cin >> KDV;
							cout << "Ürünün stok sayısı: ";
							cin >> stok;
							cout << "Yeni veriler, eski veriler ile değiştirilmiştir.";
						}
						else
						{
							DosyaYaz << uisim << " " << uretici << " " << gun << " " << yil << " " << fiyat << " " << KDV << " " << stok;
						}
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove("Urun.txt");
					rename("Urun.tmp", "Urun.txt");
					cout << endl;
				}
				else if (Usecim == 5)  // Ürün silmek için
				{
					
					cout << "Silmek istediğiniz ürünün ismi: ";
					cin >> aranan;
					DosyaYaz.open("Urun.tmp");
					DosyaOku.open("Urun.txt");
					while (!DosyaOku.eof())
					{
						DosyaOku >> uisim >> uretici >> gun >> yil >> fiyat >> KDV >> stok;

						if (aranan == uisim)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							cout << "Ürün silinmiştir."<<endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						}
						else
						{
							DosyaYaz << uisim << " " << uretici << " " << gun << " " << yil << " " << fiyat << " " << KDV << " " << stok;
						}
					}

					DosyaYaz.close();
					DosyaOku.close();
					remove("Urun.txt");
					rename("Urun.tmp", "Urun.txt");
					cout << endl;
				}

				else
				{
					if (Usecim != 0)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
						cout << "Yanlış bir sayı tuşladınız." << endl << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}
				}

			} while (Usecim != 0);
		}

		else if (Asecim == 2) 
		{
			int Msecim;
			int aranan;

			do
			{
				// Müşteri işlemleri menüsü
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "Yapmak istediğiniz işlemi seçiniz: " << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << "1.Müşteri eklemek için" << endl;
				cout << "2.Müşteri aramak için" << endl;
				cout << "3.Müşteri üzerinde değişiklik yapmak için" << endl;
				cout << "4.Müşteri silmek için" << endl;
				cout << "0.Ana menüye dönmek için"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << "Seçiminiz: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cin >> Msecim;
				cout << endl;

				if (Msecim == 1)  //müşteri eklemek için
				{	
					DosyaYaz.open("Musteri.txt",ios::app);
					cout << "Firma no: ";
					cin >> fNoo;
					cout << "Firmanın ismi: ";
					cin >> fAd;
					cout << "Firmanın telefonu: ";
					cin >> fTel;
					cout << "Firmanın sorumlusunun ismi: ";
					cin >> fSorumlu;

					do   // Yanlış bir değer girilmesini önlemek için
					{
						cout << "Müşteri kategorisi G ( genel ) ve O ( özel ): ";
						cin >> kategori;
						if (!(kategori == 'O' || kategori == 'G'))
							cout << "Yanlış bir seçim yaptınız"<<endl;
					} while (!(kategori=='O' || kategori=='G'));

					cout << "Firma'nın adresi: ";
					cin >> fAdres;
					
					DosyaYaz << fNoo << " " << fAd << " " << fTel << " " << fSorumlu << " " << kategori << " " << fAdres;
					DosyaYaz.close();
					cout << endl;
				}

				else if (Msecim == 2)  // Müşteri aramak için
				{
					cout << "Aradığınız müşterinin numarasını giriniz: ";
					cin >> aranan;
					DosyaOku.open("Musteri.txt");
					while (!DosyaOku.eof())
					{
						DosyaOku >> fNoo >> fAd >> fTel >> fSorumlu >> kategori >> fAdres;

						if (aranan == fNoo)
						{
							cout << "Firma numarası: ";
							cout << fNoo << endl;
							cout << "Firmanın ismi: ";
							cout << fAd<< endl;
							cout << "Firmanın telefon numarası: ";
							cout << fTel << endl;
							cout << "Firmanın sorumlusunun ismi: ";
							cout << fSorumlu<< endl;
							cout << "Firmanın kategorisi: ";
							cout << kategori << endl;
							cout << "Firmanın adresi: ";
							cout << fAdres << endl;
						}
					}
					cout << endl;
				}
				else if (Msecim == 3)  // Müşteri verileri üzerinde değişiklik yapmak için
				{
					cout << "Değişiklik yapmak istediğiniz müşterinin numarasını giriniz: ";
					cin >> aranan;
					DosyaOku.open("Musteri.txt");
					while (!DosyaOku.eof())
					{
						DosyaOku >> fNoo >> fAd >> fTel >> fSorumlu >> kategori >> fAdres;

						if (aranan == fNoo)
						{
							cout << "Firma no: " << endl;
							cin >> fNoo;
							cout << "Firma ismi: " << endl;
							cin >> fAd;
							cout << "Firmanın telefon numarası: " << endl;
							cin >> fTel;
							cout << "Firman sorumlusun ismi: " << endl;
							cin >> fSorumlu;
							cout << "Firmayı soktuğunuz kategori: " << endl;
							cin >> kategori;
							cout << "Firmanın adresi: " << endl;
							cin >> fAdres;
						}
						else
						{
							DosyaYaz << fNoo << " " << fAd << " " << fTel << " " << fSorumlu << " " << kategori << " " << fAdres;
						}
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove("Musteri.txt");
					rename("Musteri.tmp", "Musteri.txt");
					cout << endl;
				}
				else if (Msecim == 4)  // Müşteri verilerini silmek için
				{
					cout << "Silmek istediğiniz müşterinin numarası: ";
					cin >> aranan;
					DosyaYaz.open("Musteri.tmp");
					DosyaOku.open("Musteri.txt");
					while (!DosyaOku.eof())
					{
						DosyaOku >> fNoo >> fAd >> fTel >> fSorumlu >> kategori >> fAdres;

						if (aranan == fNoo)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							cout << "Müşteri silinmiştir."<<endl << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						}
						else
						{
							DosyaYaz << fNoo << " " << fAd << " " << fTel << " " << fSorumlu << " " << kategori << " " << fAdres;
						}
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove("Musteri.txt");
					rename("Musteri.tmp", "Musteri.txt");
					cout << endl;
				}
				else
				{
					if (Msecim != 0)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
						cout << "Yanlış bir sayı tuşladınız." << endl << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}
				}

			} while (Msecim != 0);
		}
		else if (Asecim == 3)
		{
			int Ssecim;
			int aranan;

			do
			{
				// Siparişler ile ilgili menü
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "Yapmak istediğiniz işlemi seçiniz: " << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << "1.Sipariş oluşturmak için" << endl;
				cout << "2.Sipariş aramak için" << endl;
				cout << "3.Sipariş üzerinde değişiklik yapmak için" << endl;
				cout << "4.Sipariş silmek için" << endl;
				cout << "0.Ana menüye dönmek için" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << "Seçiminiz: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cin >> Ssecim;
				cout << endl;

				if (Ssecim == 1)  //Sipariş ekleme
				{
					DosyaYaz.open("Siparis.txt",ios::app);
					cout << "Firma no: ";
					cin >> fNo;
					cout << "Siparis tarihi gün: ";
					cin >> siparisTarihG;
					cout << "Siparis tarihi ay: ";
					cin >> siparisTarihA;
					cout << "Siparis tarihi yıl: ";
					cin >> siparisTarihY;
					cout << "Siparis fiyat: ";
					cin >> siparisFiyat;
					cout << "Siparisi alan: ";
					cin >> siparisiAlan;
					cout << "Ürünün kodunu: ";
					cin >> uKod;
					cout << "uAdet: ";
					cin >> uAdet;
				
					DosyaYaz << fNo << " " << siparisTarihG << " " <<siparisTarihA << " " <<siparisTarihY << " " << siparisFiyat << " " << siparisiAlan << " " << uKod << " " << uAdet;
					DosyaYaz.close();
					cout << endl;
				}
				else if (Ssecim == 2) // Siparişler arasından istenilen siparişi arama
				{
					cout << "Aradığınız sipraşin verildiği firmanın numarası: ";
					cin >> aranan;
					DosyaOku.open("Siparis.txt");
					while (!DosyaOku.eof())
					{
						DosyaOku >> fNo >> siparisTarihG >> siparisTarihA >> siparisTarihY >> siparisFiyat >> siparisiAlan >> uKod >> uAdet;

						if (aranan == fNo)
						{
							cout << "Firma no: " <<fNo<< endl;
							cout << "Siparis tarihi gün: "<<siparisTarihG << endl;
							cout << "Siparis tarihi ay: "<<siparisTarihA<<endl;
							cout << "Siparis tarihi yıl: "<<siparisTarihY<<endl;
							cout << "Siparis fiyat: "<<siparisFiyat<<endl;
							cout << "Siparisi alan: "<<siparisiAlan<<endl;
							cout << "Ürünün kodunu: "<<uKod<<endl;
							cout << "uAdet: "<<uAdet<<endl;
						}
					}
					cout << endl;
				}
				else if (Ssecim == 3) // Sipariş verisi üzerinde değişiklik yapma
				{
					cout << "Değişiklik yapmak istediğiniz müşterinin numarasını giriniz: ";
					cin >> aranan;
					DosyaOku.open("Siparis.txt");
					while (!DosyaOku.eof())
					{
						DosyaOku >> fNo >> siparisTarihG>>siparisTarihA>>siparisTarihY >> siparisFiyat >> siparisiAlan >> uKod >> uAdet;

						if (aranan == fNo)
						{
							cout << "Firma no: ";
							cin >> fNo;
							cout << "Siparis tarihi gün: ";
							cin >> siparisTarihG;
							cout << "Siparis tarihi ay: ";
							cin >> siparisTarihA;
							cout << "Siparis tarihi yıl: ";
							cin >> siparisTarihY;
							cout << "Siparis fiyat: ";
							cin >> siparisFiyat;
							cout << "Siparisi alan: ";
							cin >> siparisiAlan;
							cout << "Ürünün kodunu: ";
							cin >> uKod;
							cout << "uAdet: ";
							cin >> uAdet;
						}
						else
						{
							DosyaYaz << fNo << " " << siparisTarihG << " " << siparisTarihA << " " << siparisTarihY << " " << siparisFiyat << " " << siparisiAlan << " " << uKod << " " << uAdet;
						}
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove("Siparis.txt");
					rename("Siparis.tmp", "Siparis.txt");
					cout << endl;
				}
				else if (Ssecim == 4)  // Sipariş verisini silmek için
				{
					cout << "Silmek istediğiniz siparişin ait olduğu firmanın numarası: ";
					cin >> aranan;
					DosyaYaz.open("Siparis.tmp");
					DosyaOku.open("Siparis.txt");
					while (!DosyaOku.eof())
					{
						DosyaOku >> fNo >> siparisTarihG >> siparisTarihA >> siparisTarihY >> siparisFiyat >> siparisiAlan >> uKod >> uAdet;

						if (aranan == fNo)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							cout << "Sipariş silinmiştir."<<endl << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						}
						else
						{
							DosyaYaz << fNo << " " << siparisTarihG << " " << siparisTarihA << " " << siparisTarihY << " " << siparisFiyat << " " << siparisiAlan << " " << uKod << " " << uAdet;
						}
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove("Siparis.txt");
					rename("Siparis.tmp", "Siparis.txt");
					cout << endl;
				}
				else
				{
					if (Ssecim != 0)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
						cout << "Yanlış bir sayı tuşladınız." << endl << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}
				}

			} while (Ssecim != 0);
		}
		else
		{
			if (Asecim != 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "Yanlış bir sayı tuşladınız." << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
		}

	} while (Asecim != 4);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "Programdan çıkış yaptınız."<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}