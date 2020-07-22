package test3_26;

import java.awt.*;
import javax.swing.*;

public class AnimalData {
public AnimalData(String title) {
  JFrame Animal = new JFrame(title);
  setLAF(); 
  init(Animal);
  Animal.getContentPane().add(new PiePanel());
  
}
class PiePanel extends JPanel {
   private int width=200;
   private int height=200; 
   private int originX; 
   private int originY;
@Override
public void paintComponent(Graphics g){
   originX=(this.getSize().width/2)-(width/2);
   originY=(this.getSize().height/2)-(height/2);

   Graphics2D pieChart=(Graphics2D) g;

   pieChart.setColor(Color.red);
   pieChart.fillArc(originX, originY,width, height,0, 72);
   pieChart.setColor(Color.BLUE);
   pieChart.fillArc(originX, originY,width, height,72, 36);
   pieChart.setColor(Color.GREEN);
   pieChart.fillArc(originX, originY,width, height,108, 108);
   pieChart.setColor(Color.WHITE);
   pieChart.fillArc(originX, originY,width, height,216, 72);
   pieChart.setColor(Color.yellow);
   pieChart.fillArc(originX, originY,width, height,288, 72);
   pieChart.drawString("England -- 20%",originX+(width*7/8),originY+(height/6));
   pieChart.drawString("China -- 10%",originX+(width/2),originY);
   pieChart.drawString("Canada -- 30%", originX-(width/4), originY+(height/3));
   pieChart.drawString("Brazil -- 20%",originX+(width*5/8),originY+(height*15/16));
   pieChart.drawString("Japan -- 20%",originX+(width*1/8),originY+(height*15/16));
   
}
}
private void setLAF() {
	try {
	    UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");
	} catch (Exception e) {
	try {
	    UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
	} catch (Exception ignore) {
	}
	}
	}

public void init(JFrame f) {
   JLabel word=new JLabel("The lion data");
   word.setSize(68,30);
   word.setLocation(-500,20);
   f.add(word);
   f.setAlwaysOnTop(true);
   f.setSize(new Dimension(600, 600));
   f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
   f.setLocationRelativeTo(null); 
   f.setVisible(true);
}
public static void main(String[] args) {
new AnimalData("Animal");
}
}