class Figure {
    final private double pi = 3.14159;
    private double radius;

    // public void setPI(double newPI){ pi = newPI;}
    public double getPI() {
        return pi;
    }

    public void setRadius(double newRadius) {
        radius = newRadius;
    }

    public double getRadius() {
        return radius;
    }

    final public double circleArea() {
        return pi * radius * radius;
    }
}

class Cylindar extends Figure {
    private double height;

    Cylindar(double newRadius, double newHeight) {
        setRadius(newRadius);
        // setPI(3.14159);
        height = newHeight;

    }

    /*
     * public double circleArea(){
     * return pi*radius*radius;
     * }
     */
    public double cylindarVolume() {
        return circleArea() * height;
    }
}