package test3_26;

public class test {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Circular c1 = new Circular();
		c1.setRadius(3);
		System.out.println(" Circular Area: " + c1.getArea() + " Perimeter: " + c1.getPerimeter());	
		
		Square s1 = new Square();
		s1.setLength(2);
		System.out.println(" Square Area: " + s1.getArea() + " Perimeter: " + s1.getPerimeter());
	
		Rectangle r1 = new Rectangle();
		r1.setLong(3);
		r1.setWide(5);
		
		System.out.println(" Rectangle Area: " + r1.getArea() + " Perimeter: " + r1.getPerimeter());
	
	}

}
