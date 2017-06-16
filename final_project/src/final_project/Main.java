//
// File Name:    
//				 Main.java put my main and the root of all children
// Author:       ChenShiCheng		Student Number: 3013218131
// Class Day:    Thursday		Class Year: 2013
// Email:       
//				 337134154@qq.com
// Assignment number:   final_project
// Description:  Short description of the program or project (should at least be a couple sentence).  
//    			 If you have input or output, where does it come from or where does it go to. 
//				 What are the features of the program?  Does it do anything beyond the requirements.  
//				 Does it include bugs that you were not able to solve?
//
// Know Bugs: as far as i know i don't have bug
//
// Future Improvements:    
//		my tile can be design more beautiful
//      my class can be design more good 
//      i want to try MVC but failed



// Class Description:   all AnchorPane's root this class have task progress and it have a
//						 son is MyLevel class
//                      it can have two thread root and task


package final_project;

import final_project.Main;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.ProgressBar;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

public class Main extends Application{
	
	public static void main(String[] args){
		Main.launch(args); // main function and it can call start
	}
	public void start(Stage stage) throws Exception {
		MyTask worker = new MyTask(); // create worker object
		
		ProgressBar progressBar = new ProgressBar();//create progressBar    
	    progressBar.progressProperty().bind(worker.progressProperty()); // it can change with time 
	    
	    AnchorPane root = new AnchorPane();
	    AnchorPane.setBottomAnchor(progressBar, 20.0);
	    AnchorPane.setRightAnchor(progressBar, 20.0);
	    AnchorPane.setLeftAnchor(progressBar, 20.0);   // progressBar's position
	    
	    MyLevel level = new MyLevel();
	    level.LEVEL_listener(worker);
		root.getChildren().addAll(progressBar,level);
		// put level object and progressBar to an AnchorPane
		
		stage.titleProperty().bind(worker.titleProperty());
		
		stage.setScene(new Scene(root,900.0,600.0));
		
		new Thread( worker ).start();// create a new thread to put worker
		stage.show();
	}
}
