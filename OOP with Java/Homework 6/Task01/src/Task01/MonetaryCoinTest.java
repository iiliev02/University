package Task01;

public class MonetaryCoinTest {
    public static void main(String[] args) {
        MonetaryCoin coinOne = new MonetaryCoin(1, Face.HEAD);
        MonetaryCoin coinTwo = new MonetaryCoin(2, Face.TAIL);
        MonetaryCoin coinFive = new MonetaryCoin(5, Face.HEAD);
        System.out.println("Face of coin before flip:" + coinFive.getFace());
        coinFive.flip();
        System.out.println("Face of coin after flip:" + coinFive.getFace());
        int sumOfValues = coinOne.getValue() + coinTwo.getValue() + coinFive.getValue();
        System.out.printf("Sum of the values of monetary coins: %d", sumOfValues);
    }
}
