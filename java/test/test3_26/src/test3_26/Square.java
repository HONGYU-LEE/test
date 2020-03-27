package test3_26;

public class Square extends Shape{
	private double length;

	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		this.length = length;
	}

	@Override
	public double getArea() 
	{
		return length * length;
	}

	@Override
	public double getPerimeter() {
		
		return 4 * length;
	}
	
}
