package SquareMatrix;

import java.util.Random;

public class SquareMatrixTest {
    public static void main(String[] args) {
        Random random = new Random();
        int sizeMatrix = 2 + random.nextInt(11);
        int[][] matrix = new int[sizeMatrix][sizeMatrix];
        for(int i = 0; i < sizeMatrix; i++){
            for (int j = 0; j < sizeMatrix; j++){
                matrix[i][j] = random.nextInt(9);
            }
        }
        SquareMatrix matrix1 = new SquareMatrix(matrix);
        matrix1.printAll();
    }
}
