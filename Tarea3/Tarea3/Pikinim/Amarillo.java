package Tarea3.Pikinim;
import java.lang.Math;

public class Amarillo extends Pikinim{

    ////////////////////
    //Magenta(int cant):
    //cant: cantidad de pikinims amarillo
    //------------------
    //Crea los pikinims amarillo, solo cambiando la cantidad a la deseada
    ////////////////////

    public Amarillo(int cant){
        super(cant,1,3);
    } 

    ////////////////////
    //disminuir(int cantidad):
    //cantidad: cantidad por lo cual se multiplicara la cantidad
    //------------------
    //Multiplica la cantidad de pikinims por la cantidad introducida asi como, si la cantidad es negativa, simplemente pasa a 0
    //////////////////// 

    public void disminuir(int cantidad){
        this.cant -=cantidad;
        if(this.cant<0) this.cant=0;
    }
    ////////////////////
    //disminuir(int cantidad):
    //cantidad: cantidad por lo cual se multiplicara la cantidad
    //------------------
    //Multiplica la cantidad de pikinims por la cantidad introducida y luego la multiplica 1.5 veces, para asi despues redondearla y obtener el entero
    ////////////////////

    public void multiplicar(int cantidad){
        double DobleCant = cantidad;
        DobleCant = Math.ceil(DobleCant*1.5);
        this.cant = (int) DobleCant;
    }

}
