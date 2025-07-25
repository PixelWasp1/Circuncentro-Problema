#include <iostream>
#include <cmath>
#include <array>
class circuncentro
{
public:
void EntradaDatos(float ex_1,float ey_1,float ex_2,float ey_2,float ex_3,float ey_3)
{
	x_1=ex_1;
	y_1=ey_1;
	x_2=ex_2;
	y_2=ey_2;
	x_3=ex_3;
	y_3=ey_3;
if (!Errores())
	{
	Pendientes();
	}
return;
}
void ObtenerDatos ()
{	//por si requieren que se pidan los datos, si tienes los datos usar la funcion entradadatos
	//  x_1 y y_1 pertenecen al punto a
	//  x_2 y y_2 pertenecen al punto b
	//  x_3 y y_3 pertenecen al punto c
	std::cout << "Ingrese el valor de x1: ";
	std::cin >> x_1;
	std::cout << "Ingrese el valor de y1: ";
	std::cin >> y_1;
	std::cout << "Ingrese el valor de x2: ";
	std::cin >> x_2;
	std::cout << "Ingrese el valor de y2: ";
	std::cin >> y_2;
	std::cout << "Ingrese el valor de x3: ";
	std::cin >> x_3;
	std::cout << "Ingrese el valor de y3: ";
	std::cin >> y_3;
if (!Errores())
	{
	Pendientes();
	}
return;
}


void Pendientes ()
{
		// pendienteAB es la pendiente del segmento AB
		// pendienteBC es la pendiente del segmento BC
	pendienteAB=(y_2-y_1)/(x_2-x_1);
	pendienteBC=(y_3-y_2)/(x_3-x_2);
		// pendienteInversaAB es la pendiente inversa del segmento AB
		// pendienteInversaBC es la pendiente inversa del segmento BC
	pendienteInversaAB=(-1/pendienteAB);
	pendienteInversaBC=(-1/pendienteBC);
		//la pendiente inversa es la pendiente que lleva la perpendicular de una pendiente
		// si la pendiente es 4 la pendiente inversa es -1/4
		// si la pendiente es 0 la pendiente inversa es -1/0  osea una linea vertical
	MitadSegmentos();
}


void MitadSegmentos()
{
	XmitadSegmentoAB=(x_1+x_2)/2;
	YmitadSegmentoAB=(y_1+y_2)/2;
	XmitadSegmentoBC=(x_2+x_3)/2;
	YmitadSegmentoBC=(y_2+y_3)/2;

	CalcularCentro();
}

bool Errores ()
{
		//la idea principal es averiguar el area del triangulo formado por los tres puntos, si el area es cercana a cero significa
		//que o estan en linea o estan een el mismo punto. si este es el caso entonces el centro estaria en el infinito  con radio
		//infinito o habria un centro en el mismo punto que los otros puntos y un radio de 0
		//la formula del area de un triangulo
	float area = (x_1*(y_2 - y_3) + x_2*(y_3 - y_1) + x_3*(y_1 - y_2)) / 2.0f;
if (std::abs(area) < 1e-5) {
		std::cout << "Error: Los puntos están alineados ()." << std::endl;
		return true;
	}
else if (x_1==x_2 && x_2==x_3)
{
	std::cout<<"Error: los puntos estan en una recta vertical"<<std::endl;
	return true;

}
else if (x_1==x_2 && x_2==x_3)
{
	std::cout<<"Error: los puntos estan en una recta horizontal"<<std::endl;
	return true;

}
return false;
}


std::array<float, 2> CalcularCentro() {
	std::cout<<pendienteAB <<std::endl;
	std::cout<<pendienteBC<<std::endl;
	std::cout<<pendienteInversaAB <<std::endl;
	std::cout<<pendienteInversaBC<<std::endl;
    // Ecuación de las mediatrices: y = m*x + b
	B1 = YmitadSegmentoAB - pendienteInversaAB * XmitadSegmentoAB;
	B2 = YmitadSegmentoBC - pendienteInversaBC * XmitadSegmentoBC;
    x_Centro = (B2 - B1) / (pendienteInversaAB - pendienteInversaBC);
    y_Centro = pendienteInversaAB * x_Centro + B1; // el problema empieza desde que x_Centro no es 100% igual al valor esperado
	std::cout<<"el centro del circulo esta en: "<<x_Centro<<","<<y_Centro<<std::endl;
	CalcularRadio();
    return {x_Centro, y_Centro};
}


float CalcularRadio()
{
		// El radio es la distancia entre el centro del circulo y un punto del circulo
	radio = sqrt(pow((x_Centro - x_1), 2) + (pow((y_Centro - y_1), 2)));
		//la formula para calcular la distancia entre 2 puntos, es solo el teorema de pitagoras

		//mas de lo mismo, es opcional
	std::cout<<"el radio del circulo es de: "<<radio<<std::endl;
	prueba();
	return radio;
}
void prueba()
{
	std::cout<<"pendienteAB"<<pendienteAB<<std::endl;
	std::cout<<"pendienteBC"<<pendienteBC<<std::endl;
	std::cout<<"pendienteInversaAB"<<pendienteInversaAB<<std::endl;
	std::cout<<"pendienteInversaBC"<<pendienteInversaBC<<std::endl;
	std::cout<<"XmitadSegmentoAB"<<XmitadSegmentoAB<<std::endl;
	std::cout<<"XmitadSegmentoBC"<<XmitadSegmentoBC<<std::endl;
	std::cout<<"YmitadSegmentoAB"<<YmitadSegmentoAB<<std::endl;
	std::cout<<"YmitadSegmentoBC"<<YmitadSegmentoBC<<std::endl;
	std::cout<<"B1"<<B1<<std::endl;
	std::cout<<"B2"<<B2<<std::endl;
	std::cout<<"x_Centro"<<x_Centro<<std::endl;
	std::cout<<"y_Centro"<<y_Centro<<std::endl; // <-desde aqui empieza el problema
	std::cout<<"radio"<<radio<<std::endl;

}
private:
float x_1=0, x_2=0, x_3=0, y_1=0, y_2=0, y_3=0;
float pendienteAB=0, pendienteBC=0;
float pendienteInversaAB=0, pendienteInversaBC=0;
float XmitadSegmentoAB=0, YmitadSegmentoAB=0, XmitadSegmentoBC=0, YmitadSegmentoBC=0;
float bFuncion1=0, bFuncion2=0, x_Centro=0, y_Centro=0;
float B1, B2;
float radio = 0;
int numeroDeError = 0;
};
int main()
{
	circuncentro objeto;
	objeto.ObtenerDatos();
	return 0;
}
