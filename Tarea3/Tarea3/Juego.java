package Tarea3;
import Tarea3.Pikinim.Pikinim;
import Tarea3.Zonas.Enemigo;
import Tarea3.Zonas.Muralla;
import Tarea3.Zonas.Pieza;
import Tarea3.Zonas.Pildora;
import Tarea3.Zonas.Zona;
import Tarea3.Pikinim.Cyan;
import java.util.Scanner;
import Tarea3.Pikinim.Amarillo;
import Tarea3.Pikinim.Magenta;

public class Juego {
    ////////////////////
    //Main: Crea las variables asi como el mapa del juego, para entrar a un loop con los condicionales que permiten colocar limites a murallas y out of bounds posibles
    //luego se toma la eleccion para mandar el codigo a la funcion, se cuentan turnos, a continuacion se recapitula el total de pikinims por si se perdieron en una pelea
    //y ya no puede pelear, tambien se cuentan las piezas recogidas y finalmente al salir del loop tenemos un condicional que verifica el metodo de victoria/derrota.
    ///////////////////
    public static void main(String[] args){
        int CantTurnos,piezasRecogidas,pos,TurnoActual,TotalPikinims;
        CantTurnos = 30;
        TurnoActual = 1;
        piezasRecogidas = 0;
        pos = 5;
        TotalPikinims = 30;

        Muralla currWall= null; 
        Pikinim cyanPiki = new Cyan(10);
        Pikinim magentaPiki = new Magenta(10);
        Pikinim amarilloPiki = new Amarillo(10);

        Zona[] Ubicaciones = new Zona[11];
        Ubicaciones[0]= new Pieza(50);
        Ubicaciones[1]= new Enemigo(130, 25, 20);
        Ubicaciones[2]=new Enemigo(50, 15, 10);
        Ubicaciones[3]=new Pildora(25);
        Ubicaciones[4]=new Muralla(50);
        Ubicaciones[5]=new Pieza(100);
        Ubicaciones[6]=new Enemigo(45, 10, 8);
        Ubicaciones[7]=new Pieza(35);
        Ubicaciones[8]=new Pildora(15);
        Ubicaciones[9]=new Enemigo(75, 20, 15);
        Ubicaciones[10]=new Muralla(150);
        
        
        System.out.println("Lomiar debe recuperar las piezas para su nave antes de que se le acabe el oxigeno y todo se acabe...pero no esta solo, con la ayuda de sus pequeños amigos, tendra posibilidades..\n --------------------------------------------------------------");
        int posAuxiliar = 5;

        Scanner Input = new Scanner(System.in);
        while (CantTurnos > 0 && piezasRecogidas < 3 && TotalPikinims>0) {
            boolean PorIzq = false;
            boolean PorDer= false;

            if(pos>10 || pos<0){
                    pos=posAuxiliar;
                    System.out.println("Lomiar se salio del mapa....pero los pikimins lo trajeron devuelta...");
                }
            
            System.out.println("Turno " + TurnoActual + " (Pikinims: Cyan//" + cyanPiki.GetCant() + " //-- Magenta//" + magentaPiki.GetCant() + " //-- Amarillo//" + amarilloPiki.GetCant() + ")");
            currUbicacion(Ubicaciones[pos]);
            if(Ubicaciones[pos].ZonaType().equals("Muralla") && Ubicaciones[pos].Complete()){
                currWall = (Muralla)Ubicaciones[pos];
                if(currWall.GetHPM()>0){
                    System.out.println("Lomiar mira a su alrededor atentamente y se da cuenta de sus únicas opciones...\n");
            
                    System.out.println("1.- Ir a la derecha(" + Ubicaciones[pos + 1].ZonaType() + ")///");
                    System.out.println("2.- Ir a la izquierda(" + Ubicaciones[pos - 1].ZonaType() + ")///");
                    System.out.println("3.- Mantener la posición.(Lomiar interactuará con la ubicación actual)///");
                    System.out.println("--------------------------------------------------------------");

                    System.out.print("Input: ");  
                }else if(pos<posAuxiliar){
                    PorIzq = true;
                    System.out.println("Lomiar mira a su alrededor atentamente y se da cuenta de sus únicas opciones...\n");
                    
                    System.out.println("1.-No es posible ir por la derecha....Lomiar esta frente a una muralla que le evita el paso.");
                    if (pos > 0) {
                        System.out.println("2.- Ir a la izquierda(" + Ubicaciones[pos - 1].ZonaType() + ")///");
                    } else {
                        System.out.println("2.- No puedes ir a la izquierda, estás en la primera posición.");
                    }
                    System.out.println("3.- Mantener la posición.(Lomiar interactuará con la ubicación actual)///");
                    System.out.println("--------------------------------------------------------------");

                    System.out.print("Input: ");  
                }else if(pos>posAuxiliar){
                    PorDer = true;
                    System.out.println("Lomiar mira a su alrededor atentamente y se da cuenta de sus únicas opciones...\n");
                            
                    if (pos < Ubicaciones.length - 1) {
                        System.out.println("1.- Ir a la derecha(" + Ubicaciones[pos + 1].ZonaType() + ")///");
                    } else {  
                        System.out.println("1.- No puedes ir a la derecha, estás en la última posición.");
                    }
                    System.out.println("2.-No es posible ir por la izquierda...Lomiar esta frente a una muralla que le evita el paso.");
                    System.out.println("3.- Mantener la posición.(Lomiar interactuará con la ubicación actual)///");
                    System.out.println("--------------------------------------------------------------");

                    System.out.print("Input: ");    
                }
            }else {
                System.out.println("Lomiar mira a su alrededor atentamente y se da cuenta de sus únicas opciones...\n");
            
                if (pos < Ubicaciones.length - 1) {
                    System.out.println("1.- Ir a la derecha(" + Ubicaciones[pos + 1].ZonaType() + ")///");
                } else {  
                    System.out.println("1.- No puedes ir a la derecha, estás en la última posición.");
                }
                if (pos > 0) {
                    System.out.println("2.- Ir a la izquierda(" + Ubicaciones[pos - 1].ZonaType() + ")///");
                } else {
                    System.out.println("2.- No puedes ir a la izquierda, estás en la primera posición.");
                }

                System.out.println("3.- Mantener la posición.(Lomiar interactuará con la ubicación actual)///");
                System.out.println("--------------------------------------------------------------");
                System.out.print("Input: ");  
            }

            int eleccion = Input.nextInt();

            if(eleccion == 1 && PorIzq){
                System.out.println("....Parece que lomiar no comprendio que no podia ir por la izquierda...\n");
                System.out.println("--------------------------------------------------------------");
            }else if(eleccion == 2 && PorDer){
                System.out.println("....Parece que lomiar no comprendio que no podia ir por la derecha...\n");
                System.out.println("--------------------------------------------------------------");
            }else{
                pos = procesarEleccion(eleccion, Ubicaciones, pos, cyanPiki, magentaPiki, amarilloPiki);
                TurnoActual++;
                CantTurnos--;
                
            }
            TotalPikinims = cyanPiki.GetCant()+magentaPiki.GetCant()+amarilloPiki.GetCant();
            if(Ubicaciones[pos].ZonaType()=="Pieza"){
                Pieza room = (Pieza) Ubicaciones[pos];
                if(room.GetLevantada()){
                    piezasRecogidas++;
                }
            }
            posAuxiliar = pos;

        }
        Input.close();
        
        if(piezasRecogidas==3){
            System.out.println("...Finalmente, tras todo el esfuerzo, Lomiar deja atras a sus pequeñitos amigos, los pikinims y logra escapar del planeta con "+CantTurnos+" horas restantes, ");
            System.out.println("Lomiar sobrevivio incluso con la presion encima del oxigeno restante...");
            System.out.println("--------------------------------------------------------------");
        }else if(CantTurnos<0 ){
            System.out.println("...A pesar de los esfuerzos, Lomiar parece quedarse estancado en el planeta..por lo que queda de su tiempo...");
            System.out.println("(al menos esta con sus amigos pikinims acompañandolo...");
            System.out.println("--------------------------------------------------------------");
        }else if(TotalPikinims<0){
            System.out.println("Lomiar se ha quedado solo...el no podra con todo lo que queda por explorar y reparar por si mismo...pero lo ve con optimismo mientras de a poco se le acaba el oxigeno....");
            System.out.println("--------------------------------------------------------------");
        }
    }

    ////////////////////
    //procesarEleccion(int eleccion, Zona[] ubicaciones, int pos, Pikinim cyanPiki, Pikinim magentaPiki, Pikinim amarilloPiki)
    //eleccion: Es el numero de la eleccion por el jugador
    //Ubicaciones:Es el arreglo/mapa
    //pos: posicion actual
    //cyan,magenta,amarillo - Piki: Son las subclases de cada color de Pikinims
    //---------------
    //Esta funcion, primero modifica la posicion si es que se decidio mover, para luego entrar en un condicional que verifica si es que la zona esta completa asi para
    //luego llamar a las interacciones si es que no esta completa,o si no printear un mensaje si es que esta completa, finalmente nos retorna la pos actualizada
    //---------------
    //return: retorna el numero de la posicion con la que quizas, se modifico
    ///////////////////
    private static int procesarEleccion(int eleccion, Zona[] ubicaciones, int pos, Pikinim cyanPiki, Pikinim magentaPiki, Pikinim amarilloPiki) {
        if (eleccion == 1) {
            pos = pos + 1;
        } else if (eleccion == 2) {
            pos = pos - 1;
            
        }
    
        if (pos < 0) {
            System.out.println("Lomiar se encuentra fuera del mapa.\n");
            System.out.println("--------------------------------------------------------------");
        } else if (pos >= ubicaciones.length) {
            System.out.println("Lomiar se encuentra fuera del mapa.\n");
            System.out.println("--------------------------------------------------------------");
        } else {
            Zona ubicacionActual = ubicaciones[pos];
            currUbicacion(ubicacionActual);
            
            if (!ubicacionActual.Complete()) {
                if (ubicacionActual instanceof Pieza) {
                    Pieza room = (Pieza) ubicacionActual;
                    room.interactuar(cyanPiki, magentaPiki, amarilloPiki);
                } else if (ubicacionActual instanceof Pildora) {
                    Pildora pills = (Pildora) ubicacionActual;
                    pills.interactuar(cyanPiki, magentaPiki, amarilloPiki);
                } else if (ubicacionActual instanceof Enemigo) {
                    Enemigo enemy = (Enemigo) ubicacionActual;
                    enemy.interactuar(cyanPiki, magentaPiki, amarilloPiki);
                } else if (ubicacionActual instanceof Muralla) {
                    Muralla wall = (Muralla) ubicacionActual;
                    wall.interactuar(cyanPiki, magentaPiki, amarilloPiki);
                }
            } else {
                System.out.println("Lomiar se da cuenta que ya ha completado esta ubicación..y no queda nada por hacer, sigue asi!");
                System.out.println("--------------------------------------------------------------");
            }
        }
        return pos;
    }
    ////////////////////
    //currUbicacion(Zona ubicacion)
    //ubicacion: se le entrega la zona en la que esta ubicado
    //---------------
    //Esta funcion primero verifica si no esta completada, si es asi manda un mensaje simplemente, si no es asi entonces se obtiene la informacion a traves de ubicacion
    //para luego castearla y printearla al jugador
    ///////////////////
    private static void currUbicacion(Zona ubicacion) {
        if(ubicacion.Complete()==true){
            System.out.println("Lomiar esta ubicado en un lugar ya completo...nada que hacer...\n"); 
        }else{
            System.out.println("Lomiar esta ubicado en..." + ubicacion.ZonaType());
            if (ubicacion instanceof Pieza) {
                Pieza room = (Pieza) ubicacion;
                System.out.println("(Peso: " + room.GetPESOP() + ")\n");
            } else if (ubicacion instanceof Pildora) {
                Pildora pills = (Pildora) ubicacion;
                System.out.println("(Cant. pildoras: " + pills.GetCANTP() + ")\n");
            } else if (ubicacion instanceof Enemigo) {
                Enemigo enemy = (Enemigo) ubicacion;
                System.out.println("(HP: " + enemy.GetHPE() + " // ATK: " + enemy.GetATKE() + " // Peso: " + enemy.GetPESOE() + " )\n");
            } else if (ubicacion instanceof Muralla) {
                Muralla wall = (Muralla) ubicacion;
                System.out.println("(HP: " + wall.GetHPM() + ")\n");
            }
        }
    }
    
}
