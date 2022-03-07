#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main(){

	// deklarasi
	const size_t jum_data = 3;
	array <int, jum_data> data = {2,6,4};	// data array tidak ber-urut
	int kunci;	// sebagai key dalam searching

	// melakukan sorting dengan standard library
	sort(data.begin(), data.end());
	cout << data[0] << " ";
	cout << data[1] << " ";
	cout << data[2] << endl;

	// pengambilan inputan dari user
	cout << "Cari : "; cin >> kunci;
	
	// lakukan proses searching
	int low = 0;
	int high = jum_data - 1;
	int ketemu = 0;	// sebagai indikator
	int index_rumus;

	do{
		index_rumus = ((kunci - data[low]) / (data[high] - data[low])) * (high - low) + low;

		if(data[index_rumus] == kunci){
			ketemu++;
			break;
		}

		if(data[index_rumus] < kunci){
			low = index_rumus + 1;
		}else if(data[index_rumus] > kunci){
			high = index_rumus - 1;
		}

	} while(kunci >= data[low] && kunci <= data[high]);

	if(ketemu > 0){
		cout << "Data ditemukan !!" << endl;
	}else{
		cout << "Data tidak ditemukan !!!" << endl;
	}


	cin.get();
	return 0;
}