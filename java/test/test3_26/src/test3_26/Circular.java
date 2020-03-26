package test3_26;

public class Circular extends Shape{
	private double Radius;

	public double getRadius() {
		return Radius;
	}

	public void setRadius(double radius) {
		Radius = radius;
	}

	@Override
	public double getArea() {
		return Radius * Radius * Math.PI;
	}

	@Override
	public double getPerimeter() {
		return 2 * Radius * Math.PI;
	}
	
	
}

