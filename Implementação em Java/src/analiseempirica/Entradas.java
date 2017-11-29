package analiseempirica;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author rodrigo
 */
public class Entradas {
    
    public static void escrever(int[] array, String path) throws IOException{
        FileWriter entradas = new FileWriter(path);
        PrintWriter pw = new PrintWriter(entradas);
        
        for (int i : array) {
            pw.println(i);
        }
        pw.close();
    }
    
    public static int[] ler(String path, int n) throws FileNotFoundException{
        Scanner scanner = new Scanner(new File(path));
        int [] arr = new int [n];
        int i = 0;
        while(scanner.hasNextInt() & i<n){
           arr[i++] = scanner.nextInt();
        }
        return arr;
    }
}
