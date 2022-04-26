package SquareMatrix;

import java.util.Random;

public class SquareMatrix {
    private int[][] dataArray;

    public SquareMatrix(){
        setDataArray(null);
    }

    public SquareMatrix(int[][] dataArray){
        setDataArray(dataArray);
    }

    public SquareMatrix(SquareMatrix squareMatrix){
        setDataArray(squareMatrix.getDataArray());
    }

    public void setDataArray(int[][] dataArray){
        int sizeDataArray;
        if(dataArray == null){
            Random random = new Random();
            sizeDataArray = 2 + random.nextInt(11);
            this.dataArray = new int[sizeDataArray][sizeDataArray];
        }else {
            sizeDataArray = dataArray.length;
            this.dataArray = new int[sizeDataArray][sizeDataArray];
            for(int i = 0; i < sizeDataArray; i++){
                for (int j = 0; j < sizeDataArray; j++){
                    this.dataArray[i][j] = dataArray[i][j];
                }
            }
        }
    }

    public int[][] getDataArray(){
        return this.dataArray;
    }

    public int findMaxSum(){
        int maxSum = 0;
        int sizeMatrix = this.dataArray.length;
        for(int i = 0; i < sizeMatrix - 1; i++){
            for(int j = 0; j < sizeMatrix - 1; j++){
                int sumOfSubMatrix = this.dataArray[i][j] + this.dataArray[i][j + 1] + this.dataArray[i + 1][j] + this.dataArray[i + 1][j + 1];
                if(sumOfSubMatrix > maxSum){
                    maxSum = sumOfSubMatrix;
                }
            }
        }
        return maxSum;
    }

    public void printAll(){
        int sizeMatrix = this.dataArray.length;
        int maxSum = this.findMaxSum();
        String coordinatesSubMatrix = "";
        for(int i = 0; i < sizeMatrix - 1; i++){
            for(int j = 0; j < sizeMatrix - 1; j++){
                int sumOfSubMatrix = this.dataArray[i][j] + this.dataArray[i][j + 1] + this.dataArray[i + 1][j] + this.dataArray[i + 1][j + 1];
                if(sumOfSubMatrix == maxSum){
                    coordinatesSubMatrix += "[" + i + ", " + j + "], ";
                }
            }
        }
        System.out.printf("Maximum sum: %d \nSubmatrices with Maximum sum: %s", maxSum, coordinatesSubMatrix);
    }

    public String toString(){
        int sizeMatrix = this.dataArray.length;
        String result = "";
        for(int i = 0; i < sizeMatrix; i++){
            for(int j = 0; j < sizeMatrix; j++){
                if(j == sizeMatrix - 1)
                {
                    result += String.format("%d\n", this.dataArray[i][j]);
                }else {
                    result += String.format("%d, ", this.dataArray[i][j]);
                }
            }
        }
        return result;
    }
}
