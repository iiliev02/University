package Task01;

public class MonetaryCoin extends Coin{
    private int value;

    MonetaryCoin(int value, Face face){
        super(face);
        setValue(value);
    }

    int getValue(){
        return this.value;
    }

    void setValue(int value){
        this.value = value == 0 ? 1 : value;
    }
}
