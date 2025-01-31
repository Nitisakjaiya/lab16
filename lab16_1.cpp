#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}
		
// i +1 เพราะมีเลข0 i+1เช่น double a[6][1] = {1,2,3,4,5,6};1 0+1/1=1ลงตัว 1+1/1=2ลงตัวมันเลยจะเคาะเรื่อยเรื่อย
void showData(double *a,int N ,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << a[i];
        if((i+1)%M == 0 ) cout << endl; 
        else cout << " ";
    }
}
// 0-100คือจำนวนทศนิยมตั้งเเต่0.00-1.00
//ทั้งหมดรวม 0 จะมี101ตัวเราหารออกมาปกติมันจะได้เป็นจำนวนเต็มเลยต้องหาร100.00เพื่อให้ค่าที่ได้ไม่เป็นจำนวนเต็มเเต่เป็นทศนิยมสองหลักแทนตามที่ต้องการ
void randData(double *a,int N,int M){
    for(int i = 0; i < N*M; i++){
        a[i] = (rand()%101)/100.00;
    }
}

//เราต้องรวมคอลัมเลยนับจากแถวเข้าไปถึงหลัก ลูปของiก่อนแล้วไปj ผลรวมหลักคือต้องเริมจากsum1[i] = 0.0 จากนั้นในหลักก็ใช้ซัมอันนี้บวกตามหลักของa[]ไปเรือยเรื่อย
//สูตร a[(i*M)+j]เป็นสูตรสำหรับในการจัดตำแหน่ง a  ex: a[0*0 + 0] = 0 ,a[0*1+1]=1,a[1*1+1] =2,a[1*1+2] =3 ทั้งหมดนี้คือตำแหน่งในอาเรย์aแถวแรก
//จากนั้นก็จะทำแถวต่อไปถ้ามี ตำแหน่งของตัวอย่างจะเป็น a[]=|0 1 2| ***อันนี้คือตำแหน่งข้อมูล***
//                                              |3 4 5|

           //Test	                                 //Result
//double a[2][3] = {1,2,3,4,5,6};                     //7.00
//double b[2];                                       //15.00
//findRowSum(a[0],b,2,3);
//showData(b,2,1);



void findRowSum(const double *a,double *sum1,int N ,int M){
    for(int i =0; i<N ; i++){
    sum1[i] =0.0;
        for(int j =0; j<M; j++){
        sum1[i] += a[(i*M)+j]; }}
}

// ทำเหมือนกันเเค่เปลี่ยนจากนับแถวไนับหลักก่อนเวลาคำนวณมันจะได้คิดจากแถว
void findColSum(const double *a,double *sum2,int N,int M){
 for(int j =0; j<M ; j++){
 sum2[j] = 0.00;
    for(int i=0; i <N ;i++){
    sum2[j] += a[i*M+j]; }}
}