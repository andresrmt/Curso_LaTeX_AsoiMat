
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void personalizador(int num);

int num;
int main()
{
    cout << "Generador de prueba personalizada" << endl << endl;
    cout << "Ingrese el numero de instancias a crear: ";
    cin >> num;
    cout << "Se crearan los archivos prueba_" << num << ".tex" << endl << endl;

    personalizador(num);
    cout << endl << "Se han creado los archivos TeX asociados a cada prueba." << endl;

    return 0;
}

///////////////////////////////////////
// Funcion que imprime la prueba en un archivo TeX
void personalizador(int num)
{
    int r;
    for ( int n = 0; n < num; n++ )
    {
        ofstream a;
        //
        //
        std::ostringstream nameite;
        nameite.str("");
        nameite << "prueba_" << n << "_de_" << num << ".tex";
        //
        a.open( nameite.str().c_str() );
        // Inicio de escritura
        a<<"\\documentclass[12pt,a4paper]{article}"<<endl;
        a<<"\\usepackage[utf8]{inputenc}"<<endl;
        a<<"\\usepackage[T1]{fontenc}"<<endl;
        a<<"\\usepackage[spanish,es-nolayout]{babel}"<<endl;
        a<<"\\usepackage{amsmath}"<< endl;
        a<<"\\usepackage{amsfonts}"<< endl;
        a<<"\\usepackage{amssymb}"<< endl;
        a<<"\\usepackage{amsthm}"<< endl;
        a<<"\\usepackage[left=2cm,right=2cm,top=2.5cm,bottom=2cm]{geometry}"<<endl;
        a<<"\\usepackage{xcolor}"<<endl<<endl;
        a<<"\\setlength\\parindent{0pt}"<<endl;
        a<<"\\title{Prueba de seguimiento}"<<endl;
        a<<"\\date{\\today}"<<endl<<endl;
        a<<"\\begin{document}"<<endl;
        a<<"\\pagenumbering{gobble}"<<endl<<endl;
        a<<"\\maketitle"<<endl<<endl;
        a<<"Nombre:"<<endl<<endl;
        a<<"Curso:"<<endl<<endl;
        a<<"\\hrulefill"<<endl<<endl;
        a<<"Encuentre el valor exacto de la siguiente integral definida:"<<endl;

        // Semilla
        srand(n);
        // Generacion de un entero aleatorio y divisible por 4
        r = 4*(rand() % 100);

        // Integral
        a<<"\\[ \\int_0^{" << r << "} \\dfrac{dx}{\\sqrt{x^2 + 16}}.\\]"<<endl;

        a<<"Incluye todo el procedimiento para llegar a tu respuesta."<<endl<<endl;
        a<<"\\end{document}";
        //fin creacion archivo .tex
        a.close();
    }
}
