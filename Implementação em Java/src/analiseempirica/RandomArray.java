package analiseempirica;

import java.util.Random;

/**
 *
 * @author rodrigo
 */
public class RandomArray {
    Random r = new Random();
    
    
    public void setSeed(long seed){
        r.setSeed(seed);
    }
    
    public int[] generate(int length, int bound, double percent){
        int[] array = new int[length];
        int cont = 0;
        int i;
        for (i = 0; i < length; i++){
            array[i] = r.nextInt(bound)+1;
        }
        while(cont < (int)(percent*length)){
            i = r.nextInt(length);
            if(array[i] > 0){
                array[i] *= -1;
                cont++;
            }
        }
        return array;
    }
}
