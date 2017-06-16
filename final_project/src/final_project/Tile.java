// Class Description:   this class is that you design pattern of every block  
//         				i use a big rectangle be a root and all 12 small blocks
//						on it ,12 small can be set visible and not visible 
//						so it can make up 1--14
//						i also set highlight to which block is selected 

package final_project;

import javafx.scene.layout.AnchorPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.RectangleBuilder;

@SuppressWarnings("deprecation")
public class Tile extends AnchorPane{
	Rectangle btn;
	Rectangle [] rec = new Rectangle [14];
	public Tile(int x,int y,int len,int ith){
		set_Rectangle(x,y,len);
		btn = RectangleBuilder.create()
				.fill(Color.web("#21285C")).stroke(Color.web("#FCB942")).strokeWidth(4).
				arcHeight(5).arcWidth(5).
				layoutX(x).layoutY(y).height(len).width(len).opacity(0.2).build();
		set_visible(ith);
		for(int j = 0;j < 12;j++){
			this.getChildren().add(rec[j]);
		}
		this.getChildren().addAll(btn);
	}
	void set_Rectangle(int x,int y,int len){
		double l1 = len / 13,l2 = len / 13 * 2,l3 = len / 13 * 6,
				l4 = len / 13 * 7,l5 = len / 13 * 11;
		double w = len / 13,l = len / 13 * 4; 
		// make 12 small rectangle
		rec[0] = RectangleBuilder.create()     
				.height(w).
				width(l).
				layoutX(x + l2).
				layoutY(y + l1).
				fill(Color.web("#FCB942")).
				opacity(0).
				build();
		rec[1] = RectangleBuilder.create()
				.height(w).
				width(l).
				layoutX(x + l4).
				layoutY(y + l1).
				fill(Color.web("#99B5BE")).
				opacity(0).
				build();
		
		rec[2] = RectangleBuilder.create()
				.height(l).
				width(w).
				layoutX(x + l1).
				layoutY(y + l2).
				fill(Color.web("#E1A6FE")).
				opacity(0).
				build();
		rec[3] = RectangleBuilder.create()
				.height(l).
				width(w).
				layoutX(x + l3).
				layoutY(y + l2).
				fill(Color.web("#254441")).
				opacity(0).
				build();
		rec[4] = RectangleBuilder.create()
				.height(l).
				width(w).
				layoutX(x + l5).
				layoutY(y + l2).
				fill(Color.web("#46E8C3")).
				opacity(0).
				build();
		
		rec[5] = RectangleBuilder.create()
				.height(w).
				width(l).
				layoutX(x + l2).
				layoutY(y + l3).
				fill(Color.web("#213F1F")).
				opacity(0).
				build();
		rec[6] = RectangleBuilder.create()
				.height(w).
				width(l).
				layoutX(x + l4).
				layoutY(y + l3).
				fill(Color.web("#88D20D")).
				opacity(0).
				build();
		
		rec[7] = RectangleBuilder.create()
				.height(l).
				width(w).
				layoutX(x + l1).
				layoutY(y + l4).
				fill(Color.web("#433E19")).
				opacity(0).
				build();
		rec[8] = RectangleBuilder.create()
				.height(l).
				width(w).
				layoutX(x + l3).
				layoutY(y + l4).
				fill(Color.web("#57524F")).
				opacity(0).
				build();
		rec[9] = RectangleBuilder.create()
				.height(l).
				width(w).
				layoutX(x + l5).
				layoutY(y + l4).
				fill(Color.web("#48221A")).
				opacity(0).
				build();
		
		rec[10] = RectangleBuilder.create()
				.height(w).
				width(l).
				layoutX(x + l2).
				layoutY(y + l5).
				fill(Color.web("#EF3423")).
				opacity(0).
				build();
		rec[11] = RectangleBuilder.create()
				.height(w).
				width(l).
				layoutX(x + l4).
				layoutY(y + l5).
				fill(Color.web("#21285C")).
				opacity(0).
				build();
	}
	// if a block is selected it's stroke will change
	public void set_color(int i){
		if(i == 1)
			btn.setStroke(Color.web("4C255B"));
		else 
			btn.setStroke(Color.web("#FCB942"));
	}
	// to set different block
	public void set_visible(int i){
		switch(i){
		case 1:{
			rec[4].setOpacity(1);
			rec[9].setOpacity(1);
			break;
		}
		case 2:{
			rec[1].setOpacity(1);
			rec[4].setOpacity(1);
			rec[6].setOpacity(1);
			rec[8].setOpacity(1);
			rec[11].setOpacity(1);
			break;
		}
		case 3:{
			rec[1].setOpacity(1);
			rec[4].setOpacity(1);
			rec[6].setOpacity(1);
			rec[9].setOpacity(1);
			rec[11].setOpacity(1);
			break;
		}
		case 4:{
			rec[3].setOpacity(1);
			rec[4].setOpacity(1);
			rec[6].setOpacity(1);
			rec[9].setOpacity(1);
			break;
		}
		case 5:{
			rec[1].setOpacity(1);
			rec[3].setOpacity(1);
			rec[6].setOpacity(1);
			rec[9].setOpacity(1);
			rec[11].setOpacity(1);
			break;
		}
		case 6:{
			rec[1].setOpacity(1);
			rec[3].setOpacity(1);
			rec[6].setOpacity(1);
			rec[8].setOpacity(1);
			rec[9].setOpacity(1);
			rec[11].setOpacity(1);
			break;
		}	
		case 7:{
			rec[1].setOpacity(1);
			rec[4].setOpacity(1);
			rec[9].setOpacity(1);
			break;
		}
		case 8:{
			rec[1].setOpacity(1);
			rec[3].setOpacity(1);
			rec[4].setOpacity(1);
			rec[6].setOpacity(1);
			rec[8].setOpacity(1);
			rec[9].setOpacity(1);
			rec[11].setOpacity(1);
			break;
		}
		case 9:{
			rec[1].setOpacity(1);
			rec[3].setOpacity(1);
			rec[4].setOpacity(1);
			rec[6].setOpacity(1);
			rec[9].setOpacity(1);
			rec[11].setOpacity(1);
			break;
		}
		case 10:{
			rec[1].setOpacity(1);
			rec[2].setOpacity(1);
			rec[7].setOpacity(1);
			rec[3].setOpacity(1);
			rec[4].setOpacity(1);
			rec[8].setOpacity(1);
			rec[9].setOpacity(1);
			rec[11].setOpacity(1);
			break;
		}
		case 11:{
			rec[2].setOpacity(1);
			rec[7].setOpacity(1);
			rec[3].setOpacity(1);
			rec[8].setOpacity(1);
			break;
		}
		case 12:{
			rec[2].setOpacity(1);
			rec[7].setOpacity(1);
			rec[1].setOpacity(1);
			rec[4].setOpacity(1);
			rec[6].setOpacity(1);
			rec[8].setOpacity(1);
			rec[11].setOpacity(1);
			break;
		}
		case 13:{
			rec[2].setOpacity(1);
			rec[7].setOpacity(1);
			rec[1].setOpacity(1);
			rec[4].setOpacity(1);
			rec[6].setOpacity(1);
			rec[9].setOpacity(1);
			rec[11].setOpacity(1);
			break;
		}
		case 14:{
			rec[2].setOpacity(1);
			rec[7].setOpacity(1);
			rec[3].setOpacity(1);
			rec[4].setOpacity(1);
			rec[6].setOpacity(1);
			rec[9].setOpacity(1);
			break;
		}
	}
	}
	
}
