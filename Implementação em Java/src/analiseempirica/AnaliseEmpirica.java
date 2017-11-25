package analiseempirica;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 *
 * @author rodrigo
 */
public class AnaliseEmpirica {

    public static void main(String[] args) throws IOException {
        
        RandomArray ra = new RandomArray();
        int [] array = ra.generate(10, 128, 0.5);
        FileWriter entradas = new FileWriter("../entradas.txt");
        PrintWriter pw = new PrintWriter(entradas);
        pw.println("teste");
        System.out.println("array:");
        for (int i : array) {
            pw.println(i);
            //System.out.println(i);
        }
        pw.close();
        
        MaxSubArray msb = new MaxSubArray();
        //int[] ar = { -10, -8, -3, -7, -2, -7, -3, -9 };
        msb.dynamicProgramming(array);
        
        int[] a = msb.betterEnumeration(array);
        System.out.println(a[0]+", "+a[1]+", "+a[2]);
        
        a = msb.divideAndConquer(array);
        System.out.println(a[0]+", "+a[1]+", "+a[2]);

    }
    
}
