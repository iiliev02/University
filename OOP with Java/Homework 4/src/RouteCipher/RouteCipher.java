package RouteCipher;

public class RouteCipher {
    private int key;

    public RouteCipher(int key){
        setKey(key);
    }

    public int getKey(){
        return this.key;
    }

    public void setKey(int key){
        this.key = key == 0 ? 1 : key;
    }

    private String positiveEncryptSpiralMatrix(char[][] encryptMatrix){  // Метод за спираловидно четене на матрица от горен ляв ъгъл
        String result = "";
        int rows = encryptMatrix.length; // Вземане на броя редове на матрицата
        int cols = encryptMatrix[0].length; // Вземане на броя колони на матрицата
        int top = 0, bottom = rows - 1, left = 0, right = cols - 1; // Определяне на границите на матрицата
        int dir = 1;

        while (top <= bottom && left <= right) {
            if (dir == 1) {          // Четене на лява страна на матрицата
                for (int i = top; i <= bottom; ++i) {
                    result += encryptMatrix[i][left];
                }
                ++left; // След прочитане на цялата първа колона, преминаваме към следващата колона
                dir = 2;
            }
            else if (dir == 2) {     // Четене на долна страна на матрицата
                for (int i = left; i <= right; ++i) {
                    result += encryptMatrix[bottom][i];
                }
                --bottom; // След прочитане на целия последен ред, преминаваме към предходния ред
                dir = 3;
            }
            else if (dir == 3) {     // Четене на дясна страна на матрицата
                for (int i = bottom; i >= top; --i) {
                    result += encryptMatrix[i][right];
                }
                --right; // След прочитане на цялата последна колона, преминаваме към предходната колона
                dir = 4;
            }
            else if (dir == 4) {     // Четене на горна страна на матрицата
                for (int i = right; i >= left; --i) {
                    result += encryptMatrix[top][i];
                }
                ++top; // След прочитане на целия първи ред, преминаваме към следващия ред
                dir = 1;
            }
        }
        return result; // Връщане на криптирания текст
    }

    private String negativeEncryptSpiralMatrix(char[][] encryptMatrix){  // Метод за спираловидно четене на матрица от долен десен ъгъл
        String result = "";
        int rows = encryptMatrix.length;
        int cols = encryptMatrix[0].length;
        int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
        int dir = 1;

        while (top <= bottom && left <= right) {
            if (dir == 1) {          // Четене на дясна страна на матрица
                for (int i = bottom; i >= top; --i) {
                    result += encryptMatrix[i][right];
                }
                --right;
                dir = 2;
            }
            else if (dir == 2) {     // Четене на горна страна на матрица
                for (int i = right; i >= left; --i) {
                    result += encryptMatrix[top][i];
                }
                ++top;
                dir = 3;
            }
            else if (dir == 3) {     // Четене на лява страна на матрица
                for (int i = top; i <= bottom; ++i) {
                    result += encryptMatrix[i][left];
                }
                ++left;
                dir = 4;
            }
            else if (dir == 4) {     // Четене на долна страна на матрица
                for (int i = left; i <= right; ++i) {
                    result += encryptMatrix[bottom][i];
                }
                --bottom;
                dir = 1;
            }
        }
        return result;
    }

    private char[][] positiveDecryptSpiralMatrix(char[] encryptTextChar){ // Метод за спираловидно създавене на матрица с начало горен ляв ъгъл
        int countEncryptTextChar = 0; // Променлива за следене на индекса на чар масива
        int cols = Math.abs(this.key); // Определяне броя на колоните на декриптиращата матрица
        int rows = (int) Math.ceil(encryptTextChar.length / (double) cols); // Определяне на броя на редовете на декриптиращта матрица
        char[][] decryptMatrix = new char[rows][cols];
        int top = 0, bottom = rows - 1, left = 0, right = cols - 1; // Определяне границите на матрицата
        int dir = 1;

        while (top <= bottom && left <= right) {
            if (dir == 1) {          // Записване на лява страна на матрицата
                for (int i = top; i <= bottom; ++i) {
                    decryptMatrix[i][left] = encryptTextChar[countEncryptTextChar++];
                }
                ++left; // След записване на цялата първа колона, преминаваме към следващата колона
                dir = 2;
            }
            else if (dir == 2) {     // Записване на долна страна на матрицата
                for (int i = left; i <= right; ++i) {
                    decryptMatrix[bottom][i] = encryptTextChar[countEncryptTextChar++];
                }
                --bottom; // След записване на целия последен ред, преминаваме към предходния ред
                dir = 3;
            }
            else if (dir == 3) {     // Записване на дясна страна на матрицата
                for (int i = bottom; i >= top; --i) {
                    decryptMatrix[i][right] = encryptTextChar[countEncryptTextChar++];
                }
                --right; // След записване на цялата последна колона, преминаваме към предходната колона
                dir = 4;
            }
            else if (dir == 4) {     // Записване на горна страна на матрицата
                for (int i = right; i >= left; --i) {
                    decryptMatrix[top][i] = encryptTextChar[countEncryptTextChar++];
                }
                ++top; // След записване на целия първи ред, преминаваме към следващия ред
                dir = 1;
            }
        }
        return decryptMatrix; // Връщане на създадената декриптираща матрица
    }

    private char[][] negativeDecryptSpiralMatrix(char[] encryptTextChar){  // Метод за спираловидно създавене на матрица с начало долен десен ъгъл
        int countEncryptTextChar = 0;
        int cols = Math.abs(this.key);
        int rows = (int) Math.ceil(encryptTextChar.length / (double) cols);
        char[][] decryptMatrix = new char[rows][cols];
        int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
        int dir = 1;

        while (top <= bottom && left <= right) {
            if (dir == 1) {          // Записване на дясна страна на матрицата
                for (int i = bottom; i >= top; --i) {
                    decryptMatrix[i][right] = encryptTextChar[countEncryptTextChar++];
                }
                --right;
                dir = 2;
            }
            else if (dir == 2) {     // Записване на горна страна на матрицата
                for (int i = right; i >= left; --i) {
                    decryptMatrix[top][i] = encryptTextChar[countEncryptTextChar++];
                }
                ++top;
                dir = 3;
            }
            else if (dir == 3) {     // Записване на лява страна на матрицата
                for (int i = top; i <= bottom; ++i) {
                    decryptMatrix[i][left] = encryptTextChar[countEncryptTextChar++];
                }
                ++left;
                dir = 4;
            }
            else if (dir == 4) {     // Записване на долна страна на матрицата
                for (int i = left; i <= right; ++i) {
                    decryptMatrix[bottom][i] = encryptTextChar[countEncryptTextChar++];
                }
                --bottom;
                dir = 1;
            }
        }
        return decryptMatrix;
    }

    public String encrypt(String plainText){
        int rows, cols, countCipherTextChars = 0;
        String readyTextForEncrypt = "", encryptedText = "";
        char[] prepareTextForEncrypt = plainText.toCharArray();
        for (int i = 0; i < prepareTextForEncrypt.length; i++)  // Премахване на препинателни знаци и интервали от подадения текст за криптиране
        {
            if((prepareTextForEncrypt[i] >= 'a' && prepareTextForEncrypt[i] <= 'z')
                    || (prepareTextForEncrypt[i] >= 'A' && prepareTextForEncrypt[i] <= 'Z')){
                readyTextForEncrypt += prepareTextForEncrypt[i];
            }
        }
        char[] cipherTextChars = readyTextForEncrypt.toCharArray();
        cols = Math.abs(this.key); // Определяне на колоните на матрицата за криптиране
        rows = (int) Math.ceil(cipherTextChars.length / (double) cols); // Определяне на редовете на матрицата за криптиране
        char[][] encryptMatrix = new char[rows][cols];
        for(int i = 0; i < rows; i++) // Въвеждане на символите в матрицата
        {
            for (int j = 0; j < cols; j++)
            {
                if(countCipherTextChars == cipherTextChars.length){
                    encryptMatrix[i][j] = '$'; // Добавяне на специален знак за допълване на матрицата, след приключване на символите на дадения текст
                }else {
                    encryptMatrix[i][j] = cipherTextChars[countCipherTextChars++];
                }
            }
        }
        if(this.key > 0) // Вземане на вече криптирания текст
        {
            encryptedText = this.positiveEncryptSpiralMatrix(encryptMatrix);
        } else{
            encryptedText = this.negativeEncryptSpiralMatrix(encryptMatrix);
        }
        return encryptedText; // Връщане на получения резултат
    }

    public String decrypt(String cipherText){
        int cols = Math.abs(this.key); // Определяне на колоните на матрицата за декриптиране на текста
        int rows = (int) Math.ceil(cipherText.length() / (double) cols); // Определяне на редовете на матрицата за декриптиране на текста
        char[][] decryptMatrix = new char[rows][cols];
        char[] encryptTextChars = cipherText.toCharArray();
        String decryptedText = "";
        if(this.key > 0){ // Вземане на вече декриптирания текст
            decryptMatrix = positiveDecryptSpiralMatrix(encryptTextChars);
        } else{
            decryptMatrix = negativeDecryptSpiralMatrix(encryptTextChars);
        }
        for (int i = 0; i < rows; i++)  // Четене и записване на текста от декриптиращата матрицата и премахне на допълнителното добавени специални знаци
        {
            for (int j = 0; j < cols; j++)
            {
                if(decryptMatrix[i][j] != '$'){
                    decryptedText += decryptMatrix[i][j];
                }
            }
        }
        return decryptedText; // Връщане на декриптирания текст
    }

    public String toString(){
        return String.format("The Cipher Key: %d", this.key);
    }
}
