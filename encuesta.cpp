#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Función que no recibe parámetros y muestra una línea separadora
void mostrarLineaSeparadora(){
    cout << endl << "-----------------------------------" << endl;
}

//Función que muestra el resultados de todas las enuestas cargadas
void mostrarResultados(vector<int> ed, vector<string> gen, vector<int> calif, vector<string> coment){
    if(gen.empty()){
        cout << "No hay encuestas cargadas.";
        return; //Este return hace que la función termine acá
    }
    for (int i = 0; i < gen.size(); i++){
        cout <<endl << "* ENCUESTA Nº: "<< i+1;
        cout <<endl << "- La edad es: " << ed[i];
        cout <<endl << "- El genero es: " << gen[i];
        cout <<endl << "- La calificacion es: " << calif[i];
        cout <<endl << "- El comentario es: " << coment[i] << endl;
    }
}

//Función que calcula y retorna el promedio de edades, si no hay encuestas cargadas retorna 0.0
double calcularPromedioEdad(vector<int> ed){
    if(ed.empty()){
        return 0.0;  //Este if evita dividir por cero
    }
    double sumatoriaDeEdades = 0;
    for (int i = 0; i < ed.size(); i++)
    {
        sumatoriaDeEdades = sumatoriaDeEdades + ed[i];
    }
    double promedio = sumatoriaDeEdades/ed.size();
    int promedioRedondeado = (promedio * 100) + 0.5;
    promedio = promedioRedondeado / 100.0;
    return promedio;
}

//Funcion que calcula Y DEVUELVE el promedio de las calificaciones
double promedioCalificaciones(vector<int> calif){
    if(calif.empty()){
        return 0.0;  //Este if evita dividir por cero
    }
    double sumaDeCalificacion = 0;
    for (int i = 0; i < calif.size(); i++){
        sumaDeCalificacion = sumaDeCalificacion + calif[i];
    }
    return sumaDeCalificacion/calif.size();
}

//Función para mostrar calificación mínima y los comentarios relacionados
void mostrarCalificacionMinima(vector<int> calif, vector<string> coment){
    if(calif.empty()){
        cout << "No hay encuestas ingresadas.";
        return; //Return hace que la función termine 
    }
    int calificacionMinima = 5;
    for (int i = 0; i < calif.size(); i++){
        if (calif[i] < calificacionMinima){
            calificacionMinima = calif[i];
        }
    }
    cout << endl << "** La calificación mínima fue: " << calificacionMinima;

    // MOSTRAR LOS COMENTARIOS QUE SE RELACIONEN CON LA CALIFICACIÓN MÍNIMA
    cout << endl << "** Los comentarios relacionados con la calificación mínima son: " << endl;
    for (int i = 0; i < calif.size(); i++){
        if (calif[i] == calificacionMinima){
            cout << "- " << coment[i] << endl;
        }
    }
}

//Función para mostrar calificación máxima y los comentarios relacionados
void mostrarCalificacionMaxima(vector<int> calif, vector<string> coment){
    if(calif.empty()){
        cout << "No hay encuestas ingresadas.";
        return; //Return hace que la función termine 
    }
    int calificacionMaxima = 0;
    for (int i = 0; i < calif.size(); i++){
        if (calif[i] > calificacionMaxima){
        calificacionMaxima = calif[i];
        }
    }
    cout << endl << "** La calificación máxima fue: " << calificacionMaxima;

    // MOSTRAR LOS COMENTARIOS QUE SE RELACIONEN CON LA CALIFICACIÓN MÁXIMA
    cout << endl << "** Los comentarios relacionados con la calificación máxima son: " << endl;
    for (int i = 0; i < calif.size(); i++){
        if (calif[i] == calificacionMaxima){
            cout << "- " << coment[i] << endl;
        }
    }
}

//Función que cuenta por género
void contarGeneros(vector<string> generos){
    if(generos.empty()){
        cout << "No hay encuestas ingresadas.";
        return; //Termina la función y solo muestra ese mensaje. 
    }
    int generoMasc = 0;
    int generoFem = 0;
    int generoOtro = 0;
    for (int i = 0; i < generos.size(); i++){
        if (generos[i]=="F")
        {
            generoFem ++;
        }else if (generos[i]=="M")
        {
            generoMasc++;
        }else
        {
            generoOtro++;
        }
    }
    double porcMasc = (generoMasc*100)/generos.size();
    cout << endl << "La cantidad de genero masculino fue: " << generoMasc << " (" << porcMasc << "%)";
    double porcFem = (generoFem*100)/generos.size();
    cout << endl << "La cantidad de genero femenino fue: " << generoFem << " (" << porcFem << "%)";
    double porcOtro = (generoOtro*100)/generos.size();
    cout << endl << "La cantidad de genero otro fue: " << generoOtro << " (" << porcOtro << "%)" << endl;
}

//Función que cuenta las calificaciones y muestra porcentaje
void contarCalificaciones(vector<int> calificaciones){
    if(calificaciones.empty()){
        cout << "No hay encuestas ingresadas.";
        return; 
    }
    double cantCalif1 = 0;
    double cantCalif2 = 0;
    double cantCalif3 = 0;
    double cantCalif4 = 0;
    double cantCalif5 = 0;
    for (int i = 0; i < calificaciones.size(); i++)
    {
        switch (calificaciones[i])
        {
        case 1:
            cantCalif1 ++;
            break;
        case 2:
            cantCalif2 ++;
            break;
        case 3:
            cantCalif3 ++;
            break;
        case 4:
            cantCalif4 ++;
            break;
        default:
            cantCalif5 ++;
            break;
        }
    }
    cout<< endl << "La cantidad de calificaciones 1 fueron: " << cantCalif1 << " (" << (cantCalif1*100)/calificaciones.size() << "%)"
        << endl << "La cantidad de calificaciones 2 fueron: " << cantCalif2 << " (" << (cantCalif2*100)/calificaciones.size() << "%)"
        << endl << "La cantidad de calificaciones 3 fueron: " << cantCalif3 << " (" << (cantCalif3*100)/calificaciones.size() << "%)"
        << endl << "La cantidad de calificaciones 4 fueron: " << cantCalif4 << " (" << (cantCalif4*100)/calificaciones.size() << "%)"
        << endl << "La cantidad de calificaciones 5 fueron: " << cantCalif5 << " (" << (cantCalif5*100)/calificaciones.size() << "%)"<< endl ;
}

void mostrarCalifPositivasYNegativas(vector<int> calificaciones){
    if(calificaciones.empty()){
        cout << "No hay encuestas ingresadas.";
        return; 
    }
    double califNegativas = 0;
    double califPositivas = 0;
    for (int i = 0; i < calificaciones.size(); i++)
    {
        switch (calificaciones[i])
        {
        case 1:
            califNegativas ++;
            break;
        case 2:
            califNegativas ++;
            break;
        case 3:
            break;
        case 4:
            califPositivas ++;
            break;
        default:
            califPositivas ++;
            break;
        }
    }

    double porcNegativas = (califNegativas*100)/calificaciones.size();
    double porcPositivas = (califPositivas*100)/calificaciones.size();
        if (porcPositivas>=60)
        {
            cout << endl << "La satisfacción general fue mayormente positiva: " << porcPositivas << "% calificaciones positivas";
        } else if (porcNegativas>=40)
        {
            cout << endl << "La satisfacción general fue mayormente negativa: " << porcNegativas << "% calificaciones negativas";
        } else 
        {
            cout << endl << "La satisfacción general fue mixta: " << porcNegativas << "% calificaciones negativas, " << porcPositivas << "% calificaciones positivas";
        }
        
        
}

//Funcion de ingreso de datos
void ingresarDatos(vector<int>& edades, vector<string>& generos, vector<int>& calificaciones, vector<string>& comentariosLibre){
    string gen;
    string calif;
    string ed;
    string coment;
    int edad;
    int calificacion;

    //Ingreso de datos en los vectores por el usuario
    string opcion = "S";
    while(opcion != "N"){
       
        cout << endl<< "Quiere ingresar una encuesta? (S/N)";
       
        getline (cin, opcion);
        //cin >> opcion;
       
        if (opcion== "s"){
           opcion = "S";
       }else if (opcion == "n"){
           opcion = "N";
       }

        if (opcion == "S"){

        bool edadValida = false;
            while (not edadValida)
        {
            cout << "Ingrese su edad, las posibles son de 5 a 120 años: ";
        getline (cin, ed);
        
        try
        {
            edad = stoi(ed);
            edadValida = (edad>=5 and edad<=120);
            //edades.push_back( edad );  AL PONERLO ACÁ, SI LA EDAD NO ES VÁLIDA, IGUAL SE AGREGA AL VECTOR
        }
        catch(exception& e)
        {
            cout << "Edad no válida";
        }

        }
    edades.push_back( edad );

        do
        {
            cout << "Ingrese su género, los posibles son F (femenino), M (masculino) y O (otro): ";
        getline (cin, gen);
        if (gen== "f"){
           gen = "F";
       }else if (gen == "m"){
           gen= "M";
       }else if (gen == "o"){
           gen = "O";
       }
        } while (gen != "F" and gen != "M" and gen != "O");
        generos.push_back( gen );

        /*cout << "Ingrese su género, los posibles son F, M y O: ";
        getline (cin, gen);
        generos.push_back( gen );*/

        bool calificacionValida = false;
            while (not calificacionValida)
        {
            cout << "Ingrese su calificación, las posibles son 1, 2, 3, 4 y 5: ";
        getline (cin, calif);
        try
        {
            calificacion = stoi(calif);
            calificacionValida = (calificacion>=1 and calificacion<=5);
            //calificaciones.push_back( calificacion );   AL PONEROLA ACÁ, SI LA CALIFICACIÓN NO ES VÁLIDA, IGUAL SE AGREGA AL VECTOR
        }
        catch(exception& e)
        {
            cout << "Calificación no válida";
        }
        }
        calificaciones.push_back( calificacion );

        /*cout << "Ingrese su calificación, las posibles son 1, 2, 3, 4 y 5: ";
        cin >> calif;
        calificacion.push_back( calif );*/

        cout << "Ingrese un comentario libre: ";
        //cin >> coment;
        getline(cin, coment);
        comentariosLibre.push_back( coment );

        }else if (opcion == "N")
        {
            cout << "Salió de la encuesta. Gracias.";
        }else
        {
            cout << "Ingrese una opción válida (s/n).";
        }
    }
}

int main(){

    //Declaraciòn de los vectores y variables
    vector <int> calificaciones;
    vector <string> generos;
    vector <int> edades;
    vector <string> comentariosLibre;
    //genero.push_back('m');
    //calificacion.push_back(1);


    //Bienvenida
    mostrarLineaSeparadora();
    cout << endl << "Bienvenido a la encuesta de satisfacción de nuestra biblioteca!" << endl;
    cout << "Por favor, ingrese los datos que le solicitamos (edad, género, calificación y comentario libre) " << endl;
    cout << "Al finalizar, se mostrarán los resultados de las encuestas" << endl;
    cout << "¡Muchas gracias!" << endl;

string op;
int opcion = 1;
    while (opcion != 0){
    cout << endl << "Ingrese una opción";
    cout << endl << "1. Ingresar datos de encuestas";
    cout << endl << "2. Mostrar resultados de las encuestas";
    cout << endl << "0. Salir" << endl;

    getline(cin, op);
    opcion = stoi(op);
    if(opcion == 1){
        ingresarDatos(edades, generos, calificaciones, comentariosLibre);
    } else if (opcion == 2){


    //RESULTADOS
        mostrarLineaSeparadora();
        cout << endl << "*** RESULTADOS DE LAS ENCUESTAS ***" << endl;
        mostrarLineaSeparadora();

        mostrarResultados(edades, generos, calificaciones, comentariosLibre);

        double promedioEdades = calcularPromedioEdad(edades);
        cout << endl << "** El promedio de edades es: " << promedioEdades << endl;

        contarGeneros(generos);

        double promedioCalif = promedioCalificaciones(calificaciones);
        cout << endl << "** El promedio de calificación fue:" << promedioCalif; 

        contarCalificaciones(calificaciones);

        mostrarCalificacionMinima(calificaciones, comentariosLibre);

        mostrarCalificacionMaxima(calificaciones, comentariosLibre);

        mostrarCalifPositivasYNegativas(calificaciones);

        mostrarLineaSeparadora();
    } else if (opcion == 0){
        cout << "Gracias por participar en la encuesta. ¡Hasta luego!";
    }else{
        cout << "Ingrese una opción válida (0, 1 o 2).";
    }
    }
}


//ingresarDatos(edades, generos, calificaciones, comentariosLibre);




//Muestro el contenido de cada encuesta
   /* for (int i = 0; i < generos.size(); i++){
        cout <<endl << "* ENCUESTA Nº: "<< i+1;
        cout <<endl << "- La edad es: " << edades[i];
        cout <<endl << "- El genero es: " << generos[i];
        cout <<endl << "- La calificacion es: " << calificaciones[i];
        cout <<endl << "- El comentario es: " << comentariosLibre[i] << endl;
    }*/

//promedio de edad
    /*double sumatoriaDeEdades = 0;
    for (int i = 0; i < edades.size(); i++)
    {
        sumatoriaDeEdades = sumatoriaDeEdades + edades[i];
    }
    cout << endl << "** El promedio de edades es: " << sumatoriaDeEdades/edades.size() << endl;*/

// Calcular y mostrar el promedio de las calif. ingresadas
    /*double sumaDeCalificacion = 0;
    for (int i = 0; i < calificaciones.size(); i++){
        sumaDeCalificacion = sumaDeCalificacion + calificaciones[i];
    }
    double promedio = sumaDeCalificacion/calificaciones.size();
    cout << endl << "** El promedio de calificación fue:" << promedio;*/

//Mostrar la calificación mínima
    /*int calificacionMinima = 5;
    for (int i = 0; i < calificaciones.size(); i++){
        if (calificaciones[i] < calificacionMinima){
            calificacionMinima = calificaciones[i];
        }
    }
    cout << endl << "** La calificación mínima fue: " << calificacionMinima;*/

// MOSTRAR LOS COMENTARIOS QUE SE RELACIONEN CON LA CALIFICACIÓN MÍNIMA
    /*cout << endl << "** Los comentarios relacionados con la calificación mínima son: " << endl;
    for (int i = 0; i < calificaciones.size(); i++){
        if (calificaciones[i] == calificacionMinima){
            cout << "- " << comentariosLibre[i] << endl;
        }
    }*/

//Mostrar la calificación máxima
    /*int calificacionMaxima = 0;
    for (int i = 0; i < calificaciones.size(); i++){
        if (calificaciones[i] > calificacionMaxima){
        calificacionMaxima = calificaciones[i];
        }
    }
    cout << endl << "** La calificación máxima fue: " << calificacionMaxima <<endl;*/

// MOSTRAR LOS COMENTARIOS QUE SE RELACIONEN CON LA CALIFICACIÓN MÁXIMA
    /*cout << endl << "** Los comentarios relacionados con la calificación máxima son: " << endl;
    for (int i = 0; i < calificaciones.size(); i++){
        if (calificaciones[i] == calificacionMaxima){
            cout << "- " << comentariosLibre[i] << endl;
        }
    }*/

//Contador por género
    /*int generoMasc = 0;
    int generoFem = 0;
    int generoOtro = 0;
    for (int i = 0; i < generos.size(); i++){
        if (generos[i]=="F")
        {
            generoFem ++;
        }else if (generos[i]=="M")
        {
            generoMasc++;
        }else
        {
            generoOtro++;
        }
    }
    double porcMasc = (generoMasc*100)/generos.size();
    cout << endl << "La cantidad de genero masculino fue: " << generoMasc << " (" << porcMasc << "%)";

    double porcFem = (generoFem*100)/generos.size();
    cout << endl << "La cantidad de genero femenino fue: " << generoFem << "  (" << porcFem << "%)";

    double porcOtro = (generoOtro*100)/generos.size();
    cout << endl << "La cantidad de genero otro fue: " << generoOtro << " (" << porcOtro << "%)"<< endl ;
*/

//Contador de calificaciones y porcentaje
/*
    double cantCalif1 = 0;
    double cantCalif2 = 0;
    double cantCalif3 = 0;
    double cantCalif4 = 0;
    double cantCalif5 = 0;
    for (int i = 0; i < calificaciones.size(); i++)
    {
        switch (calificaciones[i])
        {
        case 1:
            cantCalif1 ++;
            break;
        case 2:
            cantCalif2 ++;
            break;
        case 3:
            cantCalif3 ++;
            break;
        case 4:
            cantCalif4 ++;
            break;
        default:
            cantCalif5 ++;
            break;
        }
    }
    cout<< endl << "La cantidad de calificaciones 1 fueron: " << cantCalif1 << " (" << (cantCalif1*100)/calificaciones.size() << "%)"
        << endl << "La cantidad de calificaciones 2 fueron: " << cantCalif2 << " (" << (cantCalif2*100)/calificaciones.size() << "%)"
        << endl << "La cantidad de calificaciones 3 fueron: " << cantCalif3 << " (" << (cantCalif3*100)/calificaciones.size() << "%)"
        << endl << "La cantidad de calificaciones 4 fueron: " << cantCalif4 << " (" << (cantCalif4*100)/calificaciones.size() << "%)"
        << endl << "La cantidad de calificaciones 5 fueron: " << cantCalif5 << " (" << (cantCalif5*100)/calificaciones.size() << "%)"<< endl ;
*/

