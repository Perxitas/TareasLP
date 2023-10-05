package Tarea3.Pikinim;

public class Magenta extends Pikinim{

    ////////////////////
    //Magenta(int cant):
    //cant: cantidad de pikinims magenta
    //------------------
    //Crea los pikinims magenta, solo cambiando la cantidad a la deseada
    ////////////////////

    public Magenta(int cant){
        super(cant,2,1);
    }

    ////////////////////
    //disminuir(int cantidad):
    //cantidad: cantidad por lo cual se disminuira la cantidad
    //------------------
    //Disminuye la cantidad de pikinims por la cantidad introducida asi como, si la cantidad es negativa, simplemente pasa a 0
    ////////////////////    

    public void disminuir(int cantidad){
        this.cant -=cantidad;
        if(this.cant<0) this.cant=0;
    }

    ////////////////////
    //multiplicar(int cantidad):
    //cantidad: cantidad por lo cual se multiplicara la cantidad
    //------------------
    //Multiplica la cantidad de pikinims por la cantidad introducida y el ataque de este pikinim
    //////////////////// 

    public void multiplicar(int cantidad){
        this.cant = cantidad*this.atk;
    }
}
