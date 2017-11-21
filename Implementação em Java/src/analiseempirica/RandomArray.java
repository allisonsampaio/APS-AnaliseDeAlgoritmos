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
    
    public int[] generate(int length, int bound){
        int[] array = new int[length];
        for (int i = 0; i < length; i++){
            array[i] = r.nextInt(bound*2)-bound;
        }
        return array;
    }
}
