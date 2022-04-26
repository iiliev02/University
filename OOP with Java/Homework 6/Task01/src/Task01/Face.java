package Task01;

public enum Face {
    HEAD("Head"), TAIL("Tail");


    private String face;

    Face(String face)
    {
        this.face = face;
    }

    public String getFace()
    {
        return this.face;
    }
}
