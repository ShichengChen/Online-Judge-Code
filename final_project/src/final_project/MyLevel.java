// Class Description:   this is a class which use is to build select level button and 
//						start button,start button can start a new game and restart a 
//         				new game if you don't want to go on
//						if you complete all the level you can gain a text which is you win
//						this class is inherit from AnchorPane and give next button and start button
//						there function

package final_project;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonBuilder;
import javafx.scene.layout.AnchorPane;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.text.TextBuilder;

@SuppressWarnings("deprecation")
public class MyLevel extends AnchorPane{
	public Button btn,nextbutton;
	Text text;
	Model model;
	static AnchorPane root;
	public MyLevel() {
		btn = ButtonBuilder.create().     
				layoutX(800).
				layoutY(0).
				prefHeight(50).
				prefWidth(100).
				text("START").
				build();
		//this button can start a new game
		nextbutton = ButtonBuilder.create(). 
				layoutX(800).
				layoutY(110).
				prefHeight(50).
				prefWidth(100).
				text("NEXT").
				build();
		// when you win the game ,press this button you can go to next level
		text = TextBuilder.create().
				layoutX(10).
				layoutY(300).
				font(new Font(200)).
				text("You Win").
				build();
		// you will get this text when you win the game
		this.getChildren().addAll(btn,nextbutton);
	};
	public void LEVEL_listener(MyTask worker) {
			
		root = new AnchorPane();
		model = new Model(0);
		btn.setOnAction(new EventHandler<ActionEvent>() {
			public void handle (ActionEvent act){		
				root.getChildren().clear();
				model.clear();
				model = new Model(0);
				root.getChildren().add(model);
				worker.start();
				model.init_level();
			}
		});			
		nextbutton.setOnAction(new EventHandler<ActionEvent>() {
			public void handle (ActionEvent act){
				if(Model.times == 42 && Model.level == 0){
					model.clear();
					worker.start();
					model = new Model(1);
					root.getChildren().add(model);
					model.init_level();
				}
				else if(Model.times == 56 && Model.level == 1){
					model.clear();
					worker.start();
					model = new Model(2);
					root.getChildren().add(model);
					model.init_level();
				}
				else if(Model.times == 70 && Model.level == 2){
					model.clear();
					MyTask.win = true;
					root.getChildren().add(text);
				}
			}
		});
		// if you satisfy the condition you can go to new level
		this.getChildren().addAll(root);
	}
}
