
#include "function.h"
void main()
{

	setlocale(LC_ALL, "Russian");
	double  real,imaginary,angle,r;//z=real+i*imaginary z=r(cos(angle)+i*sin(angle))
	input(real, imaginary, angle, r);
	bool flag = true;
	string testimp;
	int i;
	 int n = 1;
	 double  real2, imaginary2, angle2, r2;
	 double  tempreal=0, tempimaginary=0, tempangle=angle, tempr=r;
	 double sumreal = 1, sumimag = 0, elemreal = 1000, elemimag,eps;
	 int j;
	while (flag)
	{
     cout << "а) \n1-вывод алгебраической формы \n2-вывод тригонометрической формы \n3-приведение аргумента к значению в промежутке [0,2p) \n"
		 <<"4-сложение \n5-вычитание \n6-умножение \n7-деление \n8-возведение в натуральную степень \nb) "
		 <<"\n9-вычислить с помощью ряда \n10-вычислить по формуле \n11 выход" << endl;
	 
	 cin >> i;
	 switch (i)
	 {
	 case 1:cout<<"z="<<real<<"+i*"<<imaginary<<endl; break;
	 case 2:cout << "z="<<r<<"("<<cos(angle)<<"+i*"<<sin(angle)<<")" << endl; break;
	 case 3:cout <<"Аргумент в радианах- ";
		 if (angle < 0)
		 {
			 cout << angle + 2 * 3.14 << endl;
		 }
		 else 
		 {
			 cout << angle << endl;
		 }
		 break;
	 case 4:input(real2, imaginary2, angle2, r2); 
		 real +=real2;
		 imaginary +=imaginary2 ;
		 angle = atan2(imaginary , real);
		 r = real / cos(angle);
		 break;
	 case 5:input(real2, imaginary2, angle2, r2);
		 real = real2;
		 imaginary = imaginary2;
		 angle = atan(imaginary / real);
		 r = real / cos(angle); break;
	 case 6:input(real2, imaginary2, angle2, r2); 
		 r *= r2; 
		 angle += angle2;
		 real = r * cos(angle);
		 imaginary = r * sin(angle);
		 real = r * cos(angle);
		 imaginary = r * sin(angle);
		 break;
	 case 7:input(real2, imaginary2, angle2, r2);
		 r /= r2;
		 angle -= angle2;
		 real = r * cos(angle);
		 imaginary = r * sin(angle);
		 break;
	 case 8:
		 do { 
			 cout << "введите степень " << endl;
			 cin >> testimp;
		 } while (!testnum(testimp));
		 j = stoi(testimp);
		 compow(j,real, imaginary, angle, r);
		 break;
	 case 9:
		 do {
			 cout << "введите эпсилон" << endl;
			
			 cin >> testimp;
		 } while (!testnum(testimp));
		 eps = stod(testimp);
		 while (eps <= abs(elemreal))
		 {
			 tempangle = angle;
			 tempr = r;
			compow(n,tempreal, tempimaginary, tempangle, tempr);
			 elemreal = tempreal/factorial(n);
			 elemimag = tempimaginary / factorial(n);
			 sumreal += elemreal;
			 sumimag += elemimag;
			 n++;
		 }
		 cout << "решение функции - e^z="<<sumreal<<"+i*"<<sumimag << endl;
		 break;
	 case 10:
		 cout << "решение функции - e^z="<<exp(real)<<"("<<cos(imaginary)<<"+i*"<<sin(imaginary)<<")="<< exp(real)*cos(imaginary)
			<< "+i*"<< exp(real)*sin(imaginary) << endl;
		 break;
	 case 11:flag = false; break;
	 default:
		 flag=false; break;
	 }
	}

}
