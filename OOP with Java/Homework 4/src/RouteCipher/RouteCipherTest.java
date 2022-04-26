package RouteCipher;

public class RouteCipherTest {
    public static void main(String[] args) {
        RouteCipher cipherOne = new RouteCipher(-5);
        String cipherTextOne = "abort the mission, you have been spotted", encryptedTextOne = "", decryptedTextOne = "";
        encryptedTextOne = cipherOne.encrypt(cipherTextOne);
        decryptedTextOne = cipherOne.decrypt(encryptedTextOne);
        System.out.printf("Original text: %s \nEncrypted Text: %s \nDecryptedText: %s", cipherTextOne, encryptedTextOne, decryptedTextOne);

        RouteCipher cipherTwo = new RouteCipher(4);
        String cipherTextTwo = "This is the plain text.", encryptedTextTwo = "", decryptedTextTwo = "";
        encryptedTextTwo = cipherTwo.encrypt(cipherTextTwo);
        decryptedTextTwo = cipherTwo.decrypt(encryptedTextTwo);
        System.out.printf("\n\nOriginal text: %s \nEncrypted Text: %s \nDecryptedText: %s", cipherTextTwo, encryptedTextTwo, decryptedTextTwo);
    }
}
