package analiseempirica;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.time.Clock;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

/**
 *
 * @author rodrigo
 */
public class AnaliseEmpirica {

    public static void main(String[] args) throws IOException {
        
        RandomArray ra = new RandomArray();
        //ra.setSeed(139);
        int n = (int) Math.pow(2, 20);
        //Entradas.escrever(ra.generate(n, 128), "../entradas/entrada5.txt");
        int [] array =Entradas.ler("../entradas/entrada1.txt", n);
        
        MaxSubArray msb = new MaxSubArray();
        
        long startTime = System.currentTimeMillis();
        long startCpuTime = Times.getCpuTime();
        long startUserTime = Times.getUserTime();
        long startSystemTime = Times.getSystemTime();
        msb.divideAndConquer(array);
        System.out.println("\nTimes:");
        System.out.println("Clock time: "+ (System.currentTimeMillis()-startTime) +" ms");
        System.out.println("CPU time: "+(Times.getCpuTime()-startCpuTime)/1000000 +" ms");
        System.out.println("User time: "+(Times.getUserTime()-startUserTime)/1000000 +" ms");
        System.out.println("System time: "+(Times.getSystemTime()-startSystemTime)/1000000 +" ms");

        /*
        int[] a = msb.betterEnumeration(array);
        System.out.println(a[0]+", "+a[1]+", "+a[2]);
        
        a = msb.divideAndConquer(array);
        System.out.println(a[0]+", "+a[1]+", "+a[2]);
        */
    }
    
}
