package Tarea3.Zonas;

import java.util.Random;
import java.util.Scanner;

import Tarea3.Interfaz.Ilevantable;
import Tarea3.Pikinim.Pikinim;

public class Enemigo extends Zona implements Ilevantable {
    private int VidaEnemigo;
    private int ATKenemigo;
    private int PesoEnemigo;
    ////////////////////
    //Enemigo:
    //Constructor de la subclase Enemigo, construye la vida, atk y peso tambien se le declara el tipo
    ///////////////////
    public Enemigo(int vidaE,int ATKe,int PesoE){
        this.VidaEnemigo = vidaE;
        this.ATKenemigo = ATKe;
        this.PesoEnemigo = PesoE;
        this.TipoZona = "Enemigo";
    }
    ////////////////////
    //interactuar(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki)
    //cyan,magenta,amarillo - Piki: Son las subclases de cada color de pikinim
    //------------------
    //Llama a la funcion pelear, para obtener su booleano, y asi entrar al condicional de si es que se gana la pelea, entonces levantar y completar la zona, si es que no
    //printear string ambiental
    ///////////////////
    public void interactuar(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki){
        boolean ResultadoPelea = this.pelear(cyanPiki, magentaPiki, amarilloPiki);
        if(ResultadoPelea==true){
            this.levantar(cyanPiki, magentaPiki, amarilloPiki);
            this.ZonaCompleta();
        }else{
            System.out.println("A pesar de los esfuerzos de los pikinims... ellos ven a sus amigos caer y aun asi, el enemigo sigue de pie..");
            System.out.println("--------------------------------------------------------------");
        }
    }
    ////////////////////
    //levantar(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki):
    //cyan,magenta,amarillo - Piki: Son las subclases de cada color de pikinim
    //------------------
    //Esta funcion declara variables para las cant * capacidad de cada color de pikinim, luego obteniendo la suma total, si se puede al enemigo nos entrega opciones 
    //para asi poder multiplicar nuestras cantidades de pikinims, finalmente aun que no se levante, la zona se completa.
    ///////////////////
    public void levantar(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki){
        int SumCyan,SumAmarilla,SumMagenta,SumTotal;

        SumCyan = cyanPiki.GetCant() * cyanPiki.GetCapacidad();
        SumMagenta = magentaPiki.GetCant() * magentaPiki.GetCapacidad();
        SumAmarilla = amarilloPiki.GetCant() * amarilloPiki.GetCapacidad();
        SumTotal = SumCyan+SumAmarilla+SumMagenta;

        if(SumTotal >=this.PesoEnemigo){
            System.out.println("Los pikinims a través de sus esfuerzos, pudieron levantar al enemigo,");
            System.out.println("entregándoles una ventaja...\n");
            System.out.println("Seleccione un color de Pikinim a multiplicar (Valor a multiplicar: " + this.PesoEnemigo + ")");
            System.out.println("Opciones:");
            System.out.println("1.- Cyan");
            System.out.println("2.- Magenta");
            System.out.println("3.- Amarillo\n");
            System.out.print("Input: ");            
            Scanner scan = new Scanner(System.in);
            int opcion= scan.nextInt();
            if(opcion==1){
                cyanPiki.multiplicar(this.PesoEnemigo);
                System.out.println("Los Pikinims Cyan han aumentado a: "+cyanPiki.GetCant()+"!");
                System.out.println("--------------------------------------------------------------");
            }else if(opcion==2){
                magentaPiki.multiplicar(this.PesoEnemigo);
                System.out.println("Los Pikinims Magenta han aumentado a: "+magentaPiki.GetCant()+"!");
                System.out.println("--------------------------------------------------------------");
            }else{
                amarilloPiki.multiplicar(this.PesoEnemigo);
                System.out.println("Los Pikinims Amarillos han aumentado a: "+amarilloPiki.GetCant()+"!");
                System.out.println("--------------------------------------------------------------");
            }
            
            
            
        }
        this.ZonaCompleta();  
    }
    ////////////////////
    //pelear:
    //cyan,magenta,amarillo - Piki: Son las subclases de cada color de pikinim
    //------------------
    //declara las variables atk que seran las cantidades * atk de cada color de pikinim, tambien se genera un numero random, luego al atacar al enemigo y quitarle vida
    //entramos a un condicional para saber que color de pikinim daño el enemigo, si el enemigo muere la funcion retornara true, sino, false
    //------------------
    //return: true/false
    ///////////////////
    public boolean pelear(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki){
        int ATKCyan,ATKAmarilla,ATKMagenta,ATKTotal;

        Random RandColor = new Random();
        int colorRandom = RandColor.nextInt(3)+1;

        ATKCyan = cyanPiki.GetCant() * cyanPiki.GetATK();
        ATKMagenta = magentaPiki.GetCant() * magentaPiki.GetATK();
        ATKAmarilla = amarilloPiki.GetCant() * amarilloPiki.GetATK();
        ATKTotal = ATKCyan+ATKAmarilla+ATKMagenta;
        this.VidaEnemigo -= ATKTotal;
        if(colorRandom==1){
            cyanPiki.disminuir(this.ATKenemigo);
        }else if(colorRandom==2){
            magentaPiki.disminuir(this.ATKenemigo); 
        }else{
            amarilloPiki.disminuir(this.ATKenemigo);
        }
        if(this.VidaEnemigo <0){
            return true;
        }else{
            return false;
        }
    }
    ////////////////////
    //GetATKE,GetHPE,GetPESOE:
    //Todas son funciones de retorno para atk, vida y peso del enemigo respectivamente
    ///////////////////
    public int GetATKE(){return ATKenemigo;}
    public int GetHPE(){return VidaEnemigo;}
    public int GetPESOE(){return PesoEnemigo;}
}
