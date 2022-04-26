package Task01;

import java.util.Random;

public class Coin {
    private Random rand;
    private Face face;

    public Coin(Face face) {
        this.rand = new Random();
        setFace(face);
    }

    public Face getFace() {

        return this.face;
    }

    public void setFace(Face face) {
        this.face = face;
    }

    public void flip() {
        boolean isFlip = this.rand.nextBoolean();
        if(isFlip){
            setFace(Face.HEAD);
        }else{
            setFace(Face.TAIL);
        }
    }

    public boolean isHeads() {
        if(this.face == Face.HEAD){
            return true;
        }else {
            return false;
        }
    }

    public String toString() {

        return String.format("Face of coin is: " + this.face);
    }
}
