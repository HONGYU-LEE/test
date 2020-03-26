package test3_26;

public class Rectangle extends Shape{

	private double Wide;
	private double Long;
	
	public double getWide() {
		return Wide;
	}

	public void setWide(double wide) {
		Wide = wide;
	}

	public double getLong() {
		return Long;
	}

	public void setLong(double l) {
		Long = l;
	}	
	public double getArea() {
		return Wide * Long;
	}

	@Override
	public double getPerimeter() {
		return (Long + Wide) * 2;
	}

}
